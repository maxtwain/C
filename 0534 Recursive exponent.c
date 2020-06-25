#include <stdio.h>

unsigned long long power(unsigned int base, unsigned int exponent);

int main(void) {
	printf("power(2, 6) = %llu\n", power(2, 6));
	printf("power(2, 1) = %llu\n", power(2, 1));
	printf("power(2, 2) = %llu\n", power(2, 2));
	printf("power(2, 3) = %llu\n", power(2, 3));
}

unsigned long long power(unsigned int base, unsigned int exponent) {
	if (exponent == 1) return base;
	else return base * power(base, exponent - 1);
}