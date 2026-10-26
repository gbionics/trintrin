# trintrin

Set of messages and interfaces used in Artificial Mechanical Intelligence.

## Installation  

### conda-forge (recommended)

To install the released package in your [Pixi](https://pixi.sh) workspace, run:

```console
pixi add trintrin
```

With Conda, install it in your active environment:

```console
conda install -c conda-forge trintrin
```

### robotology-superbuild

If you are installing trintrin for use as part of [iCub humanoid robot software installation](https://icub-tech-iit.github.io/documentation/sw_installation/), you may want to install trintrin through the [robotology-superbuild](https://github.com/robotology/robotology-superbuild), an easy way to download, compile and install the robotology software on multiple operating systems, using the [CMake](https://www.cmake.org) build system and its extension [YCM](http://robotology.github.io/ycm). To get trintrin when using the `robotology-superbuild`, please enable the `ROBOTOLOGY_ENABLE_DYNAMICS` CMake option of the superbuild. If you want to install also trintrin Python bindings, remember to enable the `ROBOTOLOGY_USES_PYTHON` option. 

### Build from source with Pixi

To use a development version of trintrin in your own Pixi project, enable
source packages and declare a Git dependency in your project's `pixi.toml`:

```toml
[dependencies]
trintrin = { git = "https://github.com/gbionics/trintrin.git" }
```

Then install your project's environment:

```console
pixi install
```

Pixi downloads the source, builds trintrin with its Python bindings, and installs
the package into your environment. The dependency uses the repository's default
branch; add `rev = "<commit>"` to select a specific revision containing the Pixi
manifest. On Windows, Visual Studio 2022 with the C++ tools must also be installed.

### Build from source (advanced)

If you want to build trintrin directly from source, make sure that you have all the dependencies ([`ycm-cmake-modules`](https://github.com/robotology/ycm-cmake-modules), [`yarp`](https://github.com/robotology/yarp), C++ compiler and CMake) and then install as any CMake project:

```console
git clone https://github.com/gbionics/trintrin.git
cd trintrin
cmake -DCMAKE_INSTALL_PREFIX=<install_prefix> -Bbuild -S.
cmake --build ./build
cmake --build ./build --target install
```

If you want to compile Python bindings, make sure to install the Python and pybind11 dependencies, and enable the `TRINTRIN_COMPILE_PYTHON_BINDINGS` CMake option. 

## Use trintrin in your project

See https://github.com/robotology/human-dynamics-estimation/pull/427 for an example of using `trintrin` in your project.

## Compatibility Policy

Patch releases does not modify any existing the public headers (i.e. the installed `.h` and `.hpp`) files of the project, or any existing messages definitions in `.thrift` YARP files, but can add new public headers or new `.thrift` YARP files. This is done to ensure that no ABI change will occur in patch releases, without having to manually track ABI changes.

## Bug reports and support

All types of [issues](https://github.com/gbionics/trintrin/issues/new) are welcome.
