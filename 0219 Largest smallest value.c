#include <stdio.h>

int main(void) {
	printf("%s", "Enter three different integers: ");

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

	printf("Sum is %d\nAverage is %d\nProduct is %d\nSmallest is %d\nLargest is %d\n", n1 + n2 + n3, (n1 + n2 + n3) / 3, n1 * n2 * n3, small, large);
}