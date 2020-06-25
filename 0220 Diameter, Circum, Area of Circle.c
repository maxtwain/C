#include <stdio.h>

int main(void) {
	printf("%s", "Radius: ");

	float radius;
	scanf_s("%f", &radius);

	const float PI = 3.14159;
	printf("Diameter = %f\nCircumference = %f\nArea = %f\n", 2 * radius, 2 * radius * PI, radius * radius * PI);
}