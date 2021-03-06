// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <lib/devmgr-launcher/launch.h>
#include <lib/devmgr-launcher/processargs.h>
#include <lib/fdio/directory.h>
#include <lib/fdio/fd.h>
#include <lib/fdio/fdio.h>
#include <lib/fdio/io.h>
#include <lib/fdio/namespace.h>
#include <lib/fdio/spawn.h>
#include <lib/zx/channel.h>
#include <lib/zx/process.h>
#include <stdint.h>
#include <zircon/assert.h>
#include <zircon/device/vfs.h>
#include <zircon/processargs.h>
#include <zircon/status.h>

#include <utility>

#include <fbl/algorithm.h>

namespace {

constexpr const char* kDevmgrPath = "/boot/bin/devcoordinator";

}  // namespace

namespace devmgr_launcher {

zx_status_t Launch(Args args, zx::channel svc_client, zx::job* devmgr_job, zx::channel* devfs_root,
                   zx::channel* outgoing_services_root) {
  // Create containing job (and copy to send to devmgr)
  zx::job job, job_copy;
  zx_status_t status = zx::job::create(*zx::job::default_job(), 0, &job);
  if (status != ZX_OK) {
    return status;
  }
  status = job.duplicate(ZX_RIGHT_SAME_RIGHTS, &job_copy);
  if (status != ZX_OK) {
    return status;
  }

  // Create channel to connect to devfs
  zx::channel devfs_client, devfs_server;
  status = zx::channel::create(0, &devfs_client, &devfs_server);
  if (status != ZX_OK) {
    return status;
  }

  // Create channel to connect to outgoing services
  zx::channel outgoing_services_client, outgoing_services_server;
  status = zx::channel::create(0, &outgoing_services_client, &outgoing_services_server);
  if (status != ZX_OK) {
    return status;
  }

  const bool clone_stdio = !args.stdio.is_valid();

  fbl::Vector<const char*> argv;
  argv.push_back(kDevmgrPath);
  argv.push_back("--no-start-svchost");
  for (const char* path : args.driver_search_paths) {
    argv.push_back("--driver-search-path");
    argv.push_back(path);
  }
  for (const char* path : args.load_drivers) {
    argv.push_back("--load-driver");
    argv.push_back(path);
  }
  if (args.sys_device_driver != nullptr) {
    argv.push_back("--sys-device-driver");
    argv.push_back(args.sys_device_driver);
  }
  if (args.disable_block_watcher) {
    argv.push_back("--disable-block-watcher");
  }
  if (args.disable_netsvc) {
    argv.push_back("--disable-netsvc");
  }
  argv.push_back(nullptr);

  fbl::Vector<fdio_spawn_action_t> actions;
  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_SET_NAME,
      .name = {.data = "test-devmgr"},
  });
  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_ADD_HANDLE,
      .h = {.id = PA_HND(PA_JOB_DEFAULT, 0), .handle = job_copy.release()},
  });
  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_ADD_HANDLE,
      .h = {.id = DEVMGR_LAUNCHER_DEVFS_ROOT_HND, .handle = devfs_server.release()},
  });
  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_ADD_HANDLE,
      .h = {.id = DEVMGR_LAUNCHER_OUTGOING_SERVICES_HND,
            .handle = outgoing_services_server.release()},
  });

  for (auto& ns : args.flat_namespace) {
    actions.push_back(fdio_spawn_action_t{
        .action = FDIO_SPAWN_ACTION_ADD_NS_ENTRY,
        .ns = {.prefix = ns.first, .handle = ns.second.release()},
    });
  }

  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_CLONE_DIR,
      .dir = {.prefix = "/boot"},
  });

  actions.push_back(fdio_spawn_action_t{
      .action = FDIO_SPAWN_ACTION_ADD_NS_ENTRY,
      .ns = {.prefix = "/svc", .handle = svc_client.release()},
  });

  if (!clone_stdio) {
    actions.push_back(fdio_spawn_action_t{
        .action = FDIO_SPAWN_ACTION_TRANSFER_FD,
        .fd = {.local_fd = args.stdio.release(), .target_fd = FDIO_FLAG_USE_FOR_STDIO},
    });
  }

  uint32_t flags = FDIO_SPAWN_DEFAULT_LDSVC;
  if (clone_stdio) {
    flags |= FDIO_SPAWN_CLONE_STDIO;
  }

  zx::process new_process;
  status = fdio_spawn_etc(job.get(), flags, kDevmgrPath, argv.data(), nullptr /* environ */,
                          actions.size(), actions.data(), new_process.reset_and_get_address(),
                          nullptr /* err_msg */);
  if (status != ZX_OK) {
    return status;
  }

  *devmgr_job = std::move(job);
  *devfs_root = std::move(devfs_client);
  *outgoing_services_root = std::move(outgoing_services_client);
  return ZX_OK;
}

}  // namespace devmgr_launcher
