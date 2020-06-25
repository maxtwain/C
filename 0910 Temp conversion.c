#include <stdio.h>

double toCel(int far);

int main(void) {
	int far = 10;
	double celsius = 5.0 / 9.0 * (far - 32);
	printf("%10d\t%+.3f\n", far, celsius);

}