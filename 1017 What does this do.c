#include <stdio.h>

/*

The function mystery first counts how many bits are ones.  If the number of 1 bits is divisible by 2, mystery returns true.  Otherwise true is returned.  Examples: 1 is false.  2 is false.  3 is true.  4 is false.  5 is true.  6 is true.  7 is false.  8 is false.  9 is true.  10 is true.  11 is false.

*/

int mystery(unsigned int bits);

int main(void) {
	unsigned int x;

	puts("Enter an integer: ");
	scanf("%u", &x);

	printf("The result is %d\n", mystery(x));
}

int mystery(unsigned int bits){
	unsigned int mask = 1 << 31;
	unsigned int total = 0;

	for (unsigned int i = 1; i <= 32; ++i, bits <<= 1) {
		if ((bits & mask) == mask) {
			++total;
		}
	}
	return !(total % 2) ? 1 : 0;
}