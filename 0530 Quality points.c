#include <stdio.h>

int toQualityPoints(double average);

int main(void) {
	printf("toQualityPoints(95) = %d\n", toQualityPoints(95));
	printf("toQualityPoints(85) = %d\n", toQualityPoints(85));
	printf("toQualityPoints(75) = %d\n", toQualityPoints(75));
	printf("toQualityPoints(55) = %d\n", toQualityPoints(55));
}

int toQualityPoints(double average) {
	if (average <= 100 && average >= 90) return 4;
	else if (average < 90 && average >= 80) return 3;
	else if (average < 80 && average >= 70) return 2;
	else if (average < 70 && average >= 60) return 1;
	return 0;
}