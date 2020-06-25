#include <stdio.h>
#include <ctype.h>
#include <string.h>

//a) 

void partA(char s1[50]);
void partB(char s2[50], char s3[50]);
void partC(char s1[50], char s2[50], char s3[50]);
void partD(char s1[50], char s2[50], char s3[50]);
void partE(char s1[50], char s2[50], char s3[50]);

int main(void) {
	char s1[50] = "jack";
	char s2[50] = "jill";
	char s3[50];

	//partA(s1);
	//partB(s2, s3);
	partC(s1, s2, s3);
	//partD(s1, s2, s3);
	partE(s1, s2, s3);
}

void partA(char s1[50]) {
	puts("Part A");
	printf("%c%s", toupper(s1[0]), &s1[1]);
	puts("\n");
}

void partB(char s2[50], char s3[50]) {
	puts("Part B");
	printf("%s", strcpy(s3, s2));
	puts("\n");
}

void partC(char s1[50], char s2[50], char s3[50]) {
	puts("Part C");
	printf("%s", strcat(strcat(strcpy(s3, s1), " and "), s2));
	puts("\n");
}

void partD(char s1[50], char s2[50], char s3[50]) {
	puts("Part D");
	printf("%u", strlen(s1) + strlen(s2));
	puts("\n");
}

void partE(char s1[50], char s2[50], char s3[50]) {
	puts("Part E");
	printf("%u", strlen(s3));
	puts("\n");
}