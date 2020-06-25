#include <stdio.h>

int recursiveMinimum(int data[], int size);

int main(void) {

	int arr[] = { 434, 356, 23, 5, 6, 45, 25, 72, 53 };

	printf("Min of arr = %d\n", recursiveMinimum(arr, sizeof(arr) / sizeof(int)));

}

int recursiveMinimum(int data[], int size) {

	if (data[size - 2] > data[size - 1]) {
		data[size - 2] = data[size - 1];
	}

	if (size <= 2) {
		return data[size - 1];
	}
	return recursiveMinimum(data, size - 1);

}