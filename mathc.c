/*
Copyright © 2018 Felipe Ferreira da Silva

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

#include "mathc.h"

#if defined(MATHC_USE_FLOATING_POINT)
bool nearly_equal(mfloat_t a, mfloat_t b, mfloat_t epsilon)
{
	bool result = false;
	if (a == b) {
		result = true;
	} else if (MFABS(a - b) <= epsilon) {
		result = true;
	}
	return result;
}

mfloat_t to_radians(mfloat_t degrees)
{
	return MRADIANS(degrees);
}

mfloat_t to_degrees(mfloat_t radians)
{
	return MDEGREES(radians);
}
#endif

#if defined(MATHC_USE_INT)
bool vec2i_is_zero(mint_t *vec2i0)
{
	return vec2i0[0] == 0 && vec2i0[1] == 0;
}

bool vec2i_is_equal(mint_t *vec2i0, mint_t *vec2i1)
{
	return vec2i0[0] == vec2i1[0] && vec2i0[1] == vec2i1[1];
}

mint_t *vec2i(mint_t *result, mint_t x, mint_t y)
{
	result[0] = x;
	result[1] = y;
	return result;
}

mint_t *vec2i_assign(mint_t *result, mint_t *vec2i0)
{
	result[0] = vec2i0[0];
	result[1] = vec2i0[1];
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec2i_assign_vec2(mint_t *result, mfloat_t *vec20)
{
	result[0] = vec20[0];
	result[1] = vec20[1];
	return result;
}
#endif

mint_t *vec2i_zero(mint_t *result)
{
	result[0] = 0;
	result[1] = 0;
	return result;
}

mint_t *vec2i_one(mint_t *result)
{
	result[0] = 1;
	result[1] = 1;
	return result;
}

mint_t *vec2i_sign(mint_t *result, mint_t *vec2i0)
{
	if (vec2i0[0] > 0) {
		result[0] = 1;
	} else if (vec2i0[0] < 0) {
		result[0] = -1;
	} else {
		result[0] = 0;
	}
	if (vec2i0[1] > 0) {
		result[1] = 1;
	} else if (vec2i0[1] < 0) {
		result[1] = -1;
	} else {
		result[1] = 0;
	}
	return result;
}

mint_t *vec2i_add(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	result[0] = vec2i0[0] + vec2i1[0];
	result[1] = vec2i0[1] + vec2i1[1];
	return result;
}

mint_t *vec2i_add_i(mint_t *result, mint_t *vec2i0, mint_t i)
{
	result[0] = vec2i0[0] + i;
	result[1] = vec2i0[1] + i;
	return result;
}

mint_t *vec2i_subtract(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	result[0] = vec2i0[0] - vec2i1[0];
	result[1] = vec2i0[1] - vec2i1[1];
	return result;
}

mint_t *vec2i_subtract_i(mint_t *result, mint_t *vec2i0, mint_t i)
{
	result[0] = vec2i0[0] - i;
	result[1] = vec2i0[1] - i;
	return result;
}

mint_t *vec2i_multiply(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	result[0] = vec2i0[0] * vec2i1[0];
	result[1] = vec2i0[1] * vec2i1[1];
	return result;
}

mint_t *vec2i_multiply_i(mint_t *result, mint_t *vec2i0, mint_t i)
{
	result[0] = vec2i0[0] * i;
	result[1] = vec2i0[1] * i;
	return result;
}

mint_t *vec2i_divide(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	result[0] = vec2i0[0] / vec2i1[0];
	result[1] = vec2i0[1] / vec2i1[1];
	return result;
}

mint_t *vec2i_divide_i(mint_t *result, mint_t *vec2i0, mint_t i)
{
	result[0] = vec2i0[0] / i;
	result[1] = vec2i0[1] / i;
	return result;
}

mint_t *vec2i_snap(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	result[0] = (vec2i0[0] / vec2i1[0]) * vec2i1[0];
	result[1] = (vec2i0[1] / vec2i1[1]) * vec2i1[1];
	return result;
}

mint_t *vec2i_snap_i(mint_t *result, mint_t *vec2i0, mint_t i)
{
	result[0] = (vec2i0[0] / i) * i;
	result[1] = (vec2i0[1] / i) * i;
	return result;
}

mint_t *vec2i_negative(mint_t *result, mint_t *vec2i0)
{
	result[0] = -vec2i0[0];
	result[1] = -vec2i0[1];
	return result;
}

mint_t *vec2i_abs(mint_t *result, mint_t *vec2i0)
{
	result[0] = vec2i0[0];
	if (result[0] < 0) {
		result[0] = -result[0];
	}
	result[1] = vec2i0[1];
	if (result[1] < 0) {
		result[1] = -result[1];
	}
	return result;
}

mint_t *vec2i_max(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	if (vec2i0[0] > vec2i1[0]) {
		result[0] = vec2i0[0];
	} else {
		result[0] = vec2i1[0];
	}
	if (vec2i0[1] > vec2i1[1]) {
		result[1] = vec2i0[1];
	} else {
		result[1] = vec2i1[1];
	}
	return result;
}

mint_t *vec2i_min(mint_t *result, mint_t *vec2i0, mint_t *vec2i1)
{
	if (vec2i0[0] < vec2i1[0]) {
		result[0] = vec2i0[0];
	} else {
		result[0] = vec2i1[0];
	}
	if (vec2i0[1] < vec2i1[1]) {
		result[1] = vec2i0[1];
	} else {
		result[1] = vec2i1[1];
	}
	return result;
}

mint_t *vec2i_clamp(mint_t *result, mint_t *vec2i0, mint_t *vec2i1, mint_t *vec2i2)
{
	vec2i_min(result, vec2i0, vec2i1);
	vec2i_max(result, vec2i0, vec2i2);
	return result;
}

mint_t *vec2i_tangent(mint_t *result, mint_t *vec2i0)
{
	mint_t a0 = vec2i0[0];
	mint_t a1 = vec2i0[1];
	result[0] = a1;
	result[1] = -a0;
	return result;
}

bool vec3i_is_zero(mint_t *vec3i0)
{
	return vec3i0[0] == 0 && vec3i0[1] == 0;
}

bool vec3i_is_equal(mint_t *vec3i0, mint_t *vec3i1)
{
	return vec3i0[0] == vec3i1[0] && vec3i0[1] == vec3i1[1] && vec3i0[2] == vec3i1[2];
}

mint_t *vec3i(mint_t *result, mint_t x, mint_t y, mint_t z)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	return result;
}

mint_t *vec3i_assign(mint_t *result, mint_t *vec3i0)
{
	result[0] = vec3i0[0];
	result[1] = vec3i0[1];
	result[2] = vec3i0[2];
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec3i_assign_vec3(mint_t *result, mfloat_t *vec30)
{
	result[0] = vec30[0];
	result[1] = vec30[1];
	result[2] = vec30[2];
	return result;
}
#endif

mint_t *vec3i_zero(mint_t *result)
{
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	return result;
}

mint_t *vec3i_one(mint_t *result)
{
	result[0] = 1;
	result[1] = 1;
	result[2] = 1;
	return result;
}

mint_t *vec3i_sign(mint_t *result, mint_t *vec3i0)
{
	if (vec3i0[0] > 0) {
		result[0] = 1;
	} else if (vec3i0[0] < 0) {
		result[0] = -1;
	} else {
		result[0] = 0;
	}
	if (vec3i0[1] > 0) {
		result[1] = 1;
	} else if (vec3i0[1] < 0) {
		result[1] = -1;
	} else {
		result[1] = 0;
	}
	if (vec3i0[2] > 0) {
		result[2] = 1;
	} else if (vec3i0[2] < 0) {
		result[2] = -1;
	} else {
		result[2] = 0;
	}
	return result;
}

mint_t *vec3i_add(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	result[0] = vec3i0[0] + vec3i1[0];
	result[1] = vec3i0[1] + vec3i1[1];
	result[2] = vec3i0[2] + vec3i1[2];
	return result;
}

mint_t *vec3i_add_i(mint_t *result, mint_t *vec3i0, mint_t i)
{
	result[0] = vec3i0[0] + i;
	result[1] = vec3i0[1] + i;
	result[2] = vec3i0[2] + i;
	return result;
}

mint_t *vec3i_subtract(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	result[0] = vec3i0[0] - vec3i1[0];
	result[1] = vec3i0[1] - vec3i1[1];
	result[2] = vec3i0[2] - vec3i1[2];
	return result;
}

mint_t *vec3i_subtract_i(mint_t *result, mint_t *vec3i0, mint_t i)
{
	result[0] = vec3i0[0] - i;
	result[1] = vec3i0[1] - i;
	result[2] = vec3i0[2] - i;
	return result;
}

mint_t *vec3i_multiply(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	result[0] = vec3i0[0] * vec3i1[0];
	result[1] = vec3i0[1] * vec3i1[1];
	result[2] = vec3i0[2] * vec3i1[2];
	return result;
}

mint_t *vec3i_multiply_i(mint_t *result, mint_t *vec3i0, mint_t i)
{
	result[0] = vec3i0[0] * i;
	result[1] = vec3i0[1] * i;
	result[2] = vec3i0[2] * i;
	return result;
}

mint_t *vec3i_divide(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	result[0] = vec3i0[0] / vec3i1[0];
	result[1] = vec3i0[1] / vec3i1[1];
	result[2] = vec3i0[2] / vec3i1[2];
	return result;
}

mint_t *vec3i_divide_i(mint_t *result, mint_t *vec3i0, mint_t i)
{
	result[0] = vec3i0[0] / i;
	result[1] = vec3i0[1] / i;
	result[2] = vec3i0[2] / i;
	return result;
}

mint_t *vec3i_snap(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	result[0] = (vec3i0[0] / vec3i1[0]) * vec3i1[0];
	result[1] = (vec3i0[1] / vec3i1[1]) * vec3i1[1];
	result[2] = (vec3i0[2] / vec3i1[2]) * vec3i1[2];
	return result;
}

mint_t *vec3i_snap_i(mint_t *result, mint_t *vec3i0, mint_t i)
{
	result[0] = (vec3i0[0] / i) * i;
	result[1] = (vec3i0[1] / i) * i;
	result[2] = (vec3i0[2] / i) * i;
	return result;
}

mint_t *vec3i_cross(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	mint_t cross[VEC3_SIZE];
	cross[0] = vec3i0[1] * vec3i1[2] - vec3i0[2] * vec3i1[1];
	cross[1] = vec3i0[2] * vec3i1[0] - vec3i0[0] * vec3i1[2];
	cross[2] = vec3i0[0] * vec3i1[1] - vec3i0[1] * vec3i1[0];
	result[0] = cross[0];
	result[1] = cross[1];
	result[2] = cross[2];
	return result;
}

mint_t *vec3i_negative(mint_t *result, mint_t *vec3i0)
{
	result[0] = -vec3i0[0];
	result[1] = -vec3i0[1];
	result[2] = -vec3i0[2];
	return result;
}

mint_t *vec3i_abs(mint_t *result, mint_t *vec3i0)
{
	result[0] = vec3i0[0];
	if (result[0] < 0) {
		result[0] = -result[0];
	}
	result[1] = vec3i0[1];
	if (result[1] < 0) {
		result[1] = -result[1];
	}
	result[2] = vec3i0[2];
	if (result[2] < 0) {
		result[2] = -result[2];
	}
	return result;
}

mint_t *vec3i_max(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	if (vec3i0[0] > vec3i1[0]) {
		result[0] = vec3i0[0];
	} else {
		result[0] = vec3i1[0];
	}
	if (vec3i0[1] > vec3i1[1]) {
		result[1] = vec3i0[1];
	} else {
		result[1] = vec3i1[1];
	}
	if (vec3i0[2] > vec3i1[2]) {
		result[2] = vec3i0[2];
	} else {
		result[2] = vec3i1[2];
	}
	return result;
}

mint_t *vec3i_min(mint_t *result, mint_t *vec3i0, mint_t *vec3i1)
{
	if (vec3i0[0] < vec3i1[0]) {
		result[0] = vec3i0[0];
	} else {
		result[0] = vec3i1[0];
	}
	if (vec3i0[1] < vec3i1[1]) {
		result[1] = vec3i0[1];
	} else {
		result[1] = vec3i1[1];
	}
	if (vec3i0[2] < vec3i1[2]) {
		result[2] = vec3i0[2];
	} else {
		result[2] = vec3i1[2];
	}
	return result;
}

mint_t *vec3i_clamp(mint_t *result, mint_t *vec3i0, mint_t *vec3i1, mint_t *vec3i2)
{
	vec3i_min(result, vec3i0, vec3i1);
	vec3i_max(result, vec3i0, vec3i2);
	return result;
}

bool vec4i_is_zero(mint_t *vec4i0)
{
	return vec4i0[0] == 0 && vec4i0[1] == 0 && vec4i0[2] == 0 && vec4i0[3] == 0;
}

bool vec4i_is_equal(mint_t *vec4i0, mint_t *vec4i1)
{
	return vec4i0[0] == vec4i1[0] && vec4i0[1] == vec4i1[1] && vec4i0[2] == vec4i1[2] && vec4i0[3] == vec4i1[3];
}

mint_t *vec4i(mint_t *result, mint_t x, mint_t y, mint_t z, mint_t w)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	result[3] = w;
	return result;
}

mint_t *vec4i_assign(mint_t *result, mint_t *vec4i0)
{
	result[0] = vec4i0[0];
	result[1] = vec4i0[1];
	result[2] = vec4i0[2];
	result[3] = vec4i0[3];
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec4i_assign_vec4(mint_t *result, mfloat_t *vec40)
{
	result[0] = vec40[0];
	result[1] = vec40[1];
	result[2] = vec40[2];
	result[3] = vec40[3];
	return result;
}
#endif

mint_t *vec4i_zero(mint_t *result)
{
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	return result;
}

mint_t *vec4i_one(mint_t *result)
{
	result[0] = 1;
	result[1] = 1;
	result[2] = 1;
	result[3] = 1;
	return result;
}

mint_t *vec4i_sign(mint_t *result, mint_t *vec4i0)
{
	if (vec4i0[0] > 0) {
		result[0] = 1;
	} else if (vec4i0[0] < 0) {
		result[0] = -1;
	} else {
		result[0] = 0;
	}
	if (vec4i0[1] > 0) {
		result[1] = 1;
	} else if (vec4i0[1] < 0) {
		result[1] = -1;
	} else {
		result[1] = 0;
	}
	if (vec4i0[2] > 0) {
		result[2] = 1;
	} else if (vec4i0[2] < 0) {
		result[2] = -1;
	} else {
		result[2] = 0;
	}
	if (vec4i0[3] > 0) {
		result[3] = 1;
	} else if (vec4i0[3] < 0) {
		result[3] = -1;
	} else {
		result[3] = 0;
	}
	return result;
}

mint_t *vec4i_add(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	result[0] = vec4i0[0] + vec4i1[0];
	result[1] = vec4i0[1] + vec4i1[1];
	result[2] = vec4i0[2] + vec4i1[2];
	result[3] = vec4i0[3] + vec4i1[3];
	return result;
}

mint_t *vec4i_add_i(mint_t *result, mint_t *vec4i0, mint_t i)
{
	result[0] = vec4i0[0] + i;
	result[1] = vec4i0[1] + i;
	result[2] = vec4i0[2] + i;
	result[3] = vec4i0[3] + i;
	return result;
}

mint_t *vec4i_subtract(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	result[0] = vec4i0[0] - vec4i1[0];
	result[1] = vec4i0[1] - vec4i1[1];
	result[2] = vec4i0[2] - vec4i1[2];
	result[3] = vec4i0[3] - vec4i1[3];
	return result;
}

mint_t *vec4i_subtract_i(mint_t *result, mint_t *vec4i0, mint_t i)
{
	result[0] = vec4i0[0] - i;
	result[1] = vec4i0[1] - i;
	result[2] = vec4i0[2] - i;
	result[3] = vec4i0[3] - i;
	return result;
}

mint_t *vec4i_multiply(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	result[0] = vec4i0[0] * vec4i1[0];
	result[1] = vec4i0[1] * vec4i1[1];
	result[2] = vec4i0[2] * vec4i1[2];
	result[3] = vec4i0[3] * vec4i1[3];
	return result;
}

mint_t *vec4i_multiply_i(mint_t *result, mint_t *vec4i0, mint_t i)
{
	result[0] = vec4i0[0] * i;
	result[1] = vec4i0[1] * i;
	result[2] = vec4i0[2] * i;
	result[3] = vec4i0[3] * i;
	return result;
}

mint_t *vec4i_divide(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	result[0] = vec4i0[0] / vec4i1[0];
	result[1] = vec4i0[1] / vec4i1[1];
	result[2] = vec4i0[2] / vec4i1[2];
	result[3] = vec4i0[3] / vec4i1[3];
	return result;
}

mint_t *vec4i_divide_i(mint_t *result, mint_t *vec4i0, mint_t i)
{
	result[0] = vec4i0[0] / i;
	result[1] = vec4i0[1] / i;
	result[2] = vec4i0[2] / i;
	result[3] = vec4i0[3] / i;
	return result;
}

mint_t *vec4i_snap(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	result[0] = (vec4i0[0] / vec4i1[0]) * vec4i1[0];
	result[1] = (vec4i0[1] / vec4i1[1]) * vec4i1[1];
	result[2] = (vec4i0[2] / vec4i1[2]) * vec4i1[2];
	result[3] = (vec4i0[3] / vec4i1[3]) * vec4i1[3];
	return result;
}

mint_t *vec4i_snap_i(mint_t *result, mint_t *vec4i0, mint_t i)
{
	result[0] = (vec4i0[0] / i) * i;
	result[1] = (vec4i0[1] / i) * i;
	result[2] = (vec4i0[2] / i) * i;
	result[3] = (vec4i0[3] / i) * i;
	return result;
}

mint_t *vec4i_negative(mint_t *result, mint_t *vec4i0)
{
	result[0] = -vec4i0[0];
	result[1] = -vec4i0[1];
	result[2] = -vec4i0[2];
	result[3] = -vec4i0[3];
	return result;
}

mint_t *vec4i_abs(mint_t *result, mint_t *vec4i0)
{
	result[0] = vec4i0[0];
	if (result[0] < 0) {
		result[0] = -result[0];
	}
	result[1] = vec4i0[1];
	if (result[1] < 0) {
		result[1] = -result[1];
	}
	result[2] = vec4i0[2];
	if (result[2] < 0) {
		result[2] = -result[2];
	}
	result[3] = vec4i0[3];
	if (result[3] < 0) {
		result[3] = -result[3];
	}
	return result;
}

mint_t *vec4i_max(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	if (vec4i0[0] > vec4i1[0]) {
		result[0] = vec4i0[0];
	} else {
		result[0] = vec4i1[0];
	}
	if (vec4i0[1] > vec4i1[1]) {
		result[1] = vec4i0[1];
	} else {
		result[1] = vec4i1[1];
	}
	if (vec4i0[2] > vec4i1[2]) {
		result[2] = vec4i0[2];
	} else {
		result[2] = vec4i1[2];
	}
	if (vec4i0[3] > vec4i1[3]) {
		result[3] = vec4i0[3];
	} else {
		result[3] = vec4i1[3];
	}
	return result;
}

mint_t *vec4i_min(mint_t *result, mint_t *vec4i0, mint_t *vec4i1)
{
	if (vec4i0[0] < vec4i1[0]) {
		result[0] = vec4i0[0];
	} else {
		result[0] = vec4i1[0];
	}
	if (vec4i0[1] < vec4i1[1]) {
		result[1] = vec4i0[1];
	} else {
		result[1] = vec4i1[1];
	}
	if (vec4i0[2] < vec4i1[2]) {
		result[2] = vec4i0[2];
	} else {
		result[2] = vec4i1[2];
	}
	if (vec4i0[3] < vec4i1[3]) {
		result[3] = vec4i0[3];
	} else {
		result[3] = vec4i1[3];
	}
	return result;
}

mint_t *vec4i_clamp(mint_t *result, mint_t *vec4i0, mint_t *vec4i1, mint_t *vec4i2)
{
	vec4i_min(result, vec4i0, vec4i1);
	vec4i_max(result, vec4i0, vec4i2);
	return result;
}
#endif

#if defined(MATHC_USE_FLOATING_POINT)
bool vec2_is_zero(mfloat_t *vec20)
{
	return vec20[0] < MFLT_EPSILON && vec20[1] < MFLT_EPSILON;
}

bool vec2_is_equal(mfloat_t *vec20, mfloat_t *vec21)
{
	return MFABS(vec20[0] - vec21[0]) < MFLT_EPSILON && MFABS(vec20[1] - vec21[1]) < MFLT_EPSILON;
}

mfloat_t *vec2(mfloat_t *result, mfloat_t x, mfloat_t y)
{
	result[0] = x;
	result[1] = y;
	return result;
}

mfloat_t *vec2_assign(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = vec20[0];
	result[1] = vec20[1];
	return result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec2_assign_vec2i(mfloat_t *result, mint_t *vec2i0)
{
	result[0] = vec2i0[0];
	result[1] = vec2i0[1];
	return result;
}
#endif

mfloat_t *vec2_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *vec2_one(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *vec2_sign(mfloat_t *result, mfloat_t *vec20)
{
	if (vec20[0] > MFLOAT_C(0.0)) {
		result[0] = MFLOAT_C(1.0);
	} else if (vec20[0] < MFLOAT_C(0.0)) {
		result[0] = -MFLOAT_C(1.0);
	} else {
		result[0] = MFLOAT_C(0.0);
	}
	if (vec20[1] > MFLOAT_C(0.0)) {
		result[1] = MFLOAT_C(1.0);
	} else if (vec20[1] < MFLOAT_C(0.0)) {
		result[1] = -MFLOAT_C(1.0);
	} else {
		result[1] = MFLOAT_C(0.0);
	}
	return result;
}

mfloat_t *vec2_add(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = vec20[0] + vec21[0];
	result[1] = vec20[1] + vec21[1];
	return result;
}

mfloat_t *vec2_add_f(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	result[0] = vec20[0] + f;
	result[1] = vec20[1] + f;
	return result;
}

mfloat_t *vec2_subtract(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = vec20[0] - vec21[0];
	result[1] = vec20[1] - vec21[1];
	return result;
}

mfloat_t *vec2_subtract_f(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	result[0] = vec20[0] - f;
	result[1] = vec20[1] - f;
	return result;
}

mfloat_t *vec2_multiply(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = vec20[0] * vec21[0];
	result[1] = vec20[1] * vec21[1];
	return result;
}

mfloat_t *vec2_multiply_f(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	result[0] = vec20[0] * f;
	result[1] = vec20[1] * f;
	return result;
}

mfloat_t *vec2_multiply_mat2(mfloat_t *result, mfloat_t *vec20, mfloat_t *mat20)
{
	mfloat_t x = vec20[0];
	mfloat_t y = vec20[1];
	result[0] = mat20[0] * x + mat20[2] * y;
	result[1] = mat20[1] * x + mat20[3] * y;
	return result;
}

mfloat_t *vec2_divide(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = vec20[0] / vec21[0];
	result[1] = vec20[1] / vec21[1];
	return result;
}

mfloat_t *vec2_divide_f(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	result[0] = vec20[0] / f;
	result[1] = vec20[1] / f;
	return result;
}

mfloat_t *vec2_snap(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = MFLOOR(vec20[0] / vec21[0]) * vec21[0];
	result[1] = MFLOOR(vec20[1] / vec21[1]) * vec21[1];
	return result;
}

mfloat_t *vec2_snap_f(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	result[0] = MFLOOR(vec20[0] / f) * f;
	result[1] = MFLOOR(vec20[1] / f) * f;
	return result;
}

mfloat_t *vec2_negative(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = -vec20[0];
	result[1] = -vec20[1];
	return result;
}

mfloat_t *vec2_abs(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = MFABS(vec20[0]);
	result[1] = MFABS(vec20[1]);
	return result;
}

mfloat_t *vec2_floor(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = MFLOOR(vec20[0]);
	result[1] = MFLOOR(vec20[1]);
	return result;
}

mfloat_t *vec2_ceil(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = MCEIL(vec20[0]);
	result[1] = MCEIL(vec20[1]);
	return result;
}

mfloat_t *vec2_round(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = MROUND(vec20[0]);
	result[1] = MROUND(vec20[1]);
	return result;
}

mfloat_t *vec2_max(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = MFMAX(vec20[0], vec21[0]);
	result[1] = MFMAX(vec20[1], vec21[1]);
	return result;
}

mfloat_t *vec2_min(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	result[0] = MFMIN(vec20[0], vec21[0]);
	result[1] = MFMIN(vec20[1], vec21[1]);
	return result;
}

mfloat_t *vec2_clamp(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21, mfloat_t *vec22)
{
	vec2_min(result, vec20, vec21);
	vec2_max(result, vec20, vec22);
	return result;
}

mfloat_t *vec2_normalize(mfloat_t *result, mfloat_t *vec20)
{
	mfloat_t l = MSQRT(vec20[0] * vec20[0] + vec20[1] * vec20[1]);
	result[0] = vec20[0] / l;
	result[1] = vec20[1] / l;
	return result;
}

mfloat_t vec2_dot(mfloat_t *vec20, mfloat_t *vec21)
{
	return vec20[0] * vec21[0] + vec20[1] * vec21[1];
}

mfloat_t *vec2_project(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	mfloat_t d = vec2_dot(vec21, vec21);
	mfloat_t s = vec2_dot(vec20, vec21) / d;
	result[0] = vec21[0] * s;
	result[1] = vec21[1] * s;
	return result;
}

mfloat_t *vec2_slide(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	mfloat_t d = vec2_dot(vec20, vec21);
	result[0] = vec20[0] - vec21[0] * d;
	result[1] = vec20[1] - vec21[1] * d;
	return result;
}

mfloat_t *vec2_reflect(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21)
{
	mfloat_t d = MFLOAT_C(2.0) * vec2_dot(vec20, vec21);
	result[0] = vec21[0] * d - vec20[0];
	result[1] = vec21[1] * d - vec20[1];
	return result;
}

mfloat_t *vec2_tangent(mfloat_t *result, mfloat_t *vec20)
{
	mfloat_t a0 = vec20[0];
	mfloat_t a1 = vec20[1];
	result[0] = a1;
	result[1] = -a0;
	return result;
}

mfloat_t *vec2_rotate(mfloat_t *result, mfloat_t *vec20, mfloat_t f)
{
	mfloat_t cs = MCOS(f);
	mfloat_t sn = MSIN(f);
	mfloat_t x = vec20[0];
	mfloat_t y = vec20[1];
	result[0] = x * cs - y * sn;
	result[1] = x * sn + y * cs;
	return result;
}

mfloat_t *vec2_lerp(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21, mfloat_t f)
{
	result[0] = vec20[0] + (vec21[0] - vec20[0]) * f;
	result[1] = vec20[1] + (vec21[1] - vec20[1]) * f;
	return result;
}

mfloat_t *vec2_bezier3(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21, mfloat_t *vec22, mfloat_t f)
{
	mfloat_t tmp0[VEC2_SIZE];
	mfloat_t tmp1[VEC2_SIZE];
	vec2_lerp(tmp0, vec20, vec21, f);
	vec2_lerp(tmp1, vec21, vec22, f);
	vec2_lerp(result, tmp0, tmp1, f);
	return result;
}

mfloat_t *vec2_bezier4(mfloat_t *result, mfloat_t *vec20, mfloat_t *vec21, mfloat_t *vec22, mfloat_t *vec23, mfloat_t f)
{
	mfloat_t tmp0[VEC2_SIZE];
	mfloat_t tmp1[VEC2_SIZE];
	mfloat_t tmp2[VEC2_SIZE];
	mfloat_t tmp3[VEC2_SIZE];
	mfloat_t tmp4[VEC2_SIZE];
	vec2_lerp(tmp0, vec20, vec21, f);
	vec2_lerp(tmp1, vec21, vec22, f);
	vec2_lerp(tmp2, vec22, vec23, f);
	vec2_lerp(tmp3, tmp0, tmp1, f);
	vec2_lerp(tmp4, tmp1, tmp2, f);
	vec2_lerp(result, tmp3, tmp4, f);
	return result;
}

mfloat_t vec2_angle(mfloat_t *vec20)
{
	return MATAN2(vec20[1], vec20[0]);
}

mfloat_t vec2_length(mfloat_t *vec20)
{
	return MSQRT(vec20[0] * vec20[0] + vec20[1] * vec20[1]);
}

mfloat_t vec2_length_squared(mfloat_t *vec20)
{
	return vec20[0] * vec20[0] + vec20[1] * vec20[1];
}

mfloat_t vec2_distance(mfloat_t *vec20, mfloat_t *vec21)
{
	return MSQRT((vec20[0] - vec21[0]) * (vec20[0] - vec21[0]) + (vec20[1] - vec21[1]) * (vec20[1] - vec21[1]));
}

mfloat_t vec2_distance_squared(mfloat_t *vec20, mfloat_t *vec21)
{
	return (vec20[0] - vec21[0]) * (vec20[0] - vec21[0]) + (vec20[1] - vec21[1]) * (vec20[1] - vec21[1]);
}

bool vec3_is_zero(mfloat_t *vec30)
{
	return vec30[0] < MFLT_EPSILON && vec30[1] < MFLT_EPSILON && vec30[2] < MFLT_EPSILON;
}

bool vec3_is_equal(mfloat_t *vec30, mfloat_t *vec31)
{
	return MFABS(vec30[0] - vec31[0]) < MFLT_EPSILON && MFABS(vec30[1] - vec31[1]) < MFLT_EPSILON && MFABS(vec30[2] - vec31[2]) < MFLT_EPSILON;
}

mfloat_t *vec3(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	return result;
}

mfloat_t *vec3_assign(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = vec30[0];
	result[1] = vec30[1];
	result[2] = vec30[2];
	return result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec3_assign_vec3i(mfloat_t *result, mint_t *vec3i0)
{
	result[0] = vec3i0[0];
	result[1] = vec3i0[1];
	result[2] = vec3i0[2];
	return result;
}
#endif

mfloat_t *vec3_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *vec3_one(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(1.0);
	result[2] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *vec3_sign(mfloat_t *result, mfloat_t *vec30)
{
	if (vec30[0] > MFLOAT_C(0.0)) {
		result[0] = MFLOAT_C(1.0);
	} else if (vec30[0] < 0) {
		result[0] = -MFLOAT_C(1.0);
	} else {
		result[0] = MFLOAT_C(0.0);
	}
	if (vec30[1] > MFLOAT_C(0.0)) {
		result[1] = MFLOAT_C(1.0);
	} else if (vec30[1] < 0) {
		result[1] = -MFLOAT_C(1.0);
	} else {
		result[1] = MFLOAT_C(0.0);
	}
	if (vec30[2] > MFLOAT_C(0.0)) {
		result[2] = MFLOAT_C(1.0);
	} else if (vec30[2] < 0) {
		result[2] = -MFLOAT_C(1.0);
	} else {
		result[2] = MFLOAT_C(0.0);
	}
	return result;
}

mfloat_t *vec3_add(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = vec30[0] + vec31[0];
	result[1] = vec30[1] + vec31[1];
	result[2] = vec30[2] + vec31[2];
	return result;
}

mfloat_t *vec3_add_f(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	result[0] = vec30[0] + f;
	result[1] = vec30[1] + f;
	result[2] = vec30[2] + f;
	return result;
}

mfloat_t *vec3_subtract(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = vec30[0] - vec31[0];
	result[1] = vec30[1] - vec31[1];
	result[2] = vec30[2] - vec31[2];
	return result;
}

mfloat_t *vec3_subtract_f(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	result[0] = vec30[0] - f;
	result[1] = vec30[1] - f;
	result[2] = vec30[2] - f;
	return result;
}

mfloat_t *vec3_multiply(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = vec30[0] * vec31[0];
	result[1] = vec30[1] * vec31[1];
	result[2] = vec30[2] * vec31[2];
	return result;
}

mfloat_t *vec3_multiply_f(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	result[0] = vec30[0] * f;
	result[1] = vec30[1] * f;
	result[2] = vec30[2] * f;
	return result;
}

mfloat_t *vec3_multiply_mat3(mfloat_t *result, mfloat_t *vec30, mfloat_t *mat30)
{
	mfloat_t x = vec30[0];
	mfloat_t y = vec30[1];
	mfloat_t z = vec30[2];
	result[0] = mat30[0] * x + mat30[3] * y + mat30[6] * z;
	result[1] = mat30[1] * x + mat30[4] * y + mat30[7] * z;
	result[2] = mat30[2] * x + mat30[5] * y + mat30[8] * z;
	return result;
}

mfloat_t *vec3_divide(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = vec30[0] / vec31[0];
	result[1] = vec30[1] / vec31[1];
	result[2] = vec30[2] / vec31[2];
	return result;
}

mfloat_t *vec3_divide_f(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	result[0] = vec30[0] / f;
	result[1] = vec30[1] / f;
	result[2] = vec30[2] / f;
	return result;
}

mfloat_t *vec3_snap(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = MFLOOR(vec30[0] / vec31[0]) * vec31[0];
	result[1] = MFLOOR(vec30[1] / vec31[1]) * vec31[1];
	result[2] = MFLOOR(vec30[2] / vec31[2]) * vec31[2];
	return result;
}

mfloat_t *vec3_snap_f(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	result[0] = MFLOOR(vec30[0] / f) * f;
	result[1] = MFLOOR(vec30[1] / f) * f;
	result[2] = MFLOOR(vec30[2] / f) * f;
	return result;
}

mfloat_t *vec3_negative(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = -vec30[0];
	result[1] = -vec30[1];
	result[2] = -vec30[2];
	return result;
}

mfloat_t *vec3_abs(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = MFABS(vec30[0]);
	result[1] = MFABS(vec30[1]);
	result[2] = MFABS(vec30[2]);
	return result;
}

mfloat_t *vec3_floor(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = MFLOOR(vec30[0]);
	result[1] = MFLOOR(vec30[1]);
	result[2] = MFLOOR(vec30[2]);
	return result;
}

mfloat_t *vec3_ceil(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = MCEIL(vec30[0]);
	result[1] = MCEIL(vec30[1]);
	result[2] = MCEIL(vec30[2]);
	return result;
}

mfloat_t *vec3_round(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = MROUND(vec30[0]);
	result[1] = MROUND(vec30[1]);
	result[2] = MROUND(vec30[2]);
	return result;
}

mfloat_t *vec3_max(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = MFMAX(vec30[0], vec31[0]);
	result[1] = MFMAX(vec30[1], vec31[1]);
	result[2] = MFMAX(vec30[2], vec31[2]);
	return result;
}

mfloat_t *vec3_min(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	result[0] = MFMIN(vec30[0], vec31[0]);
	result[1] = MFMIN(vec30[1], vec31[1]);
	result[2] = MFMIN(vec30[2], vec31[2]);
	return result;
}

mfloat_t *vec3_clamp(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31, mfloat_t *vec32)
{
	vec3_min(result, vec30, vec31);
	vec3_max(result, vec30, vec32);
	return result;
}

mfloat_t *vec3_cross(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	mfloat_t cross[VEC3_SIZE];
	cross[0] = vec30[1] * vec31[2] - vec30[2] * vec31[1];
	cross[1] = vec30[2] * vec31[0] - vec30[0] * vec31[2];
	cross[2] = vec30[0] * vec31[1] - vec30[1] * vec31[0];
	result[0] = cross[0];
	result[1] = cross[1];
	result[2] = cross[2];
	return result;
}

mfloat_t *vec3_normalize(mfloat_t *result, mfloat_t *vec30)
{
	mfloat_t l = MSQRT(vec30[0] * vec30[0] + vec30[1] * vec30[1] + vec30[2] * vec30[2]);
	result[0] = vec30[0] / l;
	result[1] = vec30[1] / l;
	result[2] = vec30[2] / l;
	return result;
}

mfloat_t vec3_dot(mfloat_t *vec30, mfloat_t *vec31)
{
	return vec30[0] * vec31[0] + vec30[1] * vec31[1] + vec30[2] * vec31[2];
}

mfloat_t *vec3_project(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	mfloat_t d = vec2_dot(vec31, vec31);
	mfloat_t s = vec2_dot(vec30, vec31) / d;
	result[0] = vec31[0] * s;
	result[1] = vec31[1] * s;
	result[2] = vec31[2] * s;
	return result;
}

mfloat_t *vec3_slide(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	mfloat_t d = vec3_dot(vec30, vec31);
	result[0] = vec30[0] - vec31[0] * d;
	result[1] = vec30[1] - vec31[1] * d;
	result[2] = vec30[2] - vec31[2] * d;
	return result;
}

mfloat_t *vec3_reflect(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	mfloat_t d = MFLOAT_C(2.0) * vec3_dot(vec30, vec31);
	result[0] = vec31[0] * d - vec30[0];
	result[1] = vec31[1] * d - vec30[1];
	result[2] = vec31[2] * d - vec30[2];
	return result;
}

mfloat_t *vec3_lerp(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31, mfloat_t f)
{
	result[0] = vec30[0] + (vec31[0] - vec30[0]) * f;
	result[1] = vec30[1] + (vec31[1] - vec30[1]) * f;
	result[2] = vec30[2] + (vec31[2] - vec30[2]) * f;
	return result;
}

mfloat_t *vec3_bezier3(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31, mfloat_t *vec32, mfloat_t f)
{
	mfloat_t tmp0[VEC3_SIZE];
	mfloat_t tmp1[VEC3_SIZE];
	vec3_lerp(tmp0, vec30, vec31, f);
	vec3_lerp(tmp1, vec31, vec32, f);
	vec3_lerp(result, tmp0, tmp1, f);
	return result;
}

mfloat_t *vec3_bezier4(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31, mfloat_t *vec32, mfloat_t *vec33, mfloat_t f)
{
	mfloat_t tmp0[VEC3_SIZE];
	mfloat_t tmp1[VEC3_SIZE];
	mfloat_t tmp2[VEC3_SIZE];
	mfloat_t tmp3[VEC3_SIZE];
	mfloat_t tmp4[VEC3_SIZE];
	vec3_lerp(tmp0, vec30, vec31, f);
	vec3_lerp(tmp1, vec31, vec32, f);
	vec3_lerp(tmp2, vec32, vec33, f);
	vec3_lerp(tmp3, tmp0, tmp1, f);
	vec3_lerp(tmp4, tmp1, tmp2, f);
	vec3_lerp(result, tmp3, tmp4, f);
	return result;
}

mfloat_t vec3_length(mfloat_t *vec30)
{
	return MSQRT(vec30[0] * vec30[0] + vec30[1] * vec30[1] + vec30[2] * vec30[2]);
}

mfloat_t vec3_length_squared(mfloat_t *vec30)
{
	return vec30[0] * vec30[0] + vec30[1] * vec30[1] + vec30[2] * vec30[2];
}

mfloat_t vec3_distance(mfloat_t *vec30, mfloat_t *vec31)
{
	return MSQRT((vec30[0] - vec31[0]) * (vec30[0] - vec31[0]) + (vec30[1] - vec31[1]) * (vec30[1] - vec31[1]) + (vec30[2] - vec31[2]) * (vec30[2] - vec31[2]));
}

mfloat_t vec3_distance_squared(mfloat_t *vec30, mfloat_t *vec31)
{
	return (vec30[0] - vec31[0]) * (vec30[0] - vec31[0]) + (vec30[1] - vec31[1]) * (vec30[1] - vec31[1]) + (vec30[2] - vec31[2]) * (vec30[2] - vec31[2]);
}

bool vec4_is_zero(mfloat_t *vec40)
{
	return vec40[0] < MFLT_EPSILON && vec40[1] < MFLT_EPSILON && vec40[2] < MFLT_EPSILON && vec40[3] < MFLT_EPSILON;
}

bool vec4_is_equal(mfloat_t *vec40, mfloat_t *vec41)
{
	return MFABS(vec40[0] - vec41[0]) < MFLT_EPSILON && MFABS(vec40[1] - vec41[1]) < MFLT_EPSILON && MFABS(vec40[2] - vec41[2]) < MFLT_EPSILON && MFABS(vec40[3] - vec41[3]) < MFLT_EPSILON;
}

mfloat_t *vec4(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	result[3] = w;
	return result;
}

mfloat_t *vec4_assign(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = vec40[0];
	result[1] = vec40[1];
	result[2] = vec40[2];
	result[3] = vec40[3];
	return result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec4_assign_vec4i(mfloat_t *result, mint_t *vec4i0)
{
	result[0] = vec4i0[0];
	result[1] = vec4i0[1];
	result[2] = vec4i0[2];
	result[3] = vec4i0[3];
	return result;
}
#endif

mfloat_t *vec4_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *vec4_one(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(1.0);
	result[2] = MFLOAT_C(1.0);
	result[3] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *vec4_sign(mfloat_t *result, mfloat_t *vec40)
{
	if (vec40[0] > MFLOAT_C(0.0)) {
		result[0] = MFLOAT_C(1.0);
	} else if (vec40[0] < 0) {
		result[0] = -MFLOAT_C(1.0);
	} else {
		result[0] = MFLOAT_C(0.0);
	}
	if (vec40[1] > MFLOAT_C(0.0)) {
		result[1] = MFLOAT_C(1.0);
	} else if (vec40[1] < 0) {
		result[1] = -MFLOAT_C(1.0);
	} else {
		result[1] = MFLOAT_C(0.0);
	}
	if (vec40[2] > MFLOAT_C(0.0)) {
		result[2] = MFLOAT_C(1.0);
	} else if (vec40[2] < 0) {
		result[2] = -MFLOAT_C(1.0);
	} else {
		result[2] = MFLOAT_C(0.0);
	}
	if (vec40[3] > MFLOAT_C(0.0)) {
		result[3] = MFLOAT_C(1.0);
	} else if (vec40[3] < 0) {
		result[3] = -MFLOAT_C(1.0);
	} else {
		result[3] = MFLOAT_C(0.0);
	}
	return result;
}

mfloat_t *vec4_add(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = vec40[0] + vec41[0];
	result[1] = vec40[1] + vec41[1];
	result[2] = vec40[2] + vec41[2];
	result[3] = vec40[3] + vec41[3];
	return result;
}

mfloat_t *vec4_add_f(mfloat_t *result, mfloat_t *vec40, mfloat_t f)
{
	result[0] = vec40[0] + f;
	result[1] = vec40[1] + f;
	result[2] = vec40[2] + f;
	result[3] = vec40[3] + f;
	return result;
}

mfloat_t *vec4_subtract(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = vec40[0] - vec41[0];
	result[1] = vec40[1] - vec41[1];
	result[2] = vec40[2] - vec41[2];
	result[3] = vec40[3] - vec41[3];
	return result;
}

mfloat_t *vec4_subtract_f(mfloat_t *result, mfloat_t *vec40, mfloat_t f)
{
	result[0] = vec40[0] - f;
	result[1] = vec40[1] - f;
	result[2] = vec40[2] - f;
	result[3] = vec40[3] - f;
	return result;
}

mfloat_t *vec4_multiply(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = vec40[0] * vec41[0];
	result[1] = vec40[1] * vec41[1];
	result[2] = vec40[2] * vec41[2];
	result[3] = vec40[3] * vec41[3];
	return result;
}

mfloat_t *vec4_multiply_f(mfloat_t *result, mfloat_t *vec40, mfloat_t f)
{
	result[0] = vec40[0] * f;
	result[1] = vec40[1] * f;
	result[2] = vec40[2] * f;
	result[3] = vec40[3] * f;
	return result;
}

mfloat_t *vec4_multiply_mat4(mfloat_t *result, mfloat_t *vec40, mfloat_t *mat40)
{
	mfloat_t x = vec40[0];
	mfloat_t y = vec40[1];
	mfloat_t z = vec40[2];
	mfloat_t w = vec40[3];
	result[0] = mat40[0] * x + mat40[4] * y + mat40[8] * z + mat40[12] * w;
	result[1] = mat40[1] * x + mat40[5] * y + mat40[9] * z + mat40[13] * w;
	result[2] = mat40[2] * x + mat40[6] * y + mat40[10] * z + mat40[14] * w;
	result[3] = mat40[3] * x + mat40[7] * y + mat40[11] * z + mat40[15] * w;
	return result;
}

mfloat_t *vec4_divide(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = vec40[0] / vec41[0];
	result[1] = vec40[1] / vec41[1];
	result[2] = vec40[2] / vec41[2];
	result[3] = vec40[3] / vec41[3];
	return result;
}

mfloat_t *vec4_divide_f(mfloat_t *result, mfloat_t *vec40, mfloat_t f)
{
	result[0] = vec40[0] / f;
	result[1] = vec40[1] / f;
	result[2] = vec40[2] / f;
	result[3] = vec40[3] / f;
	return result;
}

mfloat_t *vec4_snap(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = MFLOOR(vec40[0] / vec41[0]) * vec41[0];
	result[1] = MFLOOR(vec40[1] / vec41[1]) * vec41[1];
	result[2] = MFLOOR(vec40[2] / vec41[2]) * vec41[2];
	result[3] = MFLOOR(vec40[3] / vec41[3]) * vec41[3];
	return result;
}

mfloat_t *vec4_snap_f(mfloat_t *result, mfloat_t *vec40, mfloat_t f)
{
	result[0] = MFLOOR(vec40[0] / f) * f;
	result[1] = MFLOOR(vec40[1] / f) * f;
	result[2] = MFLOOR(vec40[2] / f) * f;
	result[3] = MFLOOR(vec40[3] / f) * f;
	return result;
}

mfloat_t *vec4_negative(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = -vec40[0];
	result[1] = -vec40[1];
	result[2] = -vec40[2];
	result[3] = -vec40[3];
	return result;
}

mfloat_t *vec4_abs(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = MFABS(vec40[0]);
	result[1] = MFABS(vec40[1]);
	result[2] = MFABS(vec40[2]);
	result[3] = MFABS(vec40[3]);
	return result;
}

mfloat_t *vec4_floor(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = MFLOOR(vec40[0]);
	result[1] = MFLOOR(vec40[1]);
	result[2] = MFLOOR(vec40[2]);
	result[3] = MFLOOR(vec40[3]);
	return result;
}

mfloat_t *vec4_ceil(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = MCEIL(vec40[0]);
	result[1] = MCEIL(vec40[1]);
	result[2] = MCEIL(vec40[2]);
	result[3] = MCEIL(vec40[3]);
	return result;
}

mfloat_t *vec4_round(mfloat_t *result, mfloat_t *vec40)
{
	result[0] = MROUND(vec40[0]);
	result[1] = MROUND(vec40[1]);
	result[2] = MROUND(vec40[2]);
	result[3] = MROUND(vec40[3]);
	return result;
}

mfloat_t *vec4_max(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = MFMAX(vec40[0], vec41[0]);
	result[1] = MFMAX(vec40[1], vec41[1]);
	result[2] = MFMAX(vec40[2], vec41[2]);
	result[3] = MFMAX(vec40[3], vec41[3]);
	return result;
}

mfloat_t *vec4_min(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41)
{
	result[0] = MFMIN(vec40[0], vec41[0]);
	result[1] = MFMIN(vec40[1], vec41[1]);
	result[2] = MFMIN(vec40[2], vec41[2]);
	result[3] = MFMIN(vec40[3], vec41[3]);
	return result;
}

mfloat_t *vec4_clamp(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41, mfloat_t *vec42)
{
	vec4_min(result, vec40, vec41);
	vec4_max(result, vec40, vec42);
	return result;
}

mfloat_t *vec4_normalize(mfloat_t *result, mfloat_t *vec40)
{
	mfloat_t l = MSQRT(vec40[0] * vec40[0] + vec40[1] * vec40[1] + vec40[2] * vec40[2] + vec40[3] * vec40[3]);
	result[0] = vec40[0] / l;
	result[1] = vec40[1] / l;
	result[2] = vec40[2] / l;
	result[3] = vec40[3] / l;
	return result;
}

mfloat_t *vec4_lerp(mfloat_t *result, mfloat_t *vec40, mfloat_t *vec41, mfloat_t f)
{
	result[0] = vec40[0] + (vec41[0] - vec40[0]) * f;
	result[1] = vec40[1] + (vec41[1] - vec40[1]) * f;
	result[2] = vec40[2] + (vec41[2] - vec40[2]) * f;
	result[3] = vec40[3] + (vec41[3] - vec40[3]) * f;
	return result;
}

bool quat_is_zero(mfloat_t *quat0)
{
	return quat0[0] < MFLT_EPSILON && quat0[1] < MFLT_EPSILON && quat0[2] < MFLT_EPSILON && quat0[3] < MFLT_EPSILON;
}

bool quat_is_equal(mfloat_t *quat0, mfloat_t *quat1)
{
	return MFABS(quat0[0] - quat1[0]) < MFLT_EPSILON && MFABS(quat0[1] - quat1[1]) < MFLT_EPSILON && MFABS(quat0[2] - quat1[2]) < MFLT_EPSILON && MFABS(quat0[3] - quat1[3]) < MFLT_EPSILON;
}

mfloat_t *quat(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	result[3] = w;
	return result;
}

mfloat_t *quat_assign(mfloat_t *result, mfloat_t *quat0)
{
	result[0] = quat0[0];
	result[1] = quat0[1];
	result[2] = quat0[2];
	result[3] = quat0[3];
	return result;
}

mfloat_t *quat_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *quat_null(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *quat_multiply(mfloat_t *result, mfloat_t *quat0, mfloat_t *quat1)
{
	result[0] = quat0[3] * quat1[0] + quat0[0] * quat1[3] + quat0[1] * quat1[2] - quat0[2] * quat1[1];
	result[1] = quat0[3] * quat1[1] + quat0[1] * quat1[3] + quat0[2] * quat1[0] - quat0[0] * quat1[2];
	result[2] = quat0[3] * quat1[2] + quat0[2] * quat1[3] + quat0[0] * quat1[1] - quat0[1] * quat1[0];
	result[3] = quat0[3] * quat1[3] - quat0[0] * quat1[0] - quat0[1] * quat1[1] - quat0[2] * quat1[2];
	return result;
}

mfloat_t *quat_multiply_f(mfloat_t *result, mfloat_t *quat0, mfloat_t f)
{
	result[0] = quat0[0] * f;
	result[1] = quat0[1] * f;
	result[2] = quat0[2] * f;
	result[3] = quat0[3] * f;
	return result;
}

mfloat_t *quat_divide(mfloat_t *result, mfloat_t *quat0, mfloat_t *quat1)
{
	mfloat_t x = quat0[0];
	mfloat_t y = quat0[1];
	mfloat_t z = quat0[2];
	mfloat_t w = quat0[3];
	mfloat_t ls = quat1[0] * quat1[0] + quat1[1] * quat1[1] + quat1[8] * quat1[8] + quat1[3] * quat1[3];
	mfloat_t normalized_x = -quat1[0] / ls;
	mfloat_t normalized_y = -quat1[1] / ls;
	mfloat_t normalized_z = -quat1[8] / ls;
	mfloat_t normalized_w = quat1[3] / ls;
	result[0] = x * normalized_w + normalized_x * w + (y * normalized_z - z * normalized_y);
	result[1] = y * normalized_w + normalized_y * w + (z * normalized_x - x * normalized_z);
	result[2] = z * normalized_w + normalized_z * w + (x * normalized_y - y * normalized_x);
	result[3] = w * normalized_w - (x * normalized_x + y * normalized_y + z * normalized_z);
	return result;
}

mfloat_t *quat_divide_f(mfloat_t *result, mfloat_t *quat0, mfloat_t f)
{
	result[0] = quat0[0] / f;
	result[1] = quat0[1] / f;
	result[2] = quat0[2] / f;
	result[3] = quat0[3] / f;
	return result;
}

mfloat_t *quat_negative(mfloat_t *result, mfloat_t *quat0)
{
	result[0] = -quat0[0];
	result[1] = -quat0[1];
	result[2] = -quat0[2];
	result[3] = -quat0[3];
	return result;
}

mfloat_t *quat_conjugate(mfloat_t *result, mfloat_t *quat0)
{
	result[0] = -quat0[0];
	result[1] = -quat0[1];
	result[2] = -quat0[2];
	result[3] = quat0[3];
	return result;
}

mfloat_t *quat_inverse(mfloat_t *result, mfloat_t *quat0)
{
	mfloat_t l = MFLOAT_C(1.0) / (quat0[0] * quat0[0] + quat0[1] * quat0[1] + quat0[2] * quat0[2] + quat0[3] * quat0[3]);
	result[0] = -quat0[0] * l;
	result[1] = -quat0[1] * l;
	result[2] = -quat0[2] * l;
	result[3] = quat0[3] * l;
	return result;
}

mfloat_t *quat_normalize(mfloat_t *result, mfloat_t *quat0)
{
	mfloat_t l = MFLOAT_C(1.0) / MSQRT(quat0[0] * quat0[0] + quat0[1] * quat0[1] + quat0[2] * quat0[2] + quat0[3] * quat0[3]);
	result[0] = quat0[0] * l;
	result[1] = quat0[1] * l;
	result[2] = quat0[2] * l;
	result[3] = quat0[3] * l;
	return result;
}

mfloat_t quat_dot(mfloat_t *quat0, mfloat_t *quat1)
{
	return quat0[0] * quat1[0] + quat0[1] * quat1[1] + quat0[2] * quat1[2] + quat0[3] * quat1[3];
}

mfloat_t *quat_power(mfloat_t *result, mfloat_t *quat0, mfloat_t exponent)
{
	if (MFABS(quat0[3]) < MFLOAT_C(1.0) - MFLT_EPSILON) {
		mfloat_t alpha = MACOS(quat0[3]);
		mfloat_t new_alpha = alpha * exponent;
		mfloat_t s = MSIN(new_alpha) / MSIN(alpha);
		result[0] = result[0] * s;
		result[1] = result[1] * s;
		result[2] = result[2] * s;
		result[3] = MCOS(new_alpha);
	} else {
		result[0] = quat0[0];
		result[1] = quat0[1];
		result[2] = quat0[1];
		result[3] = quat0[3];
	}
	return result;
}

mfloat_t *quat_from_axis_angle(mfloat_t *result, mfloat_t *vec30, mfloat_t angle)
{
	mfloat_t half = angle * MFLOAT_C(0.5);
	mfloat_t s = MSIN(half);
	result[0] = vec30[0] * s;
	result[1] = vec30[1] * s;
	result[2] = vec30[2] * s;
	result[3] = MCOS(half);
	return result;
}

mfloat_t *quat_from_vec3(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31)
{
	mfloat_t cross[VEC3_SIZE];
	mfloat_t d = vec3_dot(vec30, vec31);
	mfloat_t a_ls = vec3_length_squared(vec30);
	mfloat_t b_ls = vec3_length_squared(vec30);
	vec3_cross(cross, vec30, vec31);
	quat(result, cross[0], cross[1], cross[1], d + MSQRT(a_ls * b_ls));
	quat_normalize(result, result);
	return result;
}

mfloat_t *quat_from_mat4(mfloat_t *result, mfloat_t *mat40)
{
	mfloat_t scale = mat40[0] + mat40[5] + mat40[10];
	if (scale > MFLOAT_C(0.0)) {
		mfloat_t sr = MSQRT(scale + MFLOAT_C(1.0));
		result[3] = sr * MFLOAT_C(0.5);
		sr = MFLOAT_C(0.5) / sr;
		result[0] = (mat40[9] - mat40[6]) * sr;
		result[1] = (mat40[2] - mat40[8]) * sr;
		result[2] = (mat40[4] - mat40[1]) * sr;
	} else if ((mat40[0] >= mat40[5]) && (mat40[0] >= mat40[10])) {
		mfloat_t sr = MSQRT(MFLOAT_C(1.0) + mat40[0] - mat40[5] - mat40[10]);
		mfloat_t half = MFLOAT_C(0.5) / sr;
		result[0] = MFLOAT_C(0.5) * sr;
		result[1] = (mat40[4] + mat40[1]) * half;
		result[2] = (mat40[8] + mat40[2]) * half;
		result[3] = (mat40[9] - mat40[6]) * half;
	} else if (mat40[5] > mat40[10]) {
		mfloat_t sr = MSQRT(MFLOAT_C(1.0) + mat40[5] - mat40[0] - mat40[10]);
		mfloat_t half = MFLOAT_C(0.5) / sr;
		result[0] = (mat40[1] + mat40[4]) * half;
		result[1] = MFLOAT_C(0.5) * sr;
		result[2] = (mat40[6] + mat40[9]) * half;
		result[3] = (mat40[2] - mat40[8]) * half;
	} else {
		mfloat_t sr = MSQRT(MFLOAT_C(1.0) + mat40[10] - mat40[0] - mat40[5]);
		mfloat_t half = MFLOAT_C(0.5) / sr;
		result[0] = (mat40[2] + mat40[8]) * half;
		result[1] = (mat40[6] + mat40[9]) * half;
		result[2] = MFLOAT_C(0.5) * sr;
		result[3] = (mat40[4] - mat40[1]) * half;
	}
	return result;
}

mfloat_t *quat_lerp(mfloat_t *result, mfloat_t *quat0, mfloat_t *quat1, mfloat_t f)
{
	result[0] = quat0[0] + (quat1[0] - quat0[0]) * f;
	result[1] = quat0[1] + (quat1[1] - quat0[1]) * f;
	result[2] = quat0[2] + (quat1[2] - quat0[2]) * f;
	result[3] = quat0[3] + (quat1[3] - quat0[3]) * f;
	return result;
}

mfloat_t *quat_slerp(mfloat_t *result, mfloat_t *quat0, mfloat_t *quat1, mfloat_t f)
{
	mfloat_t tmp1[QUAT_SIZE];
	mfloat_t d = quat_dot(quat0, quat1);
	mfloat_t f0;
	mfloat_t f1;
	quat_assign(tmp1, quat1);
	if (d < MFLOAT_C(0.0)) {
		quat_negative(tmp1, tmp1);
		d = -d;
	}
	if (d > MFLOAT_C(0.9995)) {
		f0 = MFLOAT_C(1.0) - f;
		f1 = f;
	} else {
		mfloat_t theta = MACOS(d);
		mfloat_t sin_theta = MSIN(theta);
		f0 = MSIN((MFLOAT_C(1.0) - f) * theta) / sin_theta;
		f1 = MSIN(f * theta) / sin_theta;
	}
	result[0] = quat0[0] * f0 + tmp1[0] * f1;
	result[1] = quat0[1] * f0 + tmp1[1] * f1;
	result[2] = quat0[2] * f0 + tmp1[2] * f1;
	result[3] = quat0[3] * f0 + tmp1[3] * f1;
	return result;
}

mfloat_t quat_length(mfloat_t *quat0)
{
	return MSQRT(quat0[0] * quat0[0] + quat0[1] * quat0[1] + quat0[2] * quat0[2] + quat0[3] * quat0[3]);
}

mfloat_t quat_length_squared(mfloat_t *quat0)
{
	return quat0[0] * quat0[0] + quat0[1] * quat0[1] + quat0[2] * quat0[2] + quat0[3] * quat0[3];
}

mfloat_t quat_angle(mfloat_t *quat0, mfloat_t *quat1)
{
	mfloat_t s = MSQRT(quat_length_squared(quat0) * quat_length_squared(quat1));
	s = MFLOAT_C(1.0) / s;
	return MACOS(quat_dot(quat0, quat1) * s);
}

mfloat_t *mat2(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22)
{
	result[0] = m11;
	result[1] = m21;
	result[2] = m12;
	result[3] = m22;
	return result;
}

mfloat_t *mat2_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *mat2_identity(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(1.0);
	return result;
}

mfloat_t mat2_determinant(mfloat_t *mat20)
{
	return mat20[0] * mat20[3] - mat20[2] * mat20[1];
}

mfloat_t *mat2_assign(mfloat_t *result, mfloat_t *mat20)
{
	result[0] = mat20[0];
	result[1] = mat20[1];
	result[2] = mat20[2];
	result[3] = mat20[3];
	return result;
}

mfloat_t *mat2_negative(mfloat_t *result, mfloat_t *mat20)
{
	result[0] = -mat20[0];
	result[1] = -mat20[1];
	result[2] = -mat20[2];
	result[3] = -mat20[3];
	return result;
}

mfloat_t *mat2_transpose(mfloat_t *result, mfloat_t *mat20)
{
	mfloat_t transposed[MAT2_SIZE];
	transposed[0] = mat20[0];
	transposed[1] = mat20[2];
	transposed[2] = mat20[1];
	transposed[3] = mat20[3];
	result[0] = transposed[0];
	result[1] = transposed[1];
	result[2] = transposed[2];
	result[3] = transposed[3];
	return result;
}

mfloat_t *mat2_cofactor(mfloat_t *result, mfloat_t *mat20)
{
	mfloat_t cofactor[MAT2_SIZE];
	cofactor[0] = mat20[3];
	cofactor[1] = -mat20[2];
	cofactor[2] = -mat20[1];
	cofactor[3] = mat20[0];
	result[0] = cofactor[0];
	result[1] = cofactor[1];
	result[2] = cofactor[2];
	result[3] = cofactor[3];
	return result;
}

mfloat_t *mat2_adjugate(mfloat_t *result, mfloat_t *mat20)
{
	mfloat_t adjugate[MAT2_SIZE];
	adjugate[0] = mat20[3];
	adjugate[1] = -mat20[1];
	adjugate[2] = -mat20[2];
	adjugate[3] = mat20[0];
	result[0] = adjugate[0];
	result[1] = adjugate[1];
	result[2] = adjugate[2];
	result[3] = adjugate[3];
	return result;
}

mfloat_t *mat2_multiply(mfloat_t *result, mfloat_t *mat20, mfloat_t *mat21)
{
	mfloat_t multiplied[MAT3_SIZE];
	multiplied[0] = mat20[0] * mat21[0] + mat20[2] * mat21[1];
	multiplied[1] = mat20[1] * mat21[0] + mat20[3] * mat21[1];
	multiplied[2] = mat20[0] * mat21[2] + mat20[2] * mat21[3];
	multiplied[3] = mat20[1] * mat21[2] + mat20[3] * mat21[3];
	result[0] = multiplied[0];
	result[1] = multiplied[1];
	result[2] = multiplied[2];
	result[3] = multiplied[3];
	return result;
}

mfloat_t *mat2_multiply_f(mfloat_t *result, mfloat_t *mat20, mfloat_t f)
{
	result[0] = mat20[0] * f;
	result[1] = mat20[1] * f;
	result[2] = mat20[2] * f;
	result[3] = mat20[3] * f;
	return result;
}

mfloat_t *mat2_inverse(mfloat_t *result, mfloat_t *mat20)
{
	mfloat_t inverse[MAT2_SIZE];
	mfloat_t det = mat2_determinant(mat20);
	mat2_cofactor(inverse, mat20);
	mat2_multiply_f(inverse, inverse, MFLOAT_C(1.0) / det);
	result[0] = inverse[0];
	result[1] = inverse[1];
	result[2] = inverse[2];
	result[3] = inverse[3];
	return result;
}

mfloat_t *mat2_scaling(mfloat_t *result, mfloat_t *vec20)
{
	result[0] = vec20[0];
	result[3] = vec20[1];
	return result;
}

mfloat_t *mat2_scale(mfloat_t *result, mfloat_t *mat20, mfloat_t *vec20)
{
	result[0] = mat20[0] * vec20[0];
	result[3] = mat20[3] * vec20[1];
	return result;
}

mfloat_t *mat2_rotation_z(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[0] = c;
	result[1] = s;
	result[2] = -s;
	result[3] = c;
	return result;
}

mfloat_t *mat2_lerp(mfloat_t *result, mfloat_t *mat20, mfloat_t *mat21, mfloat_t f)
{
	result[0] = mat20[0] + (mat21[0] - mat20[0]) * f;
	result[1] = mat20[1] + (mat21[1] - mat20[1]) * f;
	result[2] = mat20[2] + (mat21[2] - mat20[2]) * f;
	result[3] = mat20[3] + (mat21[3] - mat20[3]) * f;
	return result;
}

mfloat_t *mat3(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33)
{
	result[0] = m11;
	result[1] = m21;
	result[2] = m31;
	result[3] = m12;
	result[4] = m22;
	result[5] = m32;
	result[6] = m13;
	result[7] = m23;
	result[8] = m33;
	return result;
}

mfloat_t *mat3_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(0.0);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *mat3_identity(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(1.0);
	result[5] = MFLOAT_C(0.0);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(8.0);
	return result;
}

mfloat_t mat3_determinant(mfloat_t *mat30)
{
	mfloat_t m11 = mat30[0];
	mfloat_t m21 = mat30[1];
	mfloat_t m31 = mat30[2];
	mfloat_t m12 = mat30[3];
	mfloat_t m22 = mat30[4];
	mfloat_t m32 = mat30[5];
	mfloat_t m13 = mat30[6];
	mfloat_t m23 = mat30[7];
	mfloat_t m33 = mat30[8];
	mfloat_t determinant = m11 * m22 * m33
		+ m12 * m23 * m31
		+ m13 * m21 * m32
		- m11 * m23 * m32
		- m12 * m21 * m33
		- m13 * m22 * m31;
	return determinant;
}

mfloat_t *mat3_assign(mfloat_t *result, mfloat_t *mat30)
{
	result[0] = mat30[0];
	result[1] = mat30[1];
	result[2] = mat30[2];
	result[3] = mat30[3];
	result[4] = mat30[4];
	result[5] = mat30[5];
	result[6] = mat30[6];
	result[7] = mat30[7];
	result[8] = mat30[8];
	return result;
}

mfloat_t *mat3_negative(mfloat_t *result, mfloat_t *mat30)
{
	result[0] = -mat30[0];
	result[1] = -mat30[1];
	result[2] = -mat30[2];
	result[3] = -mat30[3];
	result[4] = -mat30[4];
	result[5] = -mat30[5];
	result[6] = -mat30[6];
	result[7] = -mat30[7];
	result[8] = -mat30[8];
	return result;
}

mfloat_t *mat3_transpose(mfloat_t *result, mfloat_t *mat30)
{
	mfloat_t transposed[MAT4_SIZE];
	transposed[0] = mat30[0];
	transposed[1] = mat30[3];
	transposed[2] = mat30[6];
	transposed[3] = mat30[1];
	transposed[4] = mat30[4];
	transposed[5] = mat30[7];
	transposed[6] = mat30[2];
	transposed[7] = mat30[5];
	transposed[8] = mat30[8];
	result[0] = transposed[0];
	result[1] = transposed[1];
	result[2] = transposed[2];
	result[3] = transposed[3];
	result[4] = transposed[4];
	result[5] = transposed[5];
	result[6] = transposed[6];
	result[7] = transposed[7];
	result[8] = transposed[8];
	return result;
}

mfloat_t *mat3_cofactor(mfloat_t *result, mfloat_t *mat30)
{
	mfloat_t cofactor[MAT3_SIZE];
	mfloat_t minor[MAT2_SIZE];
	minor[0] = mat30[4];
	minor[1] = mat30[5];
	minor[2] = mat30[7];
	minor[3] = mat30[8];
	cofactor[0] = mat2_determinant(minor);
	minor[0] = mat30[3];
	minor[1] = mat30[5];
	minor[2] = mat30[6];
	minor[3] = mat30[8];
	cofactor[1] = -mat2_determinant(minor);
	minor[0] = mat30[3];
	minor[1] = mat30[4];
	minor[2] = mat30[6];
	minor[3] = mat30[7];
	cofactor[2] = mat2_determinant(minor);
	minor[0] = mat30[1];
	minor[1] = mat30[2];
	minor[2] = mat30[7];
	minor[3] = mat30[8];
	cofactor[3] = -mat2_determinant(minor);
	minor[0] = mat30[0];
	minor[1] = mat30[2];
	minor[2] = mat30[6];
	minor[3] = mat30[8];
	cofactor[4] = mat2_determinant(minor);
	minor[0] = mat30[0];
	minor[1] = mat30[1];
	minor[2] = mat30[6];
	minor[3] = mat30[7];
	cofactor[5] = -mat2_determinant(minor);
	minor[0] = mat30[1];
	minor[1] = mat30[2];
	minor[2] = mat30[4];
	minor[3] = mat30[5];
	cofactor[6] = mat2_determinant(minor);
	minor[0] = mat30[0];
	minor[1] = mat30[2];
	minor[2] = mat30[3];
	minor[3] = mat30[5];
	cofactor[7] = -mat2_determinant(minor);
	minor[0] = mat30[0];
	minor[1] = mat30[1];
	minor[2] = mat30[3];
	minor[3] = mat30[4];
	cofactor[8] = mat2_determinant(minor);
	result[0] = cofactor[0];
	result[1] = cofactor[1];
	result[2] = cofactor[2];
	result[3] = cofactor[3];
	result[4] = cofactor[4];
	result[5] = cofactor[5];
	result[6] = cofactor[6];
	result[7] = cofactor[7];
	result[8] = cofactor[8];
	return result;
}

mfloat_t *mat3_multiply(mfloat_t *result, mfloat_t *mat30, mfloat_t *mat31)
{
	mfloat_t multiplied[MAT3_SIZE];
	multiplied[0] = mat30[0] * mat31[0] + mat30[3] * mat31[1] + mat30[6] * mat31[2];
	multiplied[1] = mat30[1] * mat31[0] + mat30[4] * mat31[1] + mat30[7] * mat31[2];
	multiplied[2] = mat30[2] * mat31[0] + mat30[5] * mat31[1] + mat30[8] * mat31[2];
	multiplied[3] = mat30[0] * mat31[3] + mat30[3] * mat31[4] + mat30[6] * mat31[5];
	multiplied[4] = mat30[1] * mat31[3] + mat30[4] * mat31[4] + mat30[7] * mat31[5];
	multiplied[5] = mat30[2] * mat31[3] + mat30[5] * mat31[4] + mat30[8] * mat31[5];
	multiplied[6] = mat30[0] * mat31[6] + mat30[3] * mat31[7] + mat30[6] * mat31[8];
	multiplied[7] = mat30[1] * mat31[6] + mat30[4] * mat31[7] + mat30[7] * mat31[8];
	multiplied[8] = mat30[2] * mat31[6] + mat30[5] * mat31[7] + mat30[8] * mat31[8];
	result[0] = multiplied[0];
	result[1] = multiplied[1];
	result[2] = multiplied[2];
	result[3] = multiplied[3];
	result[4] = multiplied[4];
	result[5] = multiplied[5];
	result[6] = multiplied[6];
	result[7] = multiplied[7];
	result[8] = multiplied[8];
	return result;
}

mfloat_t *mat3_multiply_f(mfloat_t *result, mfloat_t *mat30, mfloat_t f)
{
	result[0] = mat30[0] * f;
	result[1] = mat30[1] * f;
	result[2] = mat30[2] * f;
	result[3] = mat30[3] * f;
	result[4] = mat30[4] * f;
	result[5] = mat30[5] * f;
	result[6] = mat30[6] * f;
	result[7] = mat30[7] * f;
	result[8] = mat30[8] * f;
	return result;
}

mfloat_t *mat3_inverse(mfloat_t *result, mfloat_t *mat30)
{
	result = mat30;
	return result;
}

mfloat_t *mat3_scaling(mfloat_t *result, mfloat_t *vec30)
{
	result[0] = vec30[0];
	result[4] = vec30[1];
	result[8] = vec30[2];
	return result;
}

mfloat_t *mat3_scale(mfloat_t *result, mfloat_t *mat30, mfloat_t *vec30)
{
	result[0] = mat30[0] * vec30[0];
	result[4] = mat30[4] * vec30[1];
	result[8] = mat30[8] * vec30[2];
	return result;
}

mfloat_t *mat3_rotation_x(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[4] = c;
	result[5] = s;
	result[7] = -s;
	result[8] = -c;
	return result;
}

mfloat_t *mat3_rotation_y(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[0] = c;
	result[2] = -s;
	result[6] = s;
	result[8] = c;
	return result;
}

mfloat_t *mat3_rotation_z(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[0] = c;
	result[1] = s;
	result[3] = -s;
	result[4] = c;
	return result;
}

mfloat_t *mat3_rotation_axis(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	mfloat_t one_c = MFLOAT_C(1.0) - c;
	mfloat_t x = vec30[0];
	mfloat_t y = vec30[4];
	mfloat_t z = vec30[8];
	mfloat_t xx = x * x;
	mfloat_t xy = x * y;
	mfloat_t xz = x * z;
	mfloat_t yy = y * y;
	mfloat_t yz = y * z;
	mfloat_t zz = z * z;
	mfloat_t l = xx + yy + zz;
	mfloat_t sqrt_l = MSQRT(l);
	result[0] = (xx + (yy + zz) * c) / l;
	result[1] = (xy * one_c + vec30[2] * sqrt_l * s) / l;
	result[2] = (xz * one_c - vec30[1] * sqrt_l * s) / l;
	result[3] = (xy * one_c - vec30[2] * sqrt_l * s) / l;
	result[4] = (yy + (xx + zz) * c) / l;
	result[5] = (yz * one_c + vec30[0] * sqrt_l * s) / l;
	result[6] = (xz * one_c + vec30[1] * sqrt_l * s) / l;
	result[7] = (yz * one_c - vec30[0] * sqrt_l * s) / l;
	result[8] = (zz + (xx + yy) * c) / l;
	return result;
}

mfloat_t *mat3_rotation_quat(mfloat_t *result, mfloat_t *quat0)
{
	mfloat_t xx = quat0[0] * quat0[0];
	mfloat_t yy = quat0[1] * quat0[1];
	mfloat_t zz = quat0[2] * quat0[2];
	mfloat_t xy = quat0[0] * quat0[1];
	mfloat_t zw = quat0[2] * quat0[3];
	mfloat_t xz = quat0[8] * quat0[0];
	mfloat_t yw = quat0[1] * quat0[3];
	mfloat_t yz = quat0[1] * quat0[2];
	mfloat_t xw = quat0[0] * quat0[3];
	result[0] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (yy - zz);
	result[1] = MFLOAT_C(2.0) * (xy + zw);
	result[2] = MFLOAT_C(2.0) * (xz - yw);
	result[3] = MFLOAT_C(2.0) * (xy - zw);
	result[4] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - zz);
	result[5] = MFLOAT_C(2.0) * (yz + xw);
	result[6] = MFLOAT_C(2.0) * (xz + yw);
	result[7] = MFLOAT_C(2.0) * (yz - xw);
	result[8] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - yy);
	return result;
}

mfloat_t *mat3_lerp(mfloat_t *result, mfloat_t *mat30, mfloat_t *mat31, mfloat_t f)
{
	result[0] = mat30[0] + (mat31[0] - mat30[0]) * f;
	result[1] = mat30[1] + (mat31[1] - mat30[1]) * f;
	result[2] = mat30[2] + (mat31[2] - mat30[2]) * f;
	result[3] = mat30[3] + (mat31[3] - mat30[3]) * f;
	result[4] = mat30[4] + (mat31[4] - mat30[4]) * f;
	result[5] = mat30[5] + (mat31[5] - mat30[5]) * f;
	result[6] = mat30[6] + (mat31[6] - mat30[6]) * f;
	result[7] = mat30[7] + (mat31[7] - mat30[7]) * f;
	result[8] = mat30[8] + (mat31[8] - mat30[8]) * f;
	return result;
}

mfloat_t *mat4(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44)
{
	result[0] = m11;
	result[1] = m21;
	result[2] = m31;
	result[3] = m41;
	result[4] = m12;
	result[5] = m22;
	result[6] = m32;
	result[7] = m42;
	result[8] = m13;
	result[9] = m23;
	result[10] = m33;
	result[11] = m43;
	result[12] = m14;
	result[13] = m24;
	result[14] = m34;
	result[15] = m44;
	return result;
}

mfloat_t *mat4_zero(mfloat_t *result)
{
	result[0] = MFLOAT_C(0.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(0.0);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = MFLOAT_C(0.0);
	result[11] = MFLOAT_C(0.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = MFLOAT_C(0.0);
	result[15] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *mat4_identity(mfloat_t *result)
{
	result[0] = MFLOAT_C(1.0);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(1.0);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = MFLOAT_C(1.0);
	result[11] = MFLOAT_C(0.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = MFLOAT_C(0.0);
	result[15] = MFLOAT_C(1.0);
	return result;
}

mfloat_t mat4_determinant(mfloat_t *mat40)
{
	mfloat_t m11 = mat40[0];
	mfloat_t m21 = mat40[1];
	mfloat_t m31 = mat40[2];
	mfloat_t m41 = mat40[3];
	mfloat_t m12 = mat40[4];
	mfloat_t m22 = mat40[5];
	mfloat_t m32 = mat40[6];
	mfloat_t m42 = mat40[7];
	mfloat_t m13 = mat40[8];
	mfloat_t m23 = mat40[9];
	mfloat_t m33 = mat40[10];
	mfloat_t m43 = mat40[11];
	mfloat_t m14 = mat40[12];
	mfloat_t m24 = mat40[13];
	mfloat_t m34 = mat40[14];
	mfloat_t m44 = mat40[15];
	mfloat_t determinant = m14 * m23 * m32 * m41 - m13 * m24 * m32 * m41
		- m14 * m22 * m33 * m41 + m12 * m24 * m33 * m41
		+ m13 * m22 * m34 * m41 - m12 * m23 * m34 * m41
		- m14 * m23 * m31 * m42 + m13 * m24 * m31 * m42
		+ m14 * m21 * m33 * m42 - m11 * m24 * m33 * m42
		- m13 * m21 * m34 * m42 + m11 * m23 * m34 * m42
		+ m14 * m22 * m31 * m43 - m12 * m24 * m31 * m43
		- m14 * m21 * m32 * m43 + m11 * m24 * m32 * m43
		+ m12 * m21 * m34 * m43 - m11 * m22 * m34 * m43
		- m13 * m22 * m31 * m44 + m12 * m23 * m31 * m44
		+ m13 * m21 * m32 * m44 - m11 * m23 * m32 * m44
		- m12 * m21 * m33 * m44 + m11 * m22 * m33 * m44;
	return determinant;
}

mfloat_t *mat4_assign(mfloat_t *result, mfloat_t *mat40)
{
	result[0] = mat40[0];
	result[1] = mat40[1];
	result[2] = mat40[2];
	result[3] = mat40[3];
	result[4] = mat40[4];
	result[5] = mat40[5];
	result[6] = mat40[6];
	result[7] = mat40[7];
	result[8] = mat40[8];
	result[9] = mat40[9];
	result[10] = mat40[10];
	result[11] = mat40[11];
	result[12] = mat40[12];
	result[13] = mat40[13];
	result[14] = mat40[14];
	result[15] = mat40[15];
	return result;
}

mfloat_t *mat4_negative(mfloat_t *result, mfloat_t *mat40)
{
	result[0] = -mat40[0];
	result[1] = -mat40[1];
	result[2] = -mat40[2];
	result[3] = -mat40[3];
	result[4] = -mat40[4];
	result[5] = -mat40[5];
	result[6] = -mat40[6];
	result[7] = -mat40[7];
	result[8] = -mat40[8];
	result[9] = -mat40[9];
	result[10] = -mat40[10];
	result[11] = -mat40[11];
	result[12] = -mat40[12];
	result[13] = -mat40[13];
	result[14] = -mat40[14];
	result[15] = -mat40[15];
	return result;
}

mfloat_t *mat4_transpose(mfloat_t *result, mfloat_t *mat40)
{
	mfloat_t transposed[MAT4_SIZE];
	transposed[0] = mat40[0];
	transposed[1] = mat40[4];
	transposed[2] = mat40[8];
	transposed[3] = mat40[12];
	transposed[4] = mat40[1];
	transposed[5] = mat40[5];
	transposed[6] = mat40[9];
	transposed[7] = mat40[13];
	transposed[8] = mat40[2];
	transposed[9] = mat40[6];
	transposed[10] = mat40[10];
	transposed[11] = mat40[14];
	transposed[12] = mat40[3];
	transposed[13] = mat40[7];
	transposed[14] = mat40[11];
	transposed[15] = mat40[15];
	result[0] = transposed[0];
	result[1] = transposed[1];
	result[2] = transposed[2];
	result[3] = transposed[3];
	result[4] = transposed[4];
	result[5] = transposed[5];
	result[6] = transposed[6];
	result[7] = transposed[7];
	result[8] = transposed[8];
	result[9] = transposed[9];
	result[10] = transposed[10];
	result[11] = transposed[11];
	result[12] = transposed[12];
	result[13] = transposed[13];
	result[14] = transposed[14];
	result[15] = transposed[15];
	return result;
}

mfloat_t *mat4_cofactor(mfloat_t *result, mfloat_t *mat40)
{
	mfloat_t cofactor[MAT4_SIZE];
	mfloat_t minor[MAT3_SIZE];
	minor[0] = mat40[5];
	minor[1] = mat40[6];
	minor[2] = mat40[7];
	minor[3] = mat40[9];
	minor[4] = mat40[10];
	minor[5] = mat40[11];
	minor[6] = mat40[13];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[0] = mat3_determinant(minor);
	minor[0] = mat40[4];
	minor[1] = mat40[6];
	minor[2] = mat40[7];
	minor[3] = mat40[8];
	minor[4] = mat40[10];
	minor[5] = mat40[11];
	minor[6] = mat40[12];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[1] = -mat3_determinant(minor);
	minor[0] = mat40[4];
	minor[1] = mat40[5];
	minor[2] = mat40[7];
	minor[3] = mat40[8];
	minor[4] = mat40[9];
	minor[5] = mat40[11];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[15];
	cofactor[2] = mat3_determinant(minor);
	minor[0] = mat40[4];
	minor[1] = mat40[5];
	minor[2] = mat40[6];
	minor[3] = mat40[8];
	minor[4] = mat40[9];
	minor[5] = mat40[10];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[14];
	cofactor[3] = -mat3_determinant(minor);
	minor[0] = mat40[1];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[9];
	minor[4] = mat40[10];
	minor[5] = mat40[11];
	minor[6] = mat40[13];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[4] = -mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[8];
	minor[4] = mat40[10];
	minor[5] = mat40[11];
	minor[6] = mat40[12];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[5] = mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[3];
	minor[3] = mat40[8];
	minor[4] = mat40[9];
	minor[5] = mat40[11];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[15];
	cofactor[6] = -mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[2];
	minor[3] = mat40[8];
	minor[4] = mat40[9];
	minor[5] = mat40[10];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[14];
	cofactor[7] = mat3_determinant(minor);
	minor[0] = mat40[1];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[5];
	minor[4] = mat40[6];
	minor[5] = mat40[7];
	minor[6] = mat40[13];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[8] = mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[4];
	minor[4] = mat40[6];
	minor[5] = mat40[7];
	minor[6] = mat40[12];
	minor[7] = mat40[14];
	minor[8] = mat40[15];
	cofactor[9] = -mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[3];
	minor[3] = mat40[4];
	minor[4] = mat40[5];
	minor[5] = mat40[7];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[15];
	cofactor[10] = mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[2];
	minor[3] = mat40[4];
	minor[4] = mat40[5];
	minor[5] = mat40[6];
	minor[6] = mat40[12];
	minor[7] = mat40[13];
	minor[8] = mat40[14];
	cofactor[11] = -mat3_determinant(minor);
	minor[0] = mat40[1];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[5];
	minor[4] = mat40[6];
	minor[5] = mat40[7];
	minor[6] = mat40[9];
	minor[7] = mat40[10];
	minor[8] = mat40[11];
	cofactor[12] = -mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[2];
	minor[2] = mat40[3];
	minor[3] = mat40[4];
	minor[4] = mat40[6];
	minor[5] = mat40[7];
	minor[6] = mat40[8];
	minor[7] = mat40[10];
	minor[8] = mat40[11];
	cofactor[13] = mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[3];
	minor[3] = mat40[4];
	minor[4] = mat40[5];
	minor[5] = mat40[7];
	minor[6] = mat40[8];
	minor[7] = mat40[9];
	minor[8] = mat40[11];
	cofactor[14] = -mat3_determinant(minor);
	minor[0] = mat40[0];
	minor[1] = mat40[1];
	minor[2] = mat40[2];
	minor[3] = mat40[4];
	minor[4] = mat40[5];
	minor[5] = mat40[6];
	minor[6] = mat40[8];
	minor[7] = mat40[9];
	minor[8] = mat40[10];
	cofactor[15] = mat3_determinant(minor);
	result[0] = cofactor[0];
	result[1] = cofactor[1];
	result[2] = cofactor[2];
	result[3] = cofactor[3];
	result[4] = cofactor[4];
	result[5] = cofactor[5];
	result[6] = cofactor[6];
	result[7] = cofactor[7];
	result[8] = cofactor[8];
	result[9] = cofactor[9];
	result[10] = cofactor[10];
	result[11] = cofactor[11];
	result[12] = cofactor[12];
	result[13] = cofactor[13];
	result[14] = cofactor[14];
	result[15] = cofactor[15];
	return result;
}

mfloat_t *mat4_rotation_x(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[5] = c;
	result[6] = s;
	result[9] = -s;
	result[10] = c;
	return result;
}

mfloat_t *mat4_rotation_y(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[0] = c;
	result[2] = -s;
	result[8] = s;
	result[10] = c;
	return result;
}

mfloat_t *mat4_rotation_z(mfloat_t *result, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	result[0] = c;
	result[1] = s;
	result[4] = -s;
	result[5] = c;
	return result;
}

mfloat_t *mat4_rotation_axis(mfloat_t *result, mfloat_t *vec30, mfloat_t f)
{
	mfloat_t c = MCOS(f);
	mfloat_t s = MSIN(f);
	mfloat_t one_c = MFLOAT_C(1.0) - c;
	mfloat_t x = vec30[0];
	mfloat_t y = vec30[4];
	mfloat_t z = vec30[8];
	mfloat_t xx = x * x;
	mfloat_t xy = x * y;
	mfloat_t xz = x * z;
	mfloat_t yy = y * y;
	mfloat_t yz = y * z;
	mfloat_t zz = z * z;
	mfloat_t l = xx + yy + zz;
	mfloat_t sqrt_l = MSQRT(l);
	result[0] = (xx + (yy + zz) * c) / l;
	result[1] = (xy * one_c + vec30[2] * sqrt_l * s) / l;
	result[2] = (xz * one_c - vec30[1] * sqrt_l * s) / l;
	result[3] = MFLOAT_C(0.0);
	result[4] = (xy * one_c - vec30[2] * sqrt_l * s) / l;
	result[5] = (yy + (xx + zz) * c) / l;
	result[6] = (yz * one_c + vec30[0] * sqrt_l * s) / l;
	result[7] = MFLOAT_C(0.0);
	result[8] = (xz * one_c + vec30[1] * sqrt_l * s) / l;
	result[9] = (yz * one_c - vec30[0] * sqrt_l * s) / l;
	result[10] = (zz + (xx + yy) * c) / l;
	result[11] = MFLOAT_C(0.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = MFLOAT_C(0.0);
	result[15] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *mat4_rotation_quat(mfloat_t *result, mfloat_t *quat0)
{
	mfloat_t xx = quat0[0] * quat0[0];
	mfloat_t yy = quat0[1] * quat0[1];
	mfloat_t zz = quat0[2] * quat0[2];
	mfloat_t xy = quat0[0] * quat0[1];
	mfloat_t zw = quat0[2] * quat0[3];
	mfloat_t xz = quat0[8] * quat0[0];
	mfloat_t yw = quat0[1] * quat0[3];
	mfloat_t yz = quat0[1] * quat0[2];
	mfloat_t xw = quat0[0] * quat0[3];
	result[0] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (yy - zz);
	result[1] = MFLOAT_C(2.0) * (xy + zw);
	result[2] = MFLOAT_C(2.0) * (xz - yw);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(2.0) * (xy - zw);
	result[5] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - zz);
	result[6] = MFLOAT_C(2.0) * (yz + xw);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(2.0) * (xz + yw);
	result[9] = MFLOAT_C(2.0) * (yz - xw);
	result[10] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - yy);
	result[11] = MFLOAT_C(0.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = MFLOAT_C(0.0);
	result[15] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *mat4_translation(mfloat_t *result, mfloat_t *mat40, mfloat_t *vec30)
{
	result[0] = mat40[0];
	result[1] = mat40[1];
	result[2] = mat40[2];
	result[3] = mat40[3];
	result[4] = mat40[4];
	result[5] = mat40[5];
	result[6] = mat40[6];
	result[7] = mat40[7];
	result[8] = mat40[8];
	result[9] = mat40[9];
	result[10] = mat40[10];
	result[11] = mat40[11];
	result[12] = vec30[0];
	result[13] = vec30[1];
	result[14] = vec30[2];
	result[15] = mat40[15];
	return result;
}

mfloat_t *mat4_translate(mfloat_t *result, mfloat_t *mat40, mfloat_t *vec30)
{
	result[0] = mat40[0];
	result[1] = mat40[1];
	result[2] = mat40[2];
	result[3] = mat40[3];
	result[4] = mat40[4];
	result[5] = mat40[5];
	result[6] = mat40[6];
	result[7] = mat40[7];
	result[8] = mat40[8];
	result[9] = mat40[9];
	result[10] = mat40[10];
	result[11] = mat40[11];
	result[12] = mat40[12] + vec30[0];
	result[13] = mat40[13] + vec30[1];
	result[14] = mat40[14] + vec30[2];
	result[15] = mat40[15];
	return result;
}

mfloat_t *mat4_scaling(mfloat_t *result, mfloat_t *mat40, mfloat_t *vec30)
{
	result[0] = vec30[0];
	result[1] = mat40[1];
	result[2] = mat40[2];
	result[3] = mat40[3];
	result[4] = mat40[4];
	result[5] = vec30[1];
	result[6] = mat40[6];
	result[7] = mat40[7];
	result[8] = mat40[8];
	result[9] = mat40[9];
	result[10] = vec30[2];
	result[11] = mat40[11];
	result[12] = mat40[12];
	result[13] = mat40[13];
	result[14] = mat40[14];
	result[15] = mat40[15];
	return result;
}

mfloat_t *mat4_scale(mfloat_t *result, mfloat_t *mat40, mfloat_t *vec30)
{
	result[0] = mat40[0] * vec30[0];
	result[1] = mat40[1];
	result[2] = mat40[2];
	result[3] = mat40[3];
	result[4] = mat40[4];
	result[5] = mat40[5] * vec30[1];
	result[6] = mat40[6];
	result[7] = mat40[7];
	result[8] = mat40[8];
	result[9] = mat40[9];
	result[10] = mat40[10] * vec30[2];
	result[11] = mat40[11];
	result[12] = mat40[12];
	result[13] = mat40[13];
	result[14] = mat40[14];
	result[15] = mat40[15];
	return result;
}

mfloat_t *mat4_multiply(mfloat_t *result, mfloat_t *mat40, mfloat_t *mat41)
{
	mfloat_t multiplied[MAT4_SIZE];
	multiplied[0] = mat40[0] * mat41[0] + mat40[4] * mat41[1] + mat40[8] * mat41[2] + mat40[12] * mat41[3];
	multiplied[1] = mat40[1] * mat41[0] + mat40[5] * mat41[1] + mat40[9] * mat41[2] + mat40[13] * mat41[3];
	multiplied[2] = mat40[2] * mat41[0] + mat40[6] * mat41[1] + mat40[10] * mat41[2] + mat40[14] * mat41[3];
	multiplied[3] = mat40[3] * mat41[0] + mat40[7] * mat41[1] + mat40[11] * mat41[2] + mat40[15] * mat41[3];
	multiplied[4] = mat40[0] * mat41[4] + mat40[4] * mat41[5] + mat40[8] * mat41[6] + mat40[12] * mat41[7];
	multiplied[5] = mat40[1] * mat41[4] + mat40[5] * mat41[5] + mat40[9] * mat41[6] + mat40[13] * mat41[7];
	multiplied[6] = mat40[2] * mat41[4] + mat40[6] * mat41[5] + mat40[10] * mat41[6] + mat40[14] * mat41[7];
	multiplied[7] = mat40[3] * mat41[4] + mat40[7] * mat41[5] + mat40[11] * mat41[6] + mat40[15] * mat41[7];
	multiplied[8] = mat40[0] * mat41[8] + mat40[4] * mat41[9] + mat40[8] * mat41[10] + mat40[12] * mat41[11];
	multiplied[9] = mat40[1] * mat41[8] + mat40[5] * mat41[9] + mat40[9] * mat41[10] + mat40[13] * mat41[11];
	multiplied[10] = mat40[2] * mat41[8] + mat40[6] * mat41[9] + mat40[10] * mat41[10] + mat40[14] * mat41[11];
	multiplied[11] = mat40[3] * mat41[8] + mat40[7] * mat41[9] + mat40[11] * mat41[10] + mat40[15] * mat41[11];
	multiplied[12] = mat40[0] * mat41[12] + mat40[4] * mat41[13] + mat40[8] * mat41[14] + mat40[12] * mat41[15];
	multiplied[13] = mat40[1] * mat41[12] + mat40[5] * mat41[13] + mat40[9] * mat41[14] + mat40[13] * mat41[15];
	multiplied[14] = mat40[2] * mat41[12] + mat40[6] * mat41[13] + mat40[10] * mat41[14] + mat40[14] * mat41[15];
	multiplied[15] = mat40[3] * mat41[12] + mat40[7] * mat41[13] + mat40[11] * mat41[14] + mat40[15] * mat41[15];
	result[0] = multiplied[0];
	result[1] = multiplied[1];
	result[2] = multiplied[2];
	result[3] = multiplied[3];
	result[4] = multiplied[4];
	result[5] = multiplied[5];
	result[6] = multiplied[6];
	result[7] = multiplied[7];
	result[8] = multiplied[8];
	result[9] = multiplied[9];
	result[10] = multiplied[10];
	result[11] = multiplied[11];
	result[12] = multiplied[12];
	result[13] = multiplied[13];
	result[14] = multiplied[14];
	result[15] = multiplied[15];
	return result;
}

mfloat_t *mat4_multiply_f(mfloat_t *result, mfloat_t *mat40, mfloat_t f)
{
	result[0] = mat40[0] * f;
	result[1] = mat40[1] * f;
	result[2] = mat40[2] * f;
	result[3] = mat40[3] * f;
	result[4] = mat40[4] * f;
	result[5] = mat40[5] * f;
	result[6] = mat40[6] * f;
	result[7] = mat40[7] * f;
	result[8] = mat40[8] * f;
	result[9] = mat40[9] * f;
	result[10] = mat40[10] * f;
	result[11] = mat40[11] * f;
	result[12] = mat40[12] * f;
	result[13] = mat40[13] * f;
	result[14] = mat40[14] * f;
	result[15] = mat40[15] * f;
	return result;
}

mfloat_t *mat4_inverse(mfloat_t *result, mfloat_t *mat40)
{
	mfloat_t inverse[MAT4_SIZE];
	mfloat_t inverted_determinant;
	mfloat_t m11 = mat40[0];
	mfloat_t m21 = mat40[1];
	mfloat_t m31 = mat40[2];
	mfloat_t m41 = mat40[3];
	mfloat_t m12 = mat40[4];
	mfloat_t m22 = mat40[5];
	mfloat_t m32 = mat40[6];
	mfloat_t m42 = mat40[7];
	mfloat_t m13 = mat40[8];
	mfloat_t m23 = mat40[9];
	mfloat_t m33 = mat40[10];
	mfloat_t m43 = mat40[11];
	mfloat_t m14 = mat40[12];
	mfloat_t m24 = mat40[13];
	mfloat_t m34 = mat40[14];
	mfloat_t m44 = mat40[15];
	inverse[0] = m22 * m33 * m44
		- m22 * m43 * m34
		- m23 * m32 * m44
		+ m23 * m42 * m34
		+ m24 * m32 * m43
		- m24 * m42 * m33;
	inverse[4] = -m12 * m33 * m44
		+ m12 * m43 * m34
		+ m13 * m32 * m44
		- m13 * m42 * m34
		- m14 * m32 * m43
		+ m14 * m42 * m33;
	inverse[8] = m12 * m23 * m44
		- m12 * m43 * m24
		- m13 * m22 * m44
		+ m13 * m42 * m24
		+ m14 * m22 * m43
		- m14 * m42 * m23;
	inverse[12] = -m12 * m23 * m34
		+ m12 * m33 * m24
		+ m13 * m22 * m34
		- m13 * m32 * m24
		- m14 * m22 * m33
		+ m14 * m32 * m23;
	inverse[1] = -m21 * m33 * m44
		+ m21 * m43 * m34
		+ m23 * m31 * m44
		- m23 * m41 * m34
		- m24 * m31 * m43
		+ m24 * m41 * m33;
	inverse[5] =m11 * m33 * m44
		-m11 * m43 * m34
		- m13 * m31 * m44
		+ m13 * m41 * m34
		+ m14 * m31 * m43
		- m14 * m41 * m33;
	inverse[9] = -m11 * m23 * m44
		+m11 * m43 * m24
		+ m13 * m21 * m44
		- m13 * m41 * m24
		- m14 * m21 * m43
		+ m14 * m41 * m23;
	inverse[13] =m11 * m23 * m34
		-m11 * m33 * m24
		- m13 * m21 * m34
		+ m13 * m31 * m24
		+ m14 * m21 * m33
		- m14 * m31 * m23;
	inverse[2] = m21 * m32 * m44
		- m21 * m42 * m34
		- m22 * m31 * m44
		+ m22 * m41 * m34
		+ m24 * m31 * m42
		- m24 * m41 * m32;
	inverse[6] = -m11 * m32 * m44
		+m11 * m42 * m34
		+ m12 * m31 * m44
		- m12 * m41 * m34
		- m14 * m31 * m42
		+ m14 * m41 * m32;
	inverse[10] =m11 * m22 * m44
		-m11 * m42 * m24
		- m12 * m21 * m44
		+ m12 * m41 * m24
		+ m14 * m21 * m42
		- m14 * m41 * m22;
	inverse[14] = -m11 * m22 * m34
		+m11 * m32 * m24
		+ m12 * m21 * m34
		- m12 * m31 * m24
		- m14 * m21 * m32
		+ m14 * m31 * m22;
	inverse[3] = -m21 * m32 * m43
		+ m21 * m42 * m33
		+ m22 * m31 * m43
		- m22 * m41 * m33
		- m23 * m31 * m42
		+ m23 * m41 * m32;
	inverse[7] =m11 * m32 * m43
		-m11 * m42 * m33
		- m12 * m31 * m43
		+ m12 * m41 * m33
		+ m13 * m31 * m42
		- m13 * m41 * m32;
	inverse[11] = -m11 * m22 * m43
		+m11 * m42 * m23
		+ m12 * m21 * m43
		- m12 * m41 * m23
		- m13 * m21 * m42
		+ m13 * m41 * m22;
	inverse[15] =m11 * m22 * m33
		-m11 * m32 * m23
		- m12 * m21 * m33
		+ m12 * m31 * m23
		+ m13 * m21 * m32
		- m13 * m31 * m22;
	inverted_determinant = MFLOAT_C(1.0) / (m11 * inverse[0] + m21 * inverse[4] + m31 * inverse[8] + m41 * inverse[12]);
	result[0] = inverse[0] * inverted_determinant;
	result[1] = inverse[1] * inverted_determinant;
	result[2] = inverse[2] * inverted_determinant;
	result[3] = inverse[3] * inverted_determinant;
	result[4] = inverse[4] * inverted_determinant;
	result[5] = inverse[5] * inverted_determinant;
	result[6] = inverse[6] * inverted_determinant;
	result[7] = inverse[7] * inverted_determinant;
	result[8] = inverse[8] * inverted_determinant;
	result[9] = inverse[9] * inverted_determinant;
	result[10] = inverse[10] * inverted_determinant;
	result[11] = inverse[11] * inverted_determinant;
	result[12] = inverse[12] * inverted_determinant;
	result[13] = inverse[13] * inverted_determinant;
	result[14] = inverse[14] * inverted_determinant;
	result[15] = inverse[15] * inverted_determinant;
	return result;
}

mfloat_t *mat4_lerp(mfloat_t *result, mfloat_t *mat40, mfloat_t *mat41, mfloat_t f)
{
	result[0] = mat40[0] + (mat41[0] - mat40[0]) * f;
	result[1] = mat40[1] + (mat41[1] - mat40[1]) * f;
	result[2] = mat40[2] + (mat41[2] - mat40[2]) * f;
	result[3] = mat40[3] + (mat41[3] - mat40[3]) * f;
	result[4] = mat40[4] + (mat41[4] - mat40[4]) * f;
	result[5] = mat40[5] + (mat41[5] - mat40[5]) * f;
	result[6] = mat40[6] + (mat41[6] - mat40[6]) * f;
	result[7] = mat40[7] + (mat41[7] - mat40[7]) * f;
	result[8] = mat40[8] + (mat41[8] - mat40[8]) * f;
	result[9] = mat40[9] + (mat41[9] - mat40[9]) * f;
	result[10] = mat40[10] + (mat41[10] - mat40[10]) * f;
	result[11] = mat40[11] + (mat41[11] - mat40[11]) * f;
	result[12] = mat40[12] + (mat41[12] - mat40[12]) * f;
	result[13] = mat40[13] + (mat41[13] - mat40[13]) * f;
	result[14] = mat40[14] + (mat41[14] - mat40[14]) * f;
	result[15] = mat40[15] + (mat41[15] - mat40[15]) * f;
	return result;
}

mfloat_t *mat4_look_at(mfloat_t *result, mfloat_t *vec30, mfloat_t *vec31, mfloat_t *vec32)
{
	mfloat_t forward[VEC3_SIZE];
	mfloat_t side[VEC3_SIZE];
	mfloat_t up[VEC3_SIZE];
	vec3_subtract(forward, vec31, vec30);
	vec3_normalize(forward, forward);
	vec3_cross(side, forward, vec32);
	vec3_normalize(side, side);
	vec3_cross(up, side, forward);
	result[0] = side[0];
	result[1] = side[1];
	result[2] = side[2];
	result[3] = vec3_dot(side, vec30);
	result[4] = up[0];
	result[5] = up[1];
	result[6] = up[2];
	result[7] = vec3_dot(up, vec30);
	result[8] = forward[0];
	result[9] = forward[1];
	result[10] = forward[2];
	result[11] = vec3_dot(forward, vec30);
	return result;
}

mfloat_t *mat4_ortho(mfloat_t *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f)
{
	result[0] = MFLOAT_C(2.0) / (r - l);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(2.0) / (t - b);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = -MFLOAT_C(2.0) / (f - n);
	result[11] = MFLOAT_C(0.0);
	result[12] = -((r + l) / (r - l));
	result[13] = -((t + b) / (t - b));
	result[14] = -((f + n) / (f - n));
	result[15] = MFLOAT_C(1.0);
	return result;
}

mfloat_t *mat4_perspective(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f)
{
	mfloat_t tan_half_fov_y = MFLOAT_C(1.0) / MTAN(fov_y * MFLOAT_C(0.5));
	result[0] = MFLOAT_C(1.0) / aspect * tan_half_fov_y;
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(1.0) / tan_half_fov_y;
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = f / (n - f);
	result[11] = -MFLOAT_C(1.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = -(f * n) / (f - n);
	result[15] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *mat4_perspective_fov(mfloat_t *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f)
{
	mfloat_t h2 = MCOS(fov * MFLOAT_C(0.5)) / MSIN(fov * MFLOAT_C(0.5));
	mfloat_t w2 = h2 * h / w;
	result[0] = w2;
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = h2;
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = f / (n - f);
	result[11] = -MFLOAT_C(1.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = -(f * n) / (f - n);
	result[15] = MFLOAT_C(0.0);
	return result;
}

mfloat_t *mat4_perspective_infinite(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n)
{
	mfloat_t range = MTAN(fov_y * MFLOAT_C(0.5)) * n;
	mfloat_t left = -range * aspect;
	mfloat_t right = range * aspect;
	mfloat_t top = range;
	mfloat_t bottom = -range;
	result[0] = MFLOAT_C(2.0) * n / (right - left);
	result[1] = MFLOAT_C(0.0);
	result[2] = MFLOAT_C(0.0);
	result[3] = MFLOAT_C(0.0);
	result[4] = MFLOAT_C(0.0);
	result[5] = MFLOAT_C(2.0) * n / (top - bottom);
	result[6] = MFLOAT_C(0.0);
	result[7] = MFLOAT_C(0.0);
	result[8] = MFLOAT_C(0.0);
	result[9] = MFLOAT_C(0.0);
	result[10] = -MFLOAT_C(1.0);
	result[11] = -MFLOAT_C(1.0);
	result[12] = MFLOAT_C(0.0);
	result[13] = MFLOAT_C(0.0);
	result[14] = -MFLOAT_C(2.0) * n;
	result[15] = MFLOAT_C(0.0);
	return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
#if defined(MATHC_USE_INT)
bool svec2i_is_zero(struct vec2i vec2i0)
{
	return vec2i_is_zero((mint_t *)&vec2i0);
}

bool svec2i_is_equal(struct vec2i vec2i0, struct vec2i vec2i1)
{
	return vec2i_is_equal((mint_t *)&vec2i0, (mint_t *)&vec2i1);
}

struct vec2i svec2i(mint_t x, mint_t y)
{
	struct vec2i result;
	vec2i((mint_t *)&result, x, y);
	return result;
}

struct vec2i svec2i_assign(struct vec2i vec2i0)
{
	struct vec2i result;
	vec2i_assign((mint_t *)&result, (mint_t *)&vec2i0);
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec2i svec2i_assign_vec2(struct vec2 vec20)
{
	struct vec2i result;
	vec2i_assign_vec2((mint_t *)&result, (mfloat_t *)&vec20);
	return result;
}
#endif

struct vec2i svec2i_zero(void)
{
	struct vec2i result;
	vec2i_zero((mint_t *)&result);
	return result;
}

struct vec2i svec2i_one(void)
{
	struct vec2i result;
	vec2i_one((mint_t *)&result);
	return result;
}

struct vec2i svec2i_sign(struct vec2i vec2i0)
{
	struct vec2i result;
	vec2i_sign((mint_t *)&result, (mint_t *)&vec2i0);
	return result;
}

struct vec2i svec2i_add(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_add((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_add_i(struct vec2i vec2i0, mint_t i)
{
	struct vec2i result;
	vec2i_add_i((mint_t *)&result, (mint_t *)&vec2i0, i);
	return result;
}

struct vec2i svec2i_subtract(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_subtract((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_subtract_i(struct vec2i vec2i0, mint_t i)
{
	struct vec2i result;
	vec2i_subtract_i((mint_t *)&result, (mint_t *)&vec2i0, i);
	return result;
}

struct vec2i svec2i_multiply(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_multiply((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_multiply_i(struct vec2i vec2i0, mint_t i)
{
	struct vec2i result;
	vec2i_multiply_i((mint_t *)&result, (mint_t *)&vec2i0, i);
	return result;
}

struct vec2i svec2i_divide(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_divide((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_divide_i(struct vec2i vec2i0, mint_t i)
{
	struct vec2i result;
	vec2i_divide_i((mint_t *)&result, (mint_t *)&vec2i0, i);
	return result;
}

struct vec2i svec2i_snap(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_snap((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_snap_i(struct vec2i vec2i0, mint_t i)
{
	struct vec2i result;
	vec2i_snap_i((mint_t *)&result, (mint_t *)&vec2i0, i);
	return result;
}

struct vec2i svec2i_negative(struct vec2i vec2i0)
{
	struct vec2i result;
	vec2i_negative((mint_t *)&result, (mint_t *)&vec2i0);
	return result;
}

struct vec2i svec2i_abs(struct vec2i vec2i0)
{
	struct vec2i result;
	vec2i_abs((mint_t *)&result, (mint_t *)&vec2i0);
	return result;
}

struct vec2i svec2i_max(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_max((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_min(struct vec2i vec2i0, struct vec2i vec2i1)
{
	struct vec2i result;
	vec2i_min((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1);
	return result;
}

struct vec2i svec2i_clamp(struct vec2i vec2i0, struct vec2i vec2i1, struct vec2i vec2i2)
{
	struct vec2i result;
	vec2i_clamp((mint_t *)&result, (mint_t *)&vec2i0, (mint_t *)&vec2i1, (mint_t *)&vec2i2);
	return result;
}

struct vec2i svec2i_tangent(struct vec2i vec2i0)
{
	struct vec2i result;
	vec2i_tangent((mint_t *)&result, (mint_t *)&vec2i0);
	return result;
}

bool svec3i_is_zero(struct vec3i vec3i0)
{
	return vec3i_is_zero((mint_t *)&vec3i0);
}

bool svec3i_is_equal(struct vec3i vec3i0, struct vec3i vec3i1)
{
	return vec3i_is_equal((mint_t *)&vec3i0, (mint_t *)&vec3i1);
}

struct vec3i svec3i(mint_t x, mint_t y, mint_t z)
{
	struct vec3i result;
	vec3i((mint_t *)&result, x, y, z);
	return result;
}

struct vec3i svec3i_assign(struct vec3i vec3i0)
{
	struct vec3i result;
	vec3i_assign((mint_t *)&result, (mint_t *)&vec3i0);
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec3i svec3i_assign_vec3(struct vec3 vec30)
{
	struct vec3i result;
	vec3i_assign_vec3((mint_t *)&result, (mfloat_t *)&vec30);
	return result;
}
#endif

struct vec3i svec3i_zero(void)
{
	struct vec3i result;
	vec3i_zero((mint_t *)&result);
	return result;
}

struct vec3i svec3i_one(void)
{
	struct vec3i result;
	vec3i_one((mint_t *)&result);
	return result;
}

struct vec3i svec3i_sign(struct vec3i vec3i0)
{
	struct vec3i result;
	vec3i_sign((mint_t *)&result, (mint_t *)&vec3i0);
	return result;
}

struct vec3i svec3i_add(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_add((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_add_i(struct vec3i vec3i0, mint_t i)
{
	struct vec3i result;
	vec3i_add_i((mint_t *)&result, (mint_t *)&vec3i0, i);
	return result;
}

struct vec3i svec3i_subtract(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_subtract((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_subtract_i(struct vec3i vec3i0, mint_t i)
{
	struct vec3i result;
	vec3i_subtract_i((mint_t *)&result, (mint_t *)&vec3i0, i);
	return result;
}

struct vec3i svec3i_multiply(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_multiply((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_multiply_i(struct vec3i vec3i0, mint_t i)
{
	struct vec3i result;
	vec3i_multiply_i((mint_t *)&result, (mint_t *)&vec3i0, i);
	return result;
}

struct vec3i svec3i_divide(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_divide((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_divide_i(struct vec3i vec3i0, mint_t i)
{
	struct vec3i result;
	vec3i_divide_i((mint_t *)&result, (mint_t *)&vec3i0, i);
	return result;
}

struct vec3i svec3i_snap(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_snap((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_snap_i(struct vec3i vec3i0, mint_t i)
{
	struct vec3i result;
	vec3i_snap_i((mint_t *)&result, (mint_t *)&vec3i0, i);
	return result;
}

struct vec3i svec3i_cross(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_cross((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_negative(struct vec3i vec3i0)
{
	struct vec3i result;
	vec3i_negative((mint_t *)&result, (mint_t *)&vec3i0);
	return result;
}

struct vec3i svec3i_abs(struct vec3i vec3i0)
{
	struct vec3i result;
	vec3i_abs((mint_t *)&result, (mint_t *)&vec3i0);
	return result;
}

struct vec3i svec3i_max(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_max((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_min(struct vec3i vec3i0, struct vec3i vec3i1)
{
	struct vec3i result;
	vec3i_min((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1);
	return result;
}

struct vec3i svec3i_clamp(struct vec3i vec3i0, struct vec3i vec3i1, struct vec3i vec3i2)
{
	struct vec3i result;
	vec3i_clamp((mint_t *)&result, (mint_t *)&vec3i0, (mint_t *)&vec3i1, (mint_t *)&vec3i2);
	return result;
}

bool svec4i_is_zero(struct vec4i vec4i0)
{
	return vec4i_is_zero((mint_t *)&vec4i0);
}

bool svec4i_is_equal(struct vec4i vec4i0, struct vec4i vec4i1)
{
	return vec4i_is_equal((mint_t *)&vec4i0, (mint_t *)&vec4i1);
}

struct vec4i svec4i(mint_t x, mint_t y, mint_t z, mint_t w)
{
	struct vec4i result;
	vec4i((mint_t *)&result, x, y, z, w);
	return result;
}

struct vec4i svec4i_assign(struct vec4i vec4i0)
{
	struct vec4i result;
	vec4i_assign((mint_t *)&result, (mint_t *)&vec4i0);
	return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec4i svec4i_assign_vec4(struct vec4 vec40)
{
	struct vec4i result;
	vec4i_assign_vec4((mint_t *)&result, (mfloat_t *)&vec40);
	return result;
}
#endif

struct vec4i svec4i_zero(void)
{
	struct vec4i result;
	vec4i_zero((mint_t *)&result);
	return result;
}

struct vec4i svec4i_one(void)
{
	struct vec4i result;
	vec4i_one((mint_t *)&result);
	return result;
}

struct vec4i svec4i_sign(struct vec4i vec4i0)
{
	struct vec4i result;
	vec4i_sign((mint_t *)&result, (mint_t *)&vec4i0);
	return result;
}

struct vec4i svec4i_add(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_add((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_add_i(struct vec4i vec4i0, mint_t i)
{
	struct vec4i result;
	vec4i_add_i((mint_t *)&result, (mint_t *)&vec4i0, i);
	return result;
}

struct vec4i svec4i_subtract(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_subtract((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_subtract_i(struct vec4i vec4i0, mint_t i)
{
	struct vec4i result;
	vec4i_subtract_i((mint_t *)&result, (mint_t *)&vec4i0, i);
	return result;
}

struct vec4i svec4i_multiply(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_multiply((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_multiply_i(struct vec4i vec4i0, mint_t i)
{
	struct vec4i result;
	vec4i_multiply_i((mint_t *)&result, (mint_t *)&vec4i0, i);
	return result;
}

struct vec4i svec4i_divide(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_divide((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_divide_i(struct vec4i vec4i0, mint_t i)
{
	struct vec4i result;
	vec4i_divide_i((mint_t *)&result, (mint_t *)&vec4i0, i);
	return result;
}

struct vec4i svec4i_snap(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_snap((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_snap_i(struct vec4i vec4i0, mint_t i)
{
	struct vec4i result;
	vec4i_snap_i((mint_t *)&result, (mint_t *)&vec4i0, i);
	return result;
}

struct vec4i svec4i_negative(struct vec4i vec4i0)
{
	struct vec4i result;
	vec4i_negative((mint_t *)&result, (mint_t *)&vec4i0);
	return result;
}

struct vec4i svec4i_abs(struct vec4i vec4i0)
{
	struct vec4i result;
	vec4i_abs((mint_t *)&result, (mint_t *)&vec4i0);
	return result;
}

struct vec4i svec4i_max(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_max((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_min(struct vec4i vec4i0, struct vec4i vec4i1)
{
	struct vec4i result;
	vec4i_min((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1);
	return result;
}

struct vec4i svec4i_clamp(struct vec4i vec4i0, struct vec4i vec4i1, struct vec4i vec4i2)
{
	struct vec4i result;
	vec4i_clamp((mint_t *)&result, (mint_t *)&vec4i0, (mint_t *)&vec4i1, (mint_t *)&vec4i2);
	return result;
}
#endif

#if defined(MATHC_USE_FLOATING_POINT)
bool svec2_is_zero(struct vec2 vec20)
{
	return vec2_is_zero((mfloat_t *)&vec20);
}

bool svec2_is_equal(struct vec2 vec20, struct vec2 vec21)
{
	return vec2_is_equal((mfloat_t *)&vec20, (mfloat_t *)&vec21);
}

struct vec2 svec2(mfloat_t x, mfloat_t y)
{
	struct vec2 result;
	vec2((mfloat_t *)&result, x, y);
	return result;
}

struct vec2 svec2_assign(struct vec2 vec20)
{
	struct vec2 result;
	vec2_assign((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

#if defined(MATHC_USE_INT)
struct vec2 svec2_assign_vec2i(struct vec2i vec2i0)
{
	struct vec2 result;
	vec2_assign_vec2i((mfloat_t *)&result, (mint_t *)&vec2i0);
	return result;
}
#endif

struct vec2 svec2_zero(void)
{
	struct vec2 result;
	vec2_zero((mfloat_t *)&result);
	return result;
}

struct vec2 svec2_one(void)
{
	struct vec2 result;
	vec2_one((mfloat_t *)&result);
	return result;
}

struct vec2 svec2_sign(struct vec2 vec20)
{
	struct vec2 result;
	vec2_sign((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_add(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_add((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_add_f(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_add_f((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_subtract(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_subtract((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_subtract_f(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_subtract_f((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_multiply(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_multiply((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_multiply_f(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_multiply_f((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_multiply_mat2(struct vec2 vec20, struct mat2 mat20)
{
	struct vec2 result;
	vec2_multiply_mat2((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&mat20);
	return result;
}

struct vec2 svec2_divide(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_divide((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_divide_f(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_divide_f((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_snap(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_snap((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_snap_f(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_snap_f((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_negative(struct vec2 vec20)
{
	struct vec2 result;
	vec2_negative((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_abs(struct vec2 vec20)
{
	struct vec2 result;
	vec2_abs((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_floor(struct vec2 vec20)
{
	struct vec2 result;
	vec2_floor((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_ceil(struct vec2 vec20)
{
	struct vec2 result;
	vec2_ceil((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_round(struct vec2 vec20)
{
	struct vec2 result;
	vec2_round((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_max(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_max((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_min(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_min((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_clamp(struct vec2 vec20, struct vec2 vec21, struct vec2 vec22)
{
	struct vec2 result;
	vec2_clamp((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21, (mfloat_t *)&vec22);
	return result;
}

struct vec2 svec2_normalize(struct vec2 vec20)
{
	struct vec2 result;
	vec2_normalize((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

mfloat_t svec2_dot(struct vec2 vec20, struct vec2 vec21)
{
	return vec2_dot((mfloat_t *)&vec20, (mfloat_t *)&vec21);
}

struct vec2 svec2_project(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_project((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_slide(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_slide((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_reflect(struct vec2 vec20, struct vec2 vec21)
{
	struct vec2 result;
	vec2_reflect((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21);
	return result;
}

struct vec2 svec2_tangent(struct vec2 vec20)
{
	struct vec2 result;
	vec2_tangent((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct vec2 svec2_rotate(struct vec2 vec20, mfloat_t f)
{
	struct vec2 result;
	vec2_rotate((mfloat_t *)&result, (mfloat_t *)&vec20, f);
	return result;
}

struct vec2 svec2_lerp(struct vec2 vec20, struct vec2 vec21, mfloat_t f)
{
	struct vec2 result;
	vec2_lerp((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21, f);
	return result;
}

struct vec2 svec2_bezier3(struct vec2 vec20, struct vec2 vec21, struct vec2 vec22, mfloat_t f)
{
	struct vec2 result;
	vec2_bezier3((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21, (mfloat_t *)&vec22, f);
	return result;
}

struct vec2 svec2_bezier4(struct vec2 vec20, struct vec2 vec21, struct vec2 vec22, struct vec2 vec23, mfloat_t f)
{
	struct vec2 result;
	vec2_bezier4((mfloat_t *)&result, (mfloat_t *)&vec20, (mfloat_t *)&vec21, (mfloat_t *)&vec22, (mfloat_t *)&vec23, f);
	return result;
}

mfloat_t svec2_angle(struct vec2 vec20)
{
	return vec2_angle((mfloat_t *)&vec20);
}

mfloat_t svec2_length(struct vec2 vec20)
{
	return vec2_length((mfloat_t *)&vec20);
}

mfloat_t svec2_length_squared(struct vec2 vec20)
{
	return vec2_length_squared((mfloat_t *)&vec20);
}

mfloat_t svec2_distance(struct vec2 vec20, struct vec2 vec21)
{
	return vec2_distance((mfloat_t *)&vec20, (mfloat_t *)&vec21);
}

mfloat_t svec2_distance_squared(struct vec2 vec20, struct vec2 vec21)
{
	return vec2_distance_squared((mfloat_t *)&vec20, (mfloat_t *)&vec21);
}

bool svec3_is_zero(struct vec3 vec30)
{
	return vec3_is_zero((mfloat_t *)&vec30);
}

bool svec3_is_equal(struct vec3 vec30, struct vec3 vec31)
{
	return vec3_is_equal((mfloat_t *)&vec30, (mfloat_t *)&vec31);
}

struct vec3 svec3(mfloat_t x, mfloat_t y, mfloat_t z)
{
	struct vec3 result;
	vec3((mfloat_t *)&result, x, y, z);
	return result;
}

struct vec3 svec3_assign(struct vec3 vec30)
{
	struct vec3 result;
	vec3_assign((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

#if defined(MATHC_USE_INT)
struct vec3 svec3_assign_vec3i(struct vec3i vec3i0)
{
	struct vec3 result;
	vec3_assign_vec3i((mfloat_t *)&result, (mint_t *)&vec3i0);
	return result;
}
#endif

struct vec3 svec3_zero(void)
{
	struct vec3 result;
	vec3_zero((mfloat_t *)&result);
	return result;
}

struct vec3 svec3_one(void)
{
	struct vec3 result;
	vec3_one((mfloat_t *)&result);
	return result;
}

struct vec3 svec3_sign(struct vec3 vec30)
{
	struct vec3 result;
	vec3_sign((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_add(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_add((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_add_f(struct vec3 vec30, mfloat_t f)
{
	struct vec3 result;
	vec3_add_f((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct vec3 svec3_subtract(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_subtract((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_subtract_f(struct vec3 vec30, mfloat_t f)
{
	struct vec3 result;
	vec3_subtract_f((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct vec3 svec3_multiply(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_multiply((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_multiply_f(struct vec3 vec30, mfloat_t f)
{
	struct vec3 result;
	vec3_multiply_f((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct vec3 svec3_multiply_mat3(struct vec3 vec30, struct mat3 mat30)
{
	struct vec3 result;
	vec3_multiply_mat3((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&mat30);
	return result;
}

struct vec3 svec3_divide(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_divide((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_divide_f(struct vec3 vec30, mfloat_t f)
{
	struct vec3 result;
	vec3_divide_f((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct vec3 svec3_snap(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_snap((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_snap_f(struct vec3 vec30, mfloat_t f)
{
	struct vec3 result;
	vec3_snap_f((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct vec3 svec3_negative(struct vec3 vec30)
{
	struct vec3 result;
	vec3_negative((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_abs(struct vec3 vec30)
{
	struct vec3 result;
	vec3_abs((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_floor(struct vec3 vec30)
{
	struct vec3 result;
	vec3_floor((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_ceil(struct vec3 vec30)
{
	struct vec3 result;
	vec3_ceil((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_round(struct vec3 vec30)
{
	struct vec3 result;
	vec3_round((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct vec3 svec3_max(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_max((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_min(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_min((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_clamp(struct vec3 vec30, struct vec3 vec31, struct vec3 vec32)
{
	struct vec3 result;
	vec3_clamp((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31, (mfloat_t *)&vec32);
	return result;
}

struct vec3 svec3_cross(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_cross((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_normalize(struct vec3 vec30)
{
	struct vec3 result;
	vec3_normalize((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

mfloat_t svec3_dot(struct vec3 vec30, struct vec3 vec31)
{
	return vec3_dot((mfloat_t *)&vec30, (mfloat_t *)&vec31);
}

struct vec3 svec3_project(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_project((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_slide(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_slide((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_reflect(struct vec3 vec30, struct vec3 vec31)
{
	struct vec3 result;
	vec3_reflect((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct vec3 svec3_lerp(struct vec3 vec30, struct vec3 vec31, mfloat_t f)
{
	struct vec3 result;
	vec3_lerp((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31, f);
	return result;
}

struct vec3 svec3_bezier3(struct vec3 vec30, struct vec3 vec31, struct vec3 vec32, mfloat_t f)
{
	struct vec3 result;
	vec3_bezier3((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31, (mfloat_t *)&vec32, f);
	return result;
}

struct vec3 svec3_bezier4(struct vec3 vec30, struct vec3 vec31, struct vec3 vec32, struct vec3 vec33, mfloat_t f)
{
	struct vec3 result;
	vec3_bezier4((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31, (mfloat_t *)&vec32, (mfloat_t *)&vec33, f);
	return result;
}

mfloat_t svec3_length(struct vec3 vec30)
{
	return vec3_length((mfloat_t *)&vec30);
}

mfloat_t svec3_length_squared(struct vec3 vec30)
{
	return vec3_length_squared((mfloat_t *)&vec30);
}

mfloat_t svec3_distance(struct vec3 vec30, struct vec3 vec31)
{
	return vec3_distance((mfloat_t *)&vec30, (mfloat_t *)&vec31);
}

mfloat_t svec3_distance_squared(struct vec3 vec30, struct vec3 vec31)
{
	return vec3_distance_squared((mfloat_t *)&vec30, (mfloat_t *)&vec31);
}

bool svec4_is_zero(struct vec4 vec40)
{
	return vec4_is_zero((mfloat_t *)&vec40);
}

bool svec4_is_equal(struct vec4 vec40, struct vec4 vec41)
{
	return vec4_is_equal((mfloat_t *)&vec40, (mfloat_t *)&vec41);
}

struct vec4 svec4(mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	struct vec4 result;
	vec4((mfloat_t *)&result, x, y, z, w);
	return result;
}

struct vec4 svec4_assign(struct vec4 vec40)
{
	struct vec4 result;
	vec4_assign((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

#if defined(MATHC_USE_INT)
struct vec4 svec4_assign_vec4i(struct vec4i vec4i0)
{
	struct vec4 result;
	vec4_assign_vec4i((mfloat_t *)&result, (mint_t *)&vec4i0);
	return result;
}
#endif

struct vec4 svec4_zero(void)
{
	struct vec4 result;
	vec4_zero((mfloat_t *)&result);
	return result;
}

struct vec4 svec4_one(void)
{
	struct vec4 result;
	vec4_one((mfloat_t *)&result);
	return result;
}

struct vec4 svec4_sign(struct vec4 vec40)
{
	struct vec4 result;
	vec4_sign((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_add(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_add((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_add_f(struct vec4 vec40, mfloat_t f)
{
	struct vec4 result;
	vec4_add_f((mfloat_t *)&result, (mfloat_t *)&vec40, f);
	return result;
}

struct vec4 svec4_subtract(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_subtract((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_subtract_f(struct vec4 vec40, mfloat_t f)
{
	struct vec4 result;
	vec4_subtract_f((mfloat_t *)&result, (mfloat_t *)&vec40, f);
	return result;
}

struct vec4 svec4_multiply(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_multiply((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_multiply_f(struct vec4 vec40, mfloat_t f)
{
	struct vec4 result;
	vec4_multiply_f((mfloat_t *)&result, (mfloat_t *)&vec40, f);
	return result;
}

struct vec4 svec4_multiply_mat4(struct vec4 vec40, struct mat4 mat40)
{
	struct vec4 result;
	vec4_multiply_mat4((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&mat40);
	return result;
}

struct vec4 svec4_divide(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_divide((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_divide_f(struct vec4 vec40, mfloat_t f)
{
	struct vec4 result;
	vec4_divide_f((mfloat_t *)&result, (mfloat_t *)&vec40, f);
	return result;
}

struct vec4 svec4_snap(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_snap((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_snap_f(struct vec4 vec40, mfloat_t f)
{
	struct vec4 result;
	vec4_snap_f((mfloat_t *)&result, (mfloat_t *)&vec40, f);
	return result;
}

struct vec4 svec4_negative(struct vec4 vec40)
{
	struct vec4 result;
	vec4_negative((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_abs(struct vec4 vec40)
{
	struct vec4 result;
	vec4_abs((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_floor(struct vec4 vec40)
{
	struct vec4 result;
	vec4_floor((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_ceil(struct vec4 vec40)
{
	struct vec4 result;
	vec4_ceil((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_round(struct vec4 vec40)
{
	struct vec4 result;
	vec4_round((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_max(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_max((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_min(struct vec4 vec40, struct vec4 vec41)
{
	struct vec4 result;
	vec4_min((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41);
	return result;
}

struct vec4 svec4_clamp(struct vec4 vec40, struct vec4 vec41, struct vec4 vec42)
{
	struct vec4 result;
	vec4_clamp((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41, (mfloat_t *)&vec42);
	return result;
}

struct vec4 svec4_normalize(struct vec4 vec40)
{
	struct vec4 result;
	vec4_normalize((mfloat_t *)&result, (mfloat_t *)&vec40);
	return result;
}

struct vec4 svec4_lerp(struct vec4 vec40, struct vec4 vec41, mfloat_t f)
{
	struct vec4 result;
	vec4_lerp((mfloat_t *)&result, (mfloat_t *)&vec40, (mfloat_t *)&vec41, f);
	return result;
}

bool squat_is_zero(struct quat quat0)
{
	return quat_is_zero((mfloat_t *)&quat0);
}

bool squat_is_equal(struct quat quat0, struct quat quat1)
{
	return quat_is_equal((mfloat_t *)&quat0, (mfloat_t *)&quat1);
}

struct quat squat(mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	struct quat result;
	quat((mfloat_t *)&result, x, y, z, w);
	return result;
}

struct quat squat_assign(struct quat quat0)
{
	struct quat result;
	quat_assign((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct quat squat_zero(void)
{
	struct quat result;
	quat_zero((mfloat_t *)&result);
	return result;
}

struct quat squat_null(void)
{
	struct quat result;
	quat_null((mfloat_t *)&result);
	return result;
}

struct quat squat_multiply(struct quat quat0, struct quat quat1)
{
	struct quat result;
	quat_multiply((mfloat_t *)&result, (mfloat_t *)&quat0, (mfloat_t *)&quat1);
	return result;
}

struct quat squat_multiply_f(struct quat quat0, mfloat_t f)
{
	struct quat result;
	quat_multiply_f((mfloat_t *)&result, (mfloat_t *)&quat0, f);
	return result;
}

struct quat squat_divide(struct quat quat0, struct quat quat1)
{
	struct quat result;
	quat_divide((mfloat_t *)&result, (mfloat_t *)&quat0, (mfloat_t *)&quat1);
	return result;
}

struct quat squat_divide_f(struct quat quat0, mfloat_t f)
{
	struct quat result;
	quat_divide_f((mfloat_t *)&result, (mfloat_t *)&quat0, f);
	return result;
}

struct quat squat_negative(struct quat quat0)
{
	struct quat result;
	quat_negative((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct quat squat_conjugate(struct quat quat0)
{
	struct quat result;
	quat_conjugate((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct quat squat_inverse(struct quat quat0)
{
	struct quat result;
	quat_inverse((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct quat squat_normalize(struct quat quat0)
{
	struct quat result;
	quat_normalize((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

mfloat_t squat_dot(struct quat quat0, struct quat quat1)
{
	return quat_dot((mfloat_t *)&quat0, (mfloat_t *)&quat1);
}

struct quat squat_power(struct quat quat0, mfloat_t exponent)
{
	struct quat result;
	quat_power((mfloat_t *)&result, (mfloat_t *)&quat0, exponent);
	return result;
}

struct quat squat_from_axis_angle(struct vec3 vec30, mfloat_t angle)
{
	struct quat result;
	quat_from_axis_angle((mfloat_t *)&result, (mfloat_t *)&vec30, angle);
	return result;
}

struct quat squat_from_vec3(struct vec3 vec30, struct vec3 vec31)
{
	struct quat result;
	quat_from_vec3((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31);
	return result;
}

struct quat squat_from_mat4(struct mat4 mat40)
{
	struct quat result;
	quat_from_mat4((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct quat squat_lerp(struct quat quat0, struct quat quat1, mfloat_t f)
{
	struct quat result;
	quat_lerp((mfloat_t *)&result, (mfloat_t *)&quat0, (mfloat_t *)&quat1, f);
	return result;
}

struct quat squat_slerp(struct quat quat0, struct quat quat1, mfloat_t f)
{
	struct quat result;
	quat_slerp((mfloat_t *)&result, (mfloat_t *)&quat0, (mfloat_t *)&quat1, f);
	return result;
}

mfloat_t squat_length(struct quat quat0)
{
	return quat_length((mfloat_t *)&quat0);
}

mfloat_t squat_length_squared(struct quat quat0)
{
	return quat_length_squared((mfloat_t *)&quat0);
}

mfloat_t squat_angle(struct quat quat0, struct quat quat1)
{
	return quat_angle((mfloat_t *)&quat0, (mfloat_t *)&quat1);
}

struct mat2 smat2(mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22)
{
	struct mat2 result;
	mat2((mfloat_t *)&result, m11, m12, m21, m22);
	return result;
}

struct mat2 smat2_zero(void)
{
	struct mat2 result;
	mat2_zero((mfloat_t *)&result);
	return result;
}

struct mat2 smat2_identity(void)
{
	struct mat2 result;
	mat2_identity((mfloat_t *)&result);
	return result;
}

mfloat_t smat2_determinant(struct mat2 mat20)
{
	return mat2_determinant((mfloat_t *)&mat20);
}

struct mat2 smat2_assign(struct mat2 mat20)
{
	struct mat2 result;
	mat2_assign((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_negative(struct mat2 mat20)
{
	struct mat2 result;
	mat2_negative((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_transpose(struct mat2 mat20)
{
	struct mat2 result;
	mat2_transpose((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_cofactor(struct mat2 mat20)
{
	struct mat2 result;
	mat2_cofactor((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_adjugate(struct mat2 mat20)
{
	struct mat2 result;
	mat2_adjugate((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_multiply(struct mat2 mat20, struct mat2 mat21)
{
	struct mat2 result;
	mat2_multiply((mfloat_t *)&result, (mfloat_t *)&mat20, (mfloat_t *)&mat21);
	return result;
}

struct mat2 smat2_multiply_f(struct mat2 mat20, mfloat_t f)
{
	struct mat2 result;
	mat2_multiply_f((mfloat_t *)&result, (mfloat_t *)&mat20, f);
	return result;
}

struct mat2 smat2_inverse(struct mat2 mat20)
{
	struct mat2 result;
	mat2_inverse((mfloat_t *)&result, (mfloat_t *)&mat20);
	return result;
}

struct mat2 smat2_scaling(struct vec2 vec20)
{
	struct mat2 result;
	mat2_scaling((mfloat_t *)&result, (mfloat_t *)&vec20);
	return result;
}

struct mat2 smat2_scale(struct mat2 mat20, struct vec2 vec20)
{
	struct mat2 result;
	mat2_scale((mfloat_t *)&result, (mfloat_t *)&mat20, (mfloat_t *)&vec20);
	return result;
}

struct mat2 smat2_rotation_z(mfloat_t f)
{
	struct mat2 result;
	mat2_rotation_z((mfloat_t *)&result, f);
	return result;
}

struct mat2 smat2_lerp(struct mat2 mat20, struct mat2 mat21, mfloat_t f)
{
	struct mat2 result;
	mat2_lerp((mfloat_t *)&result, (mfloat_t *)&mat20, (mfloat_t *)&mat21, f);
	return result;
}

struct mat3 smat3(mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33)
{
	struct mat3 result;
	mat3((mfloat_t *)&result, m11, m12, m13, m21, m22, m23, m31, m32, m33);
	return result;
}

struct mat3 smat3_zero(void)
{
	struct mat3 result;
	mat3_zero((mfloat_t *)&result);
	return result;
}

struct mat3 smat3_identity(void)
{
	struct mat3 result;
	mat3_identity((mfloat_t *)&result);
	return result;
}

mfloat_t smat3_determinant(struct mat3 mat30)
{
	return mat3_determinant((mfloat_t *)&mat30);
}

struct mat3 smat3_assign(struct mat3 mat30)
{
	struct mat3 result;
	mat3_assign((mfloat_t *)&result, (mfloat_t *)&mat30);
	return result;
}

struct mat3 smat3_negative(struct mat3 mat30)
{
	struct mat3 result;
	mat3_negative((mfloat_t *)&result, (mfloat_t *)&mat30);
	return result;
}

struct mat3 smat3_transpose(struct mat3 mat30)
{
	struct mat3 result;
	mat3_transpose((mfloat_t *)&result, (mfloat_t *)&mat30);
	return result;
}

struct mat3 smat3_cofactor(struct mat3 mat30)
{
	struct mat3 result;
	mat3_cofactor((mfloat_t *)&result, (mfloat_t *)&mat30);
	return result;
}

struct mat3 smat3_multiply(struct mat3 mat30, struct mat3 mat31)
{
	struct mat3 result;
	mat3_multiply((mfloat_t *)&result, (mfloat_t *)&mat30, (mfloat_t *)&mat31);
	return result;
}

struct mat3 smat3_multiply_f(struct mat3 mat30, mfloat_t f)
{
	struct mat3 result;
	mat3_multiply_f((mfloat_t *)&result, (mfloat_t *)&mat30, f);
	return result;
}

struct mat3 smat3_inverse(struct mat3 mat30)
{
	struct mat3 result;
	mat3_inverse((mfloat_t *)&result, (mfloat_t *)&mat30);
	return result;
}

struct mat3 smat3_scaling(struct vec3 vec30)
{
	struct mat3 result;
	mat3_scaling((mfloat_t *)&result, (mfloat_t *)&vec30);
	return result;
}

struct mat3 smat3_scale(struct mat3 mat30, struct vec3 vec30)
{
	struct mat3 result;
	mat3_scale((mfloat_t *)&result, (mfloat_t *)&mat30, (mfloat_t *)&vec30);
	return result;
}

struct mat3 smat3_rotation_x(mfloat_t f)
{
	struct mat3 result;
	mat3_rotation_x((mfloat_t *)&result, f);
	return result;
}

struct mat3 smat3_rotation_y(mfloat_t f)
{
	struct mat3 result;
	mat3_rotation_y((mfloat_t *)&result, f);
	return result;
}

struct mat3 smat3_rotation_z(mfloat_t f)
{
	struct mat3 result;
	mat3_rotation_z((mfloat_t *)&result, f);
	return result;
}

struct mat3 smat3_rotation_axis(struct vec3 vec30, mfloat_t f)
{
	struct mat3 result;
	mat3_rotation_axis((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct mat3 smat3_rotation_quat(struct quat quat0)
{
	struct mat3 result;
	mat3_rotation_quat((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct mat3 smat3_lerp(struct mat3 mat30, struct mat3 mat31, mfloat_t f)
{
	struct mat3 result;
	mat3_lerp((mfloat_t *)&result, (mfloat_t *)&mat30, (mfloat_t *)&mat31, f);
	return result;
}

struct mat4 smat4(mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44)
{
	struct mat4 result;
	mat4((mfloat_t *)&result, m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
	return result;
}

struct mat4 smat4_zero(void)
{
	struct mat4 result;
	mat4_zero((mfloat_t *)&result);
	return result;
}

struct mat4 smat4_identity(void)
{
	struct mat4 result;
	mat4_identity((mfloat_t *)&result);
	return result;
}

mfloat_t smat4_determinant(struct mat4 mat40)
{
	return mat4_determinant((mfloat_t *)&mat40);
}

struct mat4 smat4_assign(struct mat4 mat40)
{
	struct mat4 result;
	mat4_assign((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct mat4 smat4_negative(struct mat4 mat40)
{
	struct mat4 result;
	mat4_negative((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct mat4 smat4_transpose(struct mat4 mat40)
{
	struct mat4 result;
	mat4_transpose((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct mat4 smat4_cofactor(struct mat4 mat40)
{
	struct mat4 result;
	mat4_cofactor((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct mat4 smat4_rotation_x(mfloat_t f)
{
	struct mat4 result;
	mat4_rotation_x((mfloat_t *)&result, f);
	return result;
}

struct mat4 smat4_rotation_y(mfloat_t f)
{
	struct mat4 result;
	mat4_rotation_y((mfloat_t *)&result, f);
	return result;
}

struct mat4 smat4_rotation_z(mfloat_t f)
{
	struct mat4 result;
	mat4_rotation_z((mfloat_t *)&result, f);
	return result;
}

struct mat4 smat4_rotation_axis(struct vec3 vec30, mfloat_t f)
{
	struct mat4 result;
	mat4_rotation_axis((mfloat_t *)&result, (mfloat_t *)&vec30, f);
	return result;
}

struct mat4 smat4_rotation_quat(struct quat quat0)
{
	struct mat4 result;
	mat4_rotation_quat((mfloat_t *)&result, (mfloat_t *)&quat0);
	return result;
}

struct mat4 smat4_translation(struct mat4 mat40, struct vec3 vec30)
{
	struct mat4 result;
	mat4_translation((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&vec30);
	return result;
}

struct mat4 smat4_translate(struct mat4 mat40, struct vec3 vec30)
{
	struct mat4 result;
	mat4_translate((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&vec30);
	return result;
}

struct mat4 smat4_scaling(struct mat4 mat40, struct vec3 vec30)
{
	struct mat4 result;
	mat4_scaling((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&vec30);
	return result;
}

struct mat4 smat4_scale(struct mat4 mat40, struct vec3 vec30)
{
	struct mat4 result;
	mat4_scale((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&vec30);
	return result;
}

struct mat4 smat4_multiply(struct mat4 mat40, struct mat4 mat41)
{
	struct mat4 result;
	mat4_multiply((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&mat41);
	return result;
}

struct mat4 smat4_multiply_f(struct mat4 mat40, mfloat_t f)
{
	struct mat4 result;
	mat4_multiply_f((mfloat_t *)&result, (mfloat_t *)&mat40, f);
	return result;
}

struct mat4 smat4_inverse(struct mat4 mat40)
{
	struct mat4 result;
	mat4_inverse((mfloat_t *)&result, (mfloat_t *)&mat40);
	return result;
}

struct mat4 smat4_lerp(struct mat4 mat40, struct mat4 mat41, mfloat_t f)
{
	struct mat4 result;
	mat4_lerp((mfloat_t *)&result, (mfloat_t *)&mat40, (mfloat_t *)&mat41, f);
	return result;
}

struct mat4 smat4_look_at(struct vec3 vec30, struct vec3 vec31, struct vec3 vec32)
{
	struct mat4 result;
	mat4_look_at((mfloat_t *)&result, (mfloat_t *)&vec30, (mfloat_t *)&vec31, (mfloat_t *)&vec32);
	return result;
}

struct mat4 smat4_ortho(mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f)
{
	struct mat4 result;
	mat4_ortho((mfloat_t *)&result, l, r, b, t, n, f);
	return result;
}

struct mat4 smat4_perspective(mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f)
{
	struct mat4 result;
	mat4_perspective((mfloat_t *)&result, fov_y, aspect, n, f);
	return result;
}

struct mat4 smat4_perspective_fov(mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f)
{
	struct mat4 result;
	mat4_perspective_fov((mfloat_t *)&result, fov, w, h, n, f);
	return result;
}

struct mat4 smat4_perspective_infinite(mfloat_t fov_y, mfloat_t aspect, mfloat_t n)
{
	struct mat4 result;
	mat4_perspective_infinite((mfloat_t *)&result, fov_y, aspect, n);
	return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
#if defined(MATHC_USE_INT)
bool psvec2i_is_zero(struct vec2i *vec2i0)
{
	return vec2i_is_zero((mint_t *)vec2i0);
}

bool psvec2i_is_equal(struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return vec2i_is_equal((mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i(struct vec2i *result, mint_t x, mint_t y)
{
	return (struct vec2i *)vec2i((mint_t *)result, x, y);
}

struct vec2i *psvec2i_assign(struct vec2i *result, struct vec2i *vec2i0)
{
	return (struct vec2i *)vec2i_assign((mint_t *)result, (mint_t *)vec2i0);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec2i *psvec2i_assign_vec2(struct vec2i *result, struct vec2 *vec20)
{
	return (struct vec2i *)vec2i_assign_vec2((mint_t *)result, (mfloat_t *)vec20);
}
#endif

struct vec2i *psvec2i_zero(struct vec2i *result)
{
	return (struct vec2i *)vec2i_zero((mint_t *)result);
}

struct vec2i *psvec2i_one(struct vec2i *result)
{
	return (struct vec2i *)vec2i_one((mint_t *)result);
}

struct vec2i *psvec2i_sign(struct vec2i *result, struct vec2i *vec2i0)
{
	return (struct vec2i *)vec2i_sign((mint_t *)result, (mint_t *)vec2i0);
}

struct vec2i *psvec2i_add(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_add((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_add_i(struct vec2i *result, struct vec2i *vec2i0, mint_t i)
{
	return (struct vec2i *)vec2i_add_i((mint_t *)result, (mint_t *)vec2i0, i);
}

struct vec2i *psvec2i_subtract(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_subtract((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_subtract_i(struct vec2i *result, struct vec2i *vec2i0, mint_t i)
{
	return (struct vec2i *)vec2i_subtract_i((mint_t *)result, (mint_t *)vec2i0, i);
}

struct vec2i *psvec2i_multiply(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_multiply((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_multiply_i(struct vec2i *result, struct vec2i *vec2i0, mint_t i)
{
	return (struct vec2i *)vec2i_multiply_i((mint_t *)result, (mint_t *)vec2i0, i);
}

struct vec2i *psvec2i_divide(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_divide((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_divide_i(struct vec2i *result, struct vec2i *vec2i0, mint_t i)
{
	return (struct vec2i *)vec2i_divide_i((mint_t *)result, (mint_t *)vec2i0, i);
}

struct vec2i *psvec2i_snap(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_snap((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_snap_i(struct vec2i *result, struct vec2i *vec2i0, mint_t i)
{
	return (struct vec2i *)vec2i_snap_i((mint_t *)result, (mint_t *)vec2i0, i);
}

struct vec2i *psvec2i_negative(struct vec2i *result, struct vec2i *vec2i0)
{
	return (struct vec2i *)vec2i_negative((mint_t *)result, (mint_t *)vec2i0);
}

struct vec2i *psvec2i_abs(struct vec2i *result, struct vec2i *vec2i0)
{
	return (struct vec2i *)vec2i_abs((mint_t *)result, (mint_t *)vec2i0);
}

struct vec2i *psvec2i_max(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_max((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_min(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1)
{
	return (struct vec2i *)vec2i_min((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1);
}

struct vec2i *psvec2i_clamp(struct vec2i *result, struct vec2i *vec2i0, struct vec2i *vec2i1, struct vec2i *vec2i2)
{
	return (struct vec2i *)vec2i_clamp((mint_t *)result, (mint_t *)vec2i0, (mint_t *)vec2i1, (mint_t *)vec2i2);
}

struct vec2i *psvec2i_tangent(struct vec2i *result, struct vec2i *vec2i0)
{
	return (struct vec2i *)vec2i_tangent((mint_t *)result, (mint_t *)vec2i0);
}

bool psvec3i_is_zero(struct vec3i *vec3i0)
{
	return vec3i_is_zero((mint_t *)vec3i0);
}

bool psvec3i_is_equal(struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return vec3i_is_equal((mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i(struct vec3i *result, mint_t x, mint_t y, mint_t z)
{
	return (struct vec3i *)vec3i((mint_t *)result, x, y, z);
}

struct vec3i *psvec3i_assign(struct vec3i *result, struct vec3i *vec3i0)
{
	return (struct vec3i *)vec3i_assign((mint_t *)result, (mint_t *)vec3i0);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec3i *psvec3i_assign_vec3(struct vec3i *result, struct vec3 *vec30)
{
	return (struct vec3i *)vec3i_assign_vec3((mint_t *)result, (mfloat_t *)vec30);
}
#endif

struct vec3i *psvec3i_zero(struct vec3i *result)
{
	return (struct vec3i *)vec3i_zero((mint_t *)result);
}

struct vec3i *psvec3i_one(struct vec3i *result)
{
	return (struct vec3i *)vec3i_one((mint_t *)result);
}

struct vec3i *psvec3i_sign(struct vec3i *result, struct vec3i *vec3i0)
{
	return (struct vec3i *)vec3i_sign((mint_t *)result, (mint_t *)vec3i0);
}

struct vec3i *psvec3i_add(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_add((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_add_i(struct vec3i *result, struct vec3i *vec3i0, mint_t i)
{
	return (struct vec3i *)vec3i_add_i((mint_t *)result, (mint_t *)vec3i0, i);
}

struct vec3i *psvec3i_subtract(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_subtract((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_subtract_i(struct vec3i *result, struct vec3i *vec3i0, mint_t i)
{
	return (struct vec3i *)vec3i_subtract_i((mint_t *)result, (mint_t *)vec3i0, i);
}

struct vec3i *psvec3i_multiply(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_multiply((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_multiply_i(struct vec3i *result, struct vec3i *vec3i0, mint_t i)
{
	return (struct vec3i *)vec3i_multiply_i((mint_t *)result, (mint_t *)vec3i0, i);
}

struct vec3i *psvec3i_divide(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_divide((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_divide_i(struct vec3i *result, struct vec3i *vec3i0, mint_t i)
{
	return (struct vec3i *)vec3i_divide_i((mint_t *)result, (mint_t *)vec3i0, i);
}

struct vec3i *psvec3i_snap(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_snap((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_snap_i(struct vec3i *result, struct vec3i *vec3i0, mint_t i)
{
	return (struct vec3i *)vec3i_snap_i((mint_t *)result, (mint_t *)vec3i0, i);
}

struct vec3i *psvec3i_cross(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_cross((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_negative(struct vec3i *result, struct vec3i *vec3i0)
{
	return (struct vec3i *)vec3i_negative((mint_t *)result, (mint_t *)vec3i0);
}

struct vec3i *psvec3i_abs(struct vec3i *result, struct vec3i *vec3i0)
{
	return (struct vec3i *)vec3i_abs((mint_t *)result, (mint_t *)vec3i0);
}

struct vec3i *psvec3i_max(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_max((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_min(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1)
{
	return (struct vec3i *)vec3i_min((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1);
}

struct vec3i *psvec3i_clamp(struct vec3i *result, struct vec3i *vec3i0, struct vec3i *vec3i1, struct vec3i *vec3i2)
{
	return (struct vec3i *)vec3i_clamp((mint_t *)result, (mint_t *)vec3i0, (mint_t *)vec3i1, (mint_t *)vec3i2);
}

bool psvec4i_is_zero(struct vec4i *vec4i0)
{
	return vec4i_is_zero((mint_t *)vec4i0);
}

bool psvec4i_is_equal(struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return vec4i_is_equal((mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i(struct vec4i *result, mint_t x, mint_t y, mint_t z, mint_t w)
{
	return (struct vec4i *)vec4i((mint_t *)result, x, y, z, w);
}

struct vec4i *psvec4i_assign(struct vec4i *result, struct vec4i *vec4i0)
{
	return (struct vec4i *)vec4i_assign((mint_t *)result, (mint_t *)vec4i0);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec4i *psvec4i_assign_vec4(struct vec4i *result, struct vec4 *vec40)
{
	return (struct vec4i *)vec4i_assign_vec4((mint_t *)result, (mfloat_t *)vec40);
}
#endif

struct vec4i *psvec4i_zero(struct vec4i *result)
{
	return (struct vec4i *)vec4i_zero((mint_t *)result);
}

struct vec4i *psvec4i_one(struct vec4i *result)
{
	return (struct vec4i *)vec4i_one((mint_t *)result);
}

struct vec4i *psvec4i_sign(struct vec4i *result, struct vec4i *vec4i0)
{
	return (struct vec4i *)vec4i_sign((mint_t *)result, (mint_t *)vec4i0);
}

struct vec4i *psvec4i_add(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_add((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_add_i(struct vec4i *result, struct vec4i *vec4i0, mint_t i)
{
	return (struct vec4i *)vec4i_add_i((mint_t *)result, (mint_t *)vec4i0, i);
}

struct vec4i *psvec4i_subtract(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_subtract((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_subtract_i(struct vec4i *result, struct vec4i *vec4i0, mint_t i)
{
	return (struct vec4i *)vec4i_subtract_i((mint_t *)result, (mint_t *)vec4i0, i);
}

struct vec4i *psvec4i_multiply(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_multiply((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_multiply_i(struct vec4i *result, struct vec4i *vec4i0, mint_t i)
{
	return (struct vec4i *)vec4i_multiply_i((mint_t *)result, (mint_t *)vec4i0, i);
}

struct vec4i *psvec4i_divide(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_divide((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_divide_i(struct vec4i *result, struct vec4i *vec4i0, mint_t i)
{
	return (struct vec4i *)vec4i_divide_i((mint_t *)result, (mint_t *)vec4i0, i);
}

struct vec4i *psvec4i_snap(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_snap((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_snap_i(struct vec4i *result, struct vec4i *vec4i0, mint_t i)
{
	return (struct vec4i *)vec4i_snap_i((mint_t *)result, (mint_t *)vec4i0, i);
}

struct vec4i *psvec4i_negative(struct vec4i *result, struct vec4i *vec4i0)
{
	return (struct vec4i *)vec4i_negative((mint_t *)result, (mint_t *)vec4i0);
}

struct vec4i *psvec4i_abs(struct vec4i *result, struct vec4i *vec4i0)
{
	return (struct vec4i *)vec4i_abs((mint_t *)result, (mint_t *)vec4i0);
}

struct vec4i *psvec4i_max(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_max((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_min(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1)
{
	return (struct vec4i *)vec4i_min((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1);
}

struct vec4i *psvec4i_clamp(struct vec4i *result, struct vec4i *vec4i0, struct vec4i *vec4i1, struct vec4i *vec4i2)
{
	return (struct vec4i *)vec4i_clamp((mint_t *)result, (mint_t *)vec4i0, (mint_t *)vec4i1, (mint_t *)vec4i2);
}
#endif

#if defined(MATHC_USE_FLOATING_POINT)
bool psvec2_is_zero(struct vec2 *vec20)
{
	return vec2_is_zero((mfloat_t *)vec20);
}

bool psvec2_is_equal(struct vec2 *vec20, struct vec2 *vec21)
{
	return vec2_is_equal((mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2(struct vec2 *result, mfloat_t x, mfloat_t y)
{
	return (struct vec2 *)vec2((mfloat_t *)result, x, y);
}

struct vec2 *psvec2_assign(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_assign((mfloat_t *)result, (mfloat_t *)vec20);
}

#if defined(MATHC_USE_INT)
struct vec2 *psvec2_assign_vec2i(struct vec2 *result, struct vec2i *vec2i0)
{
	return (struct vec2 *)vec2_assign_vec2i((mfloat_t *)result, (mint_t *)vec2i0);
}
#endif

struct vec2 *psvec2_zero(struct vec2 *result)
{
	return (struct vec2 *)vec2_zero((mfloat_t *)result);
}

struct vec2 *psvec2_one(struct vec2 *result)
{
	return (struct vec2 *)vec2_one((mfloat_t *)result);
}

struct vec2 *psvec2_sign(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_sign((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_add(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_add((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_add_f(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_add_f((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_subtract(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_subtract((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_subtract_f(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_subtract_f((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_multiply(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_multiply((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_multiply_f(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_multiply_f((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_multiply_mat2(struct vec2 *result, struct vec2 *vec20, struct mat2 *mat20)
{
	return (struct vec2 *)vec2_multiply_mat2((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)mat20);
}

struct vec2 *psvec2_divide(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_divide((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_divide_f(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_divide_f((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_snap(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_snap((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_snap_f(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_snap_f((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_negative(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_negative((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_abs(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_abs((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_floor(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_floor((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_ceil(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_ceil((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_round(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_round((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_max(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_max((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_min(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_min((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_clamp(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21, struct vec2 *vec22)
{
	return (struct vec2 *)vec2_clamp((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21, (mfloat_t *)vec22);
}

struct vec2 *psvec2_normalize(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_normalize((mfloat_t *)result, (mfloat_t *)vec20);
}

mfloat_t psvec2_dot(struct vec2 *vec20, struct vec2 *vec21)
{
	return vec2_dot((mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_project(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_project((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_slide(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_slide((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_reflect(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21)
{
	return (struct vec2 *)vec2_reflect((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21);
}

struct vec2 *psvec2_tangent(struct vec2 *result, struct vec2 *vec20)
{
	return (struct vec2 *)vec2_tangent((mfloat_t *)result, (mfloat_t *)vec20);
}

struct vec2 *psvec2_rotate(struct vec2 *result, struct vec2 *vec20, mfloat_t f)
{
	return (struct vec2 *)vec2_rotate((mfloat_t *)result, (mfloat_t *)vec20, f);
}

struct vec2 *psvec2_lerp(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21, mfloat_t f)
{
	return (struct vec2 *)vec2_lerp((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21, f);
}

struct vec2 *psvec2_bezier3(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21, struct vec2 *vec22, mfloat_t f)
{
	return (struct vec2 *)vec2_bezier3((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21, (mfloat_t *)vec22, f);
}

struct vec2 *psvec2_bezier4(struct vec2 *result, struct vec2 *vec20, struct vec2 *vec21, struct vec2 *vec22, struct vec2 *vec23, mfloat_t f)
{
	return (struct vec2 *)vec2_bezier4((mfloat_t *)result, (mfloat_t *)vec20, (mfloat_t *)vec21, (mfloat_t *)vec22, (mfloat_t *)vec23, f);
}

mfloat_t psvec2_angle(struct vec2 *vec20)
{
	return vec2_angle((mfloat_t *)vec20);
}

mfloat_t psvec2_length(struct vec2 *vec20)
{
	return vec2_length((mfloat_t *)vec20);
}

mfloat_t psvec2_length_squared(struct vec2 *vec20)
{
	return vec2_length_squared((mfloat_t *)vec20);
}

mfloat_t psvec2_distance(struct vec2 *vec20, struct vec2 *vec21)
{
	return vec2_distance((mfloat_t *)vec20, (mfloat_t *)vec21);
}

mfloat_t psvec2_distance_squared(struct vec2 *vec20, struct vec2 *vec21)
{
	return vec2_distance_squared((mfloat_t *)vec20, (mfloat_t *)vec21);
}

bool psvec3_is_zero(struct vec3 *vec30)
{
	return vec3_is_zero((mfloat_t *)vec30);
}

bool psvec3_is_equal(struct vec3 *vec30, struct vec3 *vec31)
{
	return vec3_is_equal((mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3(struct vec3 *result, mfloat_t x, mfloat_t y, mfloat_t z)
{
	return (struct vec3 *)vec3((mfloat_t *)result, x, y, z);
}

struct vec3 *psvec3_assign(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_assign((mfloat_t *)result, (mfloat_t *)vec30);
}

#if defined(MATHC_USE_INT)
struct vec3 *psvec3_assign_vec3i(struct vec3 *result, struct vec3i *vec3i0)
{
	return (struct vec3 *)vec3_assign_vec3i((mfloat_t *)result, (mint_t *)vec3i0);
}
#endif

struct vec3 *psvec3_zero(struct vec3 *result)
{
	return (struct vec3 *)vec3_zero((mfloat_t *)result);
}

struct vec3 *psvec3_one(struct vec3 *result)
{
	return (struct vec3 *)vec3_one((mfloat_t *)result);
}

struct vec3 *psvec3_sign(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_sign((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_add(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_add((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_add_f(struct vec3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct vec3 *)vec3_add_f((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct vec3 *psvec3_subtract(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_subtract((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_subtract_f(struct vec3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct vec3 *)vec3_subtract_f((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct vec3 *psvec3_multiply(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_multiply((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_multiply_f(struct vec3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct vec3 *)vec3_multiply_f((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct vec3 *psvec3_multiply_mat3(struct vec3 *result, struct vec3 *vec30, struct mat3 *mat30)
{
	return (struct vec3 *)vec3_multiply_mat3((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)mat30);
}

struct vec3 *psvec3_divide(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_divide((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_divide_f(struct vec3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct vec3 *)vec3_divide_f((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct vec3 *psvec3_snap(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_snap((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_snap_f(struct vec3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct vec3 *)vec3_snap_f((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct vec3 *psvec3_negative(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_negative((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_abs(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_abs((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_floor(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_floor((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_ceil(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_ceil((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_round(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_round((mfloat_t *)result, (mfloat_t *)vec30);
}

struct vec3 *psvec3_max(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_max((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_min(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_min((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_clamp(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31, struct vec3 *vec32)
{
	return (struct vec3 *)vec3_clamp((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31, (mfloat_t *)vec32);
}

struct vec3 *psvec3_cross(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_cross((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_normalize(struct vec3 *result, struct vec3 *vec30)
{
	return (struct vec3 *)vec3_normalize((mfloat_t *)result, (mfloat_t *)vec30);
}

mfloat_t psvec3_dot(struct vec3 *vec30, struct vec3 *vec31)
{
	return vec3_dot((mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_project(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_project((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_slide(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_slide((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_reflect(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct vec3 *)vec3_reflect((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct vec3 *psvec3_lerp(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31, mfloat_t f)
{
	return (struct vec3 *)vec3_lerp((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31, f);
}

struct vec3 *psvec3_bezier3(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31, struct vec3 *vec32, mfloat_t f)
{
	return (struct vec3 *)vec3_bezier3((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31, (mfloat_t *)vec32, f);
}

struct vec3 *psvec3_bezier4(struct vec3 *result, struct vec3 *vec30, struct vec3 *vec31, struct vec3 *vec32, struct vec3 *vec33, mfloat_t f)
{
	return (struct vec3 *)vec3_bezier4((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31, (mfloat_t *)vec32, (mfloat_t *)vec33, f);
}

mfloat_t psvec3_length(struct vec3 *vec30)
{
	return vec3_length((mfloat_t *)vec30);
}

mfloat_t psvec3_length_squared(struct vec3 *vec30)
{
	return vec3_length_squared((mfloat_t *)vec30);
}

mfloat_t psvec3_distance(struct vec3 *vec30, struct vec3 *vec31)
{
	return vec3_distance((mfloat_t *)vec30, (mfloat_t *)vec31);
}

mfloat_t psvec3_distance_squared(struct vec3 *vec30, struct vec3 *vec31)
{
	return vec3_distance_squared((mfloat_t *)vec30, (mfloat_t *)vec31);
}

bool psvec4_is_zero(struct vec4 *vec40)
{
	return vec4_is_zero((mfloat_t *)vec40);
}

bool psvec4_is_equal(struct vec4 *vec40, struct vec4 *vec41)
{
	return vec4_is_equal((mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4(struct vec4 *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	return (struct vec4 *)vec4((mfloat_t *)result, x, y, z, w);
}

struct vec4 *psvec4_assign(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_assign((mfloat_t *)result, (mfloat_t *)vec40);
}

#if defined(MATHC_USE_INT)
struct vec4 *psvec4_assign_vec4i(struct vec4 *result, struct vec4i *vec4i0)
{
	return (struct vec4 *)vec4_assign_vec4i((mfloat_t *)result, (mint_t *)vec4i0);
}
#endif

struct vec4 *psvec4_zero(struct vec4 *result)
{
	return (struct vec4 *)vec4_zero((mfloat_t *)result);
}

struct vec4 *psvec4_one(struct vec4 *result)
{
	return (struct vec4 *)vec4_one((mfloat_t *)result);
}

struct vec4 *psvec4_sign(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_sign((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_add(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_add((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_add_f(struct vec4 *result, struct vec4 *vec40, mfloat_t f)
{
	return (struct vec4 *)vec4_add_f((mfloat_t *)result, (mfloat_t *)vec40, f);
}

struct vec4 *psvec4_subtract(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_subtract((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_subtract_f(struct vec4 *result, struct vec4 *vec40, mfloat_t f)
{
	return (struct vec4 *)vec4_subtract_f((mfloat_t *)result, (mfloat_t *)vec40, f);
}

struct vec4 *psvec4_multiply(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_multiply((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_multiply_f(struct vec4 *result, struct vec4 *vec40, mfloat_t f)
{
	return (struct vec4 *)vec4_multiply_f((mfloat_t *)result, (mfloat_t *)vec40, f);
}

struct vec4 *psvec4_multiply_mat4(struct vec4 *result, struct vec4 *vec40, struct mat4 *mat40)
{
	return (struct vec4 *)vec4_multiply_mat4((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)mat40);
}

struct vec4 *psvec4_divide(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_divide((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_divide_f(struct vec4 *result, struct vec4 *vec40, mfloat_t f)
{
	return (struct vec4 *)vec4_divide_f((mfloat_t *)result, (mfloat_t *)vec40, f);
}

struct vec4 *psvec4_snap(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_snap((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_snap_f(struct vec4 *result, struct vec4 *vec40, mfloat_t f)
{
	return (struct vec4 *)vec4_snap_f((mfloat_t *)result, (mfloat_t *)vec40, f);
}

struct vec4 *psvec4_negative(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_negative((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_abs(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_abs((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_floor(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_floor((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_ceil(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_ceil((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_round(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_round((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_max(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_max((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_min(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41)
{
	return (struct vec4 *)vec4_min((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41);
}

struct vec4 *psvec4_clamp(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41, struct vec4 *vec42)
{
	return (struct vec4 *)vec4_clamp((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41, (mfloat_t *)vec42);
}

struct vec4 *psvec4_normalize(struct vec4 *result, struct vec4 *vec40)
{
	return (struct vec4 *)vec4_normalize((mfloat_t *)result, (mfloat_t *)vec40);
}

struct vec4 *psvec4_lerp(struct vec4 *result, struct vec4 *vec40, struct vec4 *vec41, mfloat_t f)
{
	return (struct vec4 *)vec4_lerp((mfloat_t *)result, (mfloat_t *)vec40, (mfloat_t *)vec41, f);
}

bool psquat_is_zero(struct quat *quat0)
{
	return quat_is_zero((mfloat_t *)quat0);
}

bool psquat_is_equal(struct quat *quat0, struct quat *quat1)
{
	return quat_is_equal((mfloat_t *)quat0, (mfloat_t *)quat1);
}

struct quat *psquat(struct quat *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w)
{
	return (struct quat *)quat((mfloat_t *)result, x, y, z, w);
}

struct quat *psquat_assign(struct quat *result, struct quat *quat0)
{
	return (struct quat *)quat_assign((mfloat_t *)result, (mfloat_t *)quat0);
}

struct quat *psquat_zero(struct quat *result)
{
	return (struct quat *)quat_zero((mfloat_t *)result);
}

struct quat *psquat_null(struct quat *result)
{
	return (struct quat *)quat_null((mfloat_t *)result);
}

struct quat *psquat_multiply(struct quat *result, struct quat *quat0, struct quat *quat1)
{
	return (struct quat *)quat_multiply((mfloat_t *)result, (mfloat_t *)quat0, (mfloat_t *)quat1);
}

struct quat *psquat_multiply_f(struct quat *result, struct quat *quat0, mfloat_t f)
{
	return (struct quat *)quat_multiply_f((mfloat_t *)result, (mfloat_t *)quat0, f);
}

struct quat *psquat_divide(struct quat *result, struct quat *quat0, struct quat *quat1)
{
	return (struct quat *)quat_divide((mfloat_t *)result, (mfloat_t *)quat0, (mfloat_t *)quat1);
}

struct quat *psquat_divide_f(struct quat *result, struct quat *quat0, mfloat_t f)
{
	return (struct quat *)quat_divide_f((mfloat_t *)result, (mfloat_t *)quat0, f);
}

struct quat *psquat_negative(struct quat *result, struct quat *quat0)
{
	return (struct quat *)quat_negative((mfloat_t *)result, (mfloat_t *)quat0);
}

struct quat *psquat_conjugate(struct quat *result, struct quat *quat0)
{
	return (struct quat *)quat_conjugate((mfloat_t *)result, (mfloat_t *)quat0);
}

struct quat *psquat_inverse(struct quat *result, struct quat *quat0)
{
	return (struct quat *)quat_inverse((mfloat_t *)result, (mfloat_t *)quat0);
}

struct quat *psquat_normalize(struct quat *result, struct quat *quat0)
{
	return (struct quat *)quat_normalize((mfloat_t *)result, (mfloat_t *)quat0);
}

mfloat_t psquat_dot(struct quat *quat0, struct quat *quat1)
{
	return quat_dot((mfloat_t *)quat0, (mfloat_t *)quat1);
}

struct quat *psquat_power(struct quat *result, struct quat *quat0, mfloat_t exponent)
{
	return (struct quat *)quat_power((mfloat_t *)result, (mfloat_t *)quat0, exponent);
}

struct quat *psquat_from_axis_angle(struct quat *result, struct vec3 *vec30, mfloat_t angle)
{
	return (struct quat *)quat_from_axis_angle((mfloat_t *)result, (mfloat_t *)vec30, angle);
}

struct quat *psquat_from_vec3(struct quat *result, struct vec3 *vec30, struct vec3 *vec31)
{
	return (struct quat *)quat_from_vec3((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31);
}

struct quat *psquat_from_mat4(struct quat *result, struct mat4 *mat40)
{
	return (struct quat *)quat_from_mat4((mfloat_t *)result, (mfloat_t *)mat40);
}

struct quat *psquat_lerp(struct quat *result, struct quat *quat0, struct quat *quat1, mfloat_t f)
{
	return (struct quat *)quat_lerp((mfloat_t *)result, (mfloat_t *)quat0, (mfloat_t *)quat1, f);
}

struct quat *psquat_slerp(struct quat *result, struct quat *quat0, struct quat *quat1, mfloat_t f)
{
	return (struct quat *)quat_slerp((mfloat_t *)result, (mfloat_t *)quat0, (mfloat_t *)quat1, f);
}

mfloat_t psquat_length(struct quat *quat0)
{
	return quat_length((mfloat_t *)quat0);
}

mfloat_t psquat_length_squared(struct quat *quat0)
{
	return quat_length_squared((mfloat_t *)quat0);
}

mfloat_t psquat_angle(struct quat *quat0, struct quat *quat1)
{
	return quat_angle((mfloat_t *)quat0, (mfloat_t *)quat1);
}

struct mat2 *psmat2(struct mat2 *result, mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22)
{
	return (struct mat2 *)mat2((mfloat_t *)result, m11, m12, m21, m22);
}

struct mat2 *psmat2_zero(struct mat2 *result)
{
	return (struct mat2 *)mat2_zero((mfloat_t *)result);
}

struct mat2 *psmat2_identity(struct mat2 *result)
{
	return (struct mat2 *)mat2_identity((mfloat_t *)result);
}

mfloat_t psmat2_determinant(struct mat2 *mat20)
{
	return mat2_determinant((mfloat_t *)mat20);
}

struct mat2 *psmat2_assign(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_assign((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_negative(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_negative((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_transpose(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_transpose((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_cofactor(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_cofactor((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_adjugate(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_adjugate((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_multiply(struct mat2 *result, struct mat2 *mat20, struct mat2 *mat21)
{
	return (struct mat2 *)mat2_multiply((mfloat_t *)result, (mfloat_t *)mat20, (mfloat_t *)mat21);
}

struct mat2 *psmat2_multiply_f(struct mat2 *result, struct mat2 *mat20, mfloat_t f)
{
	return (struct mat2 *)mat2_multiply_f((mfloat_t *)result, (mfloat_t *)mat20, f);
}

struct mat2 *psmat2_inverse(struct mat2 *result, struct mat2 *mat20)
{
	return (struct mat2 *)mat2_inverse((mfloat_t *)result, (mfloat_t *)mat20);
}

struct mat2 *psmat2_scaling(struct mat2 *result, struct vec2 *vec20)
{
	return (struct mat2 *)mat2_scaling((mfloat_t *)result, (mfloat_t *)vec20);
}

struct mat2 *psmat2_scale(struct mat2 *result, struct mat2 *mat20, struct vec2 *vec20)
{
	return (struct mat2 *)mat2_scale((mfloat_t *)result, (mfloat_t *)mat20, (mfloat_t *)vec20);
}

struct mat2 *psmat2_rotation_z(struct mat2 *result, mfloat_t f)
{
	return (struct mat2 *)mat2_rotation_z((mfloat_t *)result, f);
}

struct mat2 *psmat2_lerp(struct mat2 *result, struct mat2 *mat20, struct mat2 *mat21, mfloat_t f)
{
	return (struct mat2 *)mat2_lerp((mfloat_t *)result, (mfloat_t *)mat20, (mfloat_t *)mat21, f);
}

struct mat3 *psmat3(struct mat3 *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33)
{
	return (struct mat3 *)mat3((mfloat_t *)result, m11, m12, m13, m21, m22, m23, m31, m32, m33);
}

struct mat3 *psmat3_zero(struct mat3 *result)
{
	return (struct mat3 *)mat3_zero((mfloat_t *)result);
}

struct mat3 *psmat3_identity(struct mat3 *result)
{
	return (struct mat3 *)mat3_identity((mfloat_t *)result);
}

mfloat_t psmat3_determinant(struct mat3 *mat30)
{
	return mat3_determinant((mfloat_t *)mat30);
}

struct mat3 *psmat3_assign(struct mat3 *result, struct mat3 *mat30)
{
	return (struct mat3 *)mat3_assign((mfloat_t *)result, (mfloat_t *)mat30);
}

struct mat3 *psmat3_negative(struct mat3 *result, struct mat3 *mat30)
{
	return (struct mat3 *)mat3_negative((mfloat_t *)result, (mfloat_t *)mat30);
}

struct mat3 *psmat3_transpose(struct mat3 *result, struct mat3 *mat30)
{
	return (struct mat3 *)mat3_transpose((mfloat_t *)result, (mfloat_t *)mat30);
}

struct mat3 *psmat3_cofactor(struct mat3 *result, struct mat3 *mat30)
{
	return (struct mat3 *)mat3_cofactor((mfloat_t *)result, (mfloat_t *)mat30);
}

struct mat3 *psmat3_multiply(struct mat3 *result, struct mat3 *mat30, struct mat3 *mat31)
{
	return (struct mat3 *)mat3_multiply((mfloat_t *)result, (mfloat_t *)mat30, (mfloat_t *)mat31);
}

struct mat3 *psmat3_multiply_f(struct mat3 *result, struct mat3 *mat30, mfloat_t f)
{
	return (struct mat3 *)mat3_multiply_f((mfloat_t *)result, (mfloat_t *)mat30, f);
}

struct mat3 *psmat3_inverse(struct mat3 *result, struct mat3 *mat30)
{
	return (struct mat3 *)mat3_inverse((mfloat_t *)result, (mfloat_t *)mat30);
}

struct mat3 *psmat3_scaling(struct mat3 *result, struct vec3 *vec30)
{
	return (struct mat3 *)mat3_scaling((mfloat_t *)result, (mfloat_t *)vec30);
}

struct mat3 *psmat3_scale(struct mat3 *result, struct mat3 *mat30, struct vec3 *vec30)
{
	return (struct mat3 *)mat3_scale((mfloat_t *)result, (mfloat_t *)mat30, (mfloat_t *)vec30);
}

struct mat3 *psmat3_rotation_x(struct mat3 *result, mfloat_t f)
{
	return (struct mat3 *)mat3_rotation_x((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_y(struct mat3 *result, mfloat_t f)
{
	return (struct mat3 *)mat3_rotation_y((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_z(struct mat3 *result, mfloat_t f)
{
	return (struct mat3 *)mat3_rotation_z((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_axis(struct mat3 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct mat3 *)mat3_rotation_axis((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct mat3 *psmat3_rotation_quat(struct mat3 *result, struct quat *quat0)
{
	return (struct mat3 *)mat3_rotation_quat((mfloat_t *)result, (mfloat_t *)quat0);
}

struct mat3 *psmat3_lerp(struct mat3 *result, struct mat3 *mat30, struct mat3 *mat31, mfloat_t f)
{
	return (struct mat3 *)mat3_lerp((mfloat_t *)result, (mfloat_t *)mat30, (mfloat_t *)mat31, f);
}

struct mat4 *psmat4(struct mat4 *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44)
{
	return (struct mat4 *)mat4((mfloat_t *)result, m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}

struct mat4 *psmat4_zero(struct mat4 *result)
{
	return (struct mat4 *)mat4_zero((mfloat_t *)result);
}

struct mat4 *psmat4_identity(struct mat4 *result)
{
	return (struct mat4 *)mat4_identity((mfloat_t *)result);
}

mfloat_t psmat4_determinant(struct mat4 *mat40)
{
	return mat4_determinant((mfloat_t *)mat40);
}

struct mat4 *psmat4_assign(struct mat4 *result, struct mat4 *mat40)
{
	return (struct mat4 *)mat4_assign((mfloat_t *)result, (mfloat_t *)mat40);
}

struct mat4 *psmat4_negative(struct mat4 *result, struct mat4 *mat40)
{
	return (struct mat4 *)mat4_negative((mfloat_t *)result, (mfloat_t *)mat40);
}

struct mat4 *psmat4_transpose(struct mat4 *result, struct mat4 *mat40)
{
	return (struct mat4 *)mat4_transpose((mfloat_t *)result, (mfloat_t *)mat40);
}

struct mat4 *psmat4_cofactor(struct mat4 *result, struct mat4 *mat40)
{
	return (struct mat4 *)mat4_cofactor((mfloat_t *)result, (mfloat_t *)mat40);
}

struct mat4 *psmat4_rotation_x(struct mat4 *result, mfloat_t f)
{
	return (struct mat4 *)mat4_rotation_x((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_y(struct mat4 *result, mfloat_t f)
{
	return (struct mat4 *)mat4_rotation_y((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_z(struct mat4 *result, mfloat_t f)
{
	return (struct mat4 *)mat4_rotation_z((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_axis(struct mat4 *result, struct vec3 *vec30, mfloat_t f)
{
	return (struct mat4 *)mat4_rotation_axis((mfloat_t *)result, (mfloat_t *)vec30, f);
}

struct mat4 *psmat4_rotation_quat(struct mat4 *result, struct quat *quat0)
{
	return (struct mat4 *)mat4_rotation_quat((mfloat_t *)result, (mfloat_t *)quat0);
}

struct mat4 *psmat4_translation(struct mat4 *result, struct mat4 *mat40, struct vec3 *vec30)
{
	return (struct mat4 *)mat4_translation((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)vec30);
}

struct mat4 *psmat4_translate(struct mat4 *result, struct mat4 *mat40, struct vec3 *vec30)
{
	return (struct mat4 *)mat4_translate((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)vec30);
}

struct mat4 *psmat4_scaling(struct mat4 *result, struct mat4 *mat40, struct vec3 *vec30)
{
	return (struct mat4 *)mat4_scaling((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)vec30);
}

struct mat4 *psmat4_scale(struct mat4 *result, struct mat4 *mat40, struct vec3 *vec30)
{
	return (struct mat4 *)mat4_scale((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)vec30);
}

struct mat4 *psmat4_multiply(struct mat4 *result, struct mat4 *mat40, struct mat4 *mat41)
{
	return (struct mat4 *)mat4_multiply((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)mat41);
}

struct mat4 *psmat4_multiply_f(struct mat4 *result, struct mat4 *mat40, mfloat_t f)
{
	return (struct mat4 *)mat4_multiply_f((mfloat_t *)result, (mfloat_t *)mat40, f);
}

struct mat4 *psmat4_inverse(struct mat4 *result, struct mat4 *mat40)
{
	return (struct mat4 *)mat4_inverse((mfloat_t *)result, (mfloat_t *)mat40);
}

struct mat4 *psmat4_lerp(struct mat4 *result, struct mat4 *mat40, struct mat4 *mat41, mfloat_t f)
{
	return (struct mat4 *)mat4_lerp((mfloat_t *)result, (mfloat_t *)mat40, (mfloat_t *)mat41, f);
}

struct mat4 *psmat4_look_at(struct mat4 *result, struct vec3 *vec30, struct vec3 *vec31, struct vec3 *vec32)
{
	return (struct mat4 *)mat4_look_at((mfloat_t *)result, (mfloat_t *)vec30, (mfloat_t *)vec31, (mfloat_t *)vec32);
}

struct mat4 *psmat4_ortho(struct mat4 *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f)
{
	return (struct mat4 *)mat4_ortho((mfloat_t *)result, l, r, b, t, n, f);
}

struct mat4 *psmat4_perspective(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f)
{
	return (struct mat4 *)mat4_perspective((mfloat_t *)result, fov_y, aspect, n, f);
}

struct mat4 *psmat4_perspective_fov(struct mat4 *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f)
{
	return (struct mat4 *)mat4_perspective_fov((mfloat_t *)result, fov, w, h, n, f);
}

struct mat4 *psmat4_perspective_infinite(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n)
{
	return (struct mat4 *)mat4_perspective_infinite((mfloat_t *)result, fov_y, aspect, n);
}
#endif
#endif
