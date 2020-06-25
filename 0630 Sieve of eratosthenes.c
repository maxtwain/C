#include <stdio.h>

#define LIMIT 1'000

int main(void) {

	int index[LIMIT] = { 0 };

	// set all elements to true
	for (int ind = 0; ind < LIMIT; ++ind) {
		index[ind] = 1;
	}

	// 0 and 1 are not prime
	index[0] = 0;
	index[1] = 0;

	// for every true, multiply it to the end of the array.
	for (int ind1 = 2; ind1 * ind1 < LIMIT; ++ind1) {
		if (index[ind1]) {
			for (int ind2 = 2; ind1 * ind2 < LIMIT; ++ind2) {
				index[ind1 * ind2] = 0;
			}
		}
	}

	printf("Primes from 2 to %d:\n", LIMIT);
	for (int ind = 0; ind < LIMIT; ++ind) {
		if (index[ind]) {
			printf("%5d", ind);
		}
	}
	puts("\n");
}