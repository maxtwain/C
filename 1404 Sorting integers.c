#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, int size);
void mergeSort(int* arr, int lInd, int rInd);
void merge(int* arr, int lInd, int mInd, int rInd);

int main(int argc, char* argv[]) {
//int main(void){
//	int argc = 8;
//	char* argv[] = { "arg[0] is filename", "77", "14", "14", "15", "79", "37", "18" };

	int* arr = malloc(sizeof(int) * argc - 1);
	for (int i = 0; i < argc - 1; ++i) {
		arr[i] = strtol(argv[i + 1], NULL, 0);
	}

	printArr(arr, argc - 1);

	mergeSort(arr, 0, argc - 2);

	printArr(arr, argc - 1);
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%4d", arr[i]);
	}
	puts("\n");
}

void mergeSort(int* arr, int lInd, int rInd) {

	if (lInd < rInd) {
		int mInd = lInd + (rInd - lInd) / 2;

		mergeSort(arr, lInd, mInd);
		mergeSort(arr, mInd + 1, rInd);

		merge(arr, lInd, mInd, rInd);
	}
}

void merge(int* arr, int lInd, int mInd, int rInd) {
	int arrSize0 = mInd - lInd + 1;
	int arrSize1 = rInd - mInd;
	
	int* arr0 = malloc(sizeof(int) * arrSize0);
	int* arr1 = malloc(sizeof(int) * arrSize1);

	for (int i = 0; i < arrSize0; ++i) {
		arr0[i] = arr[lInd + i];
	}
	for (int i = 0; i < arrSize1; ++i) {
		arr1[i] = arr[mInd + 1 + i];
	}

	int i0 = 0;
	int i1 = 0;
	for (; i0 < arrSize0 && i1 < arrSize1; ++lInd) {
		if (arr0[i0] <= arr1[i1]) {
			arr[lInd] = arr0[i0];
			++i0;
		}
		else {
			arr[lInd] = arr1[i1];
			++i1;
		}
	}

	while (i0 < arrSize0) {
		arr[lInd] = arr0[i0];
		++lInd;
		++i0;
	}
	while (i1 < arrSize1) {
		arr[lInd] = arr1[i1];
		++lInd;
		++i1;
	}
}