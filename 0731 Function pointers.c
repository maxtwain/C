#include <stdio.h>

void add(double num1, double num2);
void subtract(double num1, double num2);
void multiplication(double num1, double num2);
void division(double num1, double num2);

int main(void) {

	puts("Enter 1 to add.\nEnter 2 to subtract.\nEnter 3 to multiply.\nEnter 4 to divide.");
	int menuChoice = 0;
	scanf_s("%d", &menuChoice);

	printf("%s", "Number 1: ");
	double num1 = 0.0;
	scanf_s("%lf", &num1);
	printf("%s", "Number 2: ");
	double num2 = 0.0;
	scanf_s("%lf", &num2);

	void(*fArray[4])(double, double) = { add, subtract, multiplication, division };
	(*fArray[menuChoice - 1])(num1, num2);

}

void add(double num1, double num2) {
	printf("Addition result: %lf\n", num1 + num2);
}

void subtract(double num1, double num2) {
	printf("Subtraction result: %lf\n", num1 - num2);
}

void multiplication(double num1, double num2) {
	printf("Multiplication result: %lf\n", num1 * num2);
}

void division(double num1, double num2) {
	printf("Division result: %lf\n", num1 / num2);
}