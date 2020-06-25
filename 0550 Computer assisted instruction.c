#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplication();

int main(void) {
	while (1) {
		multiplication();
	}
}

void multiplication() {
	srand((unsigned int)time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int answer = -1;

	while (a * b != answer) {
		printf("How much is %d times %d? ", a, b);
		scanf_s("%d", &answer);

		if (a * b != answer) puts("No.  Please try again.");
	}
	puts("Very good!");
}