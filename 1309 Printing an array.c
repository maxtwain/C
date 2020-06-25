#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINTARRAY(x, y) for(int i = 0; i < y; ++i)printf("%4d", x[i]);
#define SIZE 10

int main(void) {
	srand((unsigned int)time(NULL));

	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 10;
	}

	PRINTARRAY(arr, SIZE)
	puts("");

}