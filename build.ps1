cmake -B Newhaven-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=Newhaven-install Newhaven
cmake --build Newhaven-build --config Release
cmake --install Newhaven-build