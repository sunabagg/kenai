cmake -B lucidfx-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=lucidfx-install lucidfx
cmake --build lucidfx-build --config Release
cmake --install lucidfx-build