#include <stdio.h>

int main(void) {
	printf("%s", "Enter three integers: ");

	int n1, n2, n3 = 0;
	scanf_s("%d%d%d", &n1, &n2, &n3);

	printf("The product is %d\n", n1 * n2 * n3);
}