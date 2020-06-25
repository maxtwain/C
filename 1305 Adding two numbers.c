#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUM(x, y) ((x) + (y))

int main(void) {
	srand((unsigned int)time(NULL));
	
	int a = rand() % 10;
	int b = rand() % 10;

	printf("The sum of %d and %d is %d\n", a, b, SUM(a, b));
}