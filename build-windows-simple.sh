#!/bin/bash

# Simple cross-compile script without vcpkg dependencies

set -e

echo "Cross-compiling Kenai for Windows using MinGW-w64..."

# Install required packages
echo "Installing MinGW packages..."
sudo apt update
sudo apt install -y mingw-w64 mingw-w64-common mingw-w64-tools

# Try to find or build OpenSSL for MinGW
MINGW_PREFIX="/usr/x86_64-w64-mingw32"
if [ ! -f "$MINGW_PREFIX/lib/libssl.a" ]; then
    echo "Warning: OpenSSL not found for MinGW. You may need to:"
    echo "1. Install mingw-w64 OpenSSL packages, or"
    echo "2. Build OpenSSL from source for MinGW, or" 
    echo "3. Use vcpkg to install dependencies"
    echo ""
    echo "For now, trying to proceed without OpenSSL..."
fi

# Clean previous builds
rm -rf kenai-build-windows kenai-install-windows

# Configure with minimal dependencies
cmake -B kenai-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=kenai-install-windows \
    -DOPENSSL_ROOT_DIR="$MINGW_PREFIX" \
    -DOpenSSL_DIR="$MINGW_PREFIX/lib/cmake/OpenSSL" \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build kenai-build-windows --parallel $(nproc)

# Install
echo "Installing..."
cmake --install kenai-build-windows

echo "Cross-compilation complete! Output in kenai-install-windows/"
echo "Windows binaries ready for deployment."
