#include <stdio.h>

int main(void) {
	printf("%s", "Integer: ");

	int n1;
	scanf_s("%d", &n1);

	if (n1 % 2 == 0) printf("%d is even.\n", n1);
	if (n1 % 2 == 1) printf("%d is odd.\n", n1);
}