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
#include "mathc.h"

void vector2_tests()
{
	cvector2 a;
	cvector2 b;
	cvector2 r;
	float p;
	printf("Making tests with 2D vectors...\n");
	printf("\n# Add two vectors\n");
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_add(a, b);
	printf("  Expected: %0.4f, %0.4f\n", 2.01f, 3.8f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Subtract two vectors\n");
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_subtract(a, b);
	printf("  Expected: %0.4f, %0.4f\n", 0.21f, 1.2f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Scale a vector\n");
	a = to_vector2(1.11f, 2.5f);
	r = vector2_scale(a, 3.3f);
	printf("  Expected: %0.4f, %0.4f\n", 3.663f, 8.25f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Multiply two vectors\n");
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_multiply(a, b);
	printf("  Expected: %0.4f, %0.4f\n", 0.999f, 3.25f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Divide two vectors\n");
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_divide(a, b);
	printf("  Expected: %0.4f, %0.4f\n", 1.2333333333f, 1.9230769231f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Negative vector\n");
	a = to_vector2(1.11f, 2.5f);
	r = vector2_negative(a);
	printf("  Expected: %0.4f, %0.4f\n", -1.11f, -2.5f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Absolute vector\n");
	a = to_vector2(-3.33f, 1.1f);
	r = vector2_abs(a);
	printf("  Expected: %0.4f, %0.4f\n", 3.33f, 1.1f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	a = to_vector2(3.33f, -1.1f);
	r = vector2_abs(a);
	printf("  Expected: %0.4f, %0.4f\n", 3.33f, 1.1f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	a = to_vector2(-3.33f, -1.1f);
	r = vector2_abs(a);
	printf("  Expected: %0.4f, %0.4f\n", 3.33f, 1.1f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Floor vector\n");
	a = to_vector2(1.11f, -2.5f);
	r = vector2_floor(a);
	printf("  Expected: %0.4f, %0.4f\n", 1.0f, -3.0f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Ceil vector\n");
	a = to_vector2(1.11f, -2.5f);
	r = vector2_ceil(a);
	printf("  Expected: %0.4f, %0.4f\n", 2.0f, -2.0f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Round vector\n");
	a = to_vector2(1.11f, -2.55f);
	r = vector2_round(a);
	printf("  Expected: %0.4f, %0.4f\n", 1.0f, -3.0f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Maximum value between two vector\n");
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	r = vector2_max(a, b);
	printf("  Expected: %0.4f, %0.4f\n", 4.31f, 2.7f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Minimum value between two vector\n");
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	r = vector2_min(a, b);
	printf("  Expected: %0.4f, %0.4f\n", -3.41f, -6.65f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Dot value of two vectors\n");
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	p = vector2_dot(a, b);
	printf("  Expected: %0.4f\n", -32.6521f);
	printf("    Actual: %0.4f\n", p);
	printf("\n# Angle of a vector\n");
	a = to_vector2(3.0f, 2.0f);
	p = vector2_angle(a);
	printf("  Expected: %0.4f (radians)\n", 0.5880031703f);
	printf("    Actual: %0.4f (radians)\n", p);
	a = to_vector2(4.31f, -6.65f);
	p = vector2_angle(a);
	printf("  Expected: %0.4f (radians)\n", -0.9957434995f);
	printf("    Actual: %0.4f (radians)\n", p);
	a = to_vector2(-4.31f, 6.65f);
	p = vector2_angle(a);
	printf("  Expected: %0.4f (radians)\n", 2.145847409f);
	printf("    Actual: %0.4f (radians)\n", p);
	a = to_vector2(-5.31f, -7.33f);
	p = vector2_angle(a);
	printf("  Expected: %0.4f (radians)\n", -2.19771859f);
	printf("    Actual: %0.4f (radians)\n", p);
	printf("\n# Length squared of a vector\n");
	a = to_vector2(3.33f, 2.0f);
	p = vector2_length_squared(a);
	printf("  Expected: %0.4f\n", 15.0888741136f);
	printf("    Actual: %0.4f\n", p);
	printf("\n# Length of a vector\n");
	a = to_vector2(3.33f, 2.0f);
	p = vector2_length(a);
	printf("  Expected: %0.4f\n", 3.88444f);
	printf("    Actual: %0.4f\n", p);
	printf("\n# Normalized vector\n");
	a = to_vector2(3.33f, 2.0f);
	r = vector2_normalize(a);
	printf("  Expected: %0.4f, %0.4f\n", 0.8572664271f, 0.514874731f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Slide a vector by another\n");
	a = to_vector2(1.3f, 7.7f);
	b = to_vector2(3.66f, 8.0f);
	r = vector2_slide(a, b);
	printf("  Expected: %0.4f, %0.4f\n", -82.605392f, -502.956604f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Reflect a vector by another\n");
	a = to_vector2(5.3f, 9.7f);
	b = to_vector2(3.66f, 8.0f);
	r = vector2_reflect(a, b);
	printf("  Expected: %0.4f, %0.4f\n", -168.870789f, -1013.913208f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Vector tangent\n");
	a = to_vector2(1.3f, 7.7f);
	r = vector2_tangent(a);
	printf("  Expected: %0.4f, %0.4f\n", 7.7f, -1.3f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Rotate vector\n");
	a = to_vector2(7.7f, 0.0f);
	r = vector2_rotate(a, (90.0f * M_PIF) / 180.0f);
	printf("  Expected: %0.4f, %0.4f\n", 0.0f, 7.7f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	a = to_vector2(7.7f, 0.0f);
	r = vector2_rotate(a, (180.0f * M_PIF) / 180.0f);
	printf("  Expected: %0.4f, %0.4f\n", -7.7f, 0.0f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	printf("\n# Distance between two vectors\n");
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	p = vector2_distance_to(a, b);
	printf("  Expected: %0.4f\n", 26.196374f);
	printf("    Actual: %0.4f\n", p);
	printf("\n# Distance squared between two vectors\n");
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	p = vector2_distance_squared_to(a, b);
	printf("  Expected: %0.4f\n", 686.2500107479f);
	printf("    Actual: %0.4f\n", p);
	printf("\n# Interpolation between two vectors\n");
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	r = vector2_linear_interpolation(a, b, 0.0f);
	printf("  Expected: %0.4f, %0.4f\n", -7.0f, -4.0f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
	r = vector2_linear_interpolation(a, b, 0.33f);
	printf("  Expected: %0.4f, %0.4f\n", 0.92f, -0.535f);
	printf("    Actual: %0.4f, %0.4f\n", r.x, r.y);
}

int main(int argc, char **args)
{
	vector2_tests();
	return 0;
}
