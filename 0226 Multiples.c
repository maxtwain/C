#include <stdio.h>

int main(void) {
	printf("%s", "Two integers: ");

	int n1, n2;
	scanf_s("%d%d", &n1, &n2);

	if (n1 % n2 == 0) printf("%d is a multiple of %d\n", n1, n2);
	if (n1 % n2 != 0) printf("%d is not a multiple of %d\n", n1, n2);
}