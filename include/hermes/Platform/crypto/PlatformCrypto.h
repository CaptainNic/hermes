#ifndef HERMES_PLATFORMCRYPTO_PLATFORMCRYPTO_H
#define HERMES_PLATFORMCRYPTO_PLATFORMCRYPTO_H

#include "hermes/VM/CallResult.h"

#include <string>

namespace hermes {
namespace platform_crypto {

vm::CallResult<std::string> randomUUID(vm::Runtime &runtime);

} // namespace platform_crypto
} // namespace hermes

#endif 