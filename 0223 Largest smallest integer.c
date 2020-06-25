#include <stdio.h>

int main(void) {
	printf("%s", "Three ints: ");

	int n1, n2, n3, small, large;
	scanf_s("%d%d%d", &n1, &n2, &n3);

	if (n1 > n2) {
		small = n2;
		large = n1;
	}
	if (n1 < n2) {
		small = n1;
		large = n2;
	}
	if (small > n3) small = n3;
	if (large < n3) large = n3;

	printf("Largest = %d\nSmallest = %d\n", large, small);
}