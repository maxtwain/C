#include <stdio.h>

int main(void) {
	unsigned int x, y, power;

	printf("%s", "Base: ");
	scanf_s("%u", &x);

	printf("%s", "Power: ");
	scanf_s("%u", &y);

	power = 1;
	while (y > 0) {
		power *= x;
		y--;
	}

	printf("%u\n", power);
}