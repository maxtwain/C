#include <stdio.h>

int toCelcius(int fahrenheit);
int toFahrenheit(int celcius);

int main(void) {

	printf("%s\t\t%s\n", "Celcius", "Fahrenheit");
	for (int celcius = 0; celcius <= 100; ++celcius) {
		printf("%d\t\t%d\n", celcius, toFahrenheit(celcius));
	}
	puts("");
	printf("%s\t%s\n", "Fahrenheit", "Celcius");
	for (int fahrenheit = 32; fahrenheit <= 212; ++fahrenheit) {
		printf("%d\t\t%d\n", fahrenheit, toCelcius(fahrenheit));
	}
	puts("");
}

int toCelcius(int fahrenheit) {
	return (fahrenheit - 32) * 5 / 9;
}

int toFahrenheit(int celcius) {
	return celcius * 9 / 5 + 32;
}