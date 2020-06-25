#include <stdio.h>

int main(void) {
	int size = 0;
	printf("Enter diamond size: ");
	scanf_s("%d", &size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i + j >= size / 2 && i + j <= size * 3 / 2 - 1 && i - j >= -1 * size / 2 && j - i >= -1 * (size - 1) / 2 ) printf("%s", "*");
			else printf("%s", " ");
		}
		puts("");
	}
	puts("\n");
}