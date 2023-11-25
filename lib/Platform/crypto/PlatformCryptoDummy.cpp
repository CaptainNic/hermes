#include "hermes/Platform/crypto/PlatformCrypto.h"

namespace hermes {
namespace platform_crypto {

vm::CallResult<std::string> randomUUID(vm::Runtime &runtime) {
  return "00000000-0000-0000-0000-000000000000";
}

} // namespace platform_crypto
} // namespace hermes