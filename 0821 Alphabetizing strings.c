#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(char** townPtr, int leftIndex, int rightIndex);
void merge(char** townPtr, int leftIndex, int middleIndex, int rightIndex);

int main(void) {
	char* town[15] = { "Leurbost", "Dumbarton", "Gloucester", "Pernrith", "Aelinmiley", "Dalelry", "Dungannon", "Palperroth", "Berkton", "Hepojoki", "Eelry", "Tow", "Woodhurst", "Lakeshore", "Venzor" };

	// array, left index, right index
	mergeSort(town, 0, 14);

	for (int i = 0; i < 15; ++i) {
		printf("%s\n", town[i]);
	}
	puts("\n");
}

void mergeSort(char** townPtr, int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

		mergeSort(townPtr, leftIndex, middleIndex);
		mergeSort(townPtr, middleIndex + 1, rightIndex);

		merge(townPtr, leftIndex, middleIndex, rightIndex);
	}
}

void merge(char** townPtr, int leftIndex, int middleIndex, int rightIndex) {

	int leftSize = middleIndex - leftIndex + 1;
	int rightSize = rightIndex - middleIndex;

	// temp string arrays
	char** leftArr = malloc(leftSize * sizeof(char*));
	char** rightArr = malloc(rightSize * sizeof(char*));

	// left Array text memory
	int leftTempIndex = 0;
	for (int index = leftIndex; index < middleIndex + 1; ++index) {
		int textIndex = 0;
		int wordSize = 0;
		while (townPtr[index][textIndex] != '\0') {
			++wordSize;
			++textIndex;
		}
		leftArr[leftTempIndex] = malloc((wordSize + 1) * sizeof(char));
		++leftTempIndex;
	}

	// right Array text memory
	int rightTempIndex = 0;
	for (int index = middleIndex + 1; index <= rightIndex; ++index) {
		int textIndex = 0;
		int wordSize = 0;
		while (townPtr[index][textIndex] != '\0') {
			++wordSize;
			++textIndex;
		}
		rightArr[rightTempIndex] = malloc((wordSize + 1) * sizeof(char));
		++rightTempIndex;
	}

	// left text copy
	leftTempIndex = 0;
	for (int townIndex = leftIndex; townIndex < middleIndex + 1; ++townIndex) {
		int textIndex = 0;
		while (townPtr[townIndex][textIndex] != '\0') {
			leftArr[leftTempIndex][textIndex] = townPtr[townIndex][textIndex];
			++textIndex;
		}
		leftArr[leftTempIndex][textIndex] = '\0';
		++leftTempIndex;
	}

	// right text copy
	rightTempIndex = 0;
	for (int townIndex = middleIndex + 1; townIndex <= rightIndex; ++townIndex) {
		int textIndex = 0;
		while (townPtr[townIndex][textIndex] != '\0') {
			rightArr[rightTempIndex][textIndex] = townPtr[townIndex][textIndex];
			++textIndex;
		}
		rightArr[rightTempIndex][textIndex] = '\0';
		++rightTempIndex;
	}
	
	// sort and replace into townPtr
	leftTempIndex = 0;
	rightTempIndex = 0;
	int townIndex = leftIndex;
	while (leftTempIndex < leftSize && rightTempIndex < rightSize) {
		if (strcmp(leftArr[leftTempIndex], rightArr[rightTempIndex]) == 0) {
			townPtr[townIndex] = leftArr[leftTempIndex];
			++leftTempIndex;
			++townIndex;
			townPtr[townIndex] = rightArr[rightTempIndex];
			++rightTempIndex;
			++townIndex;
		}
		else if (strcmp(leftArr[leftTempIndex], rightArr[rightTempIndex]) > 0) {
			townPtr[townIndex] = rightArr[rightTempIndex];
			++rightTempIndex;
			++townIndex;
		}
		else {
			townPtr[townIndex] = leftArr[leftTempIndex];
			++leftTempIndex;
			++townIndex;
		}
	}
	while (leftTempIndex < leftSize) {
		townPtr[townIndex] = leftArr[leftTempIndex];
		++leftTempIndex;
		++townIndex;
	}
	while (rightTempIndex < rightSize) {
		townPtr[townIndex] = rightArr[rightTempIndex];
		++rightTempIndex;
		++townIndex;
	}

	// I couldn't get free memory to work, but dynamic memory is a subject ahead of where I am.
	leftTempIndex = 0;
	while (leftTempIndex < leftSize) {
		free(leftArr[leftTempIndex]);
		++leftTempIndex;
	}
	free(leftArr);
}