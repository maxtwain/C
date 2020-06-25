#include <stdio.h>

int main(void) {
	printf("%s", "Five digits: ");

	int fiveDigit;
	scanf_s("%d", &fiveDigit);

	printf("%d   %d   %d   %d   %d\n",
		fiveDigit % 100'000 / 10'000,
		fiveDigit % 10'000 / 1'000,
		fiveDigit % 1'000 / 100,
		fiveDigit % 100 / 10,
		fiveDigit % 10 / 1);
}