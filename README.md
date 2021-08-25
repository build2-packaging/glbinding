<h1 align="center">
    build2 Package for glbinding
</h1>

<p align="center">
    glbinding is a cross-platform C++ binding for the OpenGL API, generated using the gl.xml specification.
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
