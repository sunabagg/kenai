#!/bin/bash

# Cross-compile Sunaba for Windows using system MinGW packages

set -e

echo "Cross-compiling Sunaba for Windows using system packages..."

# Install required packages for MinGW cross-compilation
echo "Installing required packages..."
sudo apt update
sudo apt install -y \
    mingw-w64 \
    mingw-w64-common \
    mingw-w64-tools \
    gcc-mingw-w64-x86-64 \
    g++-mingw-w64-x86-64

# Try to install MinGW SSL packages if available
echo "Attempting to install MinGW OpenSSL packages..."
sudo apt install -y \
    libssl-dev \
    libssl3 \
    pkg-config || echo "Some SSL packages might not be available"

# Check if MinGW compilers are available
echo "Checking MinGW compilers..."
which x86_64-w64-mingw32-gcc || echo "MinGW GCC not found in PATH"
which x86_64-w64-mingw32-g++ || echo "MinGW G++ not found in PATH"

# Clean previous builds
rm -rf sunaba-build-windows sunaba-install-windows

# Configure using our custom toolchain
echo "Configuring build..."
cmake -B sunaba-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=sunaba-install-windows \
    -DCMAKE_VERBOSE_MAKEFILE=ON \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build sunaba-build-windows --parallel $(nproc) --verbose

# Install
echo "Installing..."
cmake --install sunaba-build-windows

echo "Cross-compilation complete! Output in sunaba-install-windows/"
echo "Windows binaries ready for deployment."
