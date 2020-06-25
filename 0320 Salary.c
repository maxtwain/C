#include <stdio.h>

int main(void) {
	double hWorked = 0;
	double hRate = 0;

	for (;;) {
		printf("%s", "Enter # of hours worked (-1 to end): ");
		scanf_s("%lf", &hWorked);

		if (hWorked == -1) {
			break;
		}

		printf("%s", "Enter hourly rate of the worker ($00.00): ");
		scanf_s("%lf", &hRate);

		if (hWorked > 40) {
			hWorked = 40 + (hWorked - 40) * 1.5;
		}
		
		printf("Salary is $%.2lf\n\n", hWorked * hRate);
	}
}