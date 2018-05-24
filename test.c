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

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include "mathc.h"

#define EPSILON_1 MFLT_EPSILON
#define EPSILON_10 (MFLT_EPSILON * MFLOAT_C(10.0))
#define EPSILON_100 (MFLT_EPSILON * MFLOAT_C(100.0))
#define EPSILON_1000 (MFLT_EPSILON * MFLOAT_C(1000.0))

bool report_difference = false;
mfloat_t difference_to_report = MFLOAT_C(0.0);

void printf_bool_test(char *msg, bool e, bool r)
{
	if (e != r) {
		printf("Test %s\n", msg);
		if (e) {
			printf("  Expected\ttrue\t");
		} else {
			printf("  Expected\tfalse\t");
		}
		if (r) {
			printf("\t    Actual\ttrue\n");
		} else {
			printf("\t    Actual\tfalse\n");
		}
	}
}

void printf_1f_test(char *msg, mfloat_t e, mfloat_t r)
{
	if (!report_difference || (report_difference && !nearly_equal(e, r, difference_to_report))) {
		printf("Test %s\n  Expected\t% .16lf\n    Actual\t% .16lf\nDifference\t% .16lf\n",
			msg, e, r, MFABS(e - r));
	}
}

void printf_2f_test(char *msg, mfloat_t e0, mfloat_t e1, mfloat_t r0, mfloat_t r1)
{
	if (!report_difference || (report_difference && (!nearly_equal(e0, r0, difference_to_report) || !nearly_equal(e1, r1, difference_to_report)))) {
		printf("Test %s\n  Expected\t% .16lf, % .16lf\n    Actual\t% .16lf, % .16lf\nDifference\t% .16lf, % .16lf\n",
			msg, e0, e1, r0, r1, MFABS(e0 - r0), MFABS(e1 - r1));
	}
}

void printf_3f_test(char *msg, mfloat_t e0, mfloat_t e1, mfloat_t e2, mfloat_t r0, mfloat_t r1, mfloat_t r2)
{
	if (!report_difference || (report_difference && (!nearly_equal(e0, r0, difference_to_report) || !nearly_equal(e1, r1, difference_to_report) || !nearly_equal(e2, r2, difference_to_report)))) {
		printf("Test %s\n  Expected\t% .16lf, % .16lf, % .16lf\n    Actual\t% .16lf, % .16lf, % .16lf\nDifference\t% .16lf, % .16lf, % .16lf\n",
			msg, e0, e1, e2, r0, r1, r2, MFABS(e0 - r0), MFABS(e1 - r1), MFABS(e2 - r2));
	}
}

void printf_4f_test(char *msg, mfloat_t e0, mfloat_t e1, mfloat_t e2, mfloat_t e3, mfloat_t r0, mfloat_t r1, mfloat_t r2, mfloat_t r3)
{
	if (!report_difference || (report_difference && (!nearly_equal(e0, r0, difference_to_report) || !nearly_equal(e1, r1, difference_to_report) || !nearly_equal(e2, r2, difference_to_report) || !nearly_equal(e3, r3, difference_to_report)))) {
		printf("Test %s\n  Expected\t% .16lf, % .16lf, % .16lf, % .16lf\n    Actual\t% .16lf, % .16lf, % .16lf, % .16lf\nDifference\t% .16lf, % .16lf, % .16lf, % .16lf\n",
			msg, e0, e1, e2, e3, r0, r1, r2, r3, MFABS(e0 - r0), MFABS(e1 - r1), MFABS(e2 - r2), MFABS(e3 - r3));
	}
}

void vec2_tests(void)
{
	struct vec2 v;
	struct mat2 m;
	printf_bool_test("`vec2_is_zero`", true, svec2_is_zero(svec2(MFLOAT_C(0.0), MFLOAT_C(0.0))));
	printf_bool_test("`vec2_is_near_zero`", true, svec2_is_near_zero(svec2(MFLOAT_C(0.0), MFLOAT_C(0.0)), EPSILON_1));
	printf_bool_test("`vec2_is_equal`", true, svec2_is_equal(svec2(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0)), svec2(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0))));
	printf_bool_test("`vec2_is_nearly_equal`", true, svec2_is_nearly_equal(svec2(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0)), svec2(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0)), EPSILON_1));
	v = svec2(MFLOAT_C(2.0), MFLOAT_C(1.0));
	printf_2f_test("`vec2`", MFLOAT_C(2.0), MFLOAT_C(1.0), v.x, v.y);
	v = svec2_assign(svec2(MFLOAT_C(2.0), MFLOAT_C(1.0)));
	printf_2f_test("`vec2_assign`", MFLOAT_C(2.0), MFLOAT_C(1.0), v.x, v.y);
	v = svec2_zero();
	printf_2f_test("`vec2_zero`", MFLOAT_C(0.0), MFLOAT_C(0.0), v.x, v.y);
	v = svec2_add(svec2(MFLOAT_C(3.0), MFLOAT_C(1.0)), svec2(MFLOAT_C(1.0), MFLOAT_C(7.0)));
	printf_2f_test("`vec2_add`", MFLOAT_C(4.0), MFLOAT_C(8.0), v.x, v.y);
	v = svec2_subtract(svec2(MFLOAT_C(1.0), MFLOAT_C(20.0)), svec2(MFLOAT_C(3.0), MFLOAT_C(7.0)));
	printf_2f_test("`vec2_subtract`", MFLOAT_C(-2.0), MFLOAT_C(13.0), v.x, v.y);
	v = svec2_scale(svec2(MFLOAT_C(1.0), MFLOAT_C(3.0)), MFLOAT_C(3.0));
	printf_2f_test("`vec2_scale`", MFLOAT_C(3.0), MFLOAT_C(9.0), v.x, v.y);
	v = svec2_multiply(svec2(MFLOAT_C(1.0), MFLOAT_C(3.0)), svec2(MFLOAT_C(3.0), MFLOAT_C(5.0)));
	printf_2f_test("`vec2_multiply`", MFLOAT_C(3.0), MFLOAT_C(15.0), v.x, v.y);
	m = smat2(
		MFLOAT_C(0.8), MFLOAT_C(0.7),
		MFLOAT_C(0.5), MFLOAT_C(0.3));
	v = svec2_multiply_mat2(svec2(MFLOAT_C(3.0), MFLOAT_C(5.0)), m);
	printf_2f_test("`vec2_multiply_mat2`", MFLOAT_C(5.9), MFLOAT_C(3.0), v.x, v.y);
	v = svec2_divide(svec2(MFLOAT_C(1.0), MFLOAT_C(3.0)), svec2(MFLOAT_C(3.0), MFLOAT_C(5.0)));
	printf_2f_test("`vec2_divide`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(0.6), v.x, v.y);
	v = svec2_snap(svec2(MFLOAT_C(20.0), MFLOAT_C(-15.5)), svec2(MFLOAT_C(16.0), MFLOAT_C(16.0)));
	printf_2f_test("`vec2_snap`", MFLOAT_C(16.0), MFLOAT_C(-16.0), v.x, v.y);
	v = svec2_negative(svec2(MFLOAT_C(3.0), MFLOAT_C(5.0)));
	printf_2f_test("`vec2_negative`", MFLOAT_C(-3.0), MFLOAT_C(-5.0), v.x, v.y);
	v = svec2_inverse(svec2(MFLOAT_C(3.0), MFLOAT_C(5.0)));
	printf_2f_test("`vec2_inverse`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(0.2), v.x, v.y);
	v = svec2_abs(svec2(MFLOAT_C(-7.0), MFLOAT_C(-3.0)));
	printf_2f_test("`vec2_abs`", 7.0, MFLOAT_C(3.0), v.x, v.y);
	v = svec2_floor(svec2(MFLOAT_C(-7.2), MFLOAT_C(-3.7)));
	printf_2f_test("`vec2_floor`", -8.0, MFLOAT_C(-4.0), v.x, v.y);
	v = svec2_ceil(svec2(MFLOAT_C(-7.2), MFLOAT_C(-3.7)));
	printf_2f_test("`vec2_ceil`", -7.0, MFLOAT_C(-3.0), v.x, v.y);
	v = svec2_round(svec2(MFLOAT_C(-7.2), MFLOAT_C(-3.7)));
	printf_2f_test("`vec2_round`", -7.0, MFLOAT_C(-4.0), v.x, v.y);
	v = svec2_max(svec2(MFLOAT_C(-7.2), MFLOAT_C(-3.7)), svec2(MFLOAT_C(1.0), MFLOAT_C(3.7)));
	printf_2f_test("`vec2_max`", MFLOAT_C(1.0), MFLOAT_C(3.7), v.x, v.y);
	v = svec2_min(svec2(MFLOAT_C(-7.2), MFLOAT_C(-3.7)), svec2(MFLOAT_C(1.0), MFLOAT_C(3.7)));
	printf_2f_test("`vec2_min`", MFLOAT_C(-7.2), MFLOAT_C(-3.7), v.x, v.y);
	v = svec2_clamp(svec2(MFLOAT_C(-9.1), MFLOAT_C(8.7)), svec2(MFLOAT_C(-1.3), MFLOAT_C(2.7)), svec2(MFLOAT_C(3.3), MFLOAT_C(5.7)));
	printf_2f_test("`vec2_clamp`", MFLOAT_C(-1.3), MFLOAT_C(5.7), v.x, v.y);
	v = svec2_normalize(svec2(MFLOAT_C(1.0), MFLOAT_C(1.0)));
	printf_2f_test("`vec2_normalize`", MFLOAT_C(0.7071067811865475), MFLOAT_C(0.7071067811865475), v.x, v.y);
	v = svec2_project(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0)), svec2(MFLOAT_C(0.5), MFLOAT_C(1.0)));
	printf_2f_test("`vec2_project`", MFLOAT_C(1.2), MFLOAT_C(2.4), v.x, v.y);
	v = svec2_slide(svec2(MFLOAT_C(1.0), MFLOAT_C(0.0)), svec2(MFLOAT_C(-0.7071067811865475), MFLOAT_C(-0.7071067811865475)));
	printf_2f_test("`vec2_slide`", MFLOAT_C(0.5), MFLOAT_C(-0.5), v.x, v.y);
	v = svec2_reflect(svec2(MFLOAT_C(1.0), MFLOAT_C(0.0)), svec2(MFLOAT_C(-0.7071067811865475), MFLOAT_C(-0.7071067811865475)));
	printf_2f_test("`vec2_reflect`", MFLOAT_C(0.0), MFLOAT_C(-1.0), v.x, v.y);
	v = svec2_tangent(svec2(MFLOAT_C(1.0), MFLOAT_C(0.0)));
	printf_2f_test("`vec2_tangent`", MFLOAT_C(0.0), MFLOAT_C(-1.0), v.x, v.y);
	v = svec2_rotate(svec2(MFLOAT_C(1.0), MFLOAT_C(0.0)), to_radians(MFLOAT_C(45.0)));
	printf_2f_test("`vec2_rotate`", MFLOAT_C(0.7071067811865475), MFLOAT_C(0.7071067811865475), v.x, v.y);
	v = svec2_lerp(svec2(MFLOAT_C(3.0), MFLOAT_C(3.0)), svec2(MFLOAT_C(9.0), MFLOAT_C(1.0)), MFLOAT_C(0.5));
	printf_2f_test("`vec2_lerp`", MFLOAT_C(6.0), MFLOAT_C(2.0), v.x, v.y);
	v = svec2_bezier3(svec2(MFLOAT_C(3.0), MFLOAT_C(3.0)), svec2(MFLOAT_C(9.0), MFLOAT_C(1.0)), svec2(MFLOAT_C(14.0), MFLOAT_C(7.0)), MFLOAT_C(0.5));
	printf_2f_test("`vec2_bezier3`", MFLOAT_C(8.75), MFLOAT_C(3.0), v.x, v.y);
	v = svec2_bezier4(svec2(MFLOAT_C(3.0), MFLOAT_C(3.0)), svec2(MFLOAT_C(9.0), MFLOAT_C(1.0)), svec2(MFLOAT_C(14.0), MFLOAT_C(7.0)), svec2(MFLOAT_C(21.0), MFLOAT_C(9.0)), MFLOAT_C(0.5));
	printf_2f_test("`vec2_bezier4`", MFLOAT_C(11.625), MFLOAT_C(4.5), v.x, v.y);
	printf_1f_test("`vec2_dot`", MFLOAT_C(13.0), svec2_dot(svec2(MFLOAT_C(3.0), MFLOAT_C(2.0)), svec2(MFLOAT_C(1.0), MFLOAT_C(5.0))));
	printf_1f_test("`vec2_angle`", to_radians(MFLOAT_C(45.0)), svec2_angle(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0))));
	printf_1f_test("`vec2_length`", MFLOAT_C(2.8284271247461903), svec2_length(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0))));
	printf_1f_test("`vec2_length_squared`", MFLOAT_C(8.0), svec2_length_squared(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0))));
	printf_1f_test("`vec2_distance`", MFLOAT_C(5.6568542494923806), svec2_distance(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0)), svec2(MFLOAT_C(6.0), MFLOAT_C(6.0))));
	printf_1f_test("`vec2_distance_squared`", MFLOAT_C(32.0), svec2_distance_squared(svec2(MFLOAT_C(2.0), MFLOAT_C(2.0)), svec2(MFLOAT_C(6.0), MFLOAT_C(6.0))));
}

void vec3_tests(void)
{
	struct vec3 v;
	struct mat3 m;
	printf_bool_test("`vec3_is_zero`", true, svec3_is_zero(svec3(MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0))));
	printf_bool_test("`vec3_is_near_zero`", true, svec3_is_near_zero(svec3(MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0)), EPSILON_1));
	printf_bool_test("`vec3_is_equal`", true, svec3_is_equal(svec3(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0)), svec3(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0))));
	printf_bool_test("`vec3_is_nearly_equal`", true, svec3_is_nearly_equal(svec3(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0)), svec3(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0)), EPSILON_1));
	v = svec3(MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0));
	printf_3f_test("`vec3`", MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), v.x, v.y, v.z);
	v = svec3_assign(svec3(MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0)));
	printf_3f_test("`vec3_assign`", MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), v.x, v.y, v.z);
	v = svec3_zero();
	printf_3f_test("`vec3_zero`", MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0), v.x, v.y, v.z);
	v = svec3_add(svec3(MFLOAT_C(3.0), MFLOAT_C(1.0), MFLOAT_C(4.0)), svec3(MFLOAT_C(1.0), MFLOAT_C(7.0), MFLOAT_C(2.0)));
	printf_3f_test("`vec3_add`", MFLOAT_C(4.0), MFLOAT_C(8.0), MFLOAT_C(6.0), v.x, v.y, v.z);
	v = svec3_subtract(svec3(MFLOAT_C(1.0), MFLOAT_C(20.0), MFLOAT_C(9.0)), svec3(MFLOAT_C(3.0), MFLOAT_C(7.0), MFLOAT_C(7.0)));
	printf_3f_test("`vec3_subtract`", MFLOAT_C(-2.0), MFLOAT_C(13.0), MFLOAT_C(2.0), v.x, v.y, v.z);
	v = svec3_scale(svec3(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0)), MFLOAT_C(3.0));
	printf_3f_test("`vec3_scale`", MFLOAT_C(3.0), MFLOAT_C(9.0), MFLOAT_C(15.0), v.x, v.y, v.z);
	v = svec3_multiply(svec3(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0)), svec3(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0)));
	printf_3f_test("`vec3_multiply`", MFLOAT_C(3.0), MFLOAT_C(15.0), MFLOAT_C(10.0), v.x, v.y, v.z);
	m = smat3(
		MFLOAT_C(1.0), MFLOAT_C(2.0), MFLOAT_C(3.0),
		MFLOAT_C(4.0), MFLOAT_C(5.0), MFLOAT_C(6.0),
		MFLOAT_C(7.0), MFLOAT_C(8.0), MFLOAT_C(9.0));
	v = svec3_multiply_mat3(svec3(MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0)), m);
	printf_3f_test("`vec3_multiply_mat3`", MFLOAT_C(13.0), MFLOAT_C(31.0), MFLOAT_C(49.0), v.x, v.y, v.z);
	v = svec3_divide(svec3(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0)), svec3(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0)));
	printf_3f_test("`vec3_divide`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(0.6), MFLOAT_C(2.5), v.x, v.y, v.z);
	v = svec3_snap(svec3(MFLOAT_C(1.3), MFLOAT_C(-3.1), MFLOAT_C(4.9)), svec3(MFLOAT_C(0.5), MFLOAT_C(0.5), MFLOAT_C(0.5)));
	printf_3f_test("`vec3_snap`", MFLOAT_C(1.0), MFLOAT_C(-3.5), MFLOAT_C(4.5), v.x, v.y, v.z);
	v = svec3_negative(svec3(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(-7.0)));
	printf_3f_test("`vec3_negative`", MFLOAT_C(-3.0), MFLOAT_C(-5.0), MFLOAT_C(7.0), v.x, v.y, v.z);
	v = svec3_inverse(svec3(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(7.0)));
	printf_3f_test("`vec3_inverse`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(1.0 / 5.0), MFLOAT_C(1.0 / 7.0), v.x, v.y, v.z);
	v = svec3_abs(svec3(MFLOAT_C(-7.0), MFLOAT_C(-3.0), MFLOAT_C(1.0)));
	printf_3f_test("`vec3_abs`", 7.0, MFLOAT_C(3.0), MFLOAT_C(1.0), v.x, v.y, v.z);
	v = svec3_floor(svec3(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.1)));
	printf_3f_test("`vec3_floor`", -8.0, MFLOAT_C(-4.0), MFLOAT_C(9.0), v.x, v.y, v.z);
	v = svec3_ceil(svec3(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(0.99)));
	printf_3f_test("`vec3_ceil`", -7.0, MFLOAT_C(-3.0), MFLOAT_C(1.0), v.x, v.y, v.z);
	v = svec3_round(svec3(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(0.01)));
	printf_3f_test("`vec3_round`", -7.0, MFLOAT_C(-4.0), MFLOAT_C(0.0), v.x, v.y, v.z);
	v = svec3_max(svec3(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0)), svec3(MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0)));
	printf_3f_test("`vec3_max`", MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0), v.x, v.y, v.z);
	v = svec3_min(svec3(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0)), svec3(MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0)));
	printf_3f_test("`vec3_min`", MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0), v.x, v.y, v.z);
	v = svec3_clamp(svec3(MFLOAT_C(-9.1), MFLOAT_C(8.7), MFLOAT_C(0.4)), svec3(MFLOAT_C(-1.3), MFLOAT_C(2.7), MFLOAT_C(0.7)), svec3(MFLOAT_C(3.3), MFLOAT_C(5.7), MFLOAT_C(0.8)));
	printf_3f_test("`vec3_clamp`", MFLOAT_C(-1.3), MFLOAT_C(5.7), MFLOAT_C(0.7), v.x, v.y, v.z);
	v = svec3_normalize(svec3(MFLOAT_C(3.0), MFLOAT_C(1.0), MFLOAT_C(2.0)));
	printf_3f_test("`vec3_normalize`", MFLOAT_C(0.8017837257372732), MFLOAT_C(0.2672612419124244), MFLOAT_C(0.5345224838248488), v.x, v.y, v.z);
	v = svec3_project(svec3(MFLOAT_C(-1.0), MFLOAT_C(4.0), MFLOAT_C(2.0)), svec3(MFLOAT_C(1.0), MFLOAT_C(5.0), MFLOAT_C(3.0)));
	printf_3f_test("`vec3_project`", MFLOAT_C(0.7142857142857143), MFLOAT_C(3.5714285714285716), 2.1428571428571428, v.x, v.y, v.z);
	v = svec3_slide(svec3(MFLOAT_C(1.0), MFLOAT_C(0.5), MFLOAT_C(-1.0)), svec3(MFLOAT_C(-0.1), MFLOAT_C(0.0), MFLOAT_C(1.0)));
	printf_3f_test("`vec3_slide`", MFLOAT_C(0.89),  MFLOAT_C(0.5),  MFLOAT_C(0.1), v.x, v.y, v.z);
	v = svec3_reflect(svec3(MFLOAT_C(1.0), MFLOAT_C(0.5), MFLOAT_C(-1.0)), svec3(MFLOAT_C(-0.1), MFLOAT_C(0.0), MFLOAT_C(1.0)));
	printf_3f_test("`vec3_reflect`", MFLOAT_C(0.78),  MFLOAT_C(0.5),  MFLOAT_C(1.2), v.x, v.y, v.z);
	v = svec3_lerp(svec3(MFLOAT_C(3.0), MFLOAT_C(3.0), MFLOAT_C(3.0)), svec3(MFLOAT_C(9.0), MFLOAT_C(1.0), MFLOAT_C(30.0)), MFLOAT_C(0.5));
	printf_3f_test("`vec3_lerp`", MFLOAT_C(6.0),  MFLOAT_C(2.0),  MFLOAT_C(16.5), v.x, v.y, v.z);
	v = svec3_bezier3(svec3(MFLOAT_C(-1.0), MFLOAT_C(-0.5), MFLOAT_C(0.2)), svec3(MFLOAT_C(1.5), MFLOAT_C(0.15), MFLOAT_C(0.5)), svec3(MFLOAT_C(1.0), MFLOAT_C(-1.0), MFLOAT_C(0.0)), MFLOAT_C(0.5));
	printf_3f_test("`vec3_bezier3`", MFLOAT_C(0.75), MFLOAT_C(-0.3), MFLOAT_C(0.3), v.x, v.y, v.z);
	v = svec3_bezier4(svec3(MFLOAT_C(3.0), MFLOAT_C(3.0), MFLOAT_C(3.0)), svec3(MFLOAT_C(9.0), MFLOAT_C(7.0), MFLOAT_C(9.0)), svec3(MFLOAT_C(-4.0), MFLOAT_C(6.0), MFLOAT_C(7.0)), svec3(MFLOAT_C(-5.0), MFLOAT_C(1.0), MFLOAT_C(2.0)), MFLOAT_C(0.5));
	printf_3f_test("`vec3_bezier4`", MFLOAT_C(1.625), MFLOAT_C(5.375), MFLOAT_C(6.625), v.x, v.y, v.z);
	printf_1f_test("`vec3_dot`", MFLOAT_C(44.0), svec3_dot(svec3(MFLOAT_C(1.0), MFLOAT_C(2.0), MFLOAT_C(3.0)), svec3(MFLOAT_C(6.0), MFLOAT_C(7.0), MFLOAT_C(8.0))));
	printf_1f_test("`vec3_length`", MFLOAT_C(3.4641016151377544), svec3_length(svec3(MFLOAT_C(2.0), MFLOAT_C(2.0), MFLOAT_C(2.0))));
	printf_1f_test("`vec3_length_squared`", MFLOAT_C(12.0), svec3_length_squared(svec3(MFLOAT_C(2.0), MFLOAT_C(2.0), MFLOAT_C(2.0))));
	printf_1f_test("`vec3_distance`", MFLOAT_C(6.9282032302755088), svec3_distance(svec3(MFLOAT_C(2.0), MFLOAT_C(2.0), MFLOAT_C(2.0)), svec3(MFLOAT_C(6.0), MFLOAT_C(6.0), MFLOAT_C(6.0))));
	printf_1f_test("`vec3_distance_squared`", MFLOAT_C(48.0), svec3_distance_squared(svec3(MFLOAT_C(2.0), MFLOAT_C(2.0), MFLOAT_C(2.0)), svec3(MFLOAT_C(6.0), MFLOAT_C(6.0), MFLOAT_C(6.0))));
}

void vec4_tests(void)
{
	struct vec4 v;
	struct mat4 m;
	printf_bool_test("`vec4_is_zero`", true, svec4_is_zero(svec4(MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0))));
	printf_bool_test("`vec4_is_near_zero`", true, svec4_is_near_zero(svec4(MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0)), EPSILON_1));
	printf_bool_test("`vec4_is_equal`", true, svec4_is_equal(svec4(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0), MFLOAT_C(3.0) / MFLOAT_C(7.0)), svec4(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0), MFLOAT_C(3.0) / MFLOAT_C(7.0))));
	printf_bool_test("`vec4_is_nearly_equal`", true, svec4_is_nearly_equal(svec4(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0), MFLOAT_C(3.0) / MFLOAT_C(7.0)), svec4(MFLOAT_C(1.0) / MFLOAT_C(3.0), MFLOAT_C(7.0) / MFLOAT_C(3.0), MFLOAT_C(5.0) / MFLOAT_C(3.0), MFLOAT_C(3.0) / MFLOAT_C(7.0)), EPSILON_1));
	v.x = MFLOAT_C(2.0);
	v.y = MFLOAT_C(1.0);
	v.z = MFLOAT_C(3.0);
	v.w = MFLOAT_C(4.0);
	v = svec4(MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(4.0));
	printf_4f_test("`vec4`", MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(4.0), v.x, v.y, v.z, v.w);
	v = svec4_assign(svec4(MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(4.0)));
	printf_4f_test("`vec3_assign`", MFLOAT_C(2.0), MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(4.0), v.x, v.y, v.z, v.w);
	v = svec4_zero();
	printf_4f_test("`vec4_zero`", MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0), MFLOAT_C(0.0), v.x, v.y, v.z, v.w);
	v = svec4_add(svec4(MFLOAT_C(3.0), MFLOAT_C(1.0), MFLOAT_C(4.0), MFLOAT_C(2.0)), svec4(MFLOAT_C(1.0), MFLOAT_C(7.0), MFLOAT_C(2.0), MFLOAT_C(3.0)));
	printf_4f_test("`vec4_add`", MFLOAT_C(4.0), MFLOAT_C(8.0), MFLOAT_C(6.0), MFLOAT_C(5.0), v.x, v.y, v.z, v.w);
	v = svec4_subtract(svec4(MFLOAT_C(1.0), MFLOAT_C(20.0), MFLOAT_C(9.0), MFLOAT_C(10.0)), svec4(MFLOAT_C(3.0), MFLOAT_C(7.0), MFLOAT_C(7.0), MFLOAT_C(5.0)));
	printf_4f_test("`vec4_subtract`", MFLOAT_C(-2.0), MFLOAT_C(13.0), MFLOAT_C(2.0), MFLOAT_C(5.0), v.x, v.y, v.z, v.w);
	v = svec4_scale(svec4(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0)), MFLOAT_C(3.0));
	printf_4f_test("`vec4_scale`", MFLOAT_C(3.0), MFLOAT_C(9.0), MFLOAT_C(15.0), MFLOAT_C(6.0), v.x, v.y, v.z, v.w);
	v = svec4_multiply(svec4(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0)), svec4(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0), MFLOAT_C(2.0)));
	printf_4f_test("`vec4_multiply`", MFLOAT_C(3.0), MFLOAT_C(15.0), MFLOAT_C(10.0), MFLOAT_C(4.0), v.x, v.y, v.z, v.w);
	m = smat4(
		MFLOAT_C(1.0), MFLOAT_C(5.0), MFLOAT_C(9.0), MFLOAT_C(13.0),
		MFLOAT_C(2.0), MFLOAT_C(6.0), MFLOAT_C(10.0), MFLOAT_C(14.0),
		MFLOAT_C(3.0), MFLOAT_C(7.0), MFLOAT_C(11.0), MFLOAT_C(15.0),
		MFLOAT_C(4.0), MFLOAT_C(8.0), MFLOAT_C(12.0), MFLOAT_C(16.0));
	v = svec4_multiply_mat4(svec4(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(7.0), MFLOAT_C(9.0)), m);
	printf_4f_test("`vec4_multiply_mat4`", MFLOAT_C(208.0), MFLOAT_C(232.0), MFLOAT_C(256.0), MFLOAT_C(280.0), v.x, v.y, v.z, v.w);
	v = svec4_divide(svec4(MFLOAT_C(1.0), MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0)), svec4(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(2.0), MFLOAT_C(4.0)));
	printf_4f_test("`vec4_divide`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(0.6), MFLOAT_C(2.5), MFLOAT_C(0.5), v.x, v.y, v.z, v.w);
	v = svec4_snap(svec4(MFLOAT_C(1.3), MFLOAT_C(-3.1), MFLOAT_C(4.9), MFLOAT_C(5.6)), svec4(MFLOAT_C(0.5), MFLOAT_C(0.5), MFLOAT_C(0.5), MFLOAT_C(0.5)));
	printf_4f_test("`vec4_snap`", MFLOAT_C(1.0), MFLOAT_C(-3.5), MFLOAT_C(4.5), MFLOAT_C(5.5), v.x, v.y, v.z, v.w);
	v = svec4_negative(svec4(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(-7.0), MFLOAT_C(0.01)));
	printf_4f_test("`vec4_negative`", MFLOAT_C(-3.0), MFLOAT_C(-5.0), MFLOAT_C(7.0), MFLOAT_C(-0.01), v.x, v.y, v.z, v.w);
	v = svec4_inverse(svec4(MFLOAT_C(3.0), MFLOAT_C(5.0), MFLOAT_C(7.0), MFLOAT_C(8.0)));
	printf_4f_test("`vec4_inverse`", MFLOAT_C(1.0 / 3.0), MFLOAT_C(1.0 / 5.0), MFLOAT_C(1.0 / 7.0), MFLOAT_C(1.0 / 8.0), v.x, v.y, v.z, v.w);
	v = svec4_abs(svec4(MFLOAT_C(-7.0), MFLOAT_C(-3.0), MFLOAT_C(1.0), MFLOAT_C(0.0001)));
	printf_4f_test("`vec4_abs`", 7.0, MFLOAT_C(3.0), MFLOAT_C(1.0), MFLOAT_C(0.0001), v.x, v.y, v.z, v.w);
	v = svec4_floor(svec4(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.1), MFLOAT_C(1.0)));
	printf_4f_test("`vec4_floor`", -8.0, MFLOAT_C(-4.0), MFLOAT_C(9.0), MFLOAT_C(1.0), v.x, v.y, v.z, v.w);
	v = svec4_ceil(svec4(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(0.99), MFLOAT_C(1.0)));
	printf_4f_test("`vec4_ceil`", -7.0, MFLOAT_C(-3.0), MFLOAT_C(1.0), MFLOAT_C(1.0), v.x, v.y, v.z, v.w);
	v = svec4_round(svec4(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(0.01), MFLOAT_C(1.0)));
	printf_4f_test("`vec4_round`", -7.0, MFLOAT_C(-4.0), MFLOAT_C(0.0), MFLOAT_C(1.0), v.x, v.y, v.z, v.w);
	v = svec4_max(svec4(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0), MFLOAT_C(2.0)), svec4(MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0), MFLOAT_C(3.0)));
	printf_4f_test("`vec4_max`", MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0), MFLOAT_C(3.0), v.x, v.y, v.z, v.w);
	v = svec4_min(svec4(MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0), MFLOAT_C(2.0)), svec4(MFLOAT_C(1.0), MFLOAT_C(3.7), MFLOAT_C(30.0), MFLOAT_C(3.0)));
	printf_4f_test("`vec4_min`", MFLOAT_C(-7.2), MFLOAT_C(-3.7), MFLOAT_C(9.0), MFLOAT_C(2.0), v.x, v.y, v.z, v.w);
	v = svec4_clamp(svec4(MFLOAT_C(-9.1), MFLOAT_C(8.7), MFLOAT_C(0.4), MFLOAT_C(1.0)), svec4(MFLOAT_C(-1.3), MFLOAT_C(2.7), MFLOAT_C(0.7), MFLOAT_C(0.5)), svec4(MFLOAT_C(3.3), MFLOAT_C(5.7), MFLOAT_C(0.8), MFLOAT_C(2.0)));
	printf_4f_test("`vec4_clamp`", MFLOAT_C(-1.3), MFLOAT_C(5.7), MFLOAT_C(0.7), MFLOAT_C(1.0), v.x, v.y, v.z, v.w);
	v = svec4_normalize(svec4(MFLOAT_C(3.0), MFLOAT_C(1.0), MFLOAT_C(2.0), MFLOAT_C(4.0)));
	printf_4f_test("`vec4_normalize`", MFLOAT_C(0.5477225184440613), MFLOAT_C(0.1825741858350554), MFLOAT_C(0.3651483716701107), MFLOAT_C(0.7302967433402214), v.x, v.y, v.z, v.w);
	v = svec4_lerp(svec4(MFLOAT_C(3.0), MFLOAT_C(3.0), MFLOAT_C(3.0), MFLOAT_C(3.0)), svec4(MFLOAT_C(9.0), MFLOAT_C(1.0), MFLOAT_C(30.0), MFLOAT_C(7.0)), MFLOAT_C(0.5));
	printf_4f_test("`vec4_lerp`", MFLOAT_C(6.0),  MFLOAT_C(2.0),  MFLOAT_C(16.5), MFLOAT_C(5.0), v.x, v.y, v.z, v.w);
}

void euler_tests(void)
{
	struct euler euler;
	bool singularity;
	euler = seuler_xyz_from_quat(squat_normalize(squat(MFLOAT_C(-0.544085), MFLOAT_C(-0.256040), MFLOAT_C(0.470073), MFLOAT_C(0.646101))), &singularity);
	printf_3f_test("`rot_xyz_from_quat`", MFLOAT_C(-1.0313020971920974), MFLOAT_C(-1.0016747123760390), MFLOAT_C(0.6562711596488953), euler.v[0], euler.v[1], euler.v[2]);
	if (singularity) {
		printf("\tSingularity test failed\n");
	}
}

int main(int argc, char *args[])
{
	if (argc > 1) {
		report_difference = true;
		difference_to_report = atof(args[1]);
	}
	vec2_tests();
	vec3_tests();
	vec4_tests();
	euler_tests();
	return EXIT_SUCCESS;
}
