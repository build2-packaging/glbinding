# build2 Package for glbinding

[glbinding](https://glbinding.org/) is a cross-platform C++ binding for the OpenGL API, generated using the gl.xml specification.

[![Official](https://img.shields.io/website/https/github.com/cginternals/glbinding.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/cginternals/glbinding)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/glbinding.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/glbinding)
[![cppget.org](https://img.shields.io/website/https/cppget.org/glbinding.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/glbinding)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/glbinding.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/glbinding)

## Usage
Make sure to add the stable section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch this package.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/glbinding.git

Add the dependency in your project's `manifest` file to make the package available for import.

    depends: glbinding ^3.3.0

Both libraries, `glbinding` and `glbinding-aux`, are provided in the same package `glbinding`.
To import and add them to the variable `libs` in a `buildfile`, one would do the following.

    import libs += glbinding%lib{glbinding}
    import libs += glbinding%lib{glbinding-aux}

Additionally, this repository also contains the `glbinding-tests`, `glbinding-examples`, and `glbinding-tools` packages that contain executables for learning and testing.
These had to be provided as standalone packages to allow for custom configurations during CI runs.
Additionally, `glbinding-tools` is also installable.

## Configuration

### Boost.Thread

    config [bool] config.glbinding.use_boost_thread ?= false

For its implementation `glbinding` allows to optionally use Boost's thread library.
Set the configuration variable to `true` to use `boost::thread` instead of `std::thread` from the C++ STL.

### KHR Headers

    config [bool] config.glbinding.use_packaged_khr ?= true

`glbinding` needs some standard definitions from the `KHR/khrplatform.h` header file.
To be self-contained, it comes with its own version of that header file.
Set the configuration variable to `false` if `glbinding` should use the KHR headers given by the system.

### OpenGL Context Testing for Tests and Tools

    config [bool] config.glbinding_tests.opengl_context_testing ?= true
    config [bool] config.glbinding_tools.opengl_context_testing ?= true

These config variable decide whether to link regression tests or run executables that require a valid OpenGL context to succeed.
As tests and tools will likely to be used on targets where OpenGL drawing is required, these variables are enabled by default.
However, they should be disabled for target configurations in CI runs that do not support GUI mocking.

## Issues
- Compilation might abort due to insufficient memory as it may use up all available RAM. For this case, re-run the compilation process multiple times until no errors occur or use less threads for build2 `b -j 1 ...`.
- The examples fail on a few MinGW-based Windows configurations due to strange undefined references.
- Warnings are generated on Windows that show that redeclarations without dllimport attribute occur. It does not seem to be an actual problem but should be dealt with in the future.

## Contributing
Thanks in advance for your help and contribution to keep this package up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/glbinding/issues) for everything that is not described below.

### Recommend Updating Version
Please, file an issue on [GitHub](https://github.com/build2-packaging/glbinding/issues) with the new recommended version.

### Update Version by Pull Request
1. Fork the repository on [GitHub](https://github.com/build2-packaging/glbinding) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Test if the packages compile and execute examples and tools.
6. Update library version in all `manifest` files if it has changed or add package update by using `+n` for the `n`-th update.
7. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
8. Run `bdep ci` and test for errors for the package `glbinding` only.
9. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
10. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions
1. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Test if the packages compile and execute examples and tools.
4. Update library version in all `manifest` files if it has changed or add package update by using `+n` for the `n`-th update.
5. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
6. Run `bdep ci` and test for errors and warnings.
7. When successful, run `bdep release --tag --push` to push new tag version to repository.
8. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
