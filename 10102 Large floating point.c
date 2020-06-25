#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 15
#define SEQUENCE_MAX 2'000'000

char* calcFrac(int numer, const int denom);
void addToSum(char sum[SIZE], char frac[SIZE]);
void subFromSum(char sum[SIZE], char frac[SIZE]);
void prepare(char sum[SIZE], char frac[SIZE]);
char* leibnizPi();

int main() {
	
	/*
	// for testing functions
	char sum[SIZE] = "0.0";
	sum[SIZE - 1] = '\0';
	*/

	printf("%s\n", leibnizPi());
}

char* calcFrac(int numer, const int denom) {
	static char frac[SIZE];
	memset(frac, 0, SIZE);
	
	sprintf(frac, "%d", numer / denom);
	strcat(frac, ".");

	for (int i = strlen(frac); i < SIZE - 1; ++i) {
		numer = numer % denom * 10;
		sprintf(&frac[i], "%d", numer / denom);
	}
	if (numer % denom * 10 / denom > 4) {
		++frac[SIZE - 2];
	}
	frac[SIZE - 1] = '\0';

	return frac;
}

// Add two positive numbers
void addToSum(char sum[SIZE], char frac[SIZE]) {

	prepare(sum, frac);

	// add strings
	char addValue[3];
	int carry = 0;
	for (int i = SIZE - 2; i >= 0; --i) {
		if (sum[i] == '.') {
			--i;
		}
		memset(addValue, 0, 3);
		sprintf(addValue, "%d", sum[i] - '0' + frac[i] - '0' + carry);
		if (strtol(addValue, NULL, 0) > 9) {
			carry = 1;
			sum[i] = addValue[1];
		}
		else {
			carry = 0;
			sum[i] = addValue[0];
		}
	}

	// final carry
	while (carry == 1) {
		memmove(&sum[1], sum, SIZE - 2);
		++sum[0];
		carry = 0;
		if (sum[0] - '0' > 9) {
			carry = 1;
			sum[0] -= 10;
		}
	}
}

// subract positive number (frac) from larger positive number (sum)
void subFromSum(char sum[SIZE], char frac[SIZE]) {

	prepare(sum, frac);

	int next = 1;
	for (int i = SIZE - 2; i >= 0; --i) {
		if (sum[i] == '.') {
			--i;
		}
		if (sum[i - 1] == '.') {
			next = 2;
		}
		else {
			next = 1;
		}

		// carry
		if (sum[i] < frac[i]) {
			--sum[i - next];
			sum[i] += 10;
		}

		sum[i] -= (frac[i] - '0');
	}
	
	// remove front padding
	if (sum[1] == '0') {
		int zero = 0;
		for (int i = 1; sum[i] == '0'; ++i) {
			++zero;
		}
		zero;
		memmove(sum, &sum[zero], SIZE - zero);
	}
}

// line up decimal and pad strings
void prepare(char sum[SIZE], char frac[SIZE]) {
	
	// decimal position
	int sumDec = strcspn(sum, ".");
	int fracDec = strcspn(frac, ".");
	int diff;

	// truncate and pad front
	if (sumDec > fracDec) {
		diff = sumDec - fracDec;
		memmove(&frac[diff], frac, SIZE - 1 - diff);
		memset(frac, '0', diff);
		frac[SIZE - 1] = '\0';
	}
	else if (sumDec < fracDec) {
		diff = fracDec - sumDec;
		memmove(&sum[diff], sum, SIZE - 1 - diff);
		memset(sum, '0', diff);
		sum[SIZE - 1] = '\0';
	}

	// pad back
	int empty;
	if (strlen(sum) < SIZE) {
		empty = SIZE - strlen(sum) - 1;
		memset(&sum[strlen(sum)], '0', empty);
		frac[SIZE - 1] = '\0';
	}
	if (strlen(frac) < SIZE) {
		empty = SIZE - strlen(frac) - 1;
		memset(&sum[strlen(sum)], '0', empty);
		sum[SIZE - 1] = '\0';
	}
}

char* leibnizPi() {
	static char sum[SIZE];
	memset(sum, 0, SIZE);
	strcpy(sum, "0.0");
	sum[3] = '\0';

	int denom = 1;
	int max = SEQUENCE_MAX;
	while (denom < max) {
		addToSum(sum, calcFrac(4, denom));
		denom += 2;
		subFromSum(sum, calcFrac(4, denom));
		denom += 2;
	}

	return sum;
}