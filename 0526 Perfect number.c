#include <stdio.h>

void isPerfect(int num);

int main(void) {
	printf("%s\t%s\n", "Perfect", "Factors");
	for (int num = 1; num <= 1'000; ++num) {
		isPerfect(num);
	}
	puts("");
}

void isPerfect(int num) {
	int sum = 0;
	for (int factor = 1; factor < num; factor++) {
		if (num % factor == 0) sum += factor;
	}
	if (sum == num) {
		printf("%d\t", num);
		for (int factor = 1; factor < num; factor++) {
			if (num % factor == 0) printf("%d ", factor);
		}
		puts("");
	}
}