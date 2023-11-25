if(HERMES_ENABLE_CRYPTO)
  add_hermes_library(hermesPlatformCrypto STATIC
    PlatformCryptoPosix.cpp
    LINK_LIBS
    uuid
    hermesPublic)
  target_compile_options(hermesPlatformCrypto PRIVATE -frtti -fexceptions)
endif()
