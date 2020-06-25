#include <stdio.h>

int main(void) {
	printf("%s", "Two integers: ");

	int n1, n2;
	scanf("%d%d", &n1, &n2);

	if (n1 == n2) printf("%s", "These numbers are equal.\n");
	if (n1 > n2) printf("%d is larger.\n", n1);
	if (n2 > n1) printf("%d is larger.\n", n2);
}