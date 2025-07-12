# CMake toolchain file for cross-compiling to Windows using MinGW-w64

# Target system
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Compiler prefix (adjust if your mingw-w64 has a different prefix)
set(COMPILER_PREFIX x86_64-w64-mingw32)

# Specify the cross compilers
find_program(CMAKE_C_COMPILER NAMES ${COMPILER_PREFIX}-gcc)
find_program(CMAKE_CXX_COMPILER NAMES ${COMPILER_PREFIX}-g++)
find_program(CMAKE_RC_COMPILER NAMES ${COMPILER_PREFIX}-windres)

# Verify compilers were found
if(NOT CMAKE_C_COMPILER)
    message(FATAL_ERROR "Could not find ${COMPILER_PREFIX}-gcc")
endif()
if(NOT CMAKE_CXX_COMPILER)
    message(FATAL_ERROR "Could not find ${COMPILER_PREFIX}-g++")
endif()

# Where to look for libraries and includes
set(CMAKE_FIND_ROOT_PATH 
    /usr/${COMPILER_PREFIX}
    /usr/lib/gcc/${COMPILER_PREFIX}
    /usr/${COMPILER_PREFIX}/sys-root/mingw
)

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Set Windows-specific flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")

# Ensure we link statically to avoid DLL dependencies
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")

# Help CMake find OpenSSL and other libraries for MinGW
set(CMAKE_PREFIX_PATH 
    "/usr/${COMPILER_PREFIX}"
    "/usr/lib/gcc/${COMPILER_PREFIX}"
    "/usr/${COMPILER_PREFIX}/sys-root/mingw"
)

# Set OpenSSL root directory hints
set(OPENSSL_ROOT_DIR "/usr/${COMPILER_PREFIX}")
set(OPENSSL_USE_STATIC_LIBS TRUE)

# Additional hints for finding libraries
set(CMAKE_LIBRARY_PATH 
    "/usr/${COMPILER_PREFIX}/lib"
    "/usr/lib/gcc/${COMPILER_PREFIX}"
)
set(CMAKE_INCLUDE_PATH 
    "/usr/${COMPILER_PREFIX}/include"
)
