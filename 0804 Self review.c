#include <stdio.h>
#include <ctype.h>
#include <string.h>

void partA();
void partB();
void partC();
void partD();

int main(void) {
	
	//partA();
	//partB();
	partC();
}

void partA() {
	puts("Part A");
	// no null terminator
	char s[10];
	strncpy(s, "hello", 5);
	printf("%s\n", s);
	puts("");
}

void partB() {
	puts("Part B");
	// no null terminator.
	printf("%s", 'a');
	puts("");
}

void partC() {
	puts("Part C");
	// no null terminator.
	char s[12];
	strcpy(s, "Welcome Home");
	puts("");
}

void partD() {
	char string1[10];
	char string2[10];
	// strcmp returns 0 if the strings are equal.  if the condition returns true, the strings are not equal.
	if (strcmp(string1, string2)) {
		puts("The strings are equal");
	}
}