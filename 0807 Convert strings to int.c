#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	puts("Enter four integers to sum.");
	char str1[20] = "0";
	char str2[20] = "0";
	char str3[20] = "0";
	char str4[20] = "0";

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);
	puts("");

	printf("str1 = %s\nstr2 = %s\nstr3 = %s\nstr4 = %s\n", str1, str2, str3, str4);
	puts("");

	char* rPtr = NULL;
	num1 = strtol(str1, &rPtr, 10);
	printf("Num1 = %d\n", num1);
	rPtr = NULL;
	num2 = strtol(str2, &rPtr, 10);
	printf("Num2 = %d\n", num2);
	rPtr = NULL;
	num3 = strtol(str3, &rPtr, 10);
	printf("Num3 = %d\n", num3);
	rPtr = NULL;
	num4 = strtol(str4, &rPtr, 10);
	printf("Num4 = %d\n", num4);
	puts("");

	int sum = num1 + num2 + num3 + num4;
	printf("sum = %d\n", sum);
	puts("");
}