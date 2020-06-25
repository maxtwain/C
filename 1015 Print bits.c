#include <stdio.h>

void printBits(unsigned int pack);

int main(void) {

	unsigned int two = 27586;
	unsigned int four = 1545862557;

	printf("two = %u\nfour = %u\n", two, four);
	printf("sizeof(two) = %d\n", sizeof(two));

	printBits(four);
	printBits(two);
}

void printBits(unsigned int pack) {

	unsigned int size = sizeof(pack) * 8;

	printf("num = %u\n", pack);
	unsigned int mask = 1 << 31;

	for (unsigned int c = 1; c <= size; ++c) {
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