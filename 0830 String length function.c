#include <stdio.h>

size_t strlen0A(const char* s);
size_t strlen0P(const char* s);
void printA(const char* s);
void printP(const char* s);

int main(void) {

	printA("abc");
	printP("abc");

	puts("\n");
}

size_t strlen0A(const char* s) {
	size_t len = 0;
	while (s[len] != '\0') {
		++len;
	}
	return len;
}

size_t strlen0P(const char* s) {
	size_t len = 0;
	while (*s != '\0') {
		++len;
		++s;
	}
	return len;
}

void printA(const char* s) {
	printf("strlen0A(%s) = %d\n", s, strlen0A(s));
}

void printP(const char* s) {
	printf("strlen0P(%s) = %d\n", s, strlen0P(s));
}