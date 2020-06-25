#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))

int main(void) {
	srand((unsigned int)time(NULL));

	int a = rand() % 10;
	int b = rand() % 10;

	printf("The smallest integer between %d and %d is %d\n", a, b, MINIMUM2(a, b));

}