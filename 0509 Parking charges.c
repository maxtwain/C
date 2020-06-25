#include <stdio.h>

double calculateCharges(double hours);

int main(void) {
	double sumHours = 0.0, sumCharge = 0.0;
	double time1, time2, time3;

	printf("%s", "Enter hours parked for customer 1: ");
	scanf_s("%lf", &time1);

	printf("%s", "Enter hours parked for customer 2: ");
	scanf_s("%lf", &time2);
	
	printf("%s", "Enter hours parked for customer 3: ");
	scanf_s("%lf", &time3);

	printf("\n%s\t%s\t%s\n", "Car", "Hours", "Charge");
	printf("%u\t%.1lf\t%.2lf\n", 1, time1, calculateCharges(time1));
	printf("%u\t%.1lf\t%.2lf\n", 2, time2, calculateCharges(time2));
	printf("%u\t%.1lf\t%.2lf\n", 3, time3, calculateCharges(time3));
	printf("%s\t%.1lf\t%.2lf\n\n", "TOTAL", time1 + time2 + time3, calculateCharges(time1) + calculateCharges(time2) + calculateCharges(time3));
	
}

double calculateCharges(double hours) {
	double charge = 2.0;
	if (hours > 3.0) charge += 0.5 * (hours - 3.0);
	if (charge > 10.0) charge = 10.0;
	return charge;
}