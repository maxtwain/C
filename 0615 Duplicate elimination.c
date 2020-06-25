#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Reading the exercise carfully, the description actually asks for a data structure with the behavior of a vector.  What it wants is to add a new value to the array only if that value does not exist in previous elements.  In order to do this as it asks I need to be able to save all previous elements in an array no bigger than the number of elements.  What I could do is create a new array every time a unique value is generated, but this is far too innefficient.

#define SIZE 20

int main(void) {
	srand((unsigned int)time(NULL));

	// random array elements
	int arr[SIZE] = { 0 };
	for (size_t index = 0; index < SIZE; ++index) {
		arr[index] = 10 + rand() % 91;
	}

	unsigned int duplicate;
	for (size_t full = 0; full < SIZE; ++full) {
		duplicate = 0;
		for (size_t previous = 0; previous < full && duplicate == 0; ++previous) {
			if (arr[full] == arr[previous]) duplicate = 1;
		}
		if (duplicate == 0) printf("arr[%02u] = %d\n", full, arr[full]);
		else printf("arr[%02u] = SKIPPED\n", full);
	}
	puts("");
}