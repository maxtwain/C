#include <stdio.h>

int main(void) {
	int accNum = 0;
	double balance, charge, credit, limit;
	
	printf_s("%s", "Enter account number (-1 to end): ");
	scanf_s("%d", &accNum);
	while (accNum != -1) {
		printf_s("%s", "Enter beginning balance: ");
		scanf_s("%lf", &balance);
		printf_s("%s", "Enter total charges: ");
		scanf_s("%lf", &charge);
		printf_s("%s", "Enter total credits: ");
		scanf_s("%lf", &credit);
		printf_s("%s", "Enter credit limit: ");
		scanf_s("%lf", &limit);

		balance += charge - credit;
		if (balance > limit) {
			printf(
				"Account:\t%d\n"
				"Credit limit:\t%.2lf\n"
				"Balance:\t%.2lf\n"
				"Credit Limit Exceeded.\n",
				accNum, limit, balance);
		}

		printf_s("%s", "\nEnter account number (-1 to end): ");
		scanf_s("%d", &accNum);
	}

}