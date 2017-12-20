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
		printf("%s:\n\tExpected true\n\t", msg);
	} else {
		printf("%s:\n\tExpected false\n\t", msg);
	}
	if (r) {
		printf("  Actual true\t");
	} else {
		printf("  Actual false\t");
	}

	if (e == r) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_1f_test(struct cerror *error, char *msg, float e1, float r1)
{
	bool done = false;
	printf("%s:\n\tExpected % .4f\n\t  Actual  % .4f\t", msg, e1, r1);
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

void printf_2f_test(struct cerror *error, char *msg, float e1, float e2, float r1, float r2)
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

void printf_3f_test(struct cerror *error, char *msg, float e1, float e2, float e3, float r1, float r2, float r3)
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
	if (!done && nearly_equal(e1, r1, epsilon * 100.0f) && nearly_equal(e2, r2, epsilon * 100.0f) && nearly_equal(e2, r2, epsilon * 100.0f)) {
		error->passed_with_e100 = error->passed_with_e100 + 1;
		done = true;
		printf("~passed with epsilon * 100.0~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 1000.0f) && nearly_equal(e2, r2, epsilon * 1000.0f) && nearly_equal(e2, r2, epsilon * 1000.0f)) {
		error->passed_with_e1000 = error->passed_with_e1000 + 1;
		done = true;
		printf("~passed with epsilon * 1000.0~\n\n");
	}
	if (!done) {
		error->failed = error->failed + 1;
		printf("~failed~\n\n");
	}
}

void printf_4f_test(struct cerror *error, char *msg, float e1, float e2, float e3, float e4, float r1, float r2, float r3, float r4)
{
	bool done = false;
	printf("%s:\n\tExpected % .9f, % .9f, % .9f, % .9f\n\t  Actual % .9f, % .9f, % .9f, % .9f\t", msg, e1, e2, e3, e4, r1, r2, r3, r4);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon) && nearly_equal(e3, r3, epsilon) && nearly_equal(e3, r3, epsilon)) {
		error->passed = error->passed + 1;
		done = true;
		printf("~passed~\n\n");
	}
	if (!done && nearly_equal(e1, r1, epsilon * 10.0f) && nearly_equal(e2, r2, epsilon * 10.0f) && nearly_equal(e3, r3, epsilon * 10.0f) && nearly_equal(e3, r3, epsilon * 10.0f)) {
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

void vector2_tests(struct cerror *error)
{
}

void vector3_tests(struct cerror *error)
{
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
	struct cerror error = {0, 0, 0, 0, 0};
	vector2_tests(&error);
	vector3_tests(&error);
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
