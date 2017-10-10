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

typedef struct cvector cvector;
typedef struct cmatrix cmatrix;

struct cvector {
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
cvector to_vector2(float x, float y);
void pvector2_add(cvector *a, cvector *b, cvector *result);
void pvector2_subtract(cvector *a, cvector *b, cvector *result);
void pvector2_scale(cvector *a, float scale, cvector *result);
void pvector2_multiply(cvector *a, cvector *b, cvector *result);
void pvector2_divide(cvector *a, cvector *b, cvector *result);
void pvector2_negative(cvector *a, cvector *result);
void pvector2_abs(cvector *a, cvector *result);
void pvector2_floor(cvector *a, cvector *result);
void pvector2_ceil(cvector *a, cvector *result);
void pvector2_round(cvector *a, cvector *result);
void pvector2_max(cvector *a, cvector *b, cvector *result);
void pvector2_min(cvector *a, cvector *b, cvector *result);
float pvector2_dot(cvector *a, cvector *b);
float pvector2_angle(cvector *a);
float pvector2_length_squared(cvector *a);
float pvector2_length(cvector *a);
void pvector2_normalize(cvector *a, cvector *result);
void pvector2_slide(cvector *a, cvector *b, cvector *result);
void pvector2_reflect(cvector *a, cvector *b, cvector *result);
void pvector2_tangent(cvector *a, cvector *result);
void pvector2_rotate(cvector *a, float angle, cvector *result);
float pvector2_distance_to(cvector *a, cvector *b);
float pvector2_distance_squared_to(cvector *a, cvector *b);
void pvector2_linear_interpolation(cvector *a, cvector *b, float p, cvector *result);

cvector vector2_add(cvector a, cvector b);
cvector vector2_subtract(cvector a, cvector b);
cvector vector2_scale(cvector a, float scale);
cvector vector2_multiply(cvector a, cvector b);
cvector vector2_divide(cvector a, cvector b);
cvector vector2_negative(cvector a);
cvector vector2_abs(cvector a);
cvector vector2_floor(cvector a);
cvector vector2_ceil(cvector a);
cvector vector2_round(cvector a);
cvector vector2_max(cvector a, cvector b);
cvector vector2_min(cvector a, cvector b);
float vector2_dot(cvector a, cvector b);
float vector2_angle(cvector a);
float vector2_length_squared(cvector a);
float vector2_length(cvector a);
cvector vector2_normalize(cvector a);
cvector vector2_slide(cvector a, cvector normal);
cvector vector2_reflect(cvector a, cvector normal);
cvector vector2_tangent(cvector a);
cvector vector2_rotate(cvector a, float angle);
float vector2_distance_to(cvector a, cvector b);
float vector2_distance_squared_to(cvector a, cvector b);
cvector vector2_linear_interpolation(cvector a, cvector b, float p);

/* Vector 3D */
cvector to_vector3(float x, float y, float z);
void pvector3_add(cvector *a, cvector *b, cvector *result);
void pvector3_subtract(cvector *a, cvector *b, cvector *result);
void pvector3_scale(cvector *a, float scale, cvector *result);
void pvector3_multiply(cvector *a, cvector *b, cvector *result);
void pvector3_divide(cvector *a, cvector *b, cvector *result);
void pvector3_negative(cvector *a, cvector *result);
void pvector3_abs(cvector *a, cvector *result);
void pvector3_floor(cvector *a, cvector *result);
void pvector3_ceil(cvector *a, cvector *result);
void pvector3_round(cvector *a, cvector *result);
void pvector3_max(cvector *a, cvector *b, cvector *result);
void pvector3_min(cvector *a, cvector *b, cvector *result);
float pvector3_dot(cvector *a, cvector *b);
void pvector3_cross(cvector *a, cvector *b, cvector *result);
float pvector3_length_squared(cvector *a);
float pvector3_length(cvector *a);
void pvector3_normalize(cvector *a, cvector *result);
void pvector3_slide(cvector *a, cvector *b, cvector *result);
void pvector3_reflect(cvector *a, cvector *normal, cvector *result);
float pvector3_distance_to(cvector *a, cvector *b);
float pvector3_distance_squared_to(cvector *a, cvector *b);
void pvector3_linear_interpolation(cvector *a, cvector *b, float p, cvector *result);

cvector vector3_add(cvector a, cvector b);
cvector vector3_subtract(cvector a, cvector b);
cvector vector3_scale(cvector a, float scale);
cvector vector3_multiply(cvector a, cvector b);
cvector vector3_divide(cvector a, cvector b);
cvector vector3_negative(cvector a);
cvector vector3_abs(cvector a);
cvector vector3_floor(cvector a);
cvector vector3_ceil(cvector a);
cvector vector3_round(cvector a);
cvector vector3_max(cvector a, cvector b);
cvector vector3_min(cvector a, cvector b);
float vector3_dot(cvector a, cvector b);
cvector vector3_cross(cvector a, cvector b);
float vector3_length_squared(cvector a);
float vector3_length(cvector a);
cvector vector3_normalize(cvector a);
cvector vector3_slide(cvector a, cvector b);
cvector vector3_reflect(cvector a, cvector normal);
float vector3_distance_to(cvector a, cvector b);
float vector3_distance_squared_to(cvector a, cvector b);
cvector vector3_linear_interpolation(cvector a, cvector b, float p);

/* Quaternion */
cvector to_quaternion(float x, float y, float z, float w);
void pquaternion_add(cvector *a, cvector *b, cvector *result);
void pquaternion_subtract(cvector *a, cvector *b, cvector *result);
void pquaternion_scale(cvector *a, float scale, cvector *result);
void pquaternion_multiply(cvector *a, cvector *b, cvector *result);
void pquaternion_divide(cvector *a, cvector *b, cvector *result);
void pquaternion_negative(cvector *a, cvector *result);
void pquaternion_abs(cvector *a, cvector *result);
void pquaternion_floor(cvector *a, cvector *result);
void pquaternion_ceil(cvector *a, cvector *result);
void pquaternion_round(cvector *a, cvector *result);
void pquaternion_max(cvector *a, cvector *b, cvector *result);
void pquaternion_min(cvector *a, cvector *b, cvector *result);
float pquaternion_dot(cvector *a, cvector *b);
float pquaternion_angle(cvector *a, cvector *b);
void pquaternion_inverse(cvector *a, cvector *result);
float pquaternion_length_squared(cvector *a);
float pquaternion_length(cvector *a);
void pquaternion_normalize(cvector *a, cvector *result);
void pquaternion_conjugate(cvector *a, cvector *result);
void pquaternion_power(cvector *a, float exponent, cvector *result);
void pquaternion_axis_angle(cvector *a, float angle, cvector *result);
void pquaternion_rotation_matrix(cmatrix *m, cvector *result);
void pquaternion_yaw_pitch_roll(float yaw, float pitch, float roll, cvector *result);
void pquaternion_linear_interpolation(cvector *a, cvector *b, float p, cvector *result);
void pquaternion_spherical_linear_interpolation(cvector *a, cvector *b, float p, cvector *result);

cvector quaternion_add(cvector a, cvector b);
cvector quaternion_subtract(cvector a, cvector b);
cvector quaternion_scale(cvector a, float scale);
cvector quaternion_multiply(cvector a, cvector b);
cvector quaternion_divide(cvector a, cvector b);
cvector quaternion_negative(cvector a);
cvector quaternion_abs(cvector a);
cvector quaternion_floor(cvector a);
cvector quaternion_ceil(cvector a);
cvector quaternion_round(cvector a);
cvector quaternion_max(cvector a, cvector b);
cvector quaternion_min(cvector a, cvector b);
float quaternion_dot(cvector a, cvector b);
float quaternion_angle(cvector a, cvector b);
cvector quaternion_inverse(cvector a);
float quaternion_length_squared(cvector a);
float quaternion_length(cvector a);
cvector quaternion_normalize(cvector a);
cvector quaternion_conjugate(cvector a);
cvector quaternion_power(cvector a, float exponent);
cvector quaternion_axis_angle(cvector a, float angle);
cvector quaternion_rotation_matrix(cmatrix m);
cvector quaternion_yaw_pitch_roll(float yaw, float pitch, float roll);
cvector quaternion_linear_interpolation(cvector a, cvector b, float p);
cvector quaternion_spherical_linear_interpolation(cvector a, cvector b, float p);

/* Matrix */
void pmatrix_identity(cmatrix *result);
void pmatrix_ortho(float l, float r, float b, float t, float n, float f, cmatrix *result);
void pmatrix_perspective(float y_fov, float aspect, float n, float f, cmatrix *result);
void pmatrix_rotation_x(float angle, cmatrix *result);
void pmatrix_rotation_y(float angle, cmatrix *result);
void pmatrix_rotation_z(float angle, cmatrix *result);
void pmatrix_rotation_axis(cvector *a, float angle, cmatrix *result);
void pmatrix_rotation_quaternion(cvector *q, cmatrix *result);
void pmatrix_look_at(cvector *pos, cvector *target, cvector *up, cmatrix *result);
void pmatrix_scale(cvector *v, cmatrix *result);
void pmatrix_get_scale(cmatrix *m, cvector *result);
void pmatrix_translation(cvector *v, cmatrix *result);
void pmatrix_get_translation(cmatrix *m, cvector *result);
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
cmatrix matrix_rotation_axis(cvector a, float angle);
cmatrix matrix_rotation_quaternion(cvector q);
cmatrix matrix_look_at(cvector pos, cvector target, cvector up);
cmatrix matrix_scale(cvector v);
cvector matrix_get_scale(cmatrix m);
cmatrix matrix_translation(cvector v);
cvector matrix_get_translation(cmatrix m);
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
