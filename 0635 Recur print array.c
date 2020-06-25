#include <stdio.h>

void printArray(int data[], int size);

int main(void) {

	int arr[] = { 4, 34, 25, 11, 66, 74, 34, 26, 99 };
	printArray(arr, sizeof(arr) / sizeof(int));

}

void printArray(int data[], int size) {

	printf("%d\n", data[size - 1]);
	if (size > 1) {
		printArray(data, size - 1);
	}
}