#include <stdio.h>
#include <string.h>

void partA();
void partB();
void partC();
void partD();
void partE();

int main(void) {
	partA();
	partB();
	partC();
	partD();
	partE();
}

void partA() {
	// true, the letter A "comes before" the letter B
	puts("Part A");
	if (strcmp("A", "B") < 0) {
		printf("%s\n", "true.  A < B");
	}
	else {
		printf("%s\n", "false.  A > B");
	}
	puts("\n");
}

void partB() {
	// false
	puts("Part B");
	if (strcmp("9", "0") < 0) {
		printf("%s\n", "true.  9 < 0");
	}
	else {
		printf("%s\n", "false.  9 > 0");
	}
	puts("\n");
}

void partC() {
	// true
	puts("Part C");
	char* math = "+-*/";
	char* num = "1234567890";
	int less = 1;
	for (int i0 = 0; i0 < 4; ++i0) {
		for (int i1 = 0; i1 < 10; ++i1) {
			if ((int)math[i0] >(int)num[i1]) {
				less = 0;
			}
		}
	}
	if (less == 1) {
		printf("%s\n", "true.  math < numbers");
	}
	else {
		printf("%s\n", "false.  math > numbers");
	}
	puts("\n");
}

void partD() {
	// true
	puts("Part D");
	char* digits = "1234567890";
	char* letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	int less = 1;
	for (int i0 = 0; i0 < 10; ++i0) {
		for (int i1 = 0; letters[i1] != '\0'; ++i1) {
			if ((int)digits >(int)letters) {
				less = 0;
			}
		}
	}
	if (less == 1) {
		printf("%s\n", "true.  digits < letters");
	}
	else {
		printf("%s\n", "false.  digits > letters");
	}
	puts("\n");
}

void partE() {
	// false
	puts("Part E");
	if ((int)')' < (int)'(') {
		printf("%s\n", "true.  ) < (");
	}
	else {
		printf("%s\n", "false.  ) > (");
	}
	puts("\n");
}