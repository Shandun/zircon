// WARNING: This file is machine generated by fidlgen.

#pragma once

#include <lib/fidl/internal.h>
#include <lib/fidl/llcpp/array.h>
#include <lib/fidl/llcpp/coding.h>
#include <lib/fidl/llcpp/string_view.h>
#include <lib/fidl/llcpp/sync_call.h>
#include <lib/fidl/llcpp/traits.h>
#include <lib/fidl/llcpp/transaction.h>
#include <lib/fidl/llcpp/vector_view.h>
#include <lib/fit/function.h>
#include <lib/zx/channel.h>
#include <zircon/fidl.h>

namespace llcpp {

namespace fuchsia {
namespace hardware {
namespace usb {
namespace peripheral {
namespace block {

class Device;

extern "C" const fidl_type_t fuchsia_hardware_usb_peripheral_block_DeviceEnableWritebackCacheResponseTable;
extern "C" const fidl_type_t fuchsia_hardware_usb_peripheral_block_DeviceDisableWritebackCacheResponseTable;
extern "C" const fidl_type_t fuchsia_hardware_usb_peripheral_block_DeviceSetWritebackCacheReportedRequestTable;
extern "C" const fidl_type_t fuchsia_hardware_usb_peripheral_block_DeviceSetWritebackCacheReportedResponseTable;

// Represents a simulated USB block device whose cache can be controlled.
// This allows for integration testing of USB mass storage devices
// both with and without caches.
class Device final {
  Device() = delete;
 public:

  struct EnableWritebackCacheResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    int32_t status;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_usb_peripheral_block_DeviceEnableWritebackCacheResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kResponse;
  };
  using EnableWritebackCacheRequest = ::fidl::AnyZeroArgMessage;

  struct DisableWritebackCacheResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    int32_t status;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_usb_peripheral_block_DeviceDisableWritebackCacheResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kResponse;
  };
  using DisableWritebackCacheRequest = ::fidl::AnyZeroArgMessage;

  struct SetWritebackCacheReportedResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    int32_t status;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_usb_peripheral_block_DeviceSetWritebackCacheReportedResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kResponse;
  };
  struct SetWritebackCacheReportedRequest final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    bool report;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_usb_peripheral_block_DeviceSetWritebackCacheReportedRequestTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kRequest;
    using ResponseType = SetWritebackCacheReportedResponse;
  };


  // Collection of return types of FIDL calls in this interface.
  class ResultOf final {
    ResultOf() = delete;
   private:
    template <typename ResponseType>
    class EnableWritebackCache_Impl final : private ::fidl::internal::OwnedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::OwnedSyncCallBase<ResponseType>;
     public:
      EnableWritebackCache_Impl(zx::unowned_channel _client_end);
      ~EnableWritebackCache_Impl() = default;
      EnableWritebackCache_Impl(EnableWritebackCache_Impl&& other) = default;
      EnableWritebackCache_Impl& operator=(EnableWritebackCache_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class DisableWritebackCache_Impl final : private ::fidl::internal::OwnedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::OwnedSyncCallBase<ResponseType>;
     public:
      DisableWritebackCache_Impl(zx::unowned_channel _client_end);
      ~DisableWritebackCache_Impl() = default;
      DisableWritebackCache_Impl(DisableWritebackCache_Impl&& other) = default;
      DisableWritebackCache_Impl& operator=(DisableWritebackCache_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class SetWritebackCacheReported_Impl final : private ::fidl::internal::OwnedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::OwnedSyncCallBase<ResponseType>;
     public:
      SetWritebackCacheReported_Impl(zx::unowned_channel _client_end, bool report);
      ~SetWritebackCacheReported_Impl() = default;
      SetWritebackCacheReported_Impl(SetWritebackCacheReported_Impl&& other) = default;
      SetWritebackCacheReported_Impl& operator=(SetWritebackCacheReported_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };

   public:
    using EnableWritebackCache = EnableWritebackCache_Impl<EnableWritebackCacheResponse>;
    using DisableWritebackCache = DisableWritebackCache_Impl<DisableWritebackCacheResponse>;
    using SetWritebackCacheReported = SetWritebackCacheReported_Impl<SetWritebackCacheReportedResponse>;
  };

  // Collection of return types of FIDL calls in this interface,
  // when the caller-allocate flavor or in-place call is used.
  class UnownedResultOf final {
    UnownedResultOf() = delete;
   private:
    template <typename ResponseType>
    class EnableWritebackCache_Impl final : private ::fidl::internal::UnownedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::UnownedSyncCallBase<ResponseType>;
     public:
      EnableWritebackCache_Impl(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);
      ~EnableWritebackCache_Impl() = default;
      EnableWritebackCache_Impl(EnableWritebackCache_Impl&& other) = default;
      EnableWritebackCache_Impl& operator=(EnableWritebackCache_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class DisableWritebackCache_Impl final : private ::fidl::internal::UnownedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::UnownedSyncCallBase<ResponseType>;
     public:
      DisableWritebackCache_Impl(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);
      ~DisableWritebackCache_Impl() = default;
      DisableWritebackCache_Impl(DisableWritebackCache_Impl&& other) = default;
      DisableWritebackCache_Impl& operator=(DisableWritebackCache_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class SetWritebackCacheReported_Impl final : private ::fidl::internal::UnownedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::UnownedSyncCallBase<ResponseType>;
     public:
      SetWritebackCacheReported_Impl(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, bool report, ::fidl::BytePart _response_buffer);
      ~SetWritebackCacheReported_Impl() = default;
      SetWritebackCacheReported_Impl(SetWritebackCacheReported_Impl&& other) = default;
      SetWritebackCacheReported_Impl& operator=(SetWritebackCacheReported_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };

   public:
    using EnableWritebackCache = EnableWritebackCache_Impl<EnableWritebackCacheResponse>;
    using DisableWritebackCache = DisableWritebackCache_Impl<DisableWritebackCacheResponse>;
    using SetWritebackCacheReported = SetWritebackCacheReported_Impl<SetWritebackCacheReportedResponse>;
  };

  class SyncClient final {
   public:
    explicit SyncClient(::zx::channel channel) : channel_(std::move(channel)) {}
    ~SyncClient() = default;
    SyncClient(SyncClient&&) = default;
    SyncClient& operator=(SyncClient&&) = default;

    const ::zx::channel& channel() const { return channel_; }

    ::zx::channel* mutable_channel() { return &channel_; }

    // Enables writeback caching. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // All writes will be buffered until a BLOCK_OP_FLUSH is received.
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    ResultOf::EnableWritebackCache EnableWritebackCache();

    // Enables writeback caching. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // All writes will be buffered until a BLOCK_OP_FLUSH is received.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    UnownedResultOf::EnableWritebackCache EnableWritebackCache(::fidl::BytePart _response_buffer);

    // Disables writeback caching. This requires the device to be disconnected at the time
    // of the call. Calling it when the device is connected will result in undefined behavior.
    // Disabling this cache will cause any writes to be written immediately to non-volatile storage
    // before returning to the caller.
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    ResultOf::DisableWritebackCache DisableWritebackCache();

    // Disables writeback caching. This requires the device to be disconnected at the time
    // of the call. Calling it when the device is connected will result in undefined behavior.
    // Disabling this cache will cause any writes to be written immediately to non-volatile storage
    // before returning to the caller.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    UnownedResultOf::DisableWritebackCache DisableWritebackCache(::fidl::BytePart _response_buffer);

    // Sets writeback cache reporting behavior. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // If report is set to true, the device will report its cache capability correctly to the
    // host. If set to false, the writeback caching capabilities will NOT be reported.
    // This can be used to test host drivers to ensure that they respond properly
    // when the device does not report its caching capabilities.
    // Allocates 48 bytes of message buffer on the stack. No heap allocation necessary.
    ResultOf::SetWritebackCacheReported SetWritebackCacheReported(bool report);

    // Sets writeback cache reporting behavior. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // If report is set to true, the device will report its cache capability correctly to the
    // host. If set to false, the writeback caching capabilities will NOT be reported.
    // This can be used to test host drivers to ensure that they respond properly
    // when the device does not report its caching capabilities.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    UnownedResultOf::SetWritebackCacheReported SetWritebackCacheReported(::fidl::BytePart _request_buffer, bool report, ::fidl::BytePart _response_buffer);

   private:
    ::zx::channel channel_;
  };

  // Methods to make a sync FIDL call directly on an unowned channel, avoiding setting up a client.
  class Call final {
    Call() = delete;
   public:

    // Enables writeback caching. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // All writes will be buffered until a BLOCK_OP_FLUSH is received.
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    static ResultOf::EnableWritebackCache EnableWritebackCache(zx::unowned_channel _client_end);

    // Enables writeback caching. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // All writes will be buffered until a BLOCK_OP_FLUSH is received.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    static UnownedResultOf::EnableWritebackCache EnableWritebackCache(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);

    // Disables writeback caching. This requires the device to be disconnected at the time
    // of the call. Calling it when the device is connected will result in undefined behavior.
    // Disabling this cache will cause any writes to be written immediately to non-volatile storage
    // before returning to the caller.
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    static ResultOf::DisableWritebackCache DisableWritebackCache(zx::unowned_channel _client_end);

    // Disables writeback caching. This requires the device to be disconnected at the time
    // of the call. Calling it when the device is connected will result in undefined behavior.
    // Disabling this cache will cause any writes to be written immediately to non-volatile storage
    // before returning to the caller.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    static UnownedResultOf::DisableWritebackCache DisableWritebackCache(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);

    // Sets writeback cache reporting behavior. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // If report is set to true, the device will report its cache capability correctly to the
    // host. If set to false, the writeback caching capabilities will NOT be reported.
    // This can be used to test host drivers to ensure that they respond properly
    // when the device does not report its caching capabilities.
    // Allocates 48 bytes of message buffer on the stack. No heap allocation necessary.
    static ResultOf::SetWritebackCacheReported SetWritebackCacheReported(zx::unowned_channel _client_end, bool report);

    // Sets writeback cache reporting behavior. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // If report is set to true, the device will report its cache capability correctly to the
    // host. If set to false, the writeback caching capabilities will NOT be reported.
    // This can be used to test host drivers to ensure that they respond properly
    // when the device does not report its caching capabilities.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    static UnownedResultOf::SetWritebackCacheReported SetWritebackCacheReported(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, bool report, ::fidl::BytePart _response_buffer);

  };

  // Messages are encoded and decoded in-place when these methods are used.
  // Additionally, requests must be already laid-out according to the FIDL wire-format.
  class InPlace final {
    InPlace() = delete;
   public:

    // Enables writeback caching. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // All writes will be buffered until a BLOCK_OP_FLUSH is received.
    static ::fidl::DecodeResult<EnableWritebackCacheResponse> EnableWritebackCache(zx::unowned_channel _client_end, ::fidl::BytePart response_buffer);

    // Disables writeback caching. This requires the device to be disconnected at the time
    // of the call. Calling it when the device is connected will result in undefined behavior.
    // Disabling this cache will cause any writes to be written immediately to non-volatile storage
    // before returning to the caller.
    static ::fidl::DecodeResult<DisableWritebackCacheResponse> DisableWritebackCache(zx::unowned_channel _client_end, ::fidl::BytePart response_buffer);

    // Sets writeback cache reporting behavior. This requires the device
    // to be disconnected at the time of the call. Calling it when the device is connected
    // will result in undefined behavior.
    // If report is set to true, the device will report its cache capability correctly to the
    // host. If set to false, the writeback caching capabilities will NOT be reported.
    // This can be used to test host drivers to ensure that they respond properly
    // when the device does not report its caching capabilities.
    static ::fidl::DecodeResult<SetWritebackCacheReportedResponse> SetWritebackCacheReported(zx::unowned_channel _client_end, ::fidl::DecodedMessage<SetWritebackCacheReportedRequest> params, ::fidl::BytePart response_buffer);

  };

  // Pure-virtual interface to be implemented by a server.
  class Interface {
   public:
    Interface() = default;
    virtual ~Interface() = default;
    using _Outer = Device;
    using _Base = ::fidl::CompleterBase;

    class EnableWritebackCacheCompleterBase : public _Base {
     public:
      void Reply(int32_t status);
      void Reply(::fidl::BytePart _buffer, int32_t status);
      void Reply(::fidl::DecodedMessage<EnableWritebackCacheResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using EnableWritebackCacheCompleter = ::fidl::Completer<EnableWritebackCacheCompleterBase>;

    virtual void EnableWritebackCache(EnableWritebackCacheCompleter::Sync _completer) = 0;

    class DisableWritebackCacheCompleterBase : public _Base {
     public:
      void Reply(int32_t status);
      void Reply(::fidl::BytePart _buffer, int32_t status);
      void Reply(::fidl::DecodedMessage<DisableWritebackCacheResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using DisableWritebackCacheCompleter = ::fidl::Completer<DisableWritebackCacheCompleterBase>;

    virtual void DisableWritebackCache(DisableWritebackCacheCompleter::Sync _completer) = 0;

    class SetWritebackCacheReportedCompleterBase : public _Base {
     public:
      void Reply(int32_t status);
      void Reply(::fidl::BytePart _buffer, int32_t status);
      void Reply(::fidl::DecodedMessage<SetWritebackCacheReportedResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using SetWritebackCacheReportedCompleter = ::fidl::Completer<SetWritebackCacheReportedCompleterBase>;

    virtual void SetWritebackCacheReported(bool report, SetWritebackCacheReportedCompleter::Sync _completer) = 0;

  };

  // Attempts to dispatch the incoming message to a handler function in the server implementation.
  // If there is no matching handler, it returns false, leaving the message and transaction intact.
  // In all other cases, it consumes the message and returns true.
  // It is possible to chain multiple TryDispatch functions in this manner.
  static bool TryDispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Dispatches the incoming message to one of the handlers functions in the interface.
  // If there is no matching handler, it closes all the handles in |msg| and closes the channel with
  // a |ZX_ERR_NOT_SUPPORTED| epitaph, before returning false. The message should then be discarded.
  static bool Dispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Same as |Dispatch|, but takes a |void*| instead of |Interface*|. Only used with |fidl::Bind|
  // to reduce template expansion.
  // Do not call this method manually. Use |Dispatch| instead.
  static bool TypeErasedDispatch(void* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
    return Dispatch(static_cast<Interface*>(impl), msg, txn);
  }

};

}  // namespace block
}  // namespace peripheral
}  // namespace usb
}  // namespace hardware
}  // namespace fuchsia
}  // namespace llcpp

namespace fidl {

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::EnableWritebackCacheResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::EnableWritebackCacheResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::EnableWritebackCacheResponse)
    == ::llcpp::fuchsia::hardware::usb::peripheral::block::Device::EnableWritebackCacheResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::EnableWritebackCacheResponse, status) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::DisableWritebackCacheResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::DisableWritebackCacheResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::DisableWritebackCacheResponse)
    == ::llcpp::fuchsia::hardware::usb::peripheral::block::Device::DisableWritebackCacheResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::DisableWritebackCacheResponse, status) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedRequest> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedRequest> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedRequest)
    == ::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedRequest::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedRequest, report) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedResponse)
    == ::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::usb::peripheral::block::Device::SetWritebackCacheReportedResponse, status) == 16);

}  // namespace fidl
