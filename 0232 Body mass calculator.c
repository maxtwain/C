#include <stdio.h>

int main(void) {
	printf("%s", "Weight (lbs): ");

	double weight, height;
	const int cFactor = 703;

	scanf_s("%lf", &weight);

	printf("%s", "Height (in): ");

	scanf_s("%lf", &height);

	printf("BMI = %lf\n\n", weight * cFactor / (height * height));

	puts("BMI VALUES");
	puts("Underweight\tless than 18.5");
	puts("Normal\t\tbetween 18.5 and 24.9");
	puts("Overweight:\tbetween 25 and 29.9");
	puts("Obese\t\t30 or greater\n");
}