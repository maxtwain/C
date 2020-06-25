#include <stdio.h>

#define PI 3.14159265359

void circleCircum(double radius);
void circleArea(double radius);
void sphereVol(double radius);

int main(void) {
	
	printf("%s", "Enter 1 for circle circumference.\nEnter 2 for circle Area.\nEnter 3 for sphere volume.\n");
	int menuChoice = 0;
	scanf_s("%d", &menuChoice);
	
	printf("%s", "Radius: ");
	double radius = 0.0;
	scanf_s("%lf", &radius);

	void(*fArray[3])(double) = { circleCircum, circleArea, sphereVol };
	(*fArray[menuChoice])(radius);

}

void circleCircum(double radius) {
	printf("Result: %lf\n", PI * 2 * radius);
}

void circleArea(double radius) {
	printf("Result: %lf\n", PI * radius * radius);
}

void sphereVol(double radius) {
	printf("Result: %lf\n", 4.0 / 3.0 * PI * radius * radius * radius);
}