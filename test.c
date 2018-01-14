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

#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include "mathc.h"

const float epsilon = FLT_EPSILON;

struct cerror {
	int32_t failed;
	int32_t passed;
	int32_t passed_with_e10;
	int32_t passed_with_e100;
	int32_t passed_with_e1000;
};

void printf_bool_test(struct cerror *error, char *msg, bool e, bool r)
{
	if (e) {
		printf("%s:\n\tExpected  true\n\t", msg);
	} else {
		printf("%s:\n\tExpected  false\n\t", msg);
	}
	if (r) {
		printf("  Actual  true\t");
	} else {
		printf("  Actual  false\t");
	}
	if (e == r) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_1f_test(struct cerror *error, char *msg, mfloat_t e1, mfloat_t r1)
{
	bool done = false;
	printf("%s:\n\tExpected % .4f\n\t  Actual % .4f\t", msg, e1, r1);
	if (nearly_equal(e1, r1, epsilon)) {
		error->passed = error->passed + 1;
		done = true;
		printf("~passed~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 10.0f)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		done = true;
		printf("~passed with epsilon * 10.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 100.0f)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		done = true;
		printf("~passed with epsilon * 100.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 1000.0f)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		done = true;
		printf("~passed with epsilon * 1000.0~\n\n");
	}
	if (!done) {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_2f_test(struct cerror *error, char *msg, mfloat_t e1, mfloat_t e2, mfloat_t r1, mfloat_t r2)
{
	bool done = false;
	printf("%s:\n\tExpected % .4f, % .4f\n\t  Actual % .4f, % .4f\t", msg, e1, e2, r1, r2);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon)) {
		error->passed = error->passed + 1;
		done = true;
		printf("~passed~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 10.0f) && nearly_equal(e2, r2, epsilon * 10.0f)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		done = true;
		printf("~passed with epsilon * 10.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 100.0f) && nearly_equal(e2, r2, epsilon * 100.0f)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		done = true;
		printf("~passed with epsilon * 100.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 1000.0f) && nearly_equal(e2, r2, epsilon * 1000.0f)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		done = true;
		printf("~passed with epsilon * 1000.0~\n\n");
	}
	if (!done) {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_3f_test(struct cerror *error, char *msg, mfloat_t e1, mfloat_t e2, mfloat_t e3, mfloat_t r1, mfloat_t r2, mfloat_t r3)
{
	bool done = false;
	printf("%s:\n\tExpected % .4f, % .4f, % .4f\n\t  Actual % .4f, % .4f, % .4f\t", msg, e1, e2, e3, r1, r2, r3);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon) && nearly_equal(e3, r3, epsilon)) {
		error->passed = error->passed + 1;
		done = true;
		printf("~passed~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 10.0f) && nearly_equal(e2, r2, epsilon * 10.0f) && nearly_equal(e3, r3, epsilon * 10.0f)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		done = true;
		printf("~passed with epsilon * 10.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 100.0f) && nearly_equal(e2, r2, epsilon * 100.0f) && nearly_equal(e3, r3, epsilon * 100.0f)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		done = true;
		printf("~passed with epsilon * 100.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 1000.0f) && nearly_equal(e2, r2, epsilon * 1000.0f) && nearly_equal(e3, r3, epsilon * 1000.0f)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		done = true;
		printf("~passed with epsilon * 1000.0~\n\n");
	}
	if (!done) {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_4f_test(struct cerror *error, char *msg, mfloat_t e1, mfloat_t e2, mfloat_t e3, mfloat_t e4, mfloat_t r1, mfloat_t r2, mfloat_t r3, mfloat_t r4)
{
	bool done = false;
	printf("%s:\n\tExpected % .9f, % .9f, % .9f, % .9f\n\t  Actual % .9f, % .9f, % .9f, % .9f\t", msg, e1, e2, e3, e4, r1, r2, r3, r4);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon) && nearly_equal(e3, r3, epsilon) && nearly_equal(e4, r4, epsilon)) {
		error->passed = error->passed + 1;
		done = true;
		printf("~passed~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 10.0f) && nearly_equal(e2, r2, epsilon * 10.0f) && nearly_equal(e3, r3, epsilon * 10.0f) && nearly_equal(e4, r4, epsilon * 10.0f)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		done = true;
		printf("~passed with epsilon * 10.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 100.0f) && nearly_equal(e2, r2, epsilon * 100.0f) && nearly_equal(e3, r3, epsilon * 100.0f) && nearly_equal(e4, r4, epsilon * 100.0f)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		done = true;
		printf("~passed with epsilon * 100.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 1000.0f) && nearly_equal(e2, r2, epsilon * 1000.0f) && nearly_equal(e3, r3, epsilon * 1000.0f) && nearly_equal(e4, r4, epsilon * 1000.0f)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		done = true;
		printf("~passed with epsilon * 1000.0~\n\n");
	}
	if (!done) {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_1i_test(struct cerror *error, char *msg, mint_t e1, mint_t r1)
{
	printf("%s:\n\tExpected % d\n\t  Actual % d\t", msg, e1, r1);
	if (e1 == r1) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_2i_test(struct cerror *error, char *msg, mint_t e1, mint_t e2, mint_t r1, mint_t r2)
{
	printf("%s:\n\tExpected % d, % d\n\t  Actual % d, % d\t", msg, e1, e2, r1, r2);
	if (e1 == r1 && e2 == r2) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_3i_test(struct cerror *error, char *msg, mint_t e1, mint_t e2, mint_t e3, mint_t r1, mint_t r2, mint_t r3)
{
	printf("%s:\n\tExpected % d, % d, % d\n\t  Actual  % d, % d, % d\t", msg, e1, e2, e3, r1, r2, r3);
	if (e1 == r1 && e2 == r2 && e3 == r3) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_4i_test(struct cerror *error, char *msg, mint_t e1, mint_t e2, mint_t e3, mint_t e4, mint_t r1, mint_t r2, mint_t r3, mint_t r4)
{
	printf("%s:\n\tExpected % d, % d, % d, % d\n\t  Actual  % d, % d, % d, % d\t", msg, e1, e2, e3, e4, r1, r2, r3, r4);
	if (e1 == r1 && e2 == r2 && e3 == r3 && e4 == r4) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void vec2_tests(struct cerror *error)
{
	struct vec2 v;
	struct mat2 m;
	printf_bool_test(error, "Test `vec2_is_zero`", true, svec2_is_zero(svec2(0.0f, 0.0f)));
	printf_bool_test(error, "Test `vec2_is_near_zero`", true, svec2_is_near_zero(svec2(0.0f, 0.0f), MFLT_EPSILON));
	printf_bool_test(error, "Test `vec2_is_equal`", true, svec2_is_equal(svec2(1.0f / 3.0f, 7.0f / 3.0f), svec2(1.0f / 3.0f, 7.0f / 3.0f)));
	printf_bool_test(error, "Test `vec2_is_nearly_equal`", true, svec2_is_nearly_equal(svec2(1.0f / 3.0f, 7.0f / 3.0f), svec2(1.0f / 3.0f, 7.0f / 3.0f), MFLT_EPSILON));
	v = svec2(2.0f, 1.0f);
	printf_2f_test(error, "Test `vec2`", 2.0f, 1.0f, v.x, v.y);
	v = svec2_assign(svec2(2.0f, 1.0f));
	printf_2f_test(error, "Test `vec2_assign`", 2.0f, 1.0f, v.x, v.y);
	v = svec2_zero();
	printf_2f_test(error, "Test `vec2_zero`", 0.0f, 0.0f, v.x, v.y);
	v = svec2_add(svec2(3.0f, 1.0f), svec2(1.0f, 7.0f));
	printf_2f_test(error, "Test `vec2_add`", 4.0f, 8.0f, v.x, v.y);
	v = svec2_subtract(svec2(1.0f, 20.0f), svec2(3.0f, 7.0f));
	printf_2f_test(error, "Test `vec2_subtract`", -2.0f, 13.0f, v.x, v.y);
	v = svec2_scale(svec2(1.0f, 3.0f), 3.0f);
	printf_2f_test(error, "Test `vec2_scale`", 3.0f, 9.0f, v.x, v.y);
	v = svec2_multiply(svec2(1.0f, 3.0f), svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_multiply`", 3.0f, 15.0f, v.x, v.y);
	m = smat2(
		0.8f, 0.7f,
		0.5f, 0.3f);
	v = svec2_multiply_mat2(svec2(3.0f, 5.0f), m);
	printf_2f_test(error, "Test `vec2_multiply_mat2`", 5.9f, 3.0f, v.x, v.y);
	v = svec2_divide(svec2(1.0f, 3.0f), svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_divide`", 0.3333333333f, 0.6f, v.x, v.y);
	v = svec2_snap(svec2(20.0f, -15.5f), svec2(16.0f, 16.0f));
	printf_2f_test(error, "Test `vec2_snap`", 16.0f, -16.0f, v.x, v.y);
	v = svec2_negative(svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_negative`", -3.0f, -5.0f, v.x, v.y);
	v = svec2_inverse(svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_inverse`", 0.3333333333f, 0.2f, v.x, v.y);
	v = svec2_abs(svec2(-7.0f, -3.0f));
	printf_2f_test(error, "Test `vec2_abs`", 7.0, 3.0f, v.x, v.y);
	v = svec2_floor(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_floor`", -8.0, -4.0f, v.x, v.y);
	v = svec2_ceil(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_ceil`", -7.0, -3.0f, v.x, v.y);
	v = svec2_round(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_round`", -7.0, -4.0f, v.x, v.y);
	v = svec2_max(svec2(-7.2f, -3.7f), svec2(1.0f, 3.7f));
	printf_2f_test(error, "Test `vec2_max`", 1.0f, 3.7f, v.x, v.y);
	v = svec2_min(svec2(-7.2f, -3.7f), svec2(1.0f, 3.7f));
	printf_2f_test(error, "Test `vec2_min`", -7.2f, -3.7f, v.x, v.y);
	v = svec2_clamp(svec2(-9.1f, 8.7f), svec2(-1.3f, 2.7f), svec2(3.3f, 5.7f));
	printf_2f_test(error, "Test `vec2_clamp`", -1.3f, 5.7f, v.x, v.y);
	v = svec2_normalize(svec2(1.0f, 1.0f));
	printf_2f_test(error, "Test `vec2_normalize`", 0.7071067812f, 0.7071067812f, v.x, v.y);
	v = svec2_project(svec2(2.0f, 2.0f), svec2(0.5f, 1.0f));
	printf_2f_test(error, "Test `vec2_project`", 1.2f, 2.4f, v.x, v.y);
	v = svec2_slide(svec2(1.0f, 0.0f), svec2(-0.7071067812f, -0.7071067812f));
	printf_2f_test(error, "Test `vec2_slide`", 0.5f, -0.5f, v.x, v.y);
	v = svec2_reflect(svec2(1.0f, 0.0f), svec2(-0.7071067812f, -0.7071067812f));
	printf_2f_test(error, "Test `vec2_reflect`", 0.0f, -1.0f, v.x, v.y);
	v = svec2_tangent(svec2(1.0f, 0.0f));
	printf_2f_test(error, "Test `vec2_tangent`", 0.0f, -1.0f, v.x, v.y);
	v = svec2_rotate(svec2(1.0f, 0.0f), to_radians(45.0f));
	printf_2f_test(error, "Test `vec2_rotate`", 0.7071067812f, 0.7071067812f, v.x, v.y);
	v = svec2_lerp(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_lerp`", 6.0f, 2.0f, v.x, v.y);
	v = svec2_bezier3(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), svec2(14.0f, 7.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_bezier3`", 8.75f, 3.0f, v.x, v.y);
	v = svec2_bezier4(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), svec2(14.0f, 7.0f), svec2(21.0f, 9.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_bezier4`", 11.625f, 4.5f, v.x, v.y);
	printf_1f_test(error, "Test `vec2_dot`", 13.0f, svec2_dot(svec2(3.0f, 2.0f), svec2(1.0f, 5.0f)));
	printf_1f_test(error, "Test `vec2_angle`", to_radians(45.0f), svec2_angle(svec2(2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec2_length`", 2.8284271247f, svec2_length(svec2(2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec2_length_squared`", 5.6568542495f, svec2_distance_to(svec2(2.0f, 2.0f), svec2(6.0f, 6.0f)));
	printf_1f_test(error, "Test `vec2_distance_to`", 32.0f, svec2_distance_squared_to(svec2(2.0f, 2.0f), svec2(6.0f, 6.0f)));
}

void vec3_tests(struct cerror *error)
{
	struct vec3 v;
	struct mat3 m;
	printf_bool_test(error, "Test `vec3_is_zero`", true, svec3_is_zero(svec3(0.0f, 0.0f, 0.0f)));
	printf_bool_test(error, "Test `vec3_is_near_zero`", true, svec3_is_near_zero(svec3(0.0f, 0.0f, 0.0f), MFLT_EPSILON));
	printf_bool_test(error, "Test `vec3_is_equal`", true, svec3_is_equal(svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f)));
	printf_bool_test(error, "Test `vec3_is_nearly_equal`", true, svec3_is_nearly_equal(svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), MFLT_EPSILON));
	v = svec3(2.0f, 1.0f, 3.0f);
	printf_3f_test(error, "Test `vec3`", 2.0f, 1.0f, 3.0f, v.x, v.y, v.z);
	v = svec3_assign(svec3(2.0f, 1.0f, 3.0f));
	printf_3f_test(error, "Test `vec3_assign`", 2.0f, 1.0f, 3.0f, v.x, v.y, v.z);
	v = svec3_zero();
	printf_3f_test(error, "Test `vec3_zero`", 0.0f, 0.0f, 0.0f, v.x, v.y, v.z);
	v = svec3_add(svec3(3.0f, 1.0f, 4.0f), svec3(1.0f, 7.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_add`", 4.0f, 8.0f, 6.0f, v.x, v.y, v.z);
	v = svec3_subtract(svec3(1.0f, 20.0f, 9.0f), svec3(3.0f, 7.0f, 7.0f));
	printf_3f_test(error, "Test `vec3_subtract`", -2.0f, 13.0f, 2.0f, v.x, v.y, v.z);
	v = svec3_scale(svec3(1.0f, 3.0f, 5.0f), 3.0f);
	printf_3f_test(error, "Test `vec3_scale`", 3.0f, 9.0f, 15.0f, v.x, v.y, v.z);
	v = svec3_multiply(svec3(1.0f, 3.0f, 5.0f), svec3(3.0f, 5.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_multiply`", 3.0f, 15.0f, 10.0f, v.x, v.y, v.z);
	m = smat3(
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);
	v = svec3_multiply_mat3(svec3(2.0f, 1.0f, 3.0f), m);
	printf_3f_test(error, "Test `vec3_multiply_mat3`", 13.0f, 31.0f, 49.0f, v.x, v.y, v.z);
	v = svec3_divide(svec3(1.0f, 3.0f, 5.0f), svec3(3.0f, 5.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_divide`", 0.3333333333f, 0.6f, 2.5f, v.x, v.y, v.z);
	v = svec3_snap(svec3(1.3f, -3.1f, 4.9f), svec3(0.5f, 0.5f, 0.5f));
	printf_3f_test(error, "Test `vec3_snap`", 1.0f, -3.5f, 4.5f, v.x, v.y, v.z);
	v = svec3_negative(svec3(3.0f, 5.0f, -7.0f));
	printf_3f_test(error, "Test `vec3_negative`", -3.0f, -5.0f, 7.0f, v.x, v.y, v.z);
	v = svec3_inverse(svec3(3.0f, 5.0f, 7.0f));
	printf_3f_test(error, "Test `vec3_inverse`", 0.3333333333f, 0.2f, 0.1428571429f, v.x, v.y, v.z);
	v = svec3_abs(svec3(-7.0f, -3.0f, 1.0f));
	printf_3f_test(error, "Test `vec3_abs`", 7.0, 3.0f, 1.0f, v.x, v.y, v.z);
	v = svec3_floor(svec3(-7.2f, -3.7f, 9.1f));
	printf_3f_test(error, "Test `vec3_floor`", -8.0, -4.0f, 9.0f, v.x, v.y, v.z);
	v = svec3_ceil(svec3(-7.2f, -3.7f, 0.99f));
	printf_3f_test(error, "Test `vec3_ceil`", -7.0, -3.0f, 1.0f, v.x, v.y, v.z);
	v = svec3_round(svec3(-7.2f, -3.7f, 0.01f));
	printf_3f_test(error, "Test `vec3_round`", -7.0, -4.0f, 0.0f, v.x, v.y, v.z);
	v = svec3_max(svec3(-7.2f, -3.7f, 9.0f), svec3(1.0f, 3.7f, 30.0f));
	printf_3f_test(error, "Test `vec3_max`", 1.0f, 3.7f, 30.0f, v.x, v.y, v.z);
	v = svec3_min(svec3(-7.2f, -3.7f, 9.0f), svec3(1.0f, 3.7f, 30.0f));
	printf_3f_test(error, "Test `vec3_min`", -7.2f, -3.7f, 9.0f, v.x, v.y, v.z);
	v = svec3_clamp(svec3(-9.1f, 8.7f, 0.4f), svec3(-1.3f, 2.7f, 0.7f), svec3(3.3f, 5.7f, 0.8f));
	printf_3f_test(error, "Test `vec3_clamp`", -1.3f, 5.7f, 0.7f, v.x, v.y, v.z);
	v = svec3_normalize(svec3(3.0f, 1.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_normalize`", 0.8017837257f, 0.2672612419f, 0.5345224838f, v.x, v.y, v.z);
	v = svec3_project(svec3(-1.0f, 4.0f, 2.0f), svec3(1.0f, 5.0f, 3.0f));
	printf_3f_test(error, "Test `vec3_project`", 0.7142857143f, 3.5714285714f, 2.1428571429, v.x, v.y, v.z);
}

void quaternion_tests(struct cerror *error)
{
}

void matrix_tests(struct cerror *error)
{
}

void intersection_tests(struct cerror *error)
{
}

int main(int argc, char **args)
{
	struct cerror error = {0};
	vec2_tests(&error);
	vec3_tests(&error);
	quaternion_tests(&error);
	matrix_tests(&error);
	intersection_tests(&error);
	printf("\nTotal of failed tests: %d\n", error.failed);
	printf("Total of tests that passed: %d\n", error.passed);
	printf("Total of tests that passed with epsilon * 10.0: %d\n", error.passed_with_e10);
	printf("Total of tests that passed with epsilon * 100.0: %d\n", error.passed_with_e100);
	printf("Total of tests that passed with epsilon * 1000.0: %d\n", error.passed_with_e1000);
	return error.failed;
}
