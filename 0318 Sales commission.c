#include <stdio.h>

int main(void) {
	double sales = 0;
	
	printf("%s", "Enter sales in dollars (-1 to end): ");
	scanf_s("%lf", &sales);
	while (sales != -1) {
		printf("Salary is: %.2lf\n\n", 200 + sales * 0.09);

		printf("%s", "Enter sales in dollars (-1 to end): ");
		scanf_s("%lf", &sales);
	}
}