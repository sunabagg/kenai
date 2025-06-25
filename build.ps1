cmake -B lucidware-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=lucidware-install lucidware
cmake --build lucidware-build --config Release
cmake --install lucidware-build