#include <stdio.h>

double strtod0(const char* nPtr);
long strtol0(const char* nPtr);
unsigned long strtoul0(const char* nPtr);

int main(void) {
	char* doubleString = "76.498";
	char* intString = "-873910";
	char* unsignedString = "4382";

	printf("%s converted = %lf\n", doubleString, strtod0(doubleString));
	printf("%s converted = %ld\n", intString, strtol0(intString));
	printf("%s converted = %lu\n", unsignedString, strtoul0(unsignedString));

	puts("\n");
}

double strtod0(const char* nPtr) {
	double value = 0.0;
	int decimal = 0;
	int neg = 1;
	for (int i0 = 0; nPtr[i0] != '\0'; ++i0) {
		if (nPtr[i0] == 46) {
			++decimal;
			++i0;
		}
		else if (nPtr[i0] == 45) {
			neg = -1;
			++i0;
		}

		if (decimal == 0) {
			value *= 10;
			value += nPtr[i0] - 48;
		}
		else {
			decimal *= 10;
			value += ((double)nPtr[i0] - 48) / (decimal);
		}
	}
	value *= neg;
	return value;
}

long strtol0(const char* nPtr) {
	long int value = 0;
	int neg = 1;
	for (int i0 = 0; nPtr[i0] != '\0'; ++i0) {
		if (nPtr[i0] == 45) {
			neg = -1;
			++i0;
		}
		value *= 10;
		value += nPtr[i0] - 48;
	}
	value *= neg;
	return value;
}

unsigned long strtoul0(const char* nPtr) {
	unsigned long int value = 0;
	for (int i0 = 0; nPtr[i0] != '\0'; ++i0) {
		value *= 10;
		value += nPtr[i0] - 48;
	}
	return value;
}