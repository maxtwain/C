#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))
#define MINIMUM3(x, y, z) ((MINIMUM2(x, y)) < (z) ? (MINIMUM2(x, y)) : (z))

int main(void) {
	srand((unsigned int)time(NULL));

	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;

	printf("The smallest integer between %d, %d, and %d is %d\n", a, b, c, MINIMUM3(a, b, c));

}