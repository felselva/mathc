# MATHC

[![Build Status](https://travis-ci.org/ferreiradaselva/mathc.svg?branch=master)](https://travis-ci.org/ferreiradaselva/mathc)

MATHC is a simple math library for 2D and 3D programming. It contains implementations for:

- Vectors (2D, 3D and 4D) (integer and floating-point)
- Euler (classic and non-classic angles)
- Quaternions
- Matrices (2×2, 3×3, and 4×4)
- Easing functions

## Configuring

By default, `mint_t` is of type `int32_t` and `mfloat_t` is of type `float`.

MATHC can be configured using preprocessors:

- `MATHC_INT_TYPE`: define a new integer type for `mint_t`.
- `MATHC_FLOAT_TYPE`: define a new floating-point type for `mfloat_t`.
- `MATHC_USE_INT64`: if `mint_t` is not already defined, define `mint_t` as `int64_t`.
- `MATHC_USE_DOUBLE`: if `mfloat_t` is not already defined, define `mfloat_t` as `double`.
- `MATHC_USE_DOUBLE_PRECISION`: use the functions of the standard math library (`math.h`) with double precision. For example, use `sqrt()` instead of `sqrtf()`.
- `MATHC_USE_UNIONS`: enable anonymous unions inside structures. Only available on standard C11 or with extensions.
- `MATHC_NO_POINTER_STRUCT_FUNCTIONS`: don't define the functions that take pointer to structures.
- `MATHC_NO_STRUCT_FUNCTIONS`: don't define the functions that take structures as value.
- `MATHC_NO_EASING_FUNCTIONS`: don't define the easing functions.
- `MATHC_USE_CONFIG_HEADER`: if defined, `mathc.h` will try to include a header `config.h`.

There are two ways to declare these preprocessors:

- Declare them using the compiler's option `-D`. The problem of this approach is that the makes the command-line long.
- Declare only the `MATHC_USE_CONFIG_HEADER` using the compiler's option `-D` and then declare the other preprocessors in the header `config.h`.

Here is an **example** using the second approach:

```c
#ifndef CONFIG_H
#define CONFIG_H

#include <GL\gl.h>

#define mfloat_t GLfloat
#define MATHC_USE_UNIONS
#define MATHC_NO_EASING_FUNCTIONS

#endif /* CONFIG_H */
```

## Types

By default, types are can be declared as arrays of `mfloat_t`, arrays of `mint_t`, or structures:

```c
/* As float arrays */
mfloat_t texture_coordinates[VEC2_SIZE];
mfloat_t position[VEC3_SIZE];
mfloat_t rgba[VEC4_SIZE];
mfloat_t rotation[QUAT_SIZE];
mfloat_t rotation_mat[MAT3_SIZE];
mfloat_t model_mat[MAT4_SIZE];

/* As float structures */
struct vec2 texture_coordinates;
struct vec3 position;
struct vec4 rgba;
struct quat rotation;
struct mat3 rotation_mat;
struct mat4 model_mat;

/* As integer arrays */
mint_t texture_coordinates[VEC2_SIZE];
mint_t position[VEC3_SIZE];
mint_t rgba[VEC4_SIZE];

/* As integer structures */
struct vec2i texture_coordinates;
struct vec3i position;
struct vec4i rgba;
```

## Functions

By default, MATHC has functions that take as argument arrays of `mfloat_t`, arrays of `mint_t`, structures as value, or pointers to structure. Functions that take structure as value have a prefix `s`. Functions that take structure pointers have a prefix `ps`:

```c
/* Arrays */
mfloat_t position[VEC3_SIZE];
mfloat_t offset[VEC3_SIZE];

vec2_add(position,
	vec2(position, 0.0f, 0.0f),
	vec2(offset, 1.0f, 1.0f));

/* Structures as value */
struct vec2 position = svec2(0.0f, 0.0f);
struct vec2 offset = svec2(1.0f, 1.0f);
position = svec2_add(position, offset);

/* Pointers to structure */
struct vec2 position;
struct vec2 offset;
psvec2(&position, 0.0f, 0.0f)
psvec2(&offset, 1.0f, 1.0f)
psvec2_add(&position, &position, &offset);
```

## Structures With Unions

If the preprocessor `MATHC_USE_UNIONS` is defined, the elements in the structures can be accessed as an array using the field `v`:

```c
struct vec3 position = svec3(10.0f, 10.0f, 0.0f);

position.x = position.x * 2.0f;
position.y = position.y * 2.0f;

/* Or accessing as an array */

vec3_multiply_f(position.v, 2.0f)
```

## Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations.

Easing functions take a value inside the range `0.0-1.0` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

## Test

The test program can be compiled with the script `test.sh` and it will run automatically. The test program will execute the math operations and compare the expected values with the actual values. Due the nature of floating-point numbers, the result of operations with floating-point numbers are compared using multiple threshold (*epsilon* value). The test program will print the total of tests that passed and the total of tests that failed.

# License

Copyright © 2018 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
