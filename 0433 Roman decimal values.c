#include <stdio.h>

void printRoman(int);

// Roman Numerals: I = 1, V = 5, X = 10, L = 50, C = 100;
int main(void) {
	for (int num = 1; num <= 100; num++) {
		printRoman(num);
	}
	puts("");
}

void printRoman(int num) {
	printf("%d = ", num);
	if (num == 100) {
		printf("%s", "C");
		num -= 100;
	}
	if (num >= 90) {
		printf("%s", "XC");
		num -= 90;
	}
	if (num >= 50) {
		printf("%s", "L");
		num -= 50;
	}
	if (num >= 40) {
		printf("%s", "XL");
		num -= 40;
	}
	while (num >= 10) {
		printf("%s", "X");
		num -= 10;
	}
	if (num == 9) {
		printf("%s", "IX");
		num -= 9;
	}
	if (num >= 5) {
		printf("%s", "V");
		num -= 5;
	}
	if (num == 4) {
		printf("%s", "IV");
		num -= 4;
	}
	while (num >= 1) {
		printf("%s", "I");
		num -= 1;
	}
	puts("");
}