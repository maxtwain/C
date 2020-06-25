#include <stdio.h>

#define SIZE 15

int binarySearch(int data[], int searchKey, int low, int high);
void printHeader(void);
void printRow(int b[], int low, int mid, int high);
int binarySearchR(int data[], int searchKey, int low, int high);

int main(void) {
	int arr[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		arr[i] = 2 * i;
	}

	printf("%s", "Enter a number between 0 and 28: ");
	int key;
	scanf_s("%d", &key);

	printHeader();

	int result = binarySearchR(arr, key, 0, SIZE - 1);

	if (result != -1) {
		printf("\n%d found at index %d\n", key, result);
	}
	else {
		printf("\n%d not found\n", key);
	}
}

int binarySearch(int data[], int searchKey, int low, int high) {
	while (low <= high) {
		int middle = (low + high) / 2;

		printRow(data, low, middle, high);

		if (searchKey == data[middle]) {
			return middle;
		}
		else if (searchKey < data[middle]) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return -1;
}

int binarySearchR(int data[], int searchKey, int low, int high) {
	
	int middle = (low + high) / 2;

	printRow(data, low, middle, high);

	if (low > high) {
		return -1;
	}
	if (searchKey == data[middle]) {
		return middle;
	}
	if (searchKey < data[middle]) {
		return binarySearchR(data, searchKey, low, middle - 1);
	}
	
	return binarySearchR(data, searchKey, middle + 1, high);
}

void printHeader(void) {
	puts("\nIndices:");

	for (int i = 0; i < SIZE; ++i) {
		printf("%3u ", i);
	}
	puts("");
	for (int i = 1; i <= 4 * SIZE; ++i) {
		printf("%s", "-");
	}
	puts("");
}

void printRow(int data[], int low, int mid, int high) {
	for (int i = 0; i < SIZE; ++i) {
		if (i < low || i > high) {
			printf("%s", "    ");
		}
		else if (i == mid) {
			printf("%3d*", data[i]);
		}
		else {
			printf("%3d ", data[i]);
		}
	}

	puts("");
}
