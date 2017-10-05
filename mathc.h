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
int nearly_equal(const float a, const float b, const float epsilon);

/* Vector 2D */
cvector2 to_vector2(const float x, const float y);
cvector2 vector2_add(const cvector2 a, const cvector2 b);
cvector2 vector2_subtract(const cvector2 a, const cvector2 b);
cvector2 vector2_scale(const cvector2 a, const float scale);
cvector2 vector2_multiply(const cvector2 a, const cvector2 b);
cvector2 vector2_divide(const cvector2 a, const cvector2 b);
cvector2 vector2_negative(const cvector2 a);
cvector2 vector2_abs(const cvector2 a);
cvector2 vector2_floor(const cvector2 a);
cvector2 vector2_ceil(const cvector2 a);
cvector2 vector2_round(const cvector2 a);
cvector2 vector2_max(const cvector2 a, const cvector2 b);
cvector2 vector2_min(const cvector2 a, const cvector2 b);
float vector2_dot(const cvector2 a, const cvector2 b);
float vector2_angle(const cvector2 a);
float vector2_length_squared(const cvector2 a);
float vector2_length(const cvector2 a);
cvector2 vector2_normalize(const cvector2 a);
cvector2 vector2_slide(const cvector2 a, const cvector2 b);
cvector2 vector2_reflect(const cvector2 direction, const cvector2 normal);
cvector2 vector2_tangent(const cvector2 a);
cvector2 vector2_rotate(const cvector2 a, const float angle);
float vector2_distance_to(const cvector2 a, const cvector2 b);
float vector2_distance_squared_to(const cvector2 a, const cvector2 b);
cvector2 vector2_linear_interpolation(const cvector2 a, const cvector2 b, const float p);

/* Vector 3D */
cvector3 to_vector3(const float x, const float y, const float z);
cvector3 vector3_add(const cvector3 a, const cvector3 b);
cvector3 vector3_subtract(const cvector3 a, const cvector3 b);
cvector3 vector3_scale(const cvector3 a, const float scale);
cvector3 vector3_multiply(const cvector3 a, const cvector3 b);
cvector3 vector3_divide(const cvector3 a, const cvector3 b);
cvector3 vector3_negative(const cvector3 a);
cvector3 vector3_abs(const cvector3 a);
cvector3 vector3_floor(const cvector3 a);
cvector3 vector3_ceil(const cvector3 a);
cvector3 vector3_round(const cvector3 a);
cvector3 vector3_max(const cvector3 a, const cvector3 b);
cvector3 vector3_min(const cvector3 a, const cvector3 b);
float vector3_dot(const cvector3 a, const cvector3 b);
cvector3 vector3_cross(const cvector3 a, const cvector3 b);
float vector3_length_squared(const cvector3 a);
float vector3_length(const cvector3 a);
cvector3 vector3_normalize(const cvector3 a);
cvector3 vector3_slide(const cvector3 a, const cvector3 b);
cvector3 vector3_reflect(const cvector3 direction, const cvector3 normal);
float vector3_distance_to(const cvector3 a, const cvector3 b);
float vector3_distance_squared_to(const cvector3 a, const cvector3 b);
cvector3 vector3_linear_interpolation(const cvector3 a, const cvector3 b, const float p);

/* Vector 4D */
cvector4 to_vector4(const float x, const float y, const float z, const float w);
cvector4 vector4_add(const cvector4 a, const cvector4 b);
cvector4 vector4_subtract(const cvector4 a, const cvector4 b);
cvector4 vector4_scale(const cvector4 a, const float scale);
cvector4 vector4_multiply(const cvector4 a, const cvector4 b);
cvector4 vector4_divide(const cvector4 a, const cvector4 b);
cvector4 vector4_negative(const cvector4 a);
cvector4 vector4_abs(const cvector4 a);
cvector4 vector4_floor(const cvector4 a);
cvector4 vector4_ceil(const cvector4 a);
cvector4 vector4_round(const cvector4 a);
cvector4 vector4_max(const cvector4 a, const cvector4 b);
cvector4 vector4_min(const cvector4 a, const cvector4 b);
float vector4_dot(const cvector4 a, const cvector4 b);
float vector4_length_squared(const cvector4 a);
float vector4_length(const cvector4 a);
cvector4 vector4_normalize(const cvector4 a);
cvector4 vector4_slide(const cvector4 a, const cvector4 b);
cvector4 vector4_reflect(const cvector4 direction, const cvector4 normal);
float vector4_distance_to(const cvector4 a, const cvector4 b);
float vector4_distance_squared_to(const cvector4 a, const cvector4 b);
cvector4 vector4_linear_interpolation(const cvector4 a, const cvector4 b, const float p);

/* Quaternion */
cquaternion to_quaternion(const float x, const float y, const float z, const float w);
cquaternion quaternion_add(const cquaternion a, const cquaternion b);
cquaternion quaternion_subtract(const cquaternion a, const cquaternion b);
cquaternion quaternion_scale(const cquaternion a, const float scale);
cquaternion quaternion_multiply(const cquaternion a, const cquaternion b);
cquaternion quaternion_divide(const cquaternion a, const cquaternion b);
cquaternion quaternion_negative(const cquaternion a);
cquaternion quaternion_abs(const cquaternion a);
cquaternion quaternion_floor(const cquaternion a);
cquaternion quaternion_ceil(const cquaternion a);
cquaternion quaternion_round(const cquaternion a);
cquaternion quaternion_max(const cquaternion a, const cquaternion b);
cquaternion quaternion_min(const cquaternion a, const cquaternion b);
float quaternion_dot(const cquaternion a, const cquaternion b);
cquaternion quaternion_inverse(const cquaternion a);
float quaternion_length_squared(const cquaternion a);
float quaternion_length(const cquaternion a);
cquaternion quaternion_normalize(const cquaternion a);
cquaternion quaternion_conjugate(const cquaternion a);
cquaternion quaternion_axis_angle(const cvector3 a, const float angle);
cquaternion quaternion_rotation_matrix(const cmatrix m);
cquaternion quaternion_yaw_pitch_roll(const float yaw, const float pitch, const float roll);
cquaternion quaternion_linear_interpolation(const cquaternion a, const cquaternion b, const float p);

/* Matrix */
cmatrix matrix_identity(void);
cmatrix matrix_ortho(const float l, const float r, const float b, const float t, const float n, const float f);
cmatrix matrix_perspective(const float y_fov, const float aspect, const float n, const float f);
cmatrix matrix_rotation_x(const float angle);
cmatrix matrix_rotation_y(const float angle);
cmatrix matrix_rotation_z(const float angle);
cmatrix matrix_rotation_axis(const cvector3 a, const float angle);
cmatrix matrix_rotation_quaternion(const cquaternion q);
cmatrix matrix_look_at(const cvector3 pos, const cvector3 target, const cvector3 up);
cmatrix matrix_scale(const cvector3 v);
cvector3 matrix_get_scale(const cmatrix m);
cmatrix matrix_translation(const cvector3 v);
cvector3 matrix_get_translation(const cmatrix m);
cmatrix matrix_negative(const cmatrix m);
cmatrix matrix_multiply(const cmatrix m, const float s);
cmatrix matrix_multiply_matrix(const cmatrix a, const cmatrix b);
void matrix_multiply_f4(const cmatrix m, float *v);
void matrix_to_array(const cmatrix m, float *f);

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
