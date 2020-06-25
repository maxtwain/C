#include <stdio.h>
#include <math.h>

int main(void) {
	printf("%s", "Enter series of numbers to floor (999 to exit).\n");
	for (double x = 0; x != 999; ) {
		printf("%s", "x: ");
		scanf_s("%lf", &x);
		printf("floor(%lf + .5) = %.2lf\n\n", x, floor(x + .5));
	}
}