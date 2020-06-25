#include <stdio.h>
#include <limits.h>

unsigned long long fibonacci(unsigned int nth);
unsigned long long fibonacciMax(unsigned long long num);
unsigned long long fibonacciCount(unsigned long long num);

int main(void) {
	
	printf("fibonacci(3) = %llu\n", fibonacci(3));
	printf("fibonacci(4) = %llu\n", fibonacci(4));
	printf("fibonacci(5) = %llu\n", fibonacci(5));
	printf("fibonacci(8) = %llu\n", fibonacci(8));
	printf("fibonacci(50) = \t\t%llu\n", fibonacci(50));
	printf("fibonacci(100) = \t\t%llu\n", fibonacci(100));
	printf("fibonacci(200) = \t\t%llu\n", fibonacci(200));
	
	printf("ULLONG_MAX = \t\t\t%llu\n", ULLONG_MAX);
	printf("fibonacciMax(ULLONG_MAX) = \t%llu\n", fibonacciMax(ULLONG_MAX));
	printf("fibonacciCount(fibonacciMax(ULLONG_MAX)) = \t%llu\n", fibonacciCount(fibonacciMax(ULLONG_MAX)));

}

// returns nth fib number
unsigned long long fibonacci(unsigned int nth) {
	unsigned long long fib1 = 0, fib2 = 1;
	if (nth <= 1) return 0;
	else if (nth == 2) return 1;
	for (nth -= 2; nth > 0; --nth) {
		fib2 += fib1;
		fib1 = fib2 - fib1;
	}
	return fib2;
}

// returns largest fib number <= given number
unsigned long long fibonacciMax(unsigned long long num) {
	unsigned long long fib1 = 0, fib2 = 1;
	while(fib2 / 1'000'000'000'000 + fib1 / 1'000'000'000'000 <= num / 1'000'000'000'000) {
		fib2 += fib1;
		fib1 = fib2 - fib1;
	}
	return fib2;
}

// returns nth position of given fib number
unsigned long long fibonacciCount(unsigned long long num) {
	unsigned long long fib1 = 0, fib2 = 1, fibCount = 2;
	while (fib2 / 1'000'000'000'000 + fib1 / 1'000'000'000'000 <= num / 1'000'000'000'000) {
		fib2 += fib1;
		fib1 = fib2 - fib1;
		++fibCount;
	}
	return fibCount;
}