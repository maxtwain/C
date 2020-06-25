#include <stdio.h>

int isEven(int num);

int main(void) {
	printf("%s", "Enter series of integers to check for evenness (999 to quit).\n");
	for (int num = 0; num != 999; ) {
		printf("%s", "Entry: ");
		scanf_s("%d", &num);
		if (isEven(num) == 1) printf("%d is even.\n\n", num);
		else printf("%d is odd.\n\n", num);
	}
}

int isEven(int num) {
	if (num % 2 == 0) return 1;
	return 0;
}