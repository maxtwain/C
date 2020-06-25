#include <stdio.h>

#define SIZE 10

int linearSearch(const int data[], int size, int key);

int main(void) {
	int arr[SIZE] = { 8, 3, 1, 2, 6, 0, 9, 7, 4, 5 };

	int key = 0;
	printf("sizeof(arr) = %d\n", sizeof(arr) / sizeof(int));
	printf("%d exists in arr at index %d\n", key, linearSearch(arr, sizeof(arr) / sizeof(int), key));
	
}

int linearSearch(const int data[], int size, int key) {
	
	if (size == 0) {
		return -1;
	}
	if (data[size - 1] == key) {
		return size - 1;
	}
	return linearSearch(data, size - 1, key);
}