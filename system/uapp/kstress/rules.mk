# Copyright 2018 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userapp
MODULE_GROUP := usertest

MODULE_SRCS += \
    $(LOCAL_DIR)/vmstress.cpp

MODULE_LIBS := \
    system/ulib/c \
    system/ulib/fdio \
    system/ulib/zircon \

MODULE_STATIC_LIBS := \
    system/ulib/fbl \
    system/ulib/zx \
    system/ulib/zxcpp \

include make/module.mk
