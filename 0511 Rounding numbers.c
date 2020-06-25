#include <stdio.h>
#include <math.h>

int roundToInteger(double x);
double roundToTenths(double x);
double roundToHundredths(double x);
double roundToThousandths(double x);

int main(void) {
	double number = 0;
	while (number != 999) {
		printf("%s", "Enter a value to round (999 to exit): ");
		scanf_s("%lf", &number);
		printf("%s\t%s\t%s\t\t%s\t%s\n", "Original", "Int", "Tenths", "Hundredths", "Thousandths");
		printf("%lf\t%d\t%lf\t%lf\t%lf\n\n", number, roundToInteger(number), roundToTenths(number), roundToHundredths(number), roundToThousandths(number));
	}
}

int roundToInteger(double x) {
	return floor(x + 0.5);
}

double roundToTenths(double x) {
	return floor(x * 10 + 0.5) / 10;
}

double roundToHundredths(double x) {
	return floor(x * 100 + 0.5) / 100;
}

double roundToThousandths(double x) {
	return floor(x * 1'000 + 0.5) / 1'000;
}