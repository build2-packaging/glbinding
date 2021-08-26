<h1 align="center">
    build2 Package for glbinding
</h1>

<p align="center">
    glbinding is a cross-platform C++ binding for the OpenGL API, generated using the gl.xml specification.
</p>

<p align="center">
    <a href="https://cppget.org/glbinding">
        <img src="https://img.shields.io/website/https/cppget.org/glbinding.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online">
    </a>
    <a href="https://queue.cppget.org/glbinding">
        <img src="https://img.shields.io/website/https/queue.cppget.org/glbinding.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running">
    </a>
</p>

## Usage
Both libraries, `glbinding` and `glbinding-aux`, are provided in the same package `glbinding`.
To import them in a `buildfile`, one would do the following.

    import glbinding = glbinding%lib{glbinding}
    import glbinding_aux = glbinding%lib{glbinding-aux}

In your `manifest`, you need to add `depends: glbinding`.

## Issues
- GCC [11.0,11.2) may not work due to a bug described [here](https://github.com/build2/build2/issues/158) and [here](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=101298).
- On Windows, using other compilers than MSVC results in a bunch of undefined references to some symbols. This may due to a wrong generation of the export header.

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
