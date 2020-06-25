#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int main(void) {
	char s[SIZE];
	puts("Enter a line of text.");
	fgets(s, SIZE, stdin);
	for (char* ptr = &s[0]; *ptr != '\0'; ++ptr) {
		putchar(tolower(*ptr));
	}
	for (char* ptr = &s[0]; *ptr != '\0'; ++ptr) {
		putchar(toupper(*ptr));
	}
	puts("");

}