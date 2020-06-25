#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUMARRAY(x, y) { int total = 0; for (int i = 0; i < y; ++i) { total += x[i]; } printf("%d\n", total); }

#define SIZE 10

// This exercise asks for a program to be written that will use a macro to calculate a sum of array elements, but it doesn't say whether to print those elements or to provide a rvalue for assignment

int main(void) {
	srand((unsigned int)time(NULL));

	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 10;
	}

	SUMARRAY(arr, SIZE)
}