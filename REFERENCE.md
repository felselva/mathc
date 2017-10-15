# MathC Reference

## Utils

```c
int nearly_equal(float a, float b, float epsilon);
```

Used to compare two `float` variables with an error margin `epsilon`. The standard header `<float.h>` comes with the macro `FLT_EPSILON` that can be used as the error margin. Greater values are also acceptable in most cases, such as `FLT_EPSILON * 10.0f` and `FLT_EPSILON * 100.0f`.

Returns `TRUE` if the values are accepted as equal and `FALSE` otherwise.

```c
float to_radians(float degrees);
```

Return the angle `degrees` in radians.

```c
float to_degrees(float radians);
```

Return the angle `radians` in degrees.

## Vector and Quaternion Structure

Vectors (2D and 3D) and quaternions use the same structure `struct vec`.

```c
struct vec {
	float x;
	float y;
	float z;
	float w;
};
```

## 2D Vectors

When using 2D vectors, it is good practice to initialize the variable with `0`, so the value of the `z` component is set to `0.0f`.

Example:

```
struct vec position = {0};
```

The only functions that will set the `z` component of a 2D vector to `0.0f` are `to_pvector2()` and `to_vector2()`. The other operation functions will not change the `z` value, since it's useful when you need to modify yourself.

Every function for 2D vectors will set the value of `w` to `1.0f`.

```c
void to_pvector2(float x, float y, struct vec *result);
struct vec to_vector2(float x, float y);
```

The result is a 2D vector for the position `x` and `y`. The value of `z` is set to `0.0f` and the value of `w` is set to `1.0f`.

```c
void pvector2_add(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_add(struct vec a, struct vec b);
```

The result is a 2D vector for the addition of the 2D vector `a` with the 2D vector `b`.

```c
void pvector2_subtract(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_subtract(struct vec a, struct vec b);
```

The result is a 2D vector for the subraction of the 2D vector `a` with the 2D vector `b`.

```c
void pvector2_scale(struct vec *a, float scale, struct vec *result);
struct vec vector2_scale(struct vec a, float scale);
```

The result is a 2D vector for the scaling of the 2D vector `a` with the value `scale`.

```c
void pvector2_multiply(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_multiply(struct vec a, struct vec b);
```

The result is a 2D vector for the multiplication of the 2D vector `a` with the 2D vector `b`.

```c
void pvector2_divide(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_divide(struct vec a, struct vec b);
```

The result is a 2D vector for the division of the 2D vector `a` with the 2D vector `b`.

```c
void pvector2_negative(struct vec *a, struct vec *result);
struct vec vector2_negative(struct vec a);
```

The result is a 2D vector for the negation of the 2D vector `a`.

```c
void pvector2_inverse(struct vec *a, struct vec *result);
struct vec vector2_inverse(struct vec a);
```

The result is a 2D vector for the inversion of the 2D vector `a`.

```c
void pvector2_abs(struct vec *a, struct vec *result);
struct vec vector2_abs(struct vec a);
```

The result is a 2D vector for the 2D vector `a` with absolute values.

```c
void pvector2_floor(struct vec *a, struct vec *result);
struct vec vector2_floor(struct vec a);
```

The result is a 2D vector for the 2D vector `a` with floored values.

```c
void pvector2_ceil(struct vec *a, struct vec *result);
struct vec vector2_ceil(struct vec a);
```

The result is a 2D vector for the 2D vector `a` with ceiled values.

```c
void pvector2_round(struct vec *a, struct vec *result);
struct vec vector2_round(struct vec a);
```

The result is a 2D vector for the 2D vector `a` with rounded values.

```c
void pvector2_max(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_max(struct vec a, struct vec b);
```

The result is a 2D vector with the maximum values between the 2D vector `a` and the 2D vector `b`.

```c
void pvector2_min(struct vec *a, struct vec *b, struct vec *result);
struct vec vector2_min(struct vec a, struct vec b);
```

The result is a 2D vector with the minimum values between the 2D vector `a` and the 2D vector `b`.

```c
float pvector2_dot(struct vec *a, struct vec *b);
float vector2_dot(struct vec a, struct vec b);
```

The result is the dot product of the 2D vector `a` with the 2D vector `b`.

```c
float pvector2_angle(struct vec *a);
float vector2_angle(struct vec a);
```

The result is the angle of the 2D vector `a` with the origin.

```c
float pvector2_length_squared(struct vec *a);
float vector2_length_squared(struct vec a);
```

The result is the length squared of the 2D vector `a`.

```c
float pvector2_length(struct vec *a);
float vector2_length(struct vec a);
```

The result is the length of the 2D vector `a`.

```c
void pvector2_normalize(struct vec *a, struct vec *result);
struct vec vector2_normalize(struct vec a);
```

The result is a 2D vector for the normalized 2D vector `a`.

```c
void pvector2_slide(struct vec *a, struct vec *normal, struct vec *result);
struct vec vector2_slide(struct vec a, struct vec normal);
```

The result is a 2D vector for the slided 2D vector `a` against the 2D vector `normal`.

```c
void pvector2_reflect(struct vec *a, struct vec *normal, struct vec *result);
struct vec vector2_reflect(struct vec a, struct vec normal);
```

The result is a 2D vector for the reflected 2D vector `a` against the 2D vector `normal`.

```c
void pvector2_tangent(struct vec *a, struct vec *result);
struct vec vector2_tangent(struct vec a);
```

The result is a 2D vector for the tangent of the 2D vector `a`.

```c
void pvector2_rotate(struct vec *a, float angle, struct vec *result);
struct vec vector2_rotate(struct vec a, float angle);
```

The result is a 2D vector for the rotated 2D vector `a` with the value in radians `angle`.

```c
float pvector2_distance_to(struct vec *a, struct vec *b);
float vector2_distance_to(struct vec a, struct vec b);
```

The result is the distance between the 2D vector `a` and the 2D vector `b`.

```c
float pvector2_distance_squared_to(struct vec *a, struct vec *b);
float vector2_distance_squared_to(struct vec a, struct vec b);
```

The result is the distance squared between the 2D vector `a` and the 2D vector `b`.

```c
void pvector2_linear_interpolation(struct vec *a, struct vec *b, float, p, struct vec *result);
struct vec vector2_linear_interpolation(struct vec a, struct vec b, float p);
```

The result is a 2D vector for the linear interpolation between the 2D vector `a` and the 2D vector `b` with the value `p`.

### Easing Functions

```c
float quadratic_ease_in(float p);
float quadratic_ease_out(float p);
float quadratic_ease_in_out(float p);
float cubic_ease_in(float p);
float cubic_ease_out(float p);
float cubic_ease_in_out(float p);
float quartic_ease_in(float p);
float quartic_ease_out(float p);
float quartic_ease_in_out(float p);
float quintic_ease_in(float p);
float quintic_ease_out(float p);
float quintic_ease_in_out(float p);
float sine_ease_in(float p);
float sine_ease_out(float p);
float sine_ease_in_out(float p);
float circular_ease_in(float p);
float circular_ease_out(float p);
float circular_ease_in_out(float p);
float exponential_ease_in(float p);
float exponential_ease_out(float p);
float exponential_ease_in_out(float p);
float elastic_ease_in(float p);
float elastic_ease_out(float p);
float elastic_ease_in_out(float p);
float back_ease_in(float p);
float back_ease_out(float p);
float back_ease_in_out(float p);
float bounce_ease_in(float p);
float bounce_ease_out(float p);
float bounce_ease_in_out(float p);
```

Each easing function will return a rate of change for `p`. The value of `p` must be inside the range `0.0f-1.0f`.

The graphic visualization of the easing functions can be found on [easing.net](http://easings.net/).

# LICENSE

The source code of this project is licensed under the terms of the ZLIB license:

Copyright (C) 2016 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
