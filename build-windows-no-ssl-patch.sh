#!/bin/bash

# Cross-compile Kenai for Windows by temporarily disabling SSL components

set -e

echo "Cross-compiling Kenai for Windows (disabling SSL components)..."

# Install basic MinGW tools
echo "Installing MinGW tools..."
sudo apt update
sudo apt install -y mingw-w64 mingw-w64-common mingw-w64-tools build-essential

# Clean previous builds
rm -rf kenai-build-windows kenai-install-windows

# Create a temporary patch to disable SSL components
echo "Creating temporary CMakeLists.txt patch..."
cp CMakeLists.txt CMakeLists.txt.backup

# Comment out the OpenSSL requirement and luasec subdirectory
sed -i 's/find_package(OpenSSL REQUIRED)/#find_package(OpenSSL REQUIRED)/' CMakeLists.txt
sed -i 's/add_subdirectory( extern\/luasec )/#add_subdirectory( extern\/luasec )/' CMakeLists.txt

# Comment out luasec-related target_link_libraries
sed -i 's/luasec::ssl/#luasec::ssl/' CMakeLists.txt
sed -i 's/OpenSSL::SSL/#OpenSSL::SSL/' CMakeLists.txt
sed -i 's/OpenSSL::Crypto/#OpenSSL::Crypto/' CMakeLists.txt

# Comment out USE_LUASEC definition
sed -i 's/USE_LUASEC/#USE_LUASEC/' CMakeLists.txt

echo "Temporary patches applied. SSL components disabled."

# Configure
echo "Configuring build..."
cmake -B kenai-build-windows \
    -DCMAKE_TOOLCHAIN_FILE="${PWD}/cmake/mingw-w64-toolchain.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=kenai-install-windows \
    -DCMAKE_VERBOSE_MAKEFILE=ON \
    -G "Unix Makefiles" \
    .

# Build
echo "Building..."
cmake --build kenai-build-windows --parallel $(nproc)

# Install
echo "Installing..."
cmake --install kenai-build-windows

# Restore original CMakeLists.txt
echo "Restoring original CMakeLists.txt..."
mv CMakeLists.txt.backup CMakeLists.txt

echo "Cross-compilation complete! Output in kenai-install-windows/"
echo "Windows binaries ready for deployment (SSL functionality disabled)."
echo ""
echo "Note: SSL features have been temporarily disabled for this build."
echo "To enable SSL, you'll need to properly cross-compile OpenSSL for Windows."
