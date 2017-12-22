/*
Copyright (C) 2016 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef MATHC_H
#define MATHC_H

#include <math.h>
#include <float.h>

#ifndef MATHC_NO_STDBOOL
	#include <stdbool.h>
#else
	#define bool int
	#define true 1
	#define false 0
#endif

#define MATHC_MAJOR_VERSION 2
#define MATHC_MINOR_VERSION 0
#define MATHC_PATCH_VERSION 0
#ifndef mfloat_t
	#define mfloat_t float
#endif
#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4
#define QUAT_SIZE 4
#define MAT3_SIZE 9
#define MAT4_SIZE 16
#ifdef MATHC_DOUBLE_PRECISION
	#define MPI 3.14159265358979323846
	#define MPI_2 1.57079632679489661923
	#define MPI_4 0.78539816339744830962
	#define MFLT_EPSILON DBL_EPSILON
	#define MABS fabs
	#define MMIN fmin
	#define MMAX fmax
	#define MSQRT sqrt
	#define MSIN sin
	#define MCOS cos
	#define MACOS acos
	#define MTAN tan
	#define MATAN2 atan2
	#define MPOW pow
	#define MFLOOR floor
	#define MCEIL ceil
	#define MROUND round
	#define MFLOAT_C(c) c
#else
	#define MPI 3.1415926536f
	#define MPI_2 1.5707963268f
	#define MPI_4 0.7853981634f
	#define MFLT_EPSILON FLT_EPSILON
	#define MABS fabsf
	#define MMIN fminf
	#define MMAX fmaxf
	#define MSQRT sqrtf
	#define MSIN sinf
	#define MCOS cosf
	#define MACOS acosf
	#define MTAN tanf
	#define MATAN2 atan2f
	#define MPOW powf
	#define MFLOOR floorf
	#define MCEIL ceilf
	#define MROUND roundf
	#define MFLOAT_C(c) c ## f
#endif

/* Utils */
bool nearly_equal(mfloat_t a, mfloat_t b, mfloat_t epsilon);
mfloat_t to_radians(mfloat_t degrees);
mfloat_t to_degrees(mfloat_t radians);

/* Vector 2D */
bool vec2_is_zero(mfloat_t *a);
bool vec2_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool vec2_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *vec2(mfloat_t *result, mfloat_t x, mfloat_t y);
mfloat_t *vec2_zero(mfloat_t *result);
mfloat_t *vec2_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_scale(mfloat_t *result, mfloat_t *a, mfloat_t scale);
mfloat_t *vec2_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_divide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_negative(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_inverse(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_abs(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_floor(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_ceil(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_round(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_max(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_min(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_slide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_reflect(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_tangent(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_rotate(mfloat_t *result, mfloat_t *a, mfloat_t angle);
mfloat_t *vec2_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t *vec2_bezier3(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t p);
mfloat_t *vec2_bezier4(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t *d, mfloat_t p);
mfloat_t vec2_dot(mfloat_t *a, mfloat_t *b);
mfloat_t vec2_angle(mfloat_t *a);
mfloat_t vec2_length_squared(mfloat_t *a);
mfloat_t vec2_length(mfloat_t *a);
mfloat_t vec2_distance_to(mfloat_t *a, mfloat_t *b);
mfloat_t vec2_distance_squared_to(mfloat_t *a, mfloat_t *b);

/* Vector 3D */
bool vec3_is_zero(mfloat_t *a);
bool vec3_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool vec3_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *vec3(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z);
mfloat_t *vec3_zero(mfloat_t *result);
mfloat_t *vec3_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_scale(mfloat_t *result, mfloat_t *a, mfloat_t scale);
mfloat_t *vec3_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_multiply_mat3(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_divide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_negative(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_inverse(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_abs(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_floor(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_ceil(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_round(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_max(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_min(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_cross(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_slide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_reflect(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t *vec3_bezier3(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t p);
mfloat_t *vec3_bezier4(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t *d, mfloat_t p);
mfloat_t vec3_dot(mfloat_t *a, mfloat_t *b);
mfloat_t vec3_length_squared(mfloat_t *a);
mfloat_t vec3_length(mfloat_t *a);
mfloat_t vec3_distance_to(mfloat_t *a, mfloat_t *b);
mfloat_t vec3_distance_squared_to(mfloat_t *a, mfloat_t *b);

/* Vector 4D */
bool vec4_is_zero(mfloat_t *a);
bool vec4_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool vec4_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *vec4(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *vec4_zero(mfloat_t *result);
mfloat_t *vec4_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_scale(mfloat_t *result, mfloat_t *a, mfloat_t scale);
mfloat_t *vec4_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_multiply_mat4(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_divide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_negative(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_inverse(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_abs(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_floor(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_ceil(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_round(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_max(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_min(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_normalize(mfloat_t *result, mfloat_t *a);

/* Quaternion */
bool quat_is_zero(mfloat_t *a);
bool quat_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool quat_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *quat(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *quat_zero(mfloat_t *result);
mfloat_t *quat_null(mfloat_t *result);
mfloat_t *quat_scale(mfloat_t *result, mfloat_t *a, mfloat_t scale);
mfloat_t *quat_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_divide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_negative(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_conjugate(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_inverse(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_power(mfloat_t *result, mfloat_t *a, mfloat_t exponent);
mfloat_t *quat_from_axis_angle(mfloat_t *result, mfloat_t *a, mfloat_t angle);
mfloat_t *quat_to_axis_angle(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_from_vec3(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_from_mat4(mfloat_t *result, mfloat_t *m);
mfloat_t *quat_from_yaw_pitch_roll(mfloat_t *result, mfloat_t yaw, mfloat_t pitch, mfloat_t roll);
mfloat_t *quat_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t *quat_slerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t quat_dot(mfloat_t *a, mfloat_t *b);
mfloat_t quat_angle(mfloat_t *a, mfloat_t *b);
mfloat_t quat_length_squared(mfloat_t *a);
mfloat_t quat_length(mfloat_t *a);

/* Matrix */
mfloat_t *mat4_zero(mfloat_t *result);
mfloat_t *mat4_identity(mfloat_t *result);
mfloat_t *mat4_transpose(mfloat_t *result, mfloat_t *m);
mfloat_t *mat4_inverse(mfloat_t *result, mfloat_t *m);
mfloat_t *mat4_ortho(mfloat_t *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective_fov(mfloat_t *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective_infinite(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n);
mfloat_t *mat4_rotation_x(mfloat_t *result, mfloat_t angle);
mfloat_t *mat4_rotation_y(mfloat_t *result, mfloat_t angle);
mfloat_t *mat4_rotation_z(mfloat_t *result, mfloat_t angle);
mfloat_t *mat4_rotation_axis(mfloat_t *result, mfloat_t *a, mfloat_t angle);
mfloat_t *mat4_rotation_quaternion(mfloat_t *result, mfloat_t *q);
mfloat_t *mat4_look_at_with_up(mfloat_t *result, mfloat_t *position, mfloat_t *target, mfloat_t *up_axis);
mfloat_t *mat4_look_at(mfloat_t *result, mfloat_t *position, mfloat_t *target);
mfloat_t *mat4_scaling(mfloat_t *result, mfloat_t *v);
mfloat_t *mat4_translation(mfloat_t *result, mfloat_t *v);
mfloat_t *mat4_negative(mfloat_t *result, mfloat_t *m);
mfloat_t *mat4_scale(mfloat_t *result, mfloat_t *m, mfloat_t s);
mfloat_t *mat4_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *mat4_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);

/* Easing functions */
mfloat_t quadratic_ease_in(mfloat_t p);
mfloat_t quadratic_ease_out(mfloat_t p);
mfloat_t quadratic_ease_in_out(mfloat_t p);
mfloat_t cubic_ease_in(mfloat_t p);
mfloat_t cubic_ease_out(mfloat_t p);
mfloat_t cubic_ease_in_out(mfloat_t p);
mfloat_t quartic_ease_in(mfloat_t p);
mfloat_t quartic_ease_out(mfloat_t p);
mfloat_t quartic_ease_in_out(mfloat_t p);
mfloat_t quintic_ease_in(mfloat_t p);
mfloat_t quintic_ease_out(mfloat_t p);
mfloat_t quintic_ease_in_out(mfloat_t p);
mfloat_t sine_ease_in(mfloat_t p);
mfloat_t sine_ease_out(mfloat_t p);
mfloat_t sine_ease_in_out(mfloat_t p);
mfloat_t circular_ease_in(mfloat_t p);
mfloat_t circular_ease_out(mfloat_t p);
mfloat_t circular_ease_in_out(mfloat_t p);
mfloat_t exponential_ease_in(mfloat_t p);
mfloat_t exponential_ease_out(mfloat_t p);
mfloat_t exponential_ease_in_out(mfloat_t p);
mfloat_t elastic_ease_in(mfloat_t p);
mfloat_t elastic_ease_out(mfloat_t p);
mfloat_t elastic_ease_in_out(mfloat_t p);
mfloat_t back_ease_in(mfloat_t p);
mfloat_t back_ease_out(mfloat_t p);
mfloat_t back_ease_in_out(mfloat_t p);
mfloat_t bounce_ease_in(mfloat_t p);
mfloat_t bounce_ease_out(mfloat_t p);
mfloat_t bounce_ease_in_out(mfloat_t p);

#endif
