# Kenai

work in progress game engine

## Prerequisites

To use this locally on your machine, you will need the following:

- **[CMake](https://cmake.org/)** v3.22+
- C++ Compiler with at least **C++17** support (any recent compiler)
- Python 3.8+
- (optional) pkgconf for LuaJIT support
- (optional) vcpkg for installing LuaJIT
- (optional) **[ccache](https://ccache.dev/)** for faster rebuilds
- (optional) **[clang-format](https://clang.llvm.org/docs/ClangFormat.html)** for linting and automatic code formatting (CI uses clang-format version 15)

The GitHub actions (CI) are set up to include all of these tools. To see how to download them on your platform, take a look at the [workflow](.github/workflows/main.yml) file.

## How To Use

### Build & Install

Here's an example of how to build & install a release version (use the terminal to run the following commands in the parent directory of this repo):

#### Not MSVC or Emscripten

```sh
$ cmake -B kenai-build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=kenai-install kenai
$ cmake --build kenai-build --parallel
$ cmake --install kenai-build
```

#### Emscripten

```sh
$ emcmake cmake -B kenai-build-web -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=kenai-install-web
$ cmake --build kenai-build-web 
$ cmake --install kenai-build-web
```

> **Note:**
> When building with Emscripten, you may see warnings like:
> `ADD_LIBRARY called with SHARED option but the target platform does not support dynamic linking.  Building a STATIC library instead.`
> This is expected for dependencies and does not affect the final `.wasm` output. Only the main project will be built as a shared WebAssembly side module; dependencies are always static.

#### MSVC

```sh
$ cmake -B kenai-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=kenai-install kenai
Copy-Item "lua51.lib" -Destination "kenai-build\lua51.lib"
$ cmake --build kenai-build --config Release
$ cmake --install kenai-build
```

This tells CMake to use `Visual Studio 2022`. There is a list of Visual Studio generators [on the CMake site](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators) - pick the one you are using.

### Cmake Options

This template defines the following additional CMake options:

| Option                                                                   | Description                                      | Default                                                                                                 |
| ------------------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| `CCACHE_PROGRAM`                                                         | Path to `ccache` for faster rebuilds             | This is automatically set **ON** if `ccache` is found. If you do not want to use it, set this to "".    |
| `CLANG_FORMAT_PROGRAM`                                                   | Path to `clang-format` for code formatting.      | This is automatically set **ON** if `clang-format` is on. If you do not want to use it, set this to "". |
| `${PROJECT_NAME_UPPERCASE}_WARN_EVERYTHING` (e.g. FOO_WARN_EVERYTHING)   | Turns on all warnings. (Not available for MSVC.) | **OFF** (too noisy, but can be useful sometimes)                                                        |
| `${PROJECT_NAME_UPPERCASE}_WARNING_AS_ERROR` (e.g. FOO_WARNING_AS_ERROR) | Turns warnings into errors.                      | **ON**                                                                                                  |
