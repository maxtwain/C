#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

unsigned int reverse(unsigned int num);
void printBits(unsigned int pack);

int main(void) {

	printf("max unsigned = %u\n", UINT_MAX);

	unsigned int num = 1355853807;

	printf("num = %u\n", num);
	printBits(num);

	num = reverse(num);

	printBits(num);

}

unsigned int reverse(unsigned int num) {
	unsigned int numRev = 0;
	unsigned int mask = 1 << 31;

	// can only rightshift positive numbers
	for (unsigned int i0 = 0; i0 < 16; ++i0) {
		numRev |= (num & mask) >> (31 - 2 * i0);
		mask >>= 1;
		printf("i0 = %d\t", i0);
		printBits(numRev);
	}

	for (unsigned int i0 = 0; i0 < 16; ++i0) {
		numRev |= (num & mask) << (1 + 2 * i0);
		mask >>= 1;
		printf("i1 = %d\t", i0);
		printBits(numRev);
	}

	return numRev;
}

void printBits(unsigned int pack) {

	unsigned int mask = 1 << 31;

	for (unsigned int c = 1; c <= 32; ++c) {
		putchar(pack & mask ? '1' : '0');
		pack <<= 1;

		if (c % 4 == 0) {
			putchar(' ');
		}
		if (c % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");
}