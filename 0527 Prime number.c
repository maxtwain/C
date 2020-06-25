#include <stdio.h>

int isPrime(unsigned long long primeCheck);

int main(void) {
	
	printf("%s\n", "List of Primes");
	printf("%d\t%d\t", 2, 3);
	for (unsigned long long num = 5; num < 10'000; num += 2) {
		if (isPrime(num)) printf("%llu\t", num);
	}
	puts("");
}

int isPrime(unsigned long long primeCheck) {
	if (primeCheck % 3 == 0) return 0;

	// factors = {(5, 7), (11, 13), (17, 19), (23, 25), (29, 31), (35, 37), (41, 43), ... }
	for (int factor = 5; factor * factor <= primeCheck; factor += 6) {
		if (primeCheck % factor == 0 || primeCheck % (factor + 2) == 0) {
			return 0;
		}
	}
	return 1;
}