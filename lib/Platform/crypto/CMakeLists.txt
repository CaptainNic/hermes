if(HERMES_ENABLE_CRYPTO)
  if(UNIX)
    add_hermes_library(hermesPlatformCrypto STATIC
      PlatformCryptoPosix.cpp
      LINK_LIBS
      uuid
      hermesPublic)
  else()
    add_hermes_library(hermesPlatformCrypto STATIC
      PlatformCryptoDummy.cpp)
  endif()
  
  target_compile_options(hermesPlatformCrypto PRIVATE -frtti -fexceptions)
endif()
