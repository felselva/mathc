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

#define M_PIF 3.14159265358979f
#define M_PIF_2 1.57079632679489f

typedef struct cvector2 cvector2;
typedef struct cvector3 cvector3;
typedef struct cvector4 cvector4;
typedef struct cquaternion cquaternion;
typedef struct cmatrix cmatrix;

struct cvector2 {
	float x;
	float y;
};

struct cvector3 {
	float x;
	float y;
	float z;
};

struct cvector4 {
	float x;
	float y;
	float z;
	float w;
};

struct cquaternion {
	float x;
	float y;
	float z;
	float w;
};

struct cmatrix {
	/* Row x Column */
	float m11;
	float m21;
	float m31;
	float m41;
	float m12;
	float m22;
	float m32;
	float m42;
	float m13;
	float m23;
	float m33;
	float m43;
	float m14;
	float m24;
	float m34;
	float m44;
};

/* Utils */
int nearly_equal(float a, float b, float epsilon);

/* Vector 2D */
cvector2 to_vector2(float x, float y);
void pvector2_add(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_subtract(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_scale(cvector2 *a, float scale, cvector2 *result);
void pvector2_multiply(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_divide(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_negative(cvector2 *a, cvector2 *result);
void pvector2_abs(cvector2 *a, cvector2 *result);
void pvector2_floor(cvector2 *a, cvector2 *result);
void pvector2_ceil(cvector2 *a, cvector2 *result);
void pvector2_round(cvector2 *a, cvector2 *result);
void pvector2_max(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_min(cvector2 *a, cvector2 *b, cvector2 *result);
float pvector2_dot(cvector2 *a, cvector2 *b);
float pvector2_angle(cvector2 *a);
float pvector2_length_squared(cvector2 *a);
float pvector2_length(cvector2 *a);
void pvector2_normalize(cvector2 *a, cvector2 *result);
void pvector2_slide(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_reflect(cvector2 *a, cvector2 *b, cvector2 *result);
void pvector2_tangent(cvector2 *a, cvector2 *result);
void pvector2_rotate(cvector2 *a, float angle, cvector2 *result);
float pvector2_distance_to(cvector2 *a, cvector2 *b);
float pvector2_distance_squared_to(cvector2 *a, cvector2 *b);
void pvector2_linear_interpolation(cvector2 *a, cvector2 *b, float p, cvector2 *result);

cvector2 vector2_add(cvector2 a, cvector2 b);
cvector2 vector2_subtract(cvector2 a, cvector2 b);
cvector2 vector2_scale(cvector2 a, float scale);
cvector2 vector2_multiply(cvector2 a, cvector2 b);
cvector2 vector2_divide(cvector2 a, cvector2 b);
cvector2 vector2_negative(cvector2 a);
cvector2 vector2_abs(cvector2 a);
cvector2 vector2_floor(cvector2 a);
cvector2 vector2_ceil(cvector2 a);
cvector2 vector2_round(cvector2 a);
cvector2 vector2_max(cvector2 a, cvector2 b);
cvector2 vector2_min(cvector2 a, cvector2 b);
float vector2_dot(cvector2 a, cvector2 b);
float vector2_angle(cvector2 a);
float vector2_length_squared(cvector2 a);
float vector2_length(cvector2 a);
cvector2 vector2_normalize(cvector2 a);
cvector2 vector2_slide(cvector2 a, cvector2 normal);
cvector2 vector2_reflect(cvector2 a, cvector2 normal);
cvector2 vector2_tangent(cvector2 a);
cvector2 vector2_rotate(cvector2 a, float angle);
float vector2_distance_to(cvector2 a, cvector2 b);
float vector2_distance_squared_to(cvector2 a, cvector2 b);
cvector2 vector2_linear_interpolation(cvector2 a, cvector2 b, float p);

/* Vector 3D */
cvector3 to_vector3(float x, float y, float z);
void pvector3_add(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_subtract(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_scale(cvector3 *a, float scale, cvector3 *result);
void pvector3_multiply(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_divide(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_negative(cvector3 *a, cvector3 *result);
void pvector3_abs(cvector3 *a, cvector3 *result);
void pvector3_floor(cvector3 *a, cvector3 *result);
void pvector3_ceil(cvector3 *a, cvector3 *result);
void pvector3_round(cvector3 *a, cvector3 *result);
void pvector3_max(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_min(cvector3 *a, cvector3 *b, cvector3 *result);
float pvector3_dot(cvector3 *a, cvector3 *b);
void pvector3_cross(cvector3 *a, cvector3 *b, cvector3 *result);
float pvector3_length_squared(cvector3 *a);
float pvector3_length(cvector3 *a);
void pvector3_normalize(cvector3 *a, cvector3 *result);
void pvector3_slide(cvector3 *a, cvector3 *b, cvector3 *result);
void pvector3_reflect(cvector3 *a, cvector3 *normal, cvector3 *result);
float pvector3_distance_to(cvector3 *a, cvector3 *b);
float pvector3_distance_squared_to(cvector3 *a, cvector3 *b);
void pvector3_linear_interpolation(cvector3 *a, cvector3 *b, float p, cvector3 *result);

cvector3 vector3_add(cvector3 a, cvector3 b);
cvector3 vector3_subtract(cvector3 a, cvector3 b);
cvector3 vector3_scale(cvector3 a, float scale);
cvector3 vector3_multiply(cvector3 a, cvector3 b);
cvector3 vector3_divide(cvector3 a, cvector3 b);
cvector3 vector3_negative(cvector3 a);
cvector3 vector3_abs(cvector3 a);
cvector3 vector3_floor(cvector3 a);
cvector3 vector3_ceil(cvector3 a);
cvector3 vector3_round(cvector3 a);
cvector3 vector3_max(cvector3 a, cvector3 b);
cvector3 vector3_min(cvector3 a, cvector3 b);
float vector3_dot(cvector3 a, cvector3 b);
cvector3 vector3_cross(cvector3 a, cvector3 b);
float vector3_length_squared(cvector3 a);
float vector3_length(cvector3 a);
cvector3 vector3_normalize(cvector3 a);
cvector3 vector3_slide(cvector3 a, cvector3 b);
cvector3 vector3_reflect(cvector3 a, cvector3 normal);
float vector3_distance_to(cvector3 a, cvector3 b);
float vector3_distance_squared_to(cvector3 a, cvector3 b);
cvector3 vector3_linear_interpolation(cvector3 a, cvector3 b, float p);

/* Vector 4D */
cvector4 to_vector4(float x, float y, float z, float w);
void pvector4_add(cvector4 *a, cvector4 *b, cvector4 *result);
void pvector4_subtract(cvector4 *a, cvector4 *b, cvector4 *result);
void pvector4_scale(cvector4 *a, float scale, cvector4 *result);
void pvector4_multiply(cvector4 *a, cvector4 *b, cvector4 *result);
void pvector4_divide(cvector4 *a, cvector4 *b, cvector4 *result);
void pvector4_negative(cvector4 *a, cvector4 *result);
void pvector4_abs(cvector4 *a, cvector4 *result);
void pvector4_floor(cvector4 *a, cvector4 *result);
void pvector4_ceil(cvector4 *a, cvector4 *result);
void pvector4_round(cvector4 *a, cvector4 *result);
void pvector4_max(cvector4 *a, cvector4 *b, cvector4 *result);
void pvector4_min(cvector4 *a, cvector4 *b, cvector4 *result);
float pvector4_dot(cvector4 *a, cvector4 *b);
float pvector4_length_squared(cvector4 *a);
float pvector4_length(cvector4 *a);
void pvector4_normalize(cvector4 *a, cvector4 *result);
float pvector4_distance_to(cvector4 *a, cvector4 *b);
float pvector4_distance_squared_to(cvector4 *a, cvector4 *b);
void pvector4_linear_interpolation(cvector4 *a, cvector4 *b, float p, cvector4 *result);

cvector4 vector4_add(cvector4 a, cvector4 b);
cvector4 vector4_subtract(cvector4 a, cvector4 b);
cvector4 vector4_scale(cvector4 a, float scale);
cvector4 vector4_multiply(cvector4 a, cvector4 b);
cvector4 vector4_divide(cvector4 a, cvector4 b);
cvector4 vector4_negative(cvector4 a);
cvector4 vector4_abs(cvector4 a);
cvector4 vector4_floor(cvector4 a);
cvector4 vector4_ceil(cvector4 a);
cvector4 vector4_round(cvector4 a);
cvector4 vector4_max(cvector4 a, cvector4 b);
cvector4 vector4_min(cvector4 a, cvector4 b);
float vector4_dot(cvector4 a, cvector4 b);
float vector4_length_squared(cvector4 a);
float vector4_length(cvector4 a);
cvector4 vector4_normalize(cvector4 a);
float vector4_distance_to(cvector4 a, cvector4 b);
float vector4_distance_squared_to(cvector4 a, cvector4 b);
cvector4 vector4_linear_interpolation(cvector4 a, cvector4 b, float p);

/* Quaternion */
cquaternion to_quaternion(float x, float y, float z, float w);
void pquaternion_add(cquaternion *a, cquaternion *b, cquaternion *result);
void pquaternion_subtract(cquaternion *a, cquaternion *b, cquaternion *result);
void pquaternion_scale(cquaternion *a, float scale, cquaternion *result);
void pquaternion_multiply(cquaternion *a, cquaternion *b, cquaternion *result);
void pquaternion_divide(cquaternion *a, cquaternion *b, cquaternion *result);
void pquaternion_negative(cquaternion *a, cquaternion *result);
void pquaternion_abs(cquaternion *a, cquaternion *result);
void pquaternion_floor(cquaternion *a, cquaternion *result);
void pquaternion_ceil(cquaternion *a, cquaternion *result);
void pquaternion_round(cquaternion *a, cquaternion *result);
void pquaternion_max(cquaternion *a, cquaternion *b, cquaternion *result);
void pquaternion_min(cquaternion *a, cquaternion *b, cquaternion *result);
float pquaternion_dot(cquaternion *a, cquaternion *b);
float pquaternion_angle(cquaternion *a, cquaternion *b);
void pquaternion_inverse(cquaternion *a, cquaternion *result);
float pquaternion_length_squared(cquaternion *a);
float pquaternion_length(cquaternion *a);
void pquaternion_normalize(cquaternion *a, cquaternion *result);
void pquaternion_conjugate(cquaternion *a, cquaternion *result);
void pquaternion_power(cquaternion *a, float exponent, cquaternion *result);
void pquaternion_axis_angle(cvector3 *a, float angle, cquaternion *result);
void pquaternion_rotation_matrix(cmatrix *m, cquaternion *result);
void pquaternion_yaw_pitch_roll(float yaw, float pitch, float roll, cquaternion *result);
void pquaternion_linear_interpolation(cquaternion *a, cquaternion *b, float p, cquaternion *result);
void pquaternion_spherical_linear_interpolation(cquaternion *a, cquaternion *b, float p, cquaternion *result);

cquaternion quaternion_add(cquaternion a, cquaternion b);
cquaternion quaternion_subtract(cquaternion a, cquaternion b);
cquaternion quaternion_scale(cquaternion a, float scale);
cquaternion quaternion_multiply(cquaternion a, cquaternion b);
cquaternion quaternion_divide(cquaternion a, cquaternion b);
cquaternion quaternion_negative(cquaternion a);
cquaternion quaternion_abs(cquaternion a);
cquaternion quaternion_floor(cquaternion a);
cquaternion quaternion_ceil(cquaternion a);
cquaternion quaternion_round(cquaternion a);
cquaternion quaternion_max(cquaternion a, cquaternion b);
cquaternion quaternion_min(cquaternion a, cquaternion b);
float quaternion_dot(cquaternion a, cquaternion b);
float quaternion_angle(cquaternion a, cquaternion b);
cquaternion quaternion_inverse(cquaternion a);
float quaternion_length_squared(cquaternion a);
float quaternion_length(cquaternion a);
cquaternion quaternion_normalize(cquaternion a);
cquaternion quaternion_conjugate(cquaternion a);
cquaternion quaternion_power(cquaternion a, float exponent);
cquaternion quaternion_axis_angle(cvector3 a, float angle);
cquaternion quaternion_rotation_matrix(cmatrix m);
cquaternion quaternion_yaw_pitch_roll(float yaw, float pitch, float roll);
cquaternion quaternion_linear_interpolation(cquaternion a, cquaternion b, float p);
cquaternion quaternion_spherical_linear_interpolation(cquaternion a, cquaternion b, float p);

/* Matrix */
void pmatrix_identity(cmatrix *result);
void pmatrix_ortho(float l, float r, float b, float t, float n, float f, cmatrix *result);
void pmatrix_perspective(float y_fov, float aspect, float n, float f, cmatrix *result);
void pmatrix_rotation_x(float angle, cmatrix *result);
void pmatrix_rotation_y(float angle, cmatrix *result);
void pmatrix_rotation_z(float angle, cmatrix *result);
void pmatrix_rotation_axis(cvector3 *a, float angle, cmatrix *result);
void pmatrix_rotation_quaternion(cquaternion *q, cmatrix *result);
void pmatrix_look_at(cvector3 *pos, cvector3 *target, cvector3 *up, cmatrix *result);
void pmatrix_scale(cvector3 *v, cmatrix *result);
void pmatrix_get_scale(cmatrix *m, cvector3 *result);
void pmatrix_translation(cvector3 *v, cmatrix *result);
void pmatrix_get_translation(cmatrix *m, cvector3 *result);
void pmatrix_negative(cmatrix *m, cmatrix *result);
void pmatrix_multiply(cmatrix *m, float s, cmatrix *result);
void pmatrix_multiply_matrix(cmatrix *a, cmatrix *b, cmatrix *result);
void pmatrix_multiply_f4(cmatrix *m, float *result);
void pmatrix_to_array(cmatrix *m, float *result);

cmatrix matrix_identity(void);
cmatrix matrix_ortho(float l, float r, float b, float t, float n, float f);
cmatrix matrix_perspective(float y_fov, float aspect, float n, float f);
cmatrix matrix_rotation_x(float angle);
cmatrix matrix_rotation_y(float angle);
cmatrix matrix_rotation_z(float angle);
cmatrix matrix_rotation_axis(cvector3 a, float angle);
cmatrix matrix_rotation_quaternion(cquaternion q);
cmatrix matrix_look_at(cvector3 pos, cvector3 target, cvector3 up);
cmatrix matrix_scale(cvector3 v);
cvector3 matrix_get_scale(cmatrix m);
cmatrix matrix_translation(cvector3 v);
cvector3 matrix_get_translation(cmatrix m);
cmatrix matrix_negative(cmatrix m);
cmatrix matrix_multiply(cmatrix m, float s);
cmatrix matrix_multiply_matrix(cmatrix a, cmatrix b);
void matrix_multiply_f4(cmatrix m, float *result);
void matrix_to_array(cmatrix m, float *result);

/* Easing functions */
float quadratic_ease_in(const float p);
float quadratic_ease_out(const float p);
float quadratic_ease_in_out(const float p);
float cubic_ease_in(const float p);
float cubic_ease_out(const float p);
float cubic_ease_in_out(const float p);
float quartic_ease_in(const float p);
float quartic_ease_out(const float p);
float quartic_ease_in_out(const float p);
float quintic_ease_in(const float p);
float quintic_ease_out(const float p);
float quintic_ease_in_out(const float p);
float sine_ease_in(const float p);
float sine_ease_out(const float p);
float sine_ease_in_out(const float p);
float circular_ease_in(const float p);
float circular_ease_out(const float p);
float circular_ease_in_out(const float p);
float exponential_ease_in(const float p);
float exponential_ease_out(const float p);
float exponential_ease_in_out(const float p);
float elastic_ease_in(const float p);
float elastic_ease_out(const float p);
float elastic_ease_in_out(const float p);
float back_ease_in(const float p);
float back_ease_out(const float p);
float back_ease_in_out(const float p);
float bounce_ease_in(const float p);
float bounce_ease_out(const float p);
float bounce_ease_in_out(const float p);

#endif
