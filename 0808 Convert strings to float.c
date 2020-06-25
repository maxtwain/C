#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	puts("Enter four integers to sum.");
	char str1[20] = "0";
	char str2[20] = "0";
	char str3[20] = "0";
	char str4[20] = "0";

	double num1 = 0;
	double num2 = 0;
	double num3 = 0;
	double num4 = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);
	puts("");

	printf("str1 = %s\nstr2 = %s\nstr3 = %s\nstr4 = %s\n", str1, str2, str3, str4);
	puts("");

	char* rPtr = NULL;
	num1 = strtod(str1, &rPtr, 10);
	printf("Num1 = %f\n", num1);
	rPtr = NULL;
	num2 = strtod(str2, &rPtr, 10);
	printf("Num2 = %f\n", num2);
	rPtr = NULL;
	num3 = strtod(str3, &rPtr, 10);
	printf("Num3 = %f\n", num3);
	rPtr = NULL;
	num4 = strtod(str4, &rPtr, 10);
	printf("Num4 = %f\n", num4);
	puts("");

	double sum = num1 + num2 + num3 + num4;
	printf("sum = %f\n", sum);
	puts("");
}