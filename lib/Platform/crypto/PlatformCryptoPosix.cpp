#include "hermes/Platform/crypto/PlatformCrypto.h"

#include <uuid/uuid.h>

namespace hermes {
namespace platform_crypto {

vm::CallResult<std::string> randomUUID(vm::Runtime &runtime) {
  uuid_t uuid;
  uuid_generate(uuid);  
  
  auto uuidStr = std::string(36, '0');
  uuid_unparse(uuid, const_cast<char*>(uuidStr.data()));  
  
  printf("%s\n", uuidStr.c_str());
  return uuidStr;
}

} // namespace platform_crypto
} // namespace hermes