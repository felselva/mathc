# MATHC

MATHC is a simple math library for 2D and 3D programming.

## Features

- Vectors (2D, 3D and 4D) (integer type and floating-point type)
- Quaternions
- Matrices (2×2, 3×3, and 4×4)
- Easing functions

## Contributions and Development

You can help with the development of MATHC testing the library, sending in-scope math functions, reporting errors and giving feedback.

I work little on the library nowadays, but I am always open to suggestions and contributions.

## Versioning

Starting on version 2, the development of MATHC uses calendar versioning, with a tag `YYYY.MM.DD.MICRO` for each stable release. If a release breaks backward compatibility, then it is mentioned in the release notes.

## Configuring

MATHC can be configured using these preprocessors:

- `MATHC_NO_INT`: disable implementations using `mint_t`.
- `MATHC_USE_INT8`: define `mint_t` as `int8_t`.
- `MATHC_USE_INT16`: define `mint_t` as `int16_t`.
- `MATHC_USE_INT32`: define `mint_t` as `int32_t`. This is the default.
- `MATHC_USE_INT64`: define `mint_t` as `int64_t`.
- `MATHC_INT_TYPE`: set a custom type for `mint_t`.
- `MATHC_NO_FLOATING_POINT`: disable implementations using `mfloat_t`.
- `MATHC_USE_SINGLE_FLOATING_POINT`: define `mfloat_t` as `float`. This is the default.
- `MATHC_USE_DOUBLE_FLOATING_POINT`: define `mfloat_t` as `double`.
- `MATHC_FLOATING_POINT_TYPE`: set a custom type for `mfloat_t`.
- `MATHC_USE_UNIONS`: define anonymous unions inside structures.
- `MATHC_NO_POINTER_STRUCT_FUNCTIONS`: don't define the functions that take pointer to structures.
- `MATHC_NO_STRUCT_FUNCTIONS`: don't define the functions that take structures as value.
- `MATHC_NO_EASING_FUNCTIONS`: don't define the easing functions.

You can define these preprocessors using the compiler's option `-D` or using the compiler's option `-include` to include a configuration header with the configuration preprocessors inside it.

Example of a configuration header that makes `mint_t` a `int16_t`, `mfloat_t` a `GLfloat` and uses the standard math functions with double floating-point precision:

```c
#include <gl.h>

#define MATHC_USE_INT16
#define MATHC_FLOATING_POINT_TYPE GLfloat
#define MATHC_USE_DOUBLE_FLOATING_POINT
```

## Types

By default, vectors, quaternions and matrices can be declared as arrays of `mint_t`, arrays of `mfloat_t`, or structures.

## Functions

By default, MATHC has functions that take as argument arrays of `mint_t`, arrays of `mfloat_t`, structures as value, or pointer to structures. Functions that take structure as value have a prefix `s`. Functions that take structure pointer have a prefix `ps`.

## Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations.

Easing functions take a value inside the range `0.0-1.0` and usually will return a value inside that same range.

## Usage

Creating a "look at" view matrix, useful for 3D programming:

```c
mfloat_t position[VEC3_SIZE];
mfloat_t target[VEC3_SIZE];
mfloat_t up[VEC3_SIZE];
mfloat_t view[MAT4_SIZE];

mat4_look_at(view,
	vec3(position, 0.0, 0.0, 10.0),
	vec3(target, 0.0, 0.0, 0.0),
	vec3(up, 0.0, 1.0, 0.0));
```

Creating a perspective projection matrix:

```c
mfloat_t perspective[MAT4_SIZE];

mat4_perspective(perspective, to_radians(60.0), 1.0, 0.1, 100.0);
```

Creating a model matrix:

```c
mfloat_t position[VEC3_SIZE];
mfloat_t scaling[VEC3_SIZE];
struct {
	mfloat_t position[MAT4_SIZE];
	mfloat_t rotation[MAT4_SIZE];
	mfloat_t scaling[MAT4_SIZE];
	mfloat_t model[MAT4_SIZE];
} matrices;

/* Position */
mat4_identity(matrices.position);
mat4_translation(matrices.position,
	vec3(position, 0.0, 0.0, 0.0));

/* Rotation */
mat4_identity(matrices.rotation);
mat4_rotation_x(matrices.rotation, to_radians(30.0));

/* Scaling */
mat4_identity(matrices.scaling);
mat4_translation(matrices.scaling,
	vec3(scaling, 1.0, 1.0, 1.0));

/* Model matrix */
mat4_multiply(matrices.model, matrices.scaling, matrices.rotation);
mat4_multiply(matrices.model, matrices.position, matrices.model);
```

## License

Copyright © 2018 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
