#include <stdio.h>

int main(void) {
	unsigned int counter = 0;
	unsigned int number = 0;
	unsigned int largest1 = 0;
	unsigned int largest2 = 0;

	while (counter < 10) {
		printf_s("%s", "Enter a number: ");
		scanf_s("%u", &number);

		if (largest1 <= number) {
			largest2 = largest1;
			largest1 = number;
		}
		counter++;
	}
	printf_s("Largest entry = %u\n", largest1);
	printf_s("Next largest entry = %u\n\n", largest2);
}