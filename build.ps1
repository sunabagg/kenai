cmake -B kenai-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=kenai-install kenai
cmake --build kenai-build --config Release
cmake --install kenai-build