#include <stdio.h>

void power2(int number, int power);

int main(void) {

	printf("sizeof(unsigned int) = %d bits\n", sizeof(unsigned int) * 8);
	printf("sizeof(int) = %d\n", sizeof(int) * 8);
	puts("");

	power2(2, 0);
	power2(2, 1);
	power2(2, 2);
	power2(2, 3);
	power2(2, 4);



}

void power2(int number, int power) {

	unsigned int value = number << power;
	unsigned int mask = 1 << 31;

	printf("%10u = ", value);

	for (unsigned int c = 1; c <= 32; ++c) {
		putchar(value & mask ? '1' : '0');
		value <<= 1;

		if (c % 8 == 0) {
			putchar(' ');
		}
	}

	printf("%d * 2^%d = %d\n", number, power, number << power);
}