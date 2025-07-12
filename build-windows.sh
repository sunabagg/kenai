#!/bin/bash

# Cross-compile Sunaba for Windows using MinGW-w64

set -e

echo "Cross-compiling Sunaba for Windows..."

# Check if vcpkg is available
if [ ! -d "vcpkg" ]; then
    echo "Installing vcpkg..."
    git clone https://github.com/Microsoft/vcpkg.git
    cd vcpkg
    ./bootstrap-vcpkg.sh
    cd ..
fi

# Install Windows dependencies with vcpkg
echo "Installing Windows dependencies..."
# First, check available triplets
echo "Available MinGW triplets:"
./vcpkg/vcpkg help triplet | grep mingw || echo "No mingw triplets found in help"

# Try to install with x64-mingw-static first, fallback to x64-windows-static
if ./vcpkg/vcpkg install openssl --triplet x64-mingw-static 2>/dev/null; then
    echo "Using x64-mingw-static triplet"
    VCPKG_TRIPLET="x64-mingw-static"
    ./vcpkg/vcpkg install pkgconf --triplet x64-mingw-static
else
    echo "x64-mingw-static not available, trying x64-windows-static"
    VCPKG_TRIPLET="x64-windows-static"
    ./vcpkg/vcpkg install openssl pkgconf --triplet x64-windows-static
fi

# Clean previous builds
rm -rf sunaba-build-windows sunaba-install-windows

# Configure with vcpkg toolchain
cmake -B sunaba-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/vcpkg/scripts/buildsystems/vcpkg.cmake" \
    -DVCPKG_TARGET_TRIPLET=${VCPKG_TRIPLET} \
    -DVCPKG_HOST_TRIPLET=x64-linux \
    -DCMAKE_SYSTEM_NAME=Windows \
    -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
    -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
    -DCMAKE_RC_COMPILER=x86_64-w64-mingw32-windres \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=sunaba-install-windows \
    -G "Unix Makefiles" \
    .

# Build
cmake --build sunaba-build-windows --parallel $(nproc)

# Install
cmake --install sunaba-build-windows

echo "Cross-compilation complete! Output in sunaba-install-windows/"
echo "Windows binaries ready for deployment."
