#!/bin/bash

# Cross-compile Sunaba for Windows without SSL dependencies

set -e

echo "Cross-compiling Sunaba for Windows (without SSL)..."

# Clean previous builds
rm -rf sunaba-build-windows sunaba-install-windows

# Configure without SSL components
cmake -B sunaba-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=sunaba-install-windows \
    -DUSE_LUASEC=OFF \
    -DDISABLE_SSL=ON \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build sunaba-build-windows --parallel $(nproc)

# Install
echo "Installing..."
cmake --install sunaba-build-windows

echo "Cross-compilation complete! Output in sunaba-install-windows/"
echo "Windows binaries ready for deployment (without SSL support)."
