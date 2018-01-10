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
#ifdef MATHC_NO_STDBOOL
	#define bool int
	#define true 1
	#define false 0
#else
	#include <stdbool.h>
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
#define MAT2_SIZE 4
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

#ifdef MATHC_STRUCTURES
struct vec2 {
	union {
		struct {
			mfloat_t x;
			mfloat_t y;
		};
		mfloat_t v[2];
	};
};

struct vec3 {
	union {
		struct {
			mfloat_t x;
			mfloat_t y;
			mfloat_t z;
		};
		struct {
			mfloat_t r;
			mfloat_t g;
			mfloat_t b;
		};
		mfloat_t v[3];
	};
};

struct vec4 {
	union {
		struct {
			mfloat_t x;
			mfloat_t y;
			mfloat_t z;
			mfloat_t w;
		};
		struct {
			mfloat_t r;
			mfloat_t g;
			mfloat_t b;
			mfloat_t a;
		};
		mfloat_t v[4];
	};
};

struct quat {
	union {
		struct {
			mfloat_t x;
			mfloat_t y;
			mfloat_t z;
			mfloat_t w;
		};
		mfloat_t v[4];
	};
};

/*
Matrix 2x2 representation:
m11 m12
m21 m22
*/
struct mat2 {
	union {
		struct {
			mfloat_t m11;
			mfloat_t m21;
			mfloat_t m12;
			mfloat_t m22;
		};
		mfloat_t v[4];
	};
};

/*
Matrix 3x3 representation:
m11 m12 m13
m21 m22 m23
m31 m32 m33
*/
struct mat3 {
	union {
		struct {
			mfloat_t m11;
			mfloat_t m21;
			mfloat_t m31;
			mfloat_t m12;
			mfloat_t m22;
			mfloat_t m32;
			mfloat_t m13;
			mfloat_t m23;
			mfloat_t m33;
		};
		mfloat_t v[9];
	};
};

/*
Matrix 4x4 representation:
m11 m12 m13 m14
m21 m22 m23 m24
m31 m32 m33 m34
m41 m42 m43 m44
*/
struct mat4 {
	union {
		struct {
			mfloat_t m11;
			mfloat_t m21;
			mfloat_t m31;
			mfloat_t m41;
			mfloat_t m12;
			mfloat_t m22;
			mfloat_t m32;
			mfloat_t m42;
			mfloat_t m13;
			mfloat_t m23;
			mfloat_t m33;
			mfloat_t m43;
			mfloat_t m14;
			mfloat_t m24;
			mfloat_t m34;
			mfloat_t m44;
		};
		mfloat_t v[16];
	};
};
#else
	#undef MATHC_POINTER_STRUCT_FUNCTIONS
	#undef MATHC_STRUCT_FUNCTIONS
#endif

#if defined(MATHC_POINTER_STRUCT_FUNCTIONS) || defined(MATHC_STRUCT_FUNCTIONS)
	#ifndef MATHC_INLINE
		#ifdef _MSC_VER
			#define MATHC_INLINE __forceinline
		#else
			#define MATHC_INLINE inline __attribute__((always_inline))
		#endif
	#endif
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
mfloat_t *vec2_assign(mfloat_t *result, mfloat_t *a);
mfloat_t *vec2_zero(mfloat_t *result);
mfloat_t *vec2_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec2_scale(mfloat_t *result, mfloat_t *a, mfloat_t scalar);
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
mfloat_t *vec2_clamp(mfloat_t *result, mfloat_t *a, mfloat_t *lower, mfloat_t *higher);
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
mfloat_t vec2_length(mfloat_t *a);
mfloat_t vec2_length_squared(mfloat_t *a);
mfloat_t vec2_distance_to(mfloat_t *a, mfloat_t *b);
mfloat_t vec2_distance_squared_to(mfloat_t *a, mfloat_t *b);

/* Vector 3D */
bool vec3_is_zero(mfloat_t *a);
bool vec3_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool vec3_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *vec3(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z);
mfloat_t *vec3_assign(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_zero(mfloat_t *result);
mfloat_t *vec3_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_scale(mfloat_t *result, mfloat_t *a, mfloat_t scalar);
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
mfloat_t *vec3_clamp(mfloat_t *result, mfloat_t *a, mfloat_t *lower, mfloat_t *higher);
mfloat_t *vec3_cross(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *vec3_slide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_reflect(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec3_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t *vec3_bezier3(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t p);
mfloat_t *vec3_bezier4(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t *c, mfloat_t *d, mfloat_t p);
mfloat_t vec3_dot(mfloat_t *a, mfloat_t *b);
mfloat_t vec3_length(mfloat_t *a);
mfloat_t vec3_length_squared(mfloat_t *a);
mfloat_t vec3_distance_to(mfloat_t *a, mfloat_t *b);
mfloat_t vec3_distance_squared_to(mfloat_t *a, mfloat_t *b);

/* Vector 4D */
bool vec4_is_zero(mfloat_t *a);
bool vec4_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool vec4_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *vec4(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *vec4_assign(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_zero(mfloat_t *result);
mfloat_t *vec4_add(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_subtract(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *vec4_scale(mfloat_t *result, mfloat_t *a, mfloat_t scalar);
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
mfloat_t *vec4_clamp(mfloat_t *result, mfloat_t *a, mfloat_t *lower, mfloat_t *higher);
mfloat_t *vec4_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *vec4_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);

/* Quaternion */
bool quat_is_zero(mfloat_t *a);
bool quat_is_near_zero(mfloat_t *a, mfloat_t epsilon);
bool quat_is_equal(mfloat_t *a, mfloat_t *b, mfloat_t epsilon);
mfloat_t *quat(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *quat_assign(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_zero(mfloat_t *result);
mfloat_t *quat_null(mfloat_t *result);
mfloat_t *quat_scale(mfloat_t *result, mfloat_t *a, mfloat_t scalar);
mfloat_t *quat_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_divide(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_negative(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_conjugate(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_inverse(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_normalize(mfloat_t *result, mfloat_t *a);
mfloat_t *quat_power(mfloat_t *result, mfloat_t *a, mfloat_t exponent);
mfloat_t *quat_from_axis_angle(mfloat_t *result, mfloat_t *a, mfloat_t angle);
mfloat_t *quat_from_vec3(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *quat_from_mat4(mfloat_t *result, mfloat_t *m);
mfloat_t *quat_from_yaw_pitch_roll(mfloat_t *result, mfloat_t yaw, mfloat_t pitch, mfloat_t roll);
mfloat_t *quat_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t *quat_slerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);
mfloat_t quat_dot(mfloat_t *a, mfloat_t *b);
mfloat_t quat_angle(mfloat_t *a, mfloat_t *b);
mfloat_t quat_length(mfloat_t *a);
mfloat_t quat_length_squared(mfloat_t *a);

/* Matrix */
mfloat_t *mat4_zero(mfloat_t *result);
mfloat_t *mat4_assign(mfloat_t *result, mfloat_t *m);
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
mfloat_t *mat4_look_at(mfloat_t *result, mfloat_t *position, mfloat_t *target, mfloat_t *up_axis);
mfloat_t *mat4_translation(mfloat_t *result, mfloat_t *v);
mfloat_t *mat4_scaling(mfloat_t *result, mfloat_t *v);
mfloat_t *mat4_negative(mfloat_t *result, mfloat_t *m);
mfloat_t *mat4_scale(mfloat_t *result, mfloat_t *m, mfloat_t s);
mfloat_t *mat4_multiply(mfloat_t *result, mfloat_t *a, mfloat_t *b);
mfloat_t *mat4_lerp(mfloat_t *result, mfloat_t *a, mfloat_t *b, mfloat_t p);

#ifdef MATHC_POINTER_STRUCT_FUNCTIONS
/* Vector 2D */
MATHC_INLINE bool psvec2_is_zero(struct vec2 *a)
{
	return vec2_is_zero(a->v);
};

MATHC_INLINE bool psvec2_is_near_zero(struct vec2 *a, mfloat_t epsilon)
{
	return vec2_is_near_zero(a->v, epsilon);
};

MATHC_INLINE bool psvec2_is_equal(struct vec2 *a, struct vec2 *b, mfloat_t epsilon)
{
	return vec2_is_equal(a->v, b->v, epsilon);
};

MATHC_INLINE struct vec2 *psvec2(struct vec2 *result, mfloat_t x, mfloat_t y)
{
	vec2(result->v, x, y);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_assign(struct vec2 *result, struct vec2 *a)
{
	vec2_assign(result->v, a->v);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_zero(struct vec2 *result)
{
	vec2_zero(result->v);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_add(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_add(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_subtract(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_subtract(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_scale(struct vec2 *result, struct vec2 *a, mfloat_t scalar)
{
	vec2_scale(result->v, a->v, scalar);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_multiply(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_multiply(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec2 *psvec2_divide(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_divide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_negative(struct vec2 *result, struct vec2 *a)
{
	vec2_negative(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_inverse(struct vec2 *result, struct vec2 *a)
{
	vec2_inverse(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_abs(struct vec2 *result, struct vec2 *a)
{
	vec2_abs(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_floor(struct vec2 *result, struct vec2 *a)
{
	vec2_floor(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_ceil(struct vec2 *result, struct vec2 *a)
{
	vec2_ceil(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_round(struct vec2 *result, struct vec2 *a)
{
	vec2_round(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_max(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_max(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_min(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_min(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_clamp(struct vec2 *result, struct vec2 *a, struct vec2 *lower, struct vec2 *higher)
{
	vec2_clamp(result->v, a->v, lower->v, higher->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_normalize(struct vec2 *result, struct vec2 *a)
{
	vec2_normalize(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_slide(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_slide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_reflect(struct vec2 *result, struct vec2 *a, struct vec2 *b)
{
	vec2_reflect(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_tangent(struct vec2 *result, struct vec2 *a)
{
	vec2_tangent(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_rotate(struct vec2 *result, struct vec2 *a, mfloat_t angle)
{
	vec2_rotate(result->v, a->v, angle);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_lerp(struct vec2 *result, struct vec2 *a, struct vec2 *b, mfloat_t p)
{
	vec2_lerp(result->v, a->v, b->v, p);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_bezier3(struct vec2 *result, struct vec2 *a, struct vec2 *b, struct vec2 *c, mfloat_t p)
{
	vec2_bezier3(result->v, a->v, b->v, c->v, p);
	return result;
}

MATHC_INLINE struct vec2 *psvec2_bezier4(struct vec2 *result, struct vec2 *a, struct vec2 *b, struct vec2 *c, struct vec2 *d, mfloat_t p)
{
	vec2_bezier4(result->v, a->v, b->v, c->v, d->v, p);
	return result;
}

MATHC_INLINE mfloat_t psvec2_dot(struct vec2 *a, struct vec2 *b)
{
	return vec2_dot(a->v, b->v);
}

MATHC_INLINE mfloat_t psvec2_angle(struct vec2 *a)
{
	return vec2_angle(a->v);
}

MATHC_INLINE mfloat_t psvec2_length_squared(struct vec2 *a)
{
	return vec2_length_squared(a->v);
}

MATHC_INLINE mfloat_t psvec2_length(struct vec2 *a)
{
	return vec2_length(a->v);
}

MATHC_INLINE mfloat_t psvec2_distance_to(struct vec2 *a, struct vec2 *b)
{
	return vec2_distance_to(a->v, b->v);
}

MATHC_INLINE mfloat_t psvec2_distance_squared_to(struct vec2 *a, struct vec2 *b)
{
	return vec2_distance_squared_to(a->v, b->v);
}

/* Vector 3D */
MATHC_INLINE bool psvec3_is_zero(struct vec3 *a)
{
	return vec3_is_zero(a->v);
};

MATHC_INLINE bool psvec3_is_near_zero(struct vec3 *a, mfloat_t epsilon)
{
	return vec3_is_near_zero(a->v, epsilon);
};

MATHC_INLINE bool psvec3_is_equal(struct vec3 *a, struct vec3 *b, mfloat_t epsilon)
{
	return vec3_is_equal(a->v, b->v, epsilon);
};

MATHC_INLINE struct vec3 *psvec3(struct vec3 *result, mfloat_t x, mfloat_t y, mfloat_t z)
{
	vec3(result->v, x, y, z);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_assign(struct vec3 *result, struct vec3 *a)
{
	vec3_assign(result->v, a->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_zero(struct vec3 *result)
{
	vec3_zero(result->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_add(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_add(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_subtract(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_subtract(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_scale(struct vec3 *result, struct vec3 *a, mfloat_t scalar)
{
	vec3_scale(result->v, a->v, scalar);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_multiply(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_multiply(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_multiply_mat3(struct vec3 *result, struct vec3 *a, struct mat3 *b)
{
	vec3_multiply_mat3(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec3 *psvec3_divide(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_divide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_negative(struct vec3 *result, struct vec3 *a)
{
	vec3_negative(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_inverse(struct vec3 *result, struct vec3 *a)
{
	vec3_inverse(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_abs(struct vec3 *result, struct vec3 *a)
{
	vec3_abs(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_floor(struct vec3 *result, struct vec3 *a)
{
	vec3_floor(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_ceil(struct vec3 *result, struct vec3 *a)
{
	vec3_ceil(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_round(struct vec3 *result, struct vec3 *a)
{
	vec3_round(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_max(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_max(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_min(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_min(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_clamp(struct vec3 *result, struct vec3 *a, struct vec3 *lower, struct vec3 *higher)
{
	vec3_clamp(result->v, a->v, lower->v, higher->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_cross(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_cross(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_normalize(struct vec3 *result, struct vec3 *a)
{
	vec3_normalize(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_slide(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_slide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_reflect(struct vec3 *result, struct vec3 *a, struct vec3 *b)
{
	vec3_reflect(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_lerp(struct vec3 *result, struct vec3 *a, struct vec3 *b, mfloat_t p)
{
	vec3_lerp(result->v, a->v, b->v, p);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_bezier3(struct vec3 *result, struct vec3 *a, struct vec3 *b, struct vec3 *c, mfloat_t p)
{
	vec3_bezier3(result->v, a->v, b->v, c->v, p);
	return result;
}

MATHC_INLINE struct vec3 *psvec3_bezier4(struct vec3 *result, struct vec3 *a, struct vec3 *b, struct vec3 *c, struct vec3 *d, mfloat_t p)
{
	vec3_bezier4(result->v, a->v, b->v, c->v, d->v, p);
	return result;
}

MATHC_INLINE mfloat_t psvec3_dot(struct vec3 *a, struct vec3 *b)
{
	return vec3_dot(a->v, b->v);
}

MATHC_INLINE mfloat_t psvec3_length(struct vec3 *a)
{
	return vec3_length(a->v);
}

MATHC_INLINE mfloat_t psvec3_length_squared(struct vec3 *a)
{
	return vec3_length_squared(a->v);
}

MATHC_INLINE mfloat_t psvec3_distance_to(struct vec3 *a, struct vec3 *b)
{
	return vec3_distance_to(a->v, b->v);
}

MATHC_INLINE mfloat_t psvec3_distance_squared_to(struct vec3 *a, struct vec3 *b)
{
	return vec3_distance_squared_to(a->v, b->v);
}

/* Vector 4D */
MATHC_INLINE bool psvec4_is_zero(struct vec4 *a)
{
	return vec4_is_zero(a->v);
};

MATHC_INLINE bool psvec4_is_near_zero(struct vec4 *a, mfloat_t epsilon)
{
	return vec4_is_near_zero(a->v, epsilon);
};

MATHC_INLINE bool psvec4_is_equal(struct vec4 *a, struct vec4 *b, mfloat_t epsilon)
{
	return vec4_is_equal(a->v, b->v, epsilon);
};

MATHC_INLINE struct vec4 *psvec4(struct vec4 *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	vec4(result->v, x, y, z, w);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_assign(struct vec4 *result, struct vec4 *a)
{
	vec4_assign(result->v, a->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_zero(struct vec4 *result)
{
	vec4_zero(result->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_add(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_add(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_subtract(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_subtract(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_scale(struct vec4 *result, struct vec4 *a, mfloat_t scalar)
{
	vec4_scale(result->v, a->v, scalar);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_multiply(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_multiply(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_multiply_mat4(struct vec4 *result, struct vec4 *a, struct mat4 *b)
{
	vec4_multiply_mat4(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct vec4 *psvec4_divide(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_divide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_negative(struct vec4 *result, struct vec4 *a)
{
	vec4_negative(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_inverse(struct vec4 *result, struct vec4 *a)
{
	vec4_inverse(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_abs(struct vec4 *result, struct vec4 *a)
{
	vec4_abs(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_floor(struct vec4 *result, struct vec4 *a)
{
	vec4_floor(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_ceil(struct vec4 *result, struct vec4 *a)
{
	vec4_ceil(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_round(struct vec4 *result, struct vec4 *a)
{
	vec4_round(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_max(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_max(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_min(struct vec4 *result, struct vec4 *a, struct vec4 *b)
{
	vec4_min(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_clamp(struct vec4 *result, struct vec4 *a, struct vec4 *lower, struct vec4 *higher)
{
	vec4_clamp(result->v, a->v, lower->v, higher->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_normalize(struct vec4 *result, struct vec4 *a)
{
	vec4_normalize(result->v, a->v);
	return result;
}

MATHC_INLINE struct vec4 *psvec4_lerp(struct vec4 *result, struct vec4 *a, struct vec4 *b, mfloat_t p)
{
	vec4_lerp(result->v, a->v, b->v, p);
	return result;
}

/* Quaternion */
MATHC_INLINE bool psquat_is_zero(struct quat *a)
{
	return quat_is_zero(a->v);
};

MATHC_INLINE bool psquat_is_near_zero(struct quat *a, mfloat_t epsilon)
{
	return quat_is_near_zero(a->v, epsilon);
};

MATHC_INLINE bool psquat_is_equal(struct quat *a, struct quat *b, mfloat_t epsilon)
{
	return quat_is_equal(a->v, b->v, epsilon);
};

MATHC_INLINE struct quat *psquat(struct quat *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	quat(result->v, x, y, z, w);
	return result;
};

MATHC_INLINE struct quat *psquat_assign(struct quat *result, struct quat *a)
{
	quat_assign(result->v, a->v);
	return result;
};

MATHC_INLINE struct quat *psquat_zero(struct quat *result)
{
	quat_zero(result->v);
	return result;
};

MATHC_INLINE struct quat *psquat_null(struct quat *result)
{
	quat_null(result->v);
	return result;
};

MATHC_INLINE struct quat *psquat_scale(struct quat *result, struct quat *a, mfloat_t scalar)
{
	quat_scale(result->v, a->v, scalar);
	return result;
};

MATHC_INLINE struct quat *psquat_multiply(struct quat *result, struct quat *a, struct quat *b)
{
	quat_multiply(result->v, a->v, b->v);
	return result;
};

MATHC_INLINE struct quat *psquat_divide(struct quat *result, struct quat *a, struct quat *b)
{
	quat_divide(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct quat *psquat_negative(struct quat *result, struct quat *a)
{
	quat_negative(result->v, a->v);
	return result;
}

MATHC_INLINE struct quat *psquat_conjugate(struct quat *result, struct quat *a)
{
	quat_conjugate(result->v, a->v);
	return result;
}

MATHC_INLINE struct quat *psquat_inverse(struct quat *result, struct quat *a)
{
	quat_inverse(result->v, a->v);
	return result;
}

MATHC_INLINE struct quat *psquat_normalize(struct quat *result, struct quat *a)
{
	quat_normalize(result->v, a->v);
	return result;
}

MATHC_INLINE struct quat *psquat_power(struct quat *result, struct quat *a, mfloat_t exponent)
{
	quat_power(result->v, a->v, exponent);
	return result;
}

MATHC_INLINE struct quat *psquat_from_axis_angle(struct quat *result, struct vec3 *a, mfloat_t angle)
{
	quat_from_axis_angle(result->v, a->v, angle);
	return result;
}

MATHC_INLINE struct quat *psquat_from_vec3(struct quat *result, struct vec3 *a, struct vec3 *b)
{
	quat_from_vec3(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct quat *psquat_from_mat4(struct quat *result, struct mat4 *a)
{
	quat_from_mat4(result->v, a->v);
	return result;
}

MATHC_INLINE struct quat *psquat_from_yaw_pitch_roll(struct quat *result, mfloat_t yaw, mfloat_t pitch, mfloat_t roll)
{
	quat_from_yaw_pitch_roll(result->v, yaw, pitch, roll);
	return result;
}

MATHC_INLINE struct quat *psquat_lerp(struct quat *result, struct quat *a, struct quat *b, mfloat_t p)
{
	quat_lerp(result->v, a->v, b->v, p);
	return result;
}

MATHC_INLINE struct quat *psquat_slerp(struct quat *result, struct quat *a, struct quat *b, mfloat_t p)
{
	quat_slerp(result->v, a->v, b->v, p);
	return result;
}

MATHC_INLINE mfloat_t psquat_dot(struct quat *a, struct quat *b)
{
	return quat_dot(a->v, b->v);
}

MATHC_INLINE mfloat_t psquat_angle(struct quat *a, struct quat *b)
{
	return quat_angle(a->v, b->v);
}

MATHC_INLINE mfloat_t psquat_length(struct quat *a)
{
	return quat_length(a->v);
}

MATHC_INLINE mfloat_t psquat_length_squared(struct quat *a)
{
	return quat_length_squared(a->v);
}

/* Matrix */
MATHC_INLINE struct mat4 *psmat4_zero(struct mat4 *result)
{
	mat4_zero(result->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_assign(struct mat4 *result, struct mat4 *m)
{
	mat4_assign(result->v, m->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_identity(struct mat4 *result)
{
	mat4_identity(result->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_transpose(struct mat4 *result, struct mat4 *m)
{
	mat4_transpose(result->v, m->v);
	return result;
};

MATHC_INLINE struct mat4 *psmat4_inverse(struct mat4 *result, struct mat4 *m)
{
	mat4_inverse(result->v, m->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_ortho(struct mat4 *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f)
{
	mat4_ortho(result->v, l, r, b, t, n, f);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_perspective(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f)
{
	mat4_perspective(result->v, fov_y, aspect, n, f);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_perspective_fov(struct mat4 *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f)
{
	mat4_perspective_fov(result->v, fov, w, h, n, f);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_perspective_infinite(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n)
{
	mat4_perspective_infinite(result->v, fov_y, aspect, n);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_rotation_x(struct mat4 *result, mfloat_t angle)
{
	mat4_rotation_x(result->v, angle);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_rotation_y(struct mat4 *result, mfloat_t angle)
{
	mat4_rotation_y(result->v, angle);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_rotation_z(struct mat4 *result, mfloat_t angle)
{
	mat4_rotation_z(result->v, angle);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_rotation_axis(struct mat4 *result, struct mat4 *a, mfloat_t angle)
{
	mat4_rotation_axis(result->v, a->v, angle);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_rotation_quaternion(struct mat4 *result, struct mat4 *q)
{
	mat4_rotation_quaternion(result->v, q->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_look_at(struct mat4 *result, struct vec3 *position, struct vec3 *target, struct vec3 *up_axis)
{
	mat4_look_at(result->v, position->v, target->v, up_axis->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_translation(struct mat4 *result, struct mat4 *v)
{
	mat4_translation(result->v, v->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_scaling(struct mat4 *result, struct mat4 *v)
{
	mat4_scaling(result->v, v->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_negative(struct mat4 *result, struct mat4 *m)
{
	mat4_negative(result->v, m->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_scale(struct mat4 *result, struct mat4 *m, mfloat_t s)
{
	mat4_scale(result->v, m->v, s);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_multiply(struct mat4 *result, struct mat4 *a, struct mat4 *b)
{
	mat4_multiply(result->v, a->v, b->v);
	return result;
}

MATHC_INLINE struct mat4 *psmat4_lerp(struct mat4 *result, struct mat4 *a, struct mat4 *b, mfloat_t p)
{
	mat4_lerp(result->v, a->v, b->v, p);
	return result;
}
#endif

#ifdef MATHC_STRUCT_FUNCTIONS
MATHC_INLINE bool svec2_is_zero(struct vec2 a)
{
	return vec2_is_zero(a.v);
};

MATHC_INLINE bool svec2_is_near_zero(struct vec2 a, mfloat_t epsilon)
{
	return vec2_is_near_zero(a.v, epsilon);
};

MATHC_INLINE bool svec2_is_equal(struct vec2 a, struct vec2 b, mfloat_t epsilon)
{
	return vec2_is_equal(a.v, b.v, epsilon);
};

MATHC_INLINE struct vec2 svec2(mfloat_t x, mfloat_t y)
{
	struct vec2 result;
	vec2(result.v, x, y);
	return result;
};

MATHC_INLINE struct vec2 svec2_assign(struct vec2 a)
{
	struct vec2 result;
	vec2_assign(result.v, a.v);
	return result;
};

MATHC_INLINE struct vec2 svec2_zero(void)
{
	struct vec2 result;
	vec2_zero(result.v);
	return result;
};

MATHC_INLINE struct vec2 svec2_add(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_add(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec2 svec2_subtract(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_subtract(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec2 svec2_scale(struct vec2 a, mfloat_t scalar)
{
	struct vec2 result;
	vec2_scale(result.v, a.v, scalar);
	return result;
};

MATHC_INLINE struct vec2 svec2_multiply(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_multiply(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec2 svec2_divide(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_divide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_negative(struct vec2 a)
{
	struct vec2 result;
	vec2_negative(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_inverse(struct vec2 a)
{
	struct vec2 result;
	vec2_inverse(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_abs(struct vec2 a)
{
	struct vec2 result;
	vec2_abs(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_floor(struct vec2 a)
{
	struct vec2 result;
	vec2_floor(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_ceil(struct vec2 a)
{
	struct vec2 result;
	vec2_ceil(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_round(struct vec2 a)
{
	struct vec2 result;
	vec2_round(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_max(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_max(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_min(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_min(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_clamp(struct vec2 a, struct vec2 lower, struct vec2 higher)
{
	struct vec2 result;
	vec3_clamp(result.v, a.v, lower.v, higher.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_normalize(struct vec2 a)
{
	struct vec2 result;
	vec2_normalize(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_slide(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_slide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_reflect(struct vec2 a, struct vec2 b)
{
	struct vec2 result;
	vec2_reflect(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_tangent(struct vec2 a)
{
	struct vec2 result;
	vec2_tangent(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec2 svec2_rotate(struct vec2 a, mfloat_t angle)
{
	struct vec2 result;
	vec2_rotate(result.v, a.v, angle);
	return result;
}

MATHC_INLINE struct vec2 svec2_lerp(struct vec2 a, struct vec2 b, mfloat_t p)
{
	struct vec2 result;
	vec2_lerp(result.v, a.v, b.v, p);
	return result;
}

MATHC_INLINE struct vec2 svec2_bezier3(struct vec2 a, struct vec2 b, struct vec2 c, mfloat_t p)
{
	struct vec2 result;
	vec2_bezier3(result.v, a.v, b.v, c.v, p);
	return result;
}

MATHC_INLINE struct vec2 svec2_bezier4(struct vec2 a, struct vec2 b, struct vec2 c, struct vec2 d, mfloat_t p)
{
	struct vec2 result;
	vec2_bezier4(result.v, a.v, b.v, c.v, d.v, p);
	return result;
}

MATHC_INLINE mfloat_t svec2_dot(struct vec2 a, struct vec2 b)
{
	return vec2_dot(a.v, b.v);
}

MATHC_INLINE mfloat_t svec2_angle(struct vec2 a)
{
	return vec2_angle(a.v);
}

MATHC_INLINE mfloat_t svec2_length_squared(struct vec2 a)
{
	return vec2_length_squared(a.v);
}

MATHC_INLINE mfloat_t svec2_length(struct vec2 a)
{
	return vec2_length(a.v);
}

MATHC_INLINE mfloat_t svec2_distance_to(struct vec2 a, struct vec2 b)
{
	return vec2_distance_to(a.v, b.v);
}

MATHC_INLINE mfloat_t svec2_distance_squared_to(struct vec2 a, struct vec2 b)
{
	return vec2_distance_squared_to(a.v, b.v);
}

MATHC_INLINE bool svec3_is_zero(struct vec3 a)
{
	return vec3_is_zero(a.v);
};

MATHC_INLINE bool svec3_is_near_zero(struct vec3 a, mfloat_t epsilon)
{
	return vec3_is_near_zero(a.v, epsilon);
};

MATHC_INLINE bool svec3_is_equal(struct vec3 a, struct vec3 b, mfloat_t epsilon)
{
	return vec3_is_equal(a.v, b.v, epsilon);
};

MATHC_INLINE struct vec3 svec3(mfloat_t x, mfloat_t y, mfloat_t z)
{
	struct vec3 result;
	vec3(result.v, x, y, z);
	return result;
};

MATHC_INLINE struct vec3 svec3_assign(struct vec3 a)
{
	struct vec3 result;
	vec3_assign(result.v, a.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_zero(void)
{
	struct vec3 result;
	vec3_zero(result.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_add(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_add(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_subtract(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_subtract(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_scale(struct vec3 a, mfloat_t scalar)
{
	struct vec3 result;
	vec3_scale(result.v, a.v, scalar);
	return result;
};

MATHC_INLINE struct vec3 svec3_multiply(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_multiply(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_multiply_mat3(struct vec3 a, struct mat3 b)
{
	struct vec3 result;
	vec3_multiply_mat3(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec3 svec3_divide(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_divide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_negative(struct vec3 a)
{
	struct vec3 result;
	vec3_negative(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_inverse(struct vec3 a)
{
	struct vec3 result;
	vec3_inverse(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_abs(struct vec3 a)
{
	struct vec3 result;
	vec3_abs(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_floor(struct vec3 a)
{
	struct vec3 result;
	vec3_floor(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_ceil(struct vec3 a)
{
	struct vec3 result;
	vec3_ceil(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_round(struct vec3 a)
{
	struct vec3 result;
	vec3_round(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_max(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_max(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_min(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_min(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_clamp(struct vec3 a, struct vec3 lower, struct vec3 higher)
{
	struct vec3 result;
	vec3_clamp(result.v, a.v, lower.v, higher.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_cross(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_cross(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_normalize(struct vec3 a)
{
	struct vec3 result;
	vec3_normalize(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_slide(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_slide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_reflect(struct vec3 a, struct vec3 b)
{
	struct vec3 result;
	vec3_reflect(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec3 svec3_lerp(struct vec3 a, struct vec3 b, mfloat_t p)
{
	struct vec3 result;
	vec3_lerp(result.v, a.v, b.v, p);
	return result;
}

MATHC_INLINE struct vec3 svec3_bezier3(struct vec3 a, struct vec3 b, struct vec3 c, mfloat_t p)
{
	struct vec3 result;
	vec3_bezier3(result.v, a.v, b.v, c.v, p);
	return result;
}

MATHC_INLINE struct vec3 svec3_bezier4(struct vec3 a, struct vec3 b, struct vec3 c, struct vec3 d, mfloat_t p)
{
	struct vec3 result;
	vec3_bezier4(result.v, a.v, b.v, c.v, d.v, p);
	return result;
}

MATHC_INLINE mfloat_t svec3_dot(struct vec3 a, struct vec3 b)
{
	return vec3_dot(a.v, b.v);
}

MATHC_INLINE mfloat_t svec3_length(struct vec3 a)
{
	return vec3_length(a.v);
}

MATHC_INLINE mfloat_t svec3_length_squared(struct vec3 a)
{
	return vec3_length_squared(a.v);
}

MATHC_INLINE mfloat_t svec3_distance_to(struct vec3 a, struct vec3 b)
{
	return vec3_distance_to(a.v, b.v);
}

MATHC_INLINE mfloat_t svec3_distance_squared_to(struct vec3 a, struct vec3 b)
{
	return vec3_distance_squared_to(a.v, b.v);
}

MATHC_INLINE bool svec4_is_zero(struct vec4 a)
{
	return vec4_is_zero(a.v);
};

MATHC_INLINE bool svec4_is_near_zero(struct vec4 a, mfloat_t epsilon)
{
	return vec4_is_near_zero(a.v, epsilon);
};

MATHC_INLINE bool svec4_is_equal(struct vec4 a, struct vec4 b, mfloat_t epsilon)
{
	return vec4_is_equal(a.v, b.v, epsilon);
};

MATHC_INLINE struct vec4 svec4(mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	struct vec4 result;
	vec4(result.v, x, y, z, w);
	return result;
};

MATHC_INLINE struct vec4 svec4_assign(struct vec4 a)
{
	struct vec4 result;
	vec4_assign(result.v, a.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_zero(void)
{
	struct vec4 result;
	vec4_zero(result.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_add(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_add(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_subtract(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_subtract(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_scale(struct vec4 a, mfloat_t scalar)
{
	struct vec4 result;
	vec4_scale(result.v, a.v, scalar);
	return result;
};

MATHC_INLINE struct vec4 svec4_multiply(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_multiply(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_multiply_mat4(struct vec4 a, struct mat4 b)
{
	struct vec4 result;
	vec4_multiply_mat4(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct vec4 svec4_divide(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_divide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_negative(struct vec4 a)
{
	struct vec4 result;
	vec4_negative(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_inverse(struct vec4 a)
{
	struct vec4 result;
	vec4_inverse(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_abs(struct vec4 a)
{
	struct vec4 result;
	vec4_abs(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_floor(struct vec4 a)
{
	struct vec4 result;
	vec4_floor(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_ceil(struct vec4 a)
{
	struct vec4 result;
	vec4_ceil(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_round(struct vec4 a)
{
	struct vec4 result;
	vec4_round(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_max(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_max(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_min(struct vec4 a, struct vec4 b)
{
	struct vec4 result;
	vec4_min(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_clamp(struct vec4 a, struct vec4 lower, struct vec4 higher)
{
	struct vec4 result;
	vec4_clamp(result.v, a.v, lower.v, higher.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_normalize(struct vec4 a)
{
	struct vec4 result;
	vec4_normalize(result.v, a.v);
	return result;
}

MATHC_INLINE struct vec4 svec4_lerp(struct vec4 a, struct vec4 b, mfloat_t p)
{
	struct vec4 result;
	vec4_lerp(result.v, a.v, b.v, p);
	return result;
}

MATHC_INLINE bool squat_is_zero(struct quat a)
{
	return quat_is_zero(a.v);
};

MATHC_INLINE bool squat_is_near_zero(struct quat a, mfloat_t epsilon)
{
	return quat_is_near_zero(a.v, epsilon);
};

MATHC_INLINE bool squat_is_equal(struct quat a, struct quat b, mfloat_t epsilon)
{
	return quat_is_equal(a.v, b.v, epsilon);
};

MATHC_INLINE struct quat squat(struct quat result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	quat(result.v, x, y, z, w);
	return result;
};

MATHC_INLINE struct quat squat_assign(struct quat result, struct quat a)
{
	quat_assign(result.v, a.v);
	return result;
};

MATHC_INLINE struct quat squat_zero(struct quat result)
{
	quat_zero(result.v);
	return result;
};

MATHC_INLINE struct quat squat_null(struct quat result)
{
	quat_null(result.v);
	return result;
};

MATHC_INLINE struct quat squat_scale(struct quat result, struct quat a, mfloat_t scalar)
{
	quat_scale(result.v, a.v, scalar);
	return result;
};

MATHC_INLINE struct quat squat_multiply(struct quat result, struct quat a, struct quat b)
{
	quat_multiply(result.v, a.v, b.v);
	return result;
};

MATHC_INLINE struct quat squat_divide(struct quat result, struct quat a, struct quat b)
{
	quat_divide(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct quat squat_negative(struct quat result, struct quat a)
{
	quat_negative(result.v, a.v);
	return result;
}

MATHC_INLINE struct quat squat_conjugate(struct quat result, struct quat a)
{
	quat_conjugate(result.v, a.v);
	return result;
}

MATHC_INLINE struct quat squat_inverse(struct quat result, struct quat a)
{
	quat_inverse(result.v, a.v);
	return result;
}

MATHC_INLINE struct quat squat_normalize(struct quat result, struct quat a)
{
	quat_normalize(result.v, a.v);
	return result;
}

MATHC_INLINE struct quat squat_power(struct quat result, struct quat a, mfloat_t exponent)
{
	quat_power(result.v, a.v, exponent);
	return result;
}

MATHC_INLINE struct quat squat_from_axis_angle(struct quat result, struct vec3 a, mfloat_t angle)
{
	quat_from_axis_angle(result.v, a.v, angle);
	return result;
}

MATHC_INLINE struct quat squat_from_vec3(struct quat result, struct vec3 a, struct vec3 b)
{
	quat_from_vec3(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct quat squat_from_mat4(struct quat result, struct mat4 a)
{
	quat_from_mat4(result.v, a.v);
	return result;
}

MATHC_INLINE struct quat squat_from_yaw_pitch_roll(struct quat result, mfloat_t yaw, mfloat_t pitch, mfloat_t roll)
{
	quat_from_yaw_pitch_roll(result.v, yaw, pitch, roll);
	return result;
}

MATHC_INLINE struct quat squat_lerp(struct quat result, struct quat a, struct quat b, mfloat_t p)
{
	quat_lerp(result.v, a.v, b.v, p);
	return result;
}

MATHC_INLINE struct quat squat_slerp(struct quat result, struct quat a, struct quat b, mfloat_t p)
{
	quat_slerp(result.v, a.v, b.v, p);
	return result;
}

MATHC_INLINE mfloat_t squat_dot(struct quat result, struct quat a, struct quat b)
{
	return quat_dot(a.v, b.v);
}

MATHC_INLINE mfloat_t squat_angle(struct quat result, struct quat a, struct quat b)
{
	return quat_angle( a.v, b.v);
}

MATHC_INLINE mfloat_t squat_length(struct quat a)
{
	return quat_length(a.v);
}

MATHC_INLINE mfloat_t squat_length_squared(struct quat result, struct quat a)
{
	return quat_length_squared(a.v);
}

/* Matrix */
MATHC_INLINE struct mat4 smat4_zero(struct mat4 result)
{
	mat4_zero(result.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_assign(struct mat4 result, struct mat4 m)
{
	mat4_assign(result.v, m.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_identity(struct mat4 result)
{
	mat4_identity(result.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_transpose(struct mat4 result, struct mat4 m)
{
	mat4_transpose(result.v, m.v);
	return result;
};

MATHC_INLINE struct mat4 smat4_inverse(struct mat4 result, struct mat4 m)
{
	mat4_inverse(result.v, m.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_ortho(struct mat4 result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f)
{
	mat4_ortho(result.v, l, r, b, t, n, f);
	return result;
}

MATHC_INLINE struct mat4 smat4_perspective(struct mat4 result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f)
{
	mat4_perspective(result.v, fov_y, aspect, n, f);
	return result;
}

MATHC_INLINE struct mat4 smat4_perspective_fov(struct mat4 result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f)
{
	mat4_perspective_fov(result.v, fov, w, h, n, f);
	return result;
}

MATHC_INLINE struct mat4 smat4_perspective_infinite(struct mat4 result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n)
{
	mat4_perspective_infinite(result.v, fov_y, aspect, n);
	return result;
}

MATHC_INLINE struct mat4 smat4_rotation_x(struct mat4 result, mfloat_t angle)
{
	mat4_rotation_x(result.v, angle);
	return result;
}

MATHC_INLINE struct mat4 smat4_rotation_y(struct mat4 result, mfloat_t angle)
{
	mat4_rotation_y(result.v, angle);
	return result;
}

MATHC_INLINE struct mat4 smat4_rotation_z(struct mat4 result, mfloat_t angle)
{
	mat4_rotation_z(result.v, angle);
	return result;
}

MATHC_INLINE struct mat4 smat4_rotation_axis(struct mat4 result, struct mat4 a, mfloat_t angle)
{
	mat4_rotation_axis(result.v, a.v, angle);
	return result;
}

MATHC_INLINE struct mat4 smat4_rotation_quaternion(struct mat4 result, struct mat4 q)
{
	mat4_rotation_quaternion(result.v, q.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_look_at(struct mat4 result, struct vec3 position, struct vec3 target, struct vec3 up_axis)
{
	mat4_look_at(result.v, position.v, target.v, up_axis.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_translation(struct mat4 result, struct mat4 v)
{
	mat4_translation(result.v, v.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_scaling(struct mat4 result, struct mat4 v)
{
	mat4_scaling(result.v, v.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_negative(struct mat4 result, struct mat4 m)
{
	mat4_negative(result.v, m.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_scale(struct mat4 result, struct mat4 m, mfloat_t s)
{
	mat4_scale(result.v, m.v, s);
	return result;
}

MATHC_INLINE struct mat4 smat4_multiply(struct mat4 result, struct mat4 a, struct mat4 b)
{
	mat4_multiply(result.v, a.v, b.v);
	return result;
}

MATHC_INLINE struct mat4 smat4_lerp(struct mat4 result, struct mat4 a, struct mat4 b, mfloat_t p)
{
	mat4_lerp(result.v, a.v, b.v, p);
	return result;
}
#endif

#ifdef MATHC_EASING_FUNCTIONS
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

#endif
