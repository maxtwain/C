#include <stdio.h>
#include <math.h>

int divideToInt(int a, int b);
int mod(int a, int b);

int main(void) {
	int num = 0;
	printf("Enter number to separate (max = 32767): ");
	scanf_s("%d", &num);
	int digits = floor(log10(abs(num))) + 1;
	while (digits > 0) {
		printf("%d   ", divideToInt(mod(num, pow(10, digits)), pow(10, digits - 1)));
		--digits;
	}
	puts("");
}

int divideToInt(int a, int b) {
	return a / b;
}

int mod(int a, int b) {
	return a % b;
}

