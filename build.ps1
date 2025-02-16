cmake -B sunaba-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=sunaba-install sunaba
cmake --build sunaba-build --config Release
cmake --install sunaba-build