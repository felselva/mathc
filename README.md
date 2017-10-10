# MathC

[![Build Status](https://travis-ci.org/ferreiradaselva/mathc.svg?branch=master)](https://travis-ci.org/ferreiradaselva/mathc)

MathC is a simple math library for 2D and 3D programming. It contains implementations for:

- 2D vectors
- 3D vectors
- Quaternions
- Matrices
- Easing functions

It support C99 standard or later.

# Float

Every structure and function uses `float`, because it is the most used type on 2D and 3D programming with OpenGL.

# Vector Structure

All vectors (2D, 3D and quaternions ) use the same structure type `cvector`.

Examples:

```c
/* Rotate a 2D vector 90º */
cvector direction = to_vector2(0.0f, -1.0f);
direction = vector2_rotate(90.0f * M_PIF / 180.0f);

/* Get the angle (radians) of a 2D vector */
float angle = vector2_angle(direction);

/* Create a 3D vector */
cvector position = to_vector3(0.0f, 0.0f, 0.0f);

/* Create a quaternion */
cvector quaternion = to_quaternion(0.0f, 0.0f, 0.0f, 1.0f);
/* Spherical interpolation between two quaternions */
cvector interpolated = quaternion_spherical_linear_interpolation(a, b, 0.5f);
```

# Passing Arguments as Value or Pointer

For every function **that takes a structure**, there are two versions. One that you pass structures as value and other that you pass as pointer. The functions that pass the value by pointer have a prefix `p` and the result is the `*result` argument or a returned `float`.

You can decide which one you want to use.

Examples:

```c
/* Pass by value and return a value */
cmatrix projection = matrix_ortho(-100.0f, 100.0f, -100.0f, 100.0f, 0.0f, 1.0f);
cmatrix view = matrix_look_at(to_vector3(0.0f, 0.0f, 1.0f),
	to_vector3(0.0f, 0.0f, 0.0f),
	to_vector3(0.0f, 1.0f, 0.0f));
cmatrix pv = matrix_multiply_matrix(projection, view);

/* Pass by pointer */
cmatrix projection;
cmatrix view;
cvector pos;
cvector target;
cvector up;
cmatrix multiplied_matrix;

pmatrix_ortho(-100.0f, 100.0f, -100.0f, 100.0f, 0.0f, 1.0f, &projection);
pmatrix_look_at(&pos, &target, &up, &view);
pmatrix_multiply_matrix(&projection, &view, &multiplied_matrix);
```

# Matrices

Matrices are 4×4.

# Easing Functions

The easing functions are an implementation of the functions presented in [easing.net](http://easings.net/). They are mainly useful for animations.

Easing functions take a value that range from `0.0f` to `1.0f` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range.

# Contributing

- Before sending any pull request, open an issue asking if the feature or fix is already being worked on.
- If you find any error, you can open an issue.
- You can request more useful functions in the issues regarding 2D vectors, 3D vectors, quaternions and matrices. If you have already an implementation or know where to find, better.
- Everything here will stay licensed under ZLIB, which is a ***very*** permissive license.

# LICENSE

The source code of this project is licensed under the terms of the ZLIB license:

Copyright (C) 2016 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
