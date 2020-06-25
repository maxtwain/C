#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

int main(void) {
	printf("gcd(10, 5) = %d\n", gcd(10, 5));
	printf("gcd(49, 56) = %d\n", gcd(49, 56));
	printf("gcd(99, 110) = %d\n", gcd(99, 110));
	printf("gcd(99, 110) = %d\n", gcd(13, 19));
}

int gcd(int a, int b) {
	for (int divisor = a; divisor > 0; divisor--) {
		if (a % divisor == 0 && b % divisor == 0) return divisor;
	}
	return 0;
}