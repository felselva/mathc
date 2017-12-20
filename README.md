# MATHC

[![Build Status](https://travis-ci.org/ferreiradaselva/mathc.svg?branch=master)](https://travis-ci.org/ferreiradaselva/mathc)

MATHC (version 2) is a simple math library for 2D and 3D programming. It contains implementations for:

- 2D vectors
- 3D vectors
- Quaternions
- Matrices
- Easing functions

It support C99 standard or later.

## Declaring Variables

MATHC doesn't define any structure type. Everything is declared as an array:

```c
mfloat_t v[VEC2_SIZE];
mfloat_t v[VEC3_SIZE];
mfloat_t v[VEC4_SIZE];
mfloat_t q[QUAT_SIZE];
mfloat_t m[MAT3_SIZE];
mfloat_t m[MAT4_SIZE];
```

## Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/). They are mainly useful for animations.

Easing functions take a value inside the range `0.0-1.0` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

## Configuration Macros

The float type used by MATHC is defined by the macro `mfloat_t`, which is by default `float`.

If the macro `MATHC_NO_STDBOOL` is defined, the library will not include `stdbool.h` and will define a macro `bool` of type `int` to represent boolean values. This is useful for platforms where `stdbool.h` is not available.

If the macro `MATHC_DOUBLE_PRECISION` is defined, the Pi macros will be defined with double precision and the library will use internally the math functions for double types. Otherwise, the Pi macros will be defined with float precision and the library will use internally the math functions for float types

You can define these macros during compilation time with flags:

```
-DMATHC_NO_STDBOOL=ON -Dmfloat_t=double -DMATHC_DOUBLE_PRECISION=ON
```

Or include `mathc.c` and `mathc.h` in a source and header. This second approach is useful, because you can define `mfloat_t` as a different type other than the built-in types `float` or `double`, such as `GLfloat`:

```c
/* In a *.c file */
#define mfloat_t GLfloat
#include <mathc.c>

/* In a *.h file */
#define mfloat_t GLfloat
#include <mathc.h>
```

## Contributing

Check the file `CONTRIBUTING.md` for contribution rules and contributions of interest.

## LICENSE

The source code of this project is licensed under the terms of the ZLIB license:

Copyright (C) 2016 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
