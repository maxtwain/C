#include <stdio.h>

int main(void) {
	double milesDay, costGallon, milesGallon, parking, tolls;

	printf("%s", "Total miles driven per day: ");

	scanf_s("%lf", &milesDay);

	printf("%s", "Cost per gallon of gasoline: ");

	scanf_s("%lf", &costGallon);

	printf("%s", "Average miles per gallon: ");

	scanf_s("%lf", &milesGallon);

	printf("%s", "Parking fees per day: ");

	scanf_s("%lf", &parking);

	printf("%s", "Tolls per day: ");

	scanf_s("%lf", &tolls);

	printf("Daily driving cost = %lf\n", milesDay * costGallon / milesGallon + parking + tolls);
}