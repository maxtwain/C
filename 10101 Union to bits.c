#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

union sample {
	int m;
	float n;
	char ch;
} u;

char* intBits(int x, int mode);
int bitsInt(char buffer[37]);
char* floatBits(double x, int mode);
float bitsFloat(char buffer[37]);
char* spaceBuffer(char buffer[37]);

int main(void) {
	
	printf("Size of union = %d bytes\n", sizeof(u));
	printf("Size of int = %d bytes\n", sizeof(int));
	printf("Size of float = %d bytes\n", sizeof(float));
	puts("");

	printf("int test: %d\n", bitsInt(intBits(25, 1)));
	printf("bitsFloat 45.45 test : %f\n", bitsFloat(floatBits(45.45, 1)));
	printf("bitsFloat 1.869 test : %f\n", bitsFloat(floatBits(1.869, 1)));
	printf("bitsFloat 0.753 test : %f\n", bitsFloat(floatBits(0.753, 1)));
	puts("");

	u.m = 25;
	printf("%10s = %s\n", "u.m int", intBits(u.m, 0));
	printf("%10s = %s\n", "u.m float", floatBits(u.n, 0));
	puts("");

	u.n = (float)45.45;
	printf("%10s = %s\n", "u.m int", intBits(u.m, 0));
	printf("%10s = %s\n", "u.m float", floatBits(u.n, 0));
	puts("");

	u.m = 26;
	printf("%10s = %d\n", "u.m int", u.m);
	printf("%10s = %f\n", "u.m float", u.n);
	puts("");

	u.m = 84;
	printf("%10s = %d\n", "u.m int", u.m);
	printf("%10s = %f\n", "u.m float", u.n);
	puts("");

	printf("%10s = %s\n", "correct", "0011 1111 0100 0000 1100 0100 1001 1100");
	printf("%10s = %s\n", "0.753", floatBits((float)0.753, 0));
	puts("");

	printf("%10s = %s\n", "correct", "0011 1111 1110 1111 0011 1011 0110 0100");
	printf("%10s = %s\n", "1.869", floatBits((float)1.869, 0));
	puts("");

	printf("%10s = %s\n", "correct", "0100 0010 0011 0101 1100 1100 1100 1101");
	printf("%10s = %s\n", "45.45", floatBits((float)45.45, 0));
	puts("");
}

// if mode == 0, bit output will be formatted with spaces

// changes an int into bits
char* intBits(int x, int mode) {
	// 8 bits per byte at 4 bytes plus 4 spaces and a '\0' is 37 characters
	static char buffer[37];
	memset(buffer, 0, sizeof(buffer));

	unsigned int mask = 1 << 31;
	for (unsigned int i = 0; i < 32; ++i) {
		sprintf(&buffer[i], "%c", x & mask ? '1' : '0');
		x <<= 1;
	}

	if (mode == 0) {
		spaceBuffer(buffer);
	}
	return buffer;
}

// changes bits into an int
int bitsInt(char buffer[37]) {
	return (int) strtol(buffer, NULL, 2);
}

// changes float into bits
char* floatBits(double x, int mode) {
	static char buffer[37];
	memset(buffer, 0, sizeof(buffer));
	
	// 1 sign bit
	if (x < 0) {
		sprintf(buffer, "%c", '1');
		x *= -1;
	}
	else {
		sprintf(buffer, "%c", '0');
	}

	// 8 exponent bits, then 23 mantissa bits (whole bits + fractional bits)
	char mantissa[24];
	int whole = (int)floor(x);
	int exponent = 0;
	int oneStart = 0;
	if (whole > 0) {
		strcpy(mantissa, &strchr(intBits(whole, 1), '1')[1]);
		exponent = strlen(mantissa);
		oneStart = 1;
	}

	double fractional = x - floor(x);
	for (int i = exponent; i < 23; ++i) {
		if (oneStart == 0) {
			--exponent;
			--i;
		}

		fractional *= 2;
		if (fractional > 1) {
			if (oneStart == 0) {
				oneStart = 1;
			}
			else {
				mantissa[i] = '1';
			}
			fractional -= 1;
		}
		else if (oneStart == 1) {
			mantissa[i] = '0';
		}
	}

	mantissa[23] = '\0';
	strcpy(&buffer[1], &intBits(exponent + 127, 1)[24]);
	strcpy(&buffer[9], mantissa);

	// rounding
	if (fractional * 2 >= 1) {
		for (int i = 31; i >= 0; --i) {
			if (buffer[i] == '0') {
				buffer[i] = '1';
				break;
			}
			else {
				buffer[i] = '0';
			}
		}
	}

	if (mode == 0) {
		spaceBuffer(buffer);
	}
	return buffer;
}

// changes bits into a float
float bitsFloat(char buffer[37]) {
	float number = 0;

	// 1 sign bit
	int sign = 1;
	if (buffer[0] == '1') {
		sign *= -1;
	}

	// 8 exponent bits
	char expBuffer[8];
	strncpy(expBuffer, &buffer[1], 8);
	int exponent = strtol(expBuffer, NULL, 2) - 127;
	
	// 23 mantissa bits = whole bits + fractional bits
	int mult = 2;
	if (exponent > 0) {
		char wholeBuffer[24];
		wholeBuffer[0] = '1';
		strncpy(&wholeBuffer[1], &buffer[9], exponent);
		number += strtol(wholeBuffer, NULL, 2);
	}
	else {
		mult = 1;
		while (exponent < 0) {
			mult *= 2;
			++exponent;
		}
		number += (float)1 / mult;
		mult *= 2;
	}

	while (exponent < 23) {
		if (buffer[9 + exponent] == '1') {
			number += (float)1 / mult;
		}
		mult *= 2;
		++exponent;
	}

	number *= sign;
	
	return number;
}

// provides bit space formating for readability
char* spaceBuffer(char buffer[37]) {
	char tempBuffer[100];
	for (int i = 4; i < 37; i += 5) {
		strcpy(tempBuffer, &buffer[i]);
		buffer[i] = ' ';
		strcpy(&buffer[i + 1], tempBuffer);
	}
	return buffer;
}