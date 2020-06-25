#include <stdio.h>

int main(void) {

	union floatingPoint {
		float f;
		double d;
		long double x;
	} a;

	a.f = (float)4.3;
	printf("%f\n%lf\n%lf\n", a.f, a.d, a.x);
	puts("");

	a.d = 6.543;
	printf("%f\n%lf\n%lf\n", a.f, a.d, a.x);
	puts("");

	a.x = 73.5492;
	printf("%f\n%lf\n%lf\n", a.f, a.d, a.x);
	puts("");

}
