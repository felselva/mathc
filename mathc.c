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

#include <math.h>
#include "mathc.h"

/* Vector 2D */
cvector2 to_vector2(const float x, const float y)
{
	cvector2 result;
	result.x = x;
	result.y = y;
	return result;
}

cvector2 vector2_add(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return result;
}

cvector2 vector2_subtract(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return result;
}

cvector2 vector2_scale(const cvector2 a, const float scale)
{
	cvector2 result;
	result.x = a.x * scale;
	result.y = a.y * scale;
	return result;
}

cvector2 vector2_multiply(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	return result;
}

cvector2 vector2_divide(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	result.x = a.x / b.x;
	result.y = a.y / b.y;
	return result;
}

cvector2 vector2_negative(const cvector2 a)
{
	cvector2 result;
	result.x = -a.x;
	result.y = -a.y;
	return result;
}

cvector2 vector2_abs(const cvector2 a)
{
	cvector2 result;
	result.x = fabs(a.x);
	result.y = fabs(a.y);
	return result;
}

cvector2 vector2_floor(const cvector2 a)
{
	cvector2 result;
	result.x = floorf(a.x);
	result.y = floorf(a.y);
	return result;
}

cvector2 vector2_ceil(const cvector2 a)
{
	cvector2 result;
	result.x = ceilf(a.x);
	result.y = ceilf(a.y);
	return result;
}

cvector2 vector2_round(const cvector2 a)
{
	cvector2 result;
	result.x = roundf(a.x);
	result.y = roundf(a.y);
	return result;
}

cvector2 vector2_max(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	if (a.x > b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y > b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	return result;
}

cvector2 vector2_min(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	if (a.x < b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y < b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	return result;
}

float vector2_dot(const cvector2 a, const cvector2 b)
{
	return a.x * b.x + a.y * b.y;
}

float vector2_angle(const cvector2 a)
{
	return atan2f(a.y, a.x);
}

float vector2_length_squared(const cvector2 a)
{
	return a.x * a.x + a.y * a.y;
}

float vector2_length(const cvector2 a)
{
	return sqrtf(a.x * a.x + a.y * a.y);
}

cvector2 vector2_normalize(const cvector2 a)
{
	cvector2 result;
	float length = a.x * a.x + a.y * a.y;
	/* For better performance, only call sqrtf() if length is not 0 */
	if (length != 0.0f) {
		length = sqrtf(length);
		result.x = a.x / length;
		result.y = a.y / length;
	} else {
		result = a;
	}
	return result;
}

cvector2 vector2_slide(const cvector2 a, const cvector2 b)
{
	cvector2 result;
	const float d = vector2_dot(a, b);
	result.x = b.x - a.x * d;
	result.y = b.y - a.y * d;
	return result;
}

cvector2 vector2_reflect(const cvector2 direction, const cvector2 normal)
{
	cvector2 result;
	const float d = 2.0f * vector2_dot(direction, normal);
	result.x = direction.x - normal.x * d;
	result.y = direction.y - normal.y * d;
	return result;
}

cvector2 vector2_tangent(const cvector2 a)
{
	cvector2 result;
	result.x = -a.y;
	result.y = a.x;
	return result;
}

cvector2 vector2_rotate(const cvector2 a, const float angle)
{
	cvector2 result;
	const float cs = cosf(angle);
	const float sn = sinf(angle);
	result.x = a.x * cs - a.y * sn;
	result.y = a.x * sn + a.y * cs;
	return result;
}

float vector2_distance_to(const cvector2 a, const cvector2 b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float vector2_distance_squared_to(const cvector2 a, const cvector2 b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

cvector2 vector2_linear_interpolation(const cvector2 a, const cvector2 b, const float p)
{
	cvector2 result;
	result.x = a.x + (b.x - a.x) * p;
	result.y = a.y + (b.y - a.y) * p;
	return result;
}

/* Vector 3D */
cvector3 to_vector3(const float x, const float y, const float z)
{
	cvector3 result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

cvector3 vector3_add(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return result;
}

cvector3 vector3_subtract(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}

cvector3 vector3_scale(const cvector3 a, const float scale)
{
	cvector3 result;
	result.x = a.x * scale;
	result.y = a.y * scale;
	result.z = a.z * scale;
	return result;
}

cvector3 vector3_multiply(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return result;
}

cvector3 vector3_divide(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return result;
}

cvector3 vector3_negative(const cvector3 a)
{
	cvector3 result;
	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	return result;
}

cvector3 vector3_abs(const cvector3 a)
{
	cvector3 result;
	result.x = fabs(a.x);
	result.y = fabs(a.y);
	result.z = fabs(a.z);
	return result;
}

cvector3 vector3_floor(const cvector3 a)
{
	cvector3 result;
	result.x = floorf(a.x);
	result.y = floorf(a.y);
	result.z = floorf(a.z);
	return result;
}

cvector3 vector3_ceil(const cvector3 a)
{
	cvector3 result;
	result.x = ceilf(a.x);
	result.y = ceilf(a.y);
	result.z = ceilf(a.z);
	return result;
}

cvector3 vector3_round(const cvector3 a)
{
	cvector3 result;
	result.x = roundf(a.x);
	result.y = roundf(a.y);
	result.z = roundf(a.z);
	return result;
}

cvector3 vector3_max(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	if (a.x > b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y > b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z > b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	return result;
}

cvector3 vector3_min(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	if (a.x < b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y < b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z < b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	return result;
}

float vector3_dot(const cvector3 a, const cvector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

cvector3 vector3_cross(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}

float vector3_length_squared(const cvector3 a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z;
}

float vector3_length(const cvector3 a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

cvector3 vector3_normalize(const cvector3 a)
{
	cvector3 result;
	float length = a.x * a.x + a.y * a.y + a.z * a.z;
	/* For better performance, only call sqrtf() if length is not 0 */
	if (length != 0) {
		length = sqrtf(length);
		result.x = a.x / length;
		result.y = a.y / length;
		result.z = a.z / length;
	} else {
		result = a;
	}
	return result;
}

cvector3 vector3_slide(const cvector3 a, const cvector3 b)
{
	cvector3 result;
	const float d = vector3_dot(a, b);
	result.x = b.x - a.x * d;
	result.y = b.y - a.y * d;
	result.z = b.z - a.z * d;
	return result;
}

cvector3 vector3_reflect(const cvector3 direction, const cvector3 normal)
{
	cvector3 result;
	const float d = 2.0f * vector3_dot(direction, normal);
	result.x = direction.x - normal.x * d;
	result.y = direction.y - normal.y * d;
	result.z = direction.z - normal.z * d;
	return result;
}

float vector3_distance_to(const cvector3 a, const cvector3 b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

float vector3_distance_squared_to(const cvector3 a, const cvector3 b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

cvector3 vector3_linear_interpolation(const cvector3 a, const cvector3 b, const float p)
{
	cvector3 result;
	result.x = a.x + (b.x - a.x) * p;
	result.y = a.y + (b.y - a.y) * p;
	result.z = a.z + (b.z - a.z) * p;
	return result;
}

/* Vector 4D */
cvector4 to_vector4(const float x, const float y, const float z, const float w)
{
	cvector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

cvector4 vector4_add(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return result;
}

cvector4 vector4_subtract(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return result;
}

cvector4 vector4_scale(const cvector4 a, const float scale)
{
	cvector4 result;
	result.x = a.x * scale;
	result.y = a.y * scale;
	result.z = a.z * scale;
	result.w = a.w * scale;
	return result;
}

cvector4 vector4_multiply(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	result.w = a.w * b.w;
	return result;
}

cvector4 vector4_divide(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	result.w = a.w * b.w;
	return result;
}

cvector4 vector4_negative(const cvector4 a)
{
	cvector4 result;
	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return result;
}

cvector4 vector4_abs(const cvector4 a)
{
	cvector4 result;
	result.x = fabs(a.x);
	result.y = fabs(a.y);
	result.z = fabs(a.z);
	result.w = fabs(a.w);
	return result;
}

cvector4 vector4_floor(const cvector4 a)
{
	cvector4 result;
	result.x = floorf(a.x);
	result.y = floorf(a.y);
	result.z = floorf(a.z);
	result.w = floorf(a.w);
	return result;
}

cvector4 vector4_ceil(const cvector4 a)
{
	cvector4 result;
	result.x = ceilf(a.x);
	result.y = ceilf(a.y);
	result.z = ceilf(a.z);
	result.w = ceilf(a.w);
	return result;
}

cvector4 vector4_round(const cvector4 a)
{
	cvector4 result;
	result.x = roundf(a.x);
	result.y = roundf(a.y);
	result.z = roundf(a.z);
	result.w = roundf(a.w);
	return result;
}

cvector4 vector4_max(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	if (a.x > b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y > b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z > b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	if (a.w > b.w) {
		result.w = a.w;
	} else {
		result.w = b.w;
	}
	return result;
}

cvector4 vector4_min(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	if (a.x < b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y < b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z < b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	if (a.w < b.w) {
		result.w = a.w;
	} else {
		result.w = b.w;
	}
	return result;
}

float vector4_dot(const cvector4 a, const cvector4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float vector4_length_squared(const cvector4 a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

float vector4_length(const cvector4 a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

cvector4 vector4_normalize(const cvector4 a)
{
	cvector4 result;
	float length = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
	/* For better performance, only call sqrtf() if length is not 0 */
	if (length != 0) {
		length = sqrtf(length);
		result.x = a.x / length;
		result.y = a.y / length;
		result.z = a.z / length;
		result.w = a.w / length;
	} else {
		result = a;
	}
	return result;
}

cvector4 vector4_slide(const cvector4 a, const cvector4 b)
{
	cvector4 result;
	const float d = vector4_dot(a, b);
	result.x = b.x - a.x * d;
	result.y = b.y - a.y * d;
	result.z = b.z - a.z * d;
	result.w = b.w - a.w * d;
	return result;
}

cvector4 vector4_reflect(const cvector4 direction, const cvector4 normal)
{
	cvector4 result;
	const float d = 2.0f * vector4_dot(direction, normal);
	result.x = direction.x - normal.x * d;
	result.y = direction.y - normal.y * d;
	result.z = direction.z - normal.z * d;
	result.w = direction.w - normal.w * d;
	return result;
}

float vector4_distance_to(const cvector4 a, const cvector4 b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) + (a.w - b.w) * (a.w - b.w));
}

float vector4_distance_squared_to(const cvector4 a, const cvector4 b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) + (a.w - b.w) * (a.w - b.w);
}

cvector4 vector4_linear_interpolation(const cvector4 a, const cvector4 b, const float p)
{
	cvector4 result;
	result.x = a.x + (b.x - a.x) * p;
	result.y = a.y + (b.y - a.y) * p;
	result.z = a.z + (b.z - a.z) * p;
	result.w = a.w + (b.w - a.w) * p;
	return result;
}

/* Quaternion */
cquaternion to_quaternion(const float x, const float y, const float z, const float w)
{
	cquaternion result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

cquaternion quaternion_add(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return result;
}

cquaternion quaternion_subtract(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.y = a.z - b.z;
	result.y = a.w - b.w;
	return result;
}

cquaternion quaternion_scale(const cquaternion a, const float scale)
{
	cquaternion result;
	result.x = a.x * scale;
	result.y = a.y * scale;
	result.z = a.z * scale;
	result.w = a.w * scale;
	return result;
}

cquaternion quaternion_multiply(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	const float u = (a.y * b.z) - (a.z * b.y);
	const float i = (a.z * b.x) - (a.x * b.z);
	const float o = (a.x * b.y) - (a.y * b.x);
	const float p = ((a.x * b.x) + (a.y * b.y)) + (a.z * b.z);
	result.x = ((a.x * b.w) + (b.x * a.w)) + u;
	result.y = ((a.y * b.w) + (b.y * a.w)) + i;
	result.z = ((a.z * b.w) + (b.z * a.w)) + o;
	result.w = (a.w * b.w) - p;
	return result;
}

cquaternion quaternion_divide(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	const float x = a.x;
	const float y = a.y;
	const float z = a.z;
	const float w = a.w;
	float n1 = b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w;
	float n2 = 1.0f / n1;
	float n3 = -b.x * n2;
	float n4 = -b.y * n2;
	float n5 = -b.z * n2;
	float n6 = b.w * n2;
	float n7 = y * n5 - z * n4;
	float n8 = z * n3 - x * n5;
	float n9 = x * n4 - y * n3;
	float n10 = x * n3 + y * n4 + z * n5;
	result.x = x * n6 + n3 * w + n7;
	result.y = y * n6 + n4 * w + n8;
	result.z = z * n6 + n5 * w + n9;
	result.w = w * n6 - n10;
	return result;
}

cquaternion quaternion_negative(const cquaternion a)
{
	cquaternion result;
	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return result;
}

cquaternion quaternion_abs(const cquaternion a)
{
	cquaternion result;
	result.x = fabs(a.x);
	result.y = fabs(a.y);
	result.z = fabs(a.z);
	result.w = fabs(a.w);
	return result;
}

cquaternion quaternion_floor(const cquaternion a)
{
	cquaternion result;
	result.x = floorf(a.x);
	result.y = floorf(a.y);
	result.z = floorf(a.z);
	result.w = floorf(a.w);
	return result;
}

cquaternion quaternion_ceil(const cquaternion a)
{
	cquaternion result;
	result.x = ceilf(a.x);
	result.y = ceilf(a.y);
	result.z = ceilf(a.z);
	result.w = ceilf(a.w);
	return result;
}

cquaternion quaternion_round(const cquaternion a)
{
	cquaternion result;
	result.x = roundf(a.x);
	result.y = roundf(a.y);
	result.z = roundf(a.z);
	result.w = roundf(a.w);
	return result;
}

cquaternion quaternion_max(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	if (a.x > b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y > b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z > b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	if (a.w > b.w) {
		result.w = a.w;
	} else {
		result.w = b.w;
	}
	return result;
}

cquaternion quaternion_min(const cquaternion a, const cquaternion b)
{
	cquaternion result;
	if (a.x < b.x) {
		result.x = a.x;
	} else {
		result.x = b.x;
	}
	if (a.y < b.y) {
		result.y = a.y;
	} else {
		result.y = b.y;
	}
	if (a.z < b.z) {
		result.z = a.z;
	} else {
		result.z = b.z;
	}
	if (a.w < b.w) {
		result.w = a.w;
	} else {
		result.w = b.w;
	}
	return result;
}

float quaternion_dot(const cquaternion a, const cquaternion b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

cquaternion quaternion_inverse(const cquaternion a)
{
	cquaternion result;
	float n1 = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
	float n2 = 1.0f / n1;
	result.x = -a.x * n2;
	result.y = -a.y * n2;
	result.z = -a.z * n2;
	result.w = a.w * n2;
	return result;
}

float quaternion_length_squared(const cquaternion a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

float quaternion_length(const cquaternion a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

cquaternion quaternion_normalize(const cquaternion a)
{
	cquaternion result;
	const float n = 1.0f / quaternion_length(a);
	result.x = a.x * n;
	result.y = a.y * n;
	result.z = a.z * n;
	result.w = a.w * n;
	return result;
}

cquaternion quaternion_conjugate(const cquaternion a)
{
	cquaternion result;
	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = a.w;
	return result;
}

cquaternion quaternion_axis_angle(const cvector3 a, const float angle)
{
	cquaternion result;
	const float half = angle * 0.5f;
	const float s = sinf(half);
	const float c = cosf(half);
	result.x = a.x * s;
	result.y = a.y * s;
	result.z = a.z * s;
	result.w = c;
	return result;
}

cquaternion quaternion_rotation_matrix(const cmatrix m)
{
	cquaternion result;
	float sr;
	float half;
	const float scale = m.m11 + m.m22 + m.m33;
	if (scale > 0.0f) {
		sr = sqrtf(scale + 1.0f);
		result.w = sr * 0.5f;
		sr = 0.5f / sr;
		result.x = (m.m23 - m.m32) * sr;
		result.y = (m.m31 - m.m13) * sr;
		result.z = (m.m12 - m.m21) * sr;
	} else if ((m.m11 >= m.m22) && (m.m11 >= m.m33)) {
		sr = sqrtf(1.0f + m.m11 - m.m22 - m.m33);
		half = 0.5f / sr;
		result.x = 0.5f * sr;
		result.y = (m.m12 + m.m21) * half;
		result.z = (m.m13 + m.m31) * half;
		result.w = (m.m23 - m.m32) * half;
	} else if (m.m22 > m.m33) {
		sr = sqrtf(1.0f + m.m22 - m.m11 - m.m33);
		half = 0.5f / sr;
		result.x = (m.m21 + m.m12) * half;
		result.y = 0.5f * sr;
		result.z = (m.m32 + m.m23) * half;
		result.w = (m.m31 - m.m13) * half;
	} else {
		sr = sqrtf(1.0f + m.m33 - m.m11 - m.m22);
		half = 0.5f / sr;
		result.x = (m.m31 + m.m13) * half;
		result.y = (m.m32 + m.m23) * half;
		result.z = 0.5f * sr;
		result.w = (m.m12 - m.m21) * half;
	}
	return result;
}

cquaternion quaternion_yaw_pitch_roll(const float yaw, const float pitch, const float roll)
{
	cquaternion result;
	const float half_roll = roll * 0.5f;
	const float half_pitch = pitch * 0.5f;
	const float half_yaw = yaw * 0.5f;
	const float sin_roll = sinf(half_roll);
	const float cos_roll = cosf(half_roll);
	const float sin_pitch = sinf(half_pitch);
	const float cos_pitch = cosf(half_pitch);
	const float sin_yaw = sinf(half_yaw);
	const float cos_yaw = cosf(half_yaw);
	result.x = (cos_yaw * sin_pitch * cos_roll) + (sin_yaw * cos_pitch * sin_roll);
	result.y = (sin_yaw * cos_pitch * cos_roll) - (cos_yaw * sin_pitch * sin_roll);
	result.z = (cos_yaw * cos_pitch * sin_roll) - (sin_yaw * sin_pitch * cos_roll);
	result.w = (cos_yaw * cos_pitch * cos_roll) + (sin_yaw * sin_pitch * sin_roll);
	return result;
}

cquaternion quaternion_linear_interpolation(const cquaternion a, const cquaternion b, const float p)
{
	cquaternion result;
	float n1 = 1.0f - p;
	float n2;
	float n3;
	float n4 = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	if (n4 >= 0.0f) {
		result.x = (n1 * a.x) + (p * b.x);
		result.y = (n1 * a.y) + (p * b.y);
		result.z = (n1 * a.z) + (p * b.z);
		result.w = (n1 * a.w) + (p * b.w);
	} else {
		result.x = (n1 * a.x) - (p * b.x);
		result.y = (n1 * a.y) - (p * b.y);
		result.z = (n1 * a.z) - (p * b.z);
		result.w = (n1 * a.w) - (p * b.w);
	}
	n3 = result.x * result.x + result.y * result.y + result.z * result.z + result.w * result.w;
	n2 = 1.0f / sqrtf(n3);
	result.x = result.x * n2;
	result.y = result.y * n2;
	result.z = result.z * n2;
	result.w = result.w * n2;
	return result;
}

/* Matrices */
cmatrix matrix_identity(void)
{
	cmatrix result = {0};
	result.m11 = 1.0f;
	result.m22 = 1.0f;
	result.m33 = 1.0f;
	result.m44 = 1.0f;
	return result;
}

cmatrix matrix_ortho(const float l, const float r, const float b, const float t, const float n, const float f)
{
	cmatrix result = matrix_identity();
	result.m11 = 2.0f / (r - l);
	result.m22 = 2.0f / (b - t);
	result.m33 = 1.0f / (n - f);
	result.m41 = (l + r) / (l - r);
	result.m42 = (t + b) / (b - t);
	result.m43 = n / (n - f);
	return result;
}

cmatrix matrix_perspective(const float y_fov, const float aspect, const float n, const float f)
{
	cmatrix result = matrix_identity();
	/* Right-handed */
	const float a = 1.0f / tanf(y_fov * 0.5f);
	result.m11 = a / aspect;
	result.m22 = a;
	result.m33 = f / (n - f);
	result.m34 = -1.0f;
	result.m43 = (n * f) / (n - f);
	return result;
}

cmatrix matrix_rotation_x(const float angle)
{
	cmatrix result = matrix_identity();
	const float c = cosf(angle);
	const float s = sinf(angle);
	result.m22 = c;
	result.m23 = s;
	result.m32 = -s;
	result.m33 = c;
	return result;
}

cmatrix matrix_rotation_y(const float angle)
{
	cmatrix result = matrix_identity();
	const float c = cosf(angle);
	const float s = sinf(angle);
	result.m11 = c;
	result.m13 = -s;
	result.m31 = s;
	result.m33 = c;
	return result;
}

cmatrix matrix_rotation_z(const float angle)
{
	cmatrix result = matrix_identity();
	const float c = cosf(angle);
	const float s = sinf(angle);
	result.m11 = c;
	result.m12 = s;
	result.m21 = -s;
	result.m22 = c;
	return result;
}

cmatrix matrix_rotation_axis(const cvector3 a, const float angle)
{
	cmatrix result = matrix_identity();
	const float c = cosf(angle);
	const float s = sinf(angle);
	const float n1 = a.x * a.x;
	const float n2 = a.y * a.y;
	const float n3 = a.z * a.z;
	const float n4 = a.x * a.y;
	const float n5 = a.x * a.z;
	const float n6 = a.y * a.z;
	result.m11 = n1 + (c * (1.0f - n1));
	result.m12 = (n4 - (c * n4)) + (s * a.z);
	result.m13 = (n5 - (c * n5)) - (s * a.y);
	result.m21 = (n4 - (c * n4)) - (s * a.z);
	result.m22 = n2 + (c * (1.0f - n2));
	result.m23 = (n6 - (c * n6)) + (s * a.x);
	result.m31 = (n5 - (c * n5)) + (s * a.y);
	result.m32 = (n6 - (c * n6)) - (s * a.x);
	result.m33 = n3 + (c * (1.0f - n3));
	return result;
}

cmatrix matrix_rotation_quaternion(const cquaternion q)
{
	cmatrix result = matrix_identity();
	const float n9 = q.x * q.x;
	const float n8 = q.y * q.y;
	const float n7 = q.z * q.z;
	const float n6 = q.x * q.y;
	const float n5 = q.z * q.w;
	const float n4 = q.z * q.x;
	const float n3 = q.y * q.w;
	const float n2 = q.y * q.z;
	const float n1 = q.x * q.w;
	result.m11 = 1.0f - 2.0f * (n8 + n7);
	result.m12 = 2.0f * (n6 + n5);
	result.m13 = 2.0f * (n4 - n3);
	result.m21 = 2.0f * (n6 - n5);
	result.m22 = 1.0f - 2.0f * (n7 + n9);
	result.m23 = 2.0f * (n2 + n1);
	result.m31 = 2.0f * (n4 + n3);
	result.m32 = 2.0f * (n2 - n1);
	result.m33 = 1.0f - 2.0f * (n8 + n9);
	return result;
}

cmatrix matrix_look_at(const cvector3 pos, const cvector3 target, const cvector3 up)
{
	cmatrix result = matrix_identity();
	cvector3 v1 = vector3_normalize(vector3_subtract(pos, target));
	cvector3 v2 = vector3_normalize(vector3_cross(up, v1));
	cvector3 v3 = vector3_cross(v1, v2);
	result.m11 = v2.x;
	result.m12 = v3.x;
	result.m13 = v1.x;
	result.m21 = v2.y;
	result.m22 = v3.y;
	result.m23 = v1.y;
	result.m31 = v2.z;
	result.m32 = v3.z;
	result.m33 = v1.z;
	result.m41 = -vector3_dot(v2, pos);
	result.m42 = -vector3_dot(v3, pos);
	result.m43 = -vector3_dot(v1, pos);
	return result;
}

cmatrix matrix_scale(const cvector3 v)
{
	cmatrix result = matrix_identity();
	result.m11 = v.x;
	result.m22 = v.y;
	result.m33 = v.z;
	return result;
}

cvector3 matrix_get_scale(const cmatrix m)
{
	cvector3 result;
	result.x = m.m11;
	result.y = m.m22;
	result.z = m.m33;
	return result;
}

cmatrix matrix_translation(const cvector3 v)
{
	cmatrix result = matrix_identity();
	result.m14 = v.x;
	result.m24 = v.y;
	result.m34 = v.z;
	return result;
}

cvector3 matrix_get_translation(const cmatrix m)
{
	cvector3 result;
	result.x = m.m14;
	result.y = m.m24;
	result.z = m.m34;
	return result;
}

cmatrix matrix_negative(const cmatrix m)
{
	cmatrix result;
	result.m11 = -m.m11;
	result.m12 = -m.m12;
	result.m13 = -m.m13;
	result.m14 = -m.m14;
	result.m21 = -m.m21;
	result.m22 = -m.m22;
	result.m23 = -m.m23;
	result.m24 = -m.m24;
	result.m31 = -m.m31;
	result.m32 = -m.m32;
	result.m33 = -m.m33;
	result.m34 = -m.m34;
	result.m41 = -m.m41;
	result.m42 = -m.m42;
	result.m43 = -m.m43;
	result.m44 = -m.m44;
	return result;
}

cmatrix matrix_multiply(const cmatrix m, const float s)
{
	cmatrix result;
	result.m11 = m.m11 * s;
	result.m12 = m.m12 * s;
	result.m13 = m.m13 * s;
	result.m14 = m.m14 * s;
	result.m21 = m.m21 * s;
	result.m22 = m.m22 * s;
	result.m23 = m.m23 * s;
	result.m24 = m.m24 * s;
	result.m31 = m.m31 * s;
	result.m32 = m.m32 * s;
	result.m33 = m.m33 * s;
	result.m34 = m.m34 * s;
	result.m41 = m.m41 * s;
	result.m42 = m.m42 * s;
	result.m43 = m.m43 * s;
	result.m44 = m.m44 * s;
	return result;
}

cmatrix matrix_multiply_matrix(const cmatrix a, const cmatrix b)
{
	cmatrix result;
	result.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31 + a.m14 * b.m41;
	result.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32 + a.m14 * b.m42;
	result.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33 + a.m14 * b.m43;
	result.m14 = a.m11 * b.m14 + a.m12 * b.m24 + a.m13 * b.m34 + a.m14 * b.m44;
	result.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31 + a.m24 * b.m41;
	result.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32 + a.m24 * b.m42;
	result.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33 + a.m24 * b.m43;
	result.m24 = a.m21 * b.m14 + a.m22 * b.m24 + a.m23 * b.m34 + a.m24 * b.m44;
	result.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31 + a.m34 * b.m41;
	result.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32 + a.m34 * b.m42;
	result.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 + a.m34 * b.m43;
	result.m34 = a.m31 * b.m14 + a.m32 * b.m24 + a.m33 * b.m34 + a.m34 * b.m44;
	result.m41 = a.m41 * b.m11 + a.m42 * b.m21 + a.m43 * b.m31 + a.m44 * b.m41;
	result.m42 = a.m41 * b.m12 + a.m42 * b.m22 + a.m43 * b.m32 + a.m44 * b.m42;
	result.m43 = a.m41 * b.m13 + a.m42 * b.m23 + a.m43 * b.m33 + a.m44 * b.m43;
	result.m44 = a.m41 * b.m14 + a.m42 * b.m24 + a.m43 * b.m34 + a.m44 * b.m44;
	return result;
}

void matrix_multiply_f4(const cmatrix m, float *v)
{
	const float v0 = v[0];
	const float v1 = v[1];
	const float v2 = v[2];
	const float v3 = v[3];
	v[0] = (m.m11 * v0) + (m.m12 * v1) + (m.m13 * v2) + (m.m14 * v3);
	v[1] = (m.m21 * v0) + (m.m22 * v1) + (m.m23 * v2) + (m.m24 * v3);
	v[2] = (m.m31 * v0) + (m.m32 * v1) + (m.m33 * v2) + (m.m34 * v3);
	v[3] = (m.m41 * v0) + (m.m42 * v1) + (m.m43 * v2) + (m.m44 * v3);
}

void matrix_to_array(const cmatrix m, float *f)
{
	f[0] = m.m11;
	f[1] = m.m12;
	f[2] = m.m13;
	f[3] = m.m14;
	f[4] = m.m21;
	f[5] = m.m22;
	f[6] = m.m23;
	f[7] = m.m24;
	f[8] = m.m31;
	f[9] = m.m32;
	f[10] = m.m33;
	f[11] = m.m34;
	f[12] = m.m41;
	f[13] = m.m42;
	f[14] = m.m43;
	f[15] = m.m44;
}

/* Easing functions */
float quadratic_ease_in(const float p)
{
	return p * p;
}

float quadratic_ease_out(const float p)
{
	return -(p * (p - 2.0));
}

float quadratic_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 2.0 * p * p;
	} else {
		f = (-2.0 * p * p) + (4.0 * p) - 1.0;
	}
	return f;
}

float cubic_ease_in(const float p)
{
	return p * p * p;
}

float cubic_ease_out(const float p)
{
	float f = (p - 1);
	return f * f * f + 1;
}

float cubic_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 4.0 * p * p * p;
	} else {
		f = ((2.0 * p) - 2.0);
		f = 0.5 * f * f * f + 1.0;
	}
	return f;
}

float quartic_ease_in(const float p)
{
	return p * p * p * p;
}

float quartic_ease_out(const float p)
{
	float f = (p - 1.0);
	return f * f * f * (1.0 - p) + 1.0;
}

float quartic_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 8.0 * p * p * p * p;
	} else {
		f = (p - 1);
		f = -8.0 * f * f * f * f + 1.0;
	}
	return f;
}

float quintic_ease_in(const float p)
{
	return p * p * p * p * p;
}

float quintic_ease_out(const float p)
{
	float f = (p - 1.0);
	return f * f * f * f * f + 1.0;
}

float quintic_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 16.0 * p * p * p * p * p;
	} else {
		f = ((2.0 * p) - 2.0);
		f =  0.5 * f * f * f * f * f + 1.0;
	}
	return f;
}

float sine_ease_in(const float p)
{
	return sinf((p - 1.0) * M_PI_2) + 1.0;
}

float sine_ease_out(const float p)
{
	return sinf(p * M_PI_2);
}

float sine_ease_in_out(const float p)
{
	return 0.5 * (1.0 - cosf(p * M_PI));
}

float circular_ease_in(const float p)
{
	return 1.0 - sqrtf(1.0 - (p * p));
}

float circular_ease_out(const float p)
{
	return sqrtf((2.0 - p) * p);
}

float circular_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 0.5 * (1.0 - sqrtf(1.0 - 4.0 * (p * p)));
	} else {
		f = 0.5 * (sqrtf(-((2.0 * p) - 3.0) * ((2.0 * p) - 1.0)) + 1.0);
	}
	return f;
}

float exponential_ease_in(const float p)
{
	float f = p;
	if (p != 0.0) {
		f = powf(2.0, 10.0 * (p - 1.0));
	}
	return f;
}

float exponential_ease_out(const float p)
{
	float f = p;
	if (p != 1.0) {
		f = 1 - powf(2.0, -10.0 * p);
	}
	return f;
}

float exponential_ease_in_out(const float p)
{
	float f = p;
	if (p == 0.0 || p == 1.0) {
		f = p;
	} else if (p < 0.5) {
		f = 0.5 * powf(2.0, (20.0 * p) - 10.0);
	} else {
		f = -0.5 * powf(2.0, (-20.0 * p) + 10.0) + 1.0;
	}
	return f;
}

float elastic_ease_in(const float p)
{
	return sinf(13.0 * M_PI_2 * p) * powf(2.0, 10.0 * (p - 1.0));
}

float elastic_ease_out(const float p)
{
	return sinf(-13.0 * M_PI_2 * (p + 1.0)) * powf(2.0, -10.0 * p) + 1.0;
}

float elastic_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 0.5 * sinf(13.0 * M_PI_2 * (2.0 * p)) * powf(2.0, 10.0 * ((2.0 * p) - 1.0));
	} else {
		f = 0.5 * (sinf(-13.0 * M_PI_2 * ((2.0 * p - 1.0) + 1.0)) * powf(2.0, -10.0 * (2.0 * p - 1.0)) + 2.0);
	}
	return f;
}

float back_ease_in(const float p)
{
	return p * p * p - p * sinf(p * M_PI);
}

float back_ease_out(const float p)
{
	float f = (1.0 - p);
	return 1.0 - (f * f * f - f * sinf(f * M_PI));
}

float back_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 2.0 * p;
		f = 0.5 * (f * f * f - f * sinf(f * M_PI));
	} else {
		f = (1.0 - (2.0 * p - 1));
		f = 0.5 * (1.0 - (f * f * f - f * sinf(f * M_PI))) + 0.5;
	}
	return f;
}

float bounce_ease_in(const float p)
{
	return 1.0 - bounce_ease_out(1.0 - p);
}

float bounce_ease_out(const float p)
{
	float f = 0.0;
	if (p < 4 / 11.0) {
		f = (121 * p * p) / 16.0;
	} else if (p < 8 / 11.0) {
		f = (363 / 40.0 * p * p) - (99 / 10.0 * p) + 17 / 5.0;
	} else if (p < 9 / 10.0) {
		f = (4356 / 361.0 * p * p) - (35442 / 1805.0 * p) + 16061 / 1805.0;
	} else {
		f = (54 / 5.0 * p * p) - (513 / 25.0 * p) + 268 / 25.0;
	}
	return f;
}

float bounce_ease_in_out(const float p)
{
	float f = 0.0;
	if (p < 0.5) {
		f = 0.5 * bounce_ease_in(p * 2.0);
	} else {
		f = 0.5 * bounce_ease_out(p * 2.0 - 1.0) + 0.5;
	}
	return f;
}
