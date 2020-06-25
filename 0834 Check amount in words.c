#include <stdio.h>
#include <string.h>
#include <math.h>

void printPayment(double pay);
int hyphen(char* buffer, int pay);
int one(char* buffer, int pay);
int teen(char* buffer, int pay);
int ten(char* buffer, int pay);

int main(void) {

	printPayment(98765.32);
	printPayment(1000.00);
	printPayment(2000.00);
	printPayment(10000.00);
	printPayment(11000.00);
	printPayment(20000.00);
	printPayment(21000.00);
	printPayment(30000.00);
	printPayment(85000.00);
	printPayment(99999.99);
	printPayment(21.25);
	printPayment(32.58);
	printPayment(100.00);
	printPayment(12012.12);
	printPayment(10000.12);
	printPayment(10000.20);
	printPayment(10000.21);
	printPayment(10000.01);
	printPayment(500.00);
	printPayment(1.00);
	printPayment(2.00);
	printPayment(1.12);
	printPayment(2.13);


	puts("\n");
}

void printPayment(double pay) {
	double rem = 0.0;
	int payCent = (int)round(fabs(modf(pay, &rem)) * 100);
	int payInt = (int)rem;

	char buffer[100];
	char* bufPtr = buffer;

	if (payInt / 1'000 >= 20) {
		bufPtr += ten(bufPtr, payInt / 10'000);
		bufPtr += hyphen(bufPtr, payInt / 1'000);
		payInt %= 10'000;
	}
	else if (payInt / 1'000 >= 10) {
		bufPtr += teen(bufPtr, payInt / 1'000);
		sprintf(bufPtr, "%s", " thousand");
		bufPtr += strlen(" thousand");
		payInt %= 1'000;
		if (payInt > 0) {
			sprintf(bufPtr, "%s", " ");
			bufPtr += strlen(" ");
		}
	}
	if (payInt >= 1'000) {
		bufPtr += one(bufPtr, payInt / 1'000);
		sprintf(bufPtr, "%s", " thousand");
		bufPtr += strlen(" thousand");
		payInt %= 1'000;
		if (payInt > 0) {
			sprintf(bufPtr, "%s", " ");
			bufPtr += strlen(" ");
		}
	}
	if (payInt >= 100) {
		bufPtr += one(bufPtr, payInt / 100);
		sprintf(bufPtr, "%s", " hundred");
		bufPtr += strlen(" hundred");
		payInt %= 100;
		if (payInt > 0) {
			sprintf(bufPtr, "%s", " ");
			bufPtr += strlen(" ");
		}
	}
	if (payInt >= 20) {
		bufPtr += ten(bufPtr, payInt / 10);
		bufPtr += hyphen(bufPtr, payInt);
		payInt %= 10;
	}
	else if (payInt >= 10) {
		bufPtr += teen(bufPtr, payInt);
		payInt = 0;
	}
	if (payInt > 0) {
		bufPtr += one(bufPtr, payInt);
	}
	if (pay >= 2.0) {
		sprintf(bufPtr, "%s", " dollars");
		bufPtr += strlen(" dollars");
	}
	else if (pay >= 1.0) {
		sprintf(bufPtr, "%s", " dollar");
		bufPtr += strlen(" dollar");
	}
	if (payCent > 0) {
		sprintf(bufPtr, "%s", " and ");
		bufPtr += strlen(" and ");
	}
	if (payCent >= 20) {
		bufPtr += ten(bufPtr, payCent / 10);
		bufPtr += hyphen(bufPtr, payCent);
		payCent %= 10;
	}
	else if (payCent >= 10) {
		bufPtr += teen(bufPtr, payCent);
		payCent = 0;
	}
	if (payCent > 0) {
		bufPtr += one(bufPtr, payCent);
	}
	payCent = (int)round(fabs(modf(pay, &rem)) * 100);
	if (payCent > 1) {
		sprintf(bufPtr, "%s", " cents");
		bufPtr += strlen(" cents");
	}
	else if (payCent == 1) {
		sprintf(bufPtr, "%s", " cent");
		bufPtr += strlen(" cent");
	}

	printf("%s\n", buffer);

}

// takes two pay digits
int hyphen(char* buffer, int pay) {
	if (pay % 10 != 0) {
		sprintf(buffer, "%s", "-");
		return 1;
	}
	return 0;
}

// takes one pay digit
int one(char* buffer, int pay) {
	int addPtr = 0;

	switch (pay) {
	case 1:
		sprintf(buffer, "%s", "one");
		addPtr += strlen("one");
		break;
	case 2:
		sprintf(buffer, "%s", "two");
		addPtr += strlen("two");
		break;
	case 3:
		sprintf(buffer, "%s", "three");
		addPtr += strlen("three");
		break;
	case 4:
		sprintf(buffer, "%s", "four");
		addPtr += strlen("four");
		break;
	case 5:
		sprintf(buffer, "%s", "five");
		addPtr += strlen("five");
		break;
	case 6:
		sprintf(buffer, "%s", "six");
		addPtr += strlen("six");
		break;
	case 7:
		sprintf(buffer, "%s", "seven");
		addPtr += strlen("seven");
		break;
	case 8:
		sprintf(buffer, "%s", "eight");
		addPtr += strlen("eight");
		break;
	case 9:
		sprintf(buffer, "%s", "nine");
		addPtr += strlen("nine");
		break;
	}
	return addPtr;
}

// takes two pay digits, pay < 20 && pay > 9
int teen(char* buffer, int pay) {
	int addPtr = 0;

	switch (pay) {
	case 10:
		sprintf(buffer, "%s", "ten");
		addPtr += strlen("ten");
		break;
	case 11:
		sprintf(buffer, "%s", "eleven");
		addPtr += strlen("eleven");
		break;
	case 12:
		sprintf(buffer, "%s", "twelve");
		addPtr += strlen("twelve");
		break;
	case 13:
		sprintf(buffer, "%s", "thirteen");
		addPtr += strlen("thirteen");
		break;
	case 14:
		sprintf(buffer, "%s", "fourteen");
		addPtr += strlen("fourteen");
		break;
	case 15:
		sprintf(buffer, "%s", "fifteen");
		addPtr += strlen("fifteen");
		break;
	case 16:
		sprintf(buffer, "%s", "sixteen");
		addPtr += strlen("sixteen");
		break;
	case 17:
		sprintf(buffer, "%s", "seventeen");
		addPtr += strlen("seventeen");
		break;
	case 18:
		sprintf(buffer, "%s", "eighteen");
		addPtr += strlen("eighteen");
		break;
	case 19:
		sprintf(buffer, "%s", "nineteen");
		addPtr += strlen("nineteen");
	}
	return addPtr;
}

// takes one pay digit
int ten(char* buffer, int pay) {
	int addPtr = 0;
	
	switch (pay) {
	case 2:
		sprintf(buffer, "%s", "twenty");
		addPtr += strlen("twenty");
		break;
	case 3:
		sprintf(buffer, "%s", "thirty");
		addPtr += strlen("thirty");
		break;
	case 4:
		sprintf(buffer, "%s", "forty");
		addPtr += strlen("forty");
		break;
	case 5:
		sprintf(buffer, "%s", "fifty");
		addPtr += strlen("fifty");
		break;
	case 6:
		sprintf(buffer, "%s", "sixty");
		addPtr += strlen("sixty");
		break;
	case 7:
		sprintf(buffer, "%s", "seventy");
		addPtr += strlen("seventy");
		break;
	case 8:
		sprintf(buffer, "%s", "eighty");
		addPtr += strlen("eighty");
		break;
	case 9:
		sprintf(buffer, "%s", "ninety");
		addPtr += strlen("ninety");
		break;
	}
	// add hyphen code
	return addPtr;
}