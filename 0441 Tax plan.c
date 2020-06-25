#include <stdio.h>

int main(void) {
	double hous, food, cloth, trans, educ, health, vacat, sum = 0.0;
	printf("%s", "Enter housing expenses: ");
	scanf_s("%lf", &hous);
	printf("%s", "Enter food expenses: ");
	scanf_s("%lf", &food);
	printf("%s", "Enter clothing expenses: ");
	scanf_s("%lf", &cloth);
	printf("%s", "Enter transportation expenses: ");
	scanf_s("%lf", &trans);
	printf("%s", "Enter education expenses: ");
	scanf_s("%lf", &educ);
	printf("%s", "Enter health expenses: ");
	scanf_s("%lf", &health);
	printf("%s", "Enter vacation expenses: ");
	scanf_s("%lf", &vacat);

	sum = hous + food + cloth + trans + educ + health + vacat;
	
	printf("\nTotal Expenses = %.2lf\nThirty percent Fair Tax = %.2lf\n", sum, sum * 0.3);
}