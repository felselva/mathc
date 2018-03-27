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

#define EPSILON_1 MFLT_EPSILON
#define EPSILON_10 (MFLT_EPSILON * 10.0)
#define EPSILON_100 (MFLT_EPSILON * 100.0)
#define EPSILON_1000 (MFLT_EPSILON * 1000.0)

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

void printf_1f_test(struct cerror *error, char *msg, mfloat_t e, mfloat_t r)
{
	printf("%s:\n\tExpected % .4f\n\t  Actual % .4f\t", msg, e, r);
	if (nearly_equal(e, r, EPSILON_1)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else if (nearly_equal(e, r, EPSILON_10)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		printf("~passed with epsilon * 10.0~\n\n");
	} else if (nearly_equal(e, r, EPSILON_100)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		printf("~passed with epsilon * 100.0~\n\n");
	} else if (nearly_equal(e, r, EPSILON_1000)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		printf("~passed with epsilon * 1000.0~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_2f_test(struct cerror *error, char *msg, struct vec2 e, struct vec2 r)
{
	printf("%s:\n\tExpected % .4f, % .4f\n\t  Actual % .4f, % .4f\t", msg, e.x, e.y, r.x, r.y);
	if (svec2_is_nearly_equal(e, r, EPSILON_1)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else if (svec2_is_nearly_equal(e, r, EPSILON_10)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		printf("~passed with epsilon * 10.0~\n\n");
	} else if (svec2_is_nearly_equal(e, r, EPSILON_100)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		printf("~passed with epsilon * 100.0~\n\n");
	} else if (svec2_is_nearly_equal(e, r, EPSILON_1000)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		printf("~passed with epsilon * 1000.0~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_3f_test(struct cerror *error, char *msg, struct vec3 e, struct vec3 r)
{
	printf("%s:\n\tExpected % .4f, % .4f, % .4f\n\t  Actual % .4f, % .4f, % .4f\t", msg, e.x, e.y, e.z, r.x, r.y, r.z);
	if (svec3_is_nearly_equal(e, r, EPSILON_1)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else if (svec3_is_nearly_equal(e, r, EPSILON_10)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		printf("~passed with epsilon * 10.0~\n\n");
	} else if (svec3_is_nearly_equal(e, r, EPSILON_100)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		printf("~passed with epsilon * 100.0~\n\n");
	} else if (svec3_is_nearly_equal(e, r, EPSILON_1000)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		printf("~passed with epsilon * 1000.0~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_4f_test(struct cerror *error, char *msg, struct vec4 e, struct vec4 r)
{
	printf("%s:\n\tExpected % .4f, % .4f, % .4f, % .4f\n\t  Actual % .4f, % .4f, % .4f, % .4f\t", msg, e.x, e.y, e.z, e.w, r.x, r.y, r.z, r.w);
	if (svec4_is_nearly_equal(e, r, EPSILON_1)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else if (svec4_is_nearly_equal(e, r, EPSILON_10)) {
		error->passed_with_e10 = error->passed_with_e10 + 1;
		printf("~passed with epsilon * 10.0~\n\n");
	} else if (svec4_is_nearly_equal(e, r, EPSILON_100)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		printf("~passed with epsilon * 100.0~\n\n");
	} else if (svec4_is_nearly_equal(e, r, EPSILON_1000)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		printf("~passed with epsilon * 1000.0~\n\n");
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
	printf_bool_test(error, "Test `vec2_is_near_zero`", true, svec2_is_near_zero(svec2(0.0f, 0.0f), EPSILON_1));
	printf_bool_test(error, "Test `vec2_is_equal`", true, svec2_is_equal(svec2(1.0f / 3.0f, 7.0f / 3.0f), svec2(1.0f / 3.0f, 7.0f / 3.0f)));
	printf_bool_test(error, "Test `vec2_is_nearly_equal`", true, svec2_is_nearly_equal(svec2(1.0f / 3.0f, 7.0f / 3.0f), svec2(1.0f / 3.0f, 7.0f / 3.0f), EPSILON_1));
	v = svec2(2.0f, 1.0f);
	printf_2f_test(error, "Test `vec2`", svec2(2.0f, 1.0f), v);
	v = svec2_assign(svec2(2.0f, 1.0f));
	printf_2f_test(error, "Test `vec2_assign`", svec2(2.0f, 1.0f), v);
	v = svec2_zero();
	printf_2f_test(error, "Test `vec2_zero`", svec2(0.0f, 0.0f), v);
	v = svec2_add(svec2(3.0f, 1.0f), svec2(1.0f, 7.0f));
	printf_2f_test(error, "Test `vec2_add`", svec2(4.0f, 8.0f), v);
	v = svec2_subtract(svec2(1.0f, 20.0f), svec2(3.0f, 7.0f));
	printf_2f_test(error, "Test `vec2_subtract`", svec2(-2.0f, 13.0f), v);
	v = svec2_scale(svec2(1.0f, 3.0f), 3.0f);
	printf_2f_test(error, "Test `vec2_scale`", svec2(3.0f, 9.0f), v);
	v = svec2_multiply(svec2(1.0f, 3.0f), svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_multiply`", svec2(3.0f, 15.0f), v);
	m = smat2(
		0.8f, 0.7f,
		0.5f, 0.3f);
	v = svec2_multiply_mat2(svec2(3.0f, 5.0f), m);
	printf_2f_test(error, "Test `vec2_multiply_mat2`", svec2(5.9f, 3.0f), v);
	v = svec2_divide(svec2(1.0f, 3.0f), svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_divide`", svec2(0.3333333333f, 0.6f), v);
	v = svec2_snap(svec2(20.0f, -15.5f), svec2(16.0f, 16.0f));
	printf_2f_test(error, "Test `vec2_snap`", svec2(16.0f, -16.0f), v);
	v = svec2_negative(svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_negative`", svec2(-3.0f, -5.0f), v);
	v = svec2_inverse(svec2(3.0f, 5.0f));
	printf_2f_test(error, "Test `vec2_inverse`", svec2(0.3333333333f, 0.2f), v);
	v = svec2_abs(svec2(-7.0f, -3.0f));
	printf_2f_test(error, "Test `vec2_abs`", svec2(7.0, 3.0f), v);
	v = svec2_floor(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_floor`", svec2(-8.0, -4.0f), v);
	v = svec2_ceil(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_ceil`", svec2(-7.0, -3.0f), v);
	v = svec2_round(svec2(-7.2f, -3.7f));
	printf_2f_test(error, "Test `vec2_round`", svec2(-7.0, -4.0f), v);
	v = svec2_max(svec2(-7.2f, -3.7f), svec2(1.0f, 3.7f));
	printf_2f_test(error, "Test `vec2_max`", svec2(1.0f, 3.7f), v);
	v = svec2_min(svec2(-7.2f, -3.7f), svec2(1.0f, 3.7f));
	printf_2f_test(error, "Test `vec2_min`", svec2(-7.2f, -3.7f), v);
	v = svec2_clamp(svec2(-9.1f, 8.7f), svec2(-1.3f, 2.7f), svec2(3.3f, 5.7f));
	printf_2f_test(error, "Test `vec2_clamp`", svec2(-1.3f, 5.7f), v);
	v = svec2_normalize(svec2(1.0f, 1.0f));
	printf_2f_test(error, "Test `vec2_normalize`", svec2(0.7071067812f, 0.7071067812f), v);
	v = svec2_project(svec2(2.0f, 2.0f), svec2(0.5f, 1.0f));
	printf_2f_test(error, "Test `vec2_project`", svec2(1.2f, 2.4f), v);
	v = svec2_slide(svec2(1.0f, 0.0f), svec2(-0.7071067812f, -0.7071067812f));
	printf_2f_test(error, "Test `vec2_slide`", svec2(0.5f, -0.5f), v);
	v = svec2_reflect(svec2(1.0f, 0.0f), svec2(-0.7071067812f, -0.7071067812f));
	printf_2f_test(error, "Test `vec2_reflect`", svec2(0.0f, -1.0f), v);
	v = svec2_tangent(svec2(1.0f, 0.0f));
	printf_2f_test(error, "Test `vec2_tangent`", svec2(0.0f, -1.0f), v);
	v = svec2_rotate(svec2(1.0f, 0.0f), to_radians(45.0f));
	printf_2f_test(error, "Test `vec2_rotate`", svec2(0.7071067812f, 0.7071067812f), v);
	v = svec2_lerp(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_lerp`", svec2(6.0f, 2.0f), v);
	v = svec2_bezier3(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), svec2(14.0f, 7.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_bezier3`", svec2(8.75f, 3.0f), v);
	v = svec2_bezier4(svec2(3.0f, 3.0f), svec2(9.0f, 1.0f), svec2(14.0f, 7.0f), svec2(21.0f, 9.0f), 0.5f);
	printf_2f_test(error, "Test `vec2_bezier4`", svec2(11.625f, 4.5f), v);
	printf_1f_test(error, "Test `vec2_dot`", 13.0f, svec2_dot(svec2(3.0f, 2.0f), svec2(1.0f, 5.0f)));
	printf_1f_test(error, "Test `vec2_angle`", to_radians(45.0f), svec2_angle(svec2(2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec2_length`", 2.8284271247f, svec2_length(svec2(2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec2_length_squared`", 8.0f, svec2_length_squared(svec2(2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec2_distance`", 5.6568542495f, svec2_distance(svec2(2.0f, 2.0f), svec2(6.0f, 6.0f)));
	printf_1f_test(error, "Test `vec2_distance_squared`", 32.0f, svec2_distance_squared(svec2(2.0f, 2.0f), svec2(6.0f, 6.0f)));
}

void vec3_tests(struct cerror *error)
{
	struct vec3 v;
	struct mat3 m;
	printf_bool_test(error, "Test `vec3_is_zero`", true, svec3_is_zero(svec3(0.0f, 0.0f, 0.0f)));
	printf_bool_test(error, "Test `vec3_is_near_zero`", true, svec3_is_near_zero(svec3(0.0f, 0.0f, 0.0f), EPSILON_1));
	printf_bool_test(error, "Test `vec3_is_equal`", true, svec3_is_equal(svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f)));
	printf_bool_test(error, "Test `vec3_is_nearly_equal`", true, svec3_is_nearly_equal(svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), svec3(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f), EPSILON_1));
	v = svec3(2.0f, 1.0f, 3.0f);
	printf_3f_test(error, "Test `vec3`", svec3(2.0f, 1.0f, 3.0f), v);
	v = svec3_assign(svec3(2.0f, 1.0f, 3.0f));
	printf_3f_test(error, "Test `vec3_assign`", svec3(2.0f, 1.0f, 3.0f), v);
	v = svec3_zero();
	printf_3f_test(error, "Test `vec3_zero`", svec3(0.0f, 0.0f, 0.0f), v);
	v = svec3_add(svec3(3.0f, 1.0f, 4.0f), svec3(1.0f, 7.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_add`", svec3(4.0f, 8.0f, 6.0f), v);
	v = svec3_subtract(svec3(1.0f, 20.0f, 9.0f), svec3(3.0f, 7.0f, 7.0f));
	printf_3f_test(error, "Test `vec3_subtract`", svec3(-2.0f, 13.0f, 2.0f), v);
	v = svec3_scale(svec3(1.0f, 3.0f, 5.0f), 3.0f);
	printf_3f_test(error, "Test `vec3_scale`", svec3(3.0f, 9.0f, 15.0f), v);
	v = svec3_multiply(svec3(1.0f, 3.0f, 5.0f), svec3(3.0f, 5.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_multiply`", svec3(3.0f, 15.0f, 10.0f), v);
	m = smat3(
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);
	v = svec3_multiply_mat3(svec3(2.0f, 1.0f, 3.0f), m);
	printf_3f_test(error, "Test `vec3_multiply_mat3`", svec3(13.0f, 31.0f, 49.0f), v);
	v = svec3_divide(svec3(1.0f, 3.0f, 5.0f), svec3(3.0f, 5.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_divide`", svec3(0.3333333333f, 0.6f, 2.5f), v);
	v = svec3_snap(svec3(1.3f, -3.1f, 4.9f), svec3(0.5f, 0.5f, 0.5f));
	printf_3f_test(error, "Test `vec3_snap`", svec3(1.0f, -3.5f, 4.5f), v);
	v = svec3_negative(svec3(3.0f, 5.0f, -7.0f));
	printf_3f_test(error, "Test `vec3_negative`", svec3(-3.0f, -5.0f, 7.0f), v);
	v = svec3_inverse(svec3(3.0f, 5.0f, 7.0f));
	printf_3f_test(error, "Test `vec3_inverse`", svec3(0.3333333333f, 0.2f, 0.1428571429f), v);
	v = svec3_abs(svec3(-7.0f, -3.0f, 1.0f));
	printf_3f_test(error, "Test `vec3_abs`", svec3(7.0, 3.0f, 1.0f), v);
	v = svec3_floor(svec3(-7.2f, -3.7f, 9.1f));
	printf_3f_test(error, "Test `vec3_floor`", svec3(-8.0, -4.0f, 9.0f), v);
	v = svec3_ceil(svec3(-7.2f, -3.7f, 0.99f));
	printf_3f_test(error, "Test `vec3_ceil`", svec3(-7.0, -3.0f, 1.0f), v);
	v = svec3_round(svec3(-7.2f, -3.7f, 0.01f));
	printf_3f_test(error, "Test `vec3_round`", svec3(-7.0, -4.0f, 0.0f), v);
	v = svec3_max(svec3(-7.2f, -3.7f, 9.0f), svec3(1.0f, 3.7f, 30.0f));
	printf_3f_test(error, "Test `vec3_max`", svec3(1.0f, 3.7f, 30.0f), v);
	v = svec3_min(svec3(-7.2f, -3.7f, 9.0f), svec3(1.0f, 3.7f, 30.0f));
	printf_3f_test(error, "Test `vec3_min`", svec3(-7.2f, -3.7f, 9.0f), v);
	v = svec3_clamp(svec3(-9.1f, 8.7f, 0.4f), svec3(-1.3f, 2.7f, 0.7f), svec3(3.3f, 5.7f, 0.8f));
	printf_3f_test(error, "Test `vec3_clamp`", svec3(-1.3f, 5.7f, 0.7f), v);
	v = svec3_normalize(svec3(3.0f, 1.0f, 2.0f));
	printf_3f_test(error, "Test `vec3_normalize`", svec3(0.8017837257f, 0.2672612419f, 0.5345224838f), v);
	v = svec3_project(svec3(-1.0f, 4.0f, 2.0f), svec3(1.0f, 5.0f, 3.0f));
	printf_3f_test(error, "Test `vec3_project`", svec3(0.7142857143f, 3.5714285714f, 2.1428571429), v);
	v = svec3_slide(svec3(1.0f, 0.5f, -1.0f), svec3(-0.1f, 0.0f, 1.0f));
	printf_3f_test(error, "Test `vec3_slide`", svec3(0.89f,  0.5f,  0.1f), v);
	v = svec3_reflect(svec3(1.0f, 0.5f, -1.0f), svec3(-0.1f, 0.0f, 1.0f));
	printf_3f_test(error, "Test `vec3_reflect`", svec3(0.78f,  0.5f,  1.2f), v);
	v = svec3_lerp(svec3(3.0f, 3.0f, 3.0f), svec3(9.0f, 1.0f, 30.0f), 0.5f);
	printf_3f_test(error, "Test `vec3_lerp`", svec3(6.0f,  2.0f,  16.5f), v);
	v = svec3_bezier3(svec3(-1.0f, -0.5f, 0.2f), svec3(1.5f, 0.15f, 0.5f), svec3(1.0f, -1.0f, 0.0f), 0.5f);
	printf_3f_test(error, "Test `vec3_bezier3`", svec3(0.75f, -0.3f, 0.3f), v);
	v = svec3_bezier4(svec3(3.0f, 3.0f, 3.0f), svec3(9.0f, 7.0f, 9.0f), svec3(-4.0f, 6.0f, 7.0f), svec3(-5.0f, 1.0f, 2.0f), 0.5f);
	printf_3f_test(error, "Test `vec3_bezier4`", svec3(1.625f, 5.375f, 6.625f), v);
	printf_1f_test(error, "Test `vec3_dot`", 44.0f, svec3_dot(svec3(1.0f, 2.0f, 3.0f), svec3(6.0f, 7.0f, 8.0f)));
	printf_1f_test(error, "Test `vec3_length`", 3.4641016151f, svec3_length(svec3(2.0f, 2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec3_length_squared`", 12.0f, svec3_length_squared(svec3(2.0f, 2.0f, 2.0f)));
	printf_1f_test(error, "Test `vec3_distance`", 6.9282032303f, svec3_distance(svec3(2.0f, 2.0f, 2.0f), svec3(6.0f, 6.0f, 6.0f)));
	printf_1f_test(error, "Test `vec3_distance_squared`", 48.0f, svec3_distance_squared(svec3(2.0f, 2.0f, 2.0f), svec3(6.0f, 6.0f, 6.0f)));
}

void vec4_tests(struct cerror *error)
{
	struct vec4 v;
	struct mat4 m;
	printf_bool_test(error, "Test `vec4_is_zero`", true, svec4_is_zero(svec4(0.0f, 0.0f, 0.0f, 0.0f)));
	printf_bool_test(error, "Test `vec4_is_near_zero`", true, svec4_is_near_zero(svec4(0.0f, 0.0f, 0.0f, 0.0f), EPSILON_1));
	printf_bool_test(error, "Test `vec4_is_equal`", true, svec4_is_equal(svec4(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f, 3.0f / 7.0f), svec4(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f, 3.0f / 7.0f)));
	printf_bool_test(error, "Test `vec4_is_nearly_equal`", true, svec4_is_nearly_equal(svec4(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f, 3.0f / 7.0f), svec4(1.0f / 3.0f, 7.0f / 3.0f, 5.0f / 3.0f, 3.0f / 7.0f), EPSILON_1));
	v.x = 2.0f;
	v.y = 1.0f;
	v.z = 3.0f;
	v.w = 4.0f;
	v = svec4(2.0f, 1.0f, 3.0f, 4.0f);
	printf_4f_test(error, "Test `vec4`", svec4(2.0f, 1.0f, 3.0f, 4.0f), v);
	v = svec4_assign(svec4(2.0f, 1.0f, 3.0f, 4.0f));
	printf_4f_test(error, "Test `vec3_assign`", svec4(2.0f, 1.0f, 3.0f, 4.0f), v);
	v = svec4_zero();
	printf_4f_test(error, "Test `vec4_zero`", svec4(0.0f, 0.0f, 0.0f, 0.0f), v);
	v = svec4_add(svec4(3.0f, 1.0f, 4.0f, 2.0f), svec4(1.0f, 7.0f, 2.0f, 3.0f));
	printf_4f_test(error, "Test `vec4_add`", svec4(4.0f, 8.0f, 6.0f, 5.0f), v);
	v = svec4_subtract(svec4(1.0f, 20.0f, 9.0f, 10.0f), svec4(3.0f, 7.0f, 7.0f, 5.0f));
	printf_4f_test(error, "Test `vec4_subtract`", svec4(-2.0f, 13.0f, 2.0f, 5.0f), v);
	v = svec4_scale(svec4(1.0f, 3.0f, 5.0f, 2.0f), 3.0f);
	printf_4f_test(error, "Test `vec4_scale`", svec4(3.0f, 9.0f, 15.0f, 6.0f), v);
	v = svec4_multiply(svec4(1.0f, 3.0f, 5.0f, 2.0f), svec4(3.0f, 5.0f, 2.0f, 2.0f));
	printf_4f_test(error, "Test `vec4_multiply`", svec4(3.0f, 15.0f, 10.0f, 4.0f), v);
	m = smat4(
		1.0f, 5.0f, 9.0f, 13.0f,
		2.0f, 6.0f, 10.0f, 14.0f,
		3.0f, 7.0f, 11.0f, 15.0f,
		4.0f, 8.0f, 12.0f, 16.0f);
	v = svec4_multiply_mat4(svec4(3.0f, 5.0f, 7.0f, 9.0f), m);
	printf_4f_test(error, "Test `vec4_multiply_mat4`", svec4(208.0f, 232.0f, 256.0f, 280.0f), v);
	v = svec4_divide(svec4(1.0f, 3.0f, 5.0f, 2.0f), svec4(3.0f, 5.0f, 2.0f, 4.0f));
	printf_4f_test(error, "Test `vec4_divide`", svec4(0.3333333333f, 0.6f, 2.5f, 0.5f), v);
	v = svec4_snap(svec4(1.3f, -3.1f, 4.9f, 5.6f), svec4(0.5f, 0.5f, 0.5f, 0.5f));
	printf_4f_test(error, "Test `vec4_snap`", svec4(1.0f, -3.5f, 4.5f, 5.5f), v);
	v = svec4_negative(svec4(3.0f, 5.0f, -7.0f, 0.01f));
	printf_4f_test(error, "Test `vec4_negative`", svec4(-3.0f, -5.0f, 7.0f, -0.01f), v);
	v = svec4_inverse(svec4(3.0f, 5.0f, 7.0f, 8.0f));
	printf_4f_test(error, "Test `vec4_inverse`", svec4(0.3333333333f, 0.2f, 0.1428571429f, 0.125f), v);
	v = svec4_abs(svec4(-7.0f, -3.0f, 1.0f, 0.0001f));
	printf_4f_test(error, "Test `vec4_abs`", svec4(7.0, 3.0f, 1.0f, 0.0001f), v);
	v = svec4_floor(svec4(-7.2f, -3.7f, 9.1f, 1.0f));
	printf_4f_test(error, "Test `vec4_floor`", svec4(-8.0, -4.0f, 9.0f, 1.0f), v);
	v = svec4_ceil(svec4(-7.2f, -3.7f, 0.99f, 1.0f));
	printf_4f_test(error, "Test `vec4_ceil`", svec4(-7.0, -3.0f, 1.0f, 1.0f), v);
	v = svec4_round(svec4(-7.2f, -3.7f, 0.01f, 1.0f));
	printf_4f_test(error, "Test `vec4_round`", svec4(-7.0, -4.0f, 0.0f, 1.0f), v);
	v = svec4_max(svec4(-7.2f, -3.7f, 9.0f, 2.0f), svec4(1.0f, 3.7f, 30.0f, 3.0f));
	printf_4f_test(error, "Test `vec4_max`", svec4(1.0f, 3.7f, 30.0f, 3.0f), v);
	v = svec4_min(svec4(-7.2f, -3.7f, 9.0f, 2.0f), svec4(1.0f, 3.7f, 30.0f, 3.0f));
	printf_4f_test(error, "Test `vec4_min`", svec4(-7.2f, -3.7f, 9.0f, 2.0f), v);
	v = svec4_clamp(svec4(-9.1f, 8.7f, 0.4f, 1.0f), svec4(-1.3f, 2.7f, 0.7f, 0.5f), svec4(3.3f, 5.7f, 0.8f, 2.0f));
	printf_4f_test(error, "Test `vec4_clamp`", svec4(-1.3f, 5.7f, 0.7f, 1.0f), v);
	v = svec4_normalize(svec4(3.0f, 1.0f, 2.0f, 4.0f));
	printf_4f_test(error, "Test `vec4_normalize`", svec4(0.5477225575f, 0.1825741858f, 0.3651483717f, 0.7302967433f), v);
	v = svec4_lerp(svec4(3.0f, 3.0f, 3.0f, 3.0f), svec4(9.0f, 1.0f, 30.0f, 7.0f), 0.5f);
	printf_4f_test(error, "Test `vec4_lerp`", svec4(6.0f,  2.0f,  16.5f, 5.0f), v);
}

void quaternion_tests(struct cerror *error)
{
}

int main(int argc, char **args)
{
	struct cerror error = {0};
	vec2_tests(&error);
	vec3_tests(&error);
	vec4_tests(&error);
	quaternion_tests(&error);
	printf("\nTotal of failed tests: %d\n", error.failed);
	printf("Total of tests that passed: %d\n", error.passed);
	printf("Total of tests that passed with epsilon * 10.0: %d\n", error.passed_with_e10);
	printf("Total of tests that passed with epsilon * 100.0: %d\n", error.passed_with_e100);
	printf("Total of tests that passed with epsilon * 1000.0: %d\n", error.passed_with_e1000);
	return error.failed;
}
