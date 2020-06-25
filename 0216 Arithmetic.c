#include <stdio.h>

int main(void) {
	printf("%s", "Two numbers: ");

	int n1, n2 = 0;
	scanf_s("%d%d", &n1, &n2);
	printf("sum = %d\nproduct = %d\ndifference = %d\nquotient = %d\nremainder = %d\n", n1 + n2, n1 * n2, n1 - n2, n1 / n2, n1 % n2);
}