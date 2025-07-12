#!/bin/bash

# Cross-compile Kenai for Windows without SSL dependencies

set -e

echo "Cross-compiling Kenai for Windows (without SSL)..."

# Clean previous builds
rm -rf kenai-build-windows kenai-install-windows

# Configure without SSL components
cmake -B kenai-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=kenai-install-windows \
    -DUSE_LUASEC=OFF \
    -DDISABLE_SSL=ON \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build kenai-build-windows --parallel $(nproc)

# Install
echo "Installing..."
cmake --install kenai-build-windows

echo "Cross-compilation complete! Output in kenai-install-windows/"
echo "Windows binaries ready for deployment (without SSL support)."
