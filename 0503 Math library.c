#include <stdio.h>
#include <math.h>

int main(void) {
	printf("sqrt(900.0) = %.1f\n", sqrt(900.0));
	printf("sqrt(9.0) = %.1f\n", sqrt(9.0));
	puts("");

	printf("cbrt(27.0) = %.1f\n", cbrt(27.0));
	printf("cbrt(-8.0) = %.1f\n", cbrt(-8.0));
	puts("");
	
	printf("exp(1.0) = %f\n", exp(1.0));
	printf("exp(2.0) = %f\n", exp(2.0));
	puts("");
	
	printf("log(2.718080) = %.1f\n", log(2.718282));
	printf("log(7.389056) = %.1f\n", log(7.389056));
	puts("");
	
	printf("log10(1.0) = %.1f\n", log10(1.0));
	printf("log10(10.0) = %.1f\n", log10(10.0));
	printf("log10(100.0) = %.1f\n", log10(100.0));
	puts("");
	
	printf("fabs(13.5) = %.1f\n", fabs(13.5));
	printf("fabs(0.0) = %.1f\n", fabs(0.0));
	printf("fabs(-13.5) = %.1f\n", fabs(-13.5));
	puts("");
	
	printf("ceil(9.2) = %.1f\n", ceil(9.2));
	printf("ceil(-9.8) = %.1f\n", ceil(-9.8));
	puts("");
	
	printf("floor(9.2) = %.1f\n", floor(9.2));
	printf("floor(-9.8) = %.1f\n", floor(-9.8));
	puts("");
	
	printf("pow(2, 7) = %.1f\n", pow(2, 7));
	printf("pow(9, .5) = %.1f\n", pow(9, .5));
	puts("");
	
	printf("fmod(13.657, 2.333) = %.3f\n", fmod(13.657, 2.333));
	puts("");
	
	printf("sin(0.0) = %.1f\n", sin(0.0));
	printf("cos(0.0) = %.1f\n", cos(0.0));
	printf("tan(0.0) = %.1f\n", tan(0.0));
	puts("");
}