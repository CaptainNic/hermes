#ifdef HERMES_ENABLE_CRYPTO

#include "JSLibInternal.h"
#include "hermes/VM/JSObject.h"
#include "hermes/VM/Runtime.h"
#include "hermes/VM/StringPrimitive.h"
#include "hermes/Platform/crypto/PlatformCrypto.h"

namespace hermes {
namespace vm {

vm::Handle<vm::JSObject> createCryptoObject(vm::Runtime &runtime) {
    vm::Handle<vm::JSObject> crypto =
        runtime.makeHandle(vm::JSObject::create(runtime));
    defineMethod(
        runtime,
        crypto,
        vm::Predefined::getSymbolID(vm::Predefined::randomUUID),
        nullptr,
        cryptoRandomUUID,
        1);

    return crypto;
}

CallResult<HermesValue> cryptoRandomUUID(void *, Runtime &runtime, NativeArgs) {
    auto uuid = platform_crypto::randomUUID(runtime);
    if (LLVM_UNLIKELY(uuid == ExecutionStatus::EXCEPTION)) {
        return ExecutionStatus::EXCEPTION;
    }

    return vm::StringPrimitive::create(runtime, createASCIIRef(uuid->c_str()));
}

} // namespace vm
} // namespace hermes

#endif