#include <stdio.h>

int main(void) {
	double gallons, miles, gSum, mSum;
	
	gallons = miles = gSum = mSum = 0.0;

	printf_s("%s", "Enter the gallons used (-1 to end): ");
	scanf_s("%lf", &gallons);
	while (gallons != -1) {
		gSum += gallons;
		printf_s("%s", "Enter the miles driven: ");
		scanf_s("%lf", &miles);
		mSum += miles;
		printf_s("The miles/gallon for this tank was %lf\n\n", miles / gallons);
		printf_s("%s", "Enter the gallons used (-1 to end): ");
		scanf_s("%lf", &gallons);
	}

	printf_s("\nThe overall average miles/gallon was %lf\n", mSum / gSum);
}