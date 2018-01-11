# MATHC

[![Build Status](https://travis-ci.org/ferreiradaselva/mathc.svg?branch=master)](https://travis-ci.org/ferreiradaselva/mathc)

MATHC (version 2) is a simple math library for 2D and 3D programming. It contains implementations for:

- Vectors (2D, 3D and 4D)
- Quaternions
- Matrices (2×2, 3×3, and 4×4)
- Easing functions

## Configuring

MATHC can be configured with the following preprocessors (described in the following sections of this document):

- `MATHC_NO_STDBOOL`
- `mfloat_t`
- `MATHC_DOUBLE_PRECISION`
- `MATHC_NO_STRUCTURES`
- `MATHC_NO_POINTER_STRUCT_FUNCTIONS`
- `MATHC_NO_STRUCT_FUNCTIONS`
- `MATHC_NO_EASING_FUNCTIONS`

You can define these macros during compilation time with flags:

```
gcc -DMATHC_NO_STDBOOL=ON -Dmfloat_t=double -DMATHC_DOUBLE_PRECISION=ON
```

Or include `mathc.c` in a source file. This second approach is more useful and flexible, because you can define `mfloat_t` as a different type other than the built-in types `float` or `double`, such as `GLfloat`:

```c
/* In a *.c file */
#include <GL.h>
#define mfloat_t GLfloat
#define MATHC_DOUBLE_PRECISION
#include <mathc.c>
```

## Float-Point Type

By default, `mfloat_t` is a `float`. This can be changed by predefining `mfloat_t` as a desired type.

## Math Precision

By default, MATHC will use single-precision internally. This can be changed by predefining `MATHC_DOUBLE_PRECISION`.

## Types

By default, MATHC types are can be declared as `mfloat_t` arrays or structures:

```c
/* As arrays */
mfloat_t texture_coordinates[VEC2_SIZE];
mfloat_t position[VEC3_SIZE];
mfloat_t rgba[VEC4_SIZE];
mfloat_t rotation[QUAT_SIZE];
mfloat_t rotation_mat[MAT3_SIZE];
mfloat_t model_mat[MAT4_SIZE];

/* As structures */
struct vec2 texture_coordinates;
struct vec3 position;
struct vec4 rgba;
struct quat rotation;
struct mat3 rotation_mat;
struct mat4 model_mat;
```

Note that the structures are composed of a union. This means that the members can be still accessed as a `mfloat_t` array:

```c
struct vec3 position;

printf("Position (Address: %p) = {%f, %f, %f}\n",
	position.v,
	position.v[0], position.v[1], position.v[2])
```

By defining `MATHC_NO_STRUCTURES`, structure types will not defined.

## Functions

By default, MATHC will declare functions that take `mfloat_t` array, structure values, and structure pointers as arguments:

```c
/* As array */
mfloat_t position[VEC3_SIZE];
mfloat_t offset[VEC3_SIZE];

vec2_add(position,
	vec2(position, 0.0f, 0.0f),
	vec2(offset, 1.0f, 1.0f));

/* As structures */
struct vec2 position = svec2(0.0f, 0.0f);
struct vec2 offset = svec2(1.0f, 1.0f);

/* As structure value */
position = svec2_add(position, offset);
/* As structure pointer */
psvec2_add(&position, &position, &offset);
```

By defining `MATHC_NO_STRUCT_FUNCTIONS`, functions that take structure as value will not be defined.

By defining `MATHC_NO_POINTER_STRUCT_FUNCTIONS`, functions that take structure pointers will not be defined.

## Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations.

Easing functions take a value inside the range `0.0-1.0` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

By defining `MATHC_NO_EASING_FUNCTIONS`, the easing functions will not be defined.

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
