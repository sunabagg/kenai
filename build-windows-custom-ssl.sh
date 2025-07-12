#!/bin/bash

# Cross-compile Sunaba for Windows, building OpenSSL from source if needed

set -e

echo "Cross-compiling Sunaba for Windows with custom OpenSSL..."

# Install basic MinGW tools
echo "Installing MinGW tools..."
sudo apt update
sudo apt install -y mingw-w64 mingw-w64-common mingw-w64-tools build-essential

# Set up variables
MINGW_PREFIX="x86_64-w64-mingw32"
MINGW_ROOT="/usr/${MINGW_PREFIX}"
OPENSSL_VERSION="3.1.4"
OPENSSL_DIR="${PWD}/openssl-mingw"

# Check if we already have OpenSSL built for MinGW
if [ ! -f "${OPENSSL_DIR}/lib/libssl.a" ]; then
    echo "Building OpenSSL for MinGW..."
    
    # Download OpenSSL source
    if [ ! -f "openssl-${OPENSSL_VERSION}.tar.gz" ]; then
        wget "https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz"
    fi
    
    # Extract and build
    tar -xzf "openssl-${OPENSSL_VERSION}.tar.gz"
    cd "openssl-${OPENSSL_VERSION}"
    
    # Configure for MinGW cross-compilation
    ./Configure mingw64 \
        --cross-compile-prefix=${MINGW_PREFIX}- \
        --prefix="${OPENSSL_DIR}" \
        no-shared \
        no-async
    
    # Build and install
    make -j$(nproc)
    make install_sw
    
    cd ..
    rm -rf "openssl-${OPENSSL_VERSION}"
    
    echo "OpenSSL built and installed to ${OPENSSL_DIR}"
else
    echo "Using existing OpenSSL build at ${OPENSSL_DIR}"
fi

# Clean previous builds
rm -rf sunaba-build-windows sunaba-install-windows

# Configure with custom OpenSSL path
echo "Configuring build with custom OpenSSL..."
cmake -B sunaba-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=sunaba-install-windows \
    -DOPENSSL_ROOT_DIR="${OPENSSL_DIR}" \
    -DOPENSSL_INCLUDE_DIR="${OPENSSL_DIR}/include" \
    -DOPENSSL_CRYPTO_LIBRARY="${OPENSSL_DIR}/lib/libcrypto.a" \
    -DOPENSSL_SSL_LIBRARY="${OPENSSL_DIR}/lib/libssl.a" \
    -DCMAKE_PREFIX_PATH="${OPENSSL_DIR}" \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build sunaba-build-windows --parallel $(nproc)

# Install
echo "Installing..."
cmake --install sunaba-build-windows

echo "Cross-compilation complete! Output in sunaba-install-windows/"
echo "Windows binaries ready for deployment."
