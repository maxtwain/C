#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main(void) {
	const int limit = 100;

	srand(time(NULL));

	int sumFlips = 0;
	for (int flips = 0; flips < limit; ++flips) {
		sumFlips += flip();
	}
	printf("Heads = %d\tTails = %d\n", sumFlips, limit - sumFlips);
}

int flip() {
	return rand() % 2;
}