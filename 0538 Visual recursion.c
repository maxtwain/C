#include <stdio.h>

unsigned long long int factorial(unsigned long long int number);

int main(void) {
	for (unsigned int i = 0; i <= 21; ++i) {
		printf("%u! = %llu\n", i, factorial(i));
	}
}

unsigned long long int factorial(unsigned long long int number) {
	if (number <= 1) {
		printf("local variable = %llu\n", number);
		return 1;
	}
	else{
		unsigned long long factPortion = factorial(number - 1);
		printf("local variable = %llu\tfactorial(number - 1) = %llu\n", number, factPortion);
		return number * factPortion;
	}
}