#include <stdio.h>
#include <math.h>

int reverse(int num);

int main(void) {
	printf("Reverse %d = %d\n", 12345, reverse(12345));
	printf("Reverse %d = %d\n", 123456, reverse(123456));

}

int reverse(int num) {
	int digits = (int)floor(log10(abs(num))) + 1;
	int dCount = 0, newNum = 0;
	// middle digit if odd
	if (digits % 2 == 1) {
		newNum += num % (int)pow(10, (digits + 1) / 2) / (int)pow(10, (digits + 1) / 2 - 1) * (int)pow(10, (digits + 1) / 2 - 1);
	}
	// largest becomes least, then least becomes largest
	while (dCount * 2 < digits - 1) {
		newNum += num % (int)pow(10, digits - dCount) / (int)pow(10, digits - 1 - dCount) * (int)pow(10, dCount);
		newNum += num % (int)pow(10, dCount + 1) / (int)pow(10, dCount) * (int)pow(10, digits - dCount - 1);
		++dCount;
	}
	return newNum;
}