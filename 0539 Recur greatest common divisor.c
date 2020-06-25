#include <stdio.h>

unsigned long long gcd(unsigned long long x, unsigned long long y);

int main(void) {
	printf("gcd(2, 4) = %llu\n", gcd(2, 4));
	printf("gcd(42, 56) = %llu\n", gcd(42, 56));
	printf("gcd(110, 99) = %llu\n", gcd(110, 99));
	printf("gcd(96, 3) = %llu\n", gcd(96, 3));
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}