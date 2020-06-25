#include <stdio.h>

int main(void) {
	double hWorked, hRate;

	for (;;) {
		printf("%s", "Enter # of hours worked (-1 to end): ");
		scanf_s("%lf", &hWorked);

		if (hWorked == -1) {
			break;
		}

		printf("%s", "Enter hourly rate of the worker ($00.00): ");
		scanf_s("%lf", &hRate);

		printf("Salary is $%.2lf\n\n", hWorked * hRate);
	}
}