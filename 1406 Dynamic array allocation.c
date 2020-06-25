#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char buffer[500];
	printf("%s", "Enter an array size followed by int elements: ");
	fgets(buffer, 500, stdin);
	
	char* token = strtok(buffer, " ");
	int size = strtol(token, NULL, 0);
	int* arr = malloc(sizeof(int) * size);

	for (int i = 0; token = strtok(NULL, " "); ++i) {
		arr[i] = strtol(token, NULL, 0);
	}

	puts("malloc values");
	for (int i = 0; i < size; ++i) {
		printf("%4d", arr[i]);
	}
	puts("\n");

	size = size / 2;
	arr = realloc(arr, sizeof(int) * size);

	puts("realloc values");
	for (int i = 0; i < size; ++i) {
		printf("%4d", arr[i]);
	}
	puts("\n");

}