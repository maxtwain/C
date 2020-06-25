#include <stdio.h>

int main(void) {
	unsigned int counter = 0;
	unsigned int number = 0;
	unsigned int largest = 0;

	while (counter < 10) {
		printf_s("%s", "Enter a number: ");
		scanf_s("%u", &number);

		if (largest < number) {
			largest = number;
		}
		counter++;
	}
	printf_s("Largest entry = %u\n\n", largest);
}