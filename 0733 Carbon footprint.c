#include <stdio.h>

void building();
void car();
void bicycle();

int main(void) {

	puts("Enter 1 for building.\nEnter 2 for car.\nEnter 3 for bicycle.");
	int menuChoice = 0;
	scanf_s("%d", &menuChoice);

	void(*fArray[3])() = { building, car, bicycle };
	(*fArray[menuChoice-1])();

}

void building() {
	puts("builings contribute to 39% of all CO2 emissions per year.");
}

void car() {
	puts("4.7 metric tons of CO2 per year.");
}

void bicycle() {
	puts("0 metric tons of CO2 per year");
}