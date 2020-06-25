#include <stdio.h>

/*

The multiple function checks num to see if it has ten zeros before any 1's.  The result is that num is checked if it is divisable by 2^10, which is 1024 in base 10.

*/

int multiple(int num);

int main(void) {

	int y;

	puts("Enter an integer between 1 and 32000: ");
	scanf("%d", &y);

	if (multiple(y)) {
		printf("%d is a multiple of X\n", y);
	}
	else {
		printf("%d is not a multiple of X\n", y);
	}
}

int multiple(int num){
	int mask = 1;
	int mult = 1;

	for (int i = 1; i <= 10; ++i, mask <<= 1) {
		if ((num & mask) != 0) {
			mult = 0;
			break;
		}
	}
	return mult;
}