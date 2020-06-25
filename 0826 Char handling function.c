#include <stdio.h>

int isblank0(int c);
int isdigit0(int c);
int isalpha0(int c);
int isalnum0(int c);
int isxdigit0(int c);
int islower0(int c);
int isupper0(int c);
int tolower0(int c);
int toupper0(int c);
int isspace0(int c);
int iscntrl0(int c);
int ispunct0(int c);
int isprint0(int c);
int isgraph0(int c);

int main(void) {

	printf("%d\n", isblank0('\t'));
	printf("%d\n", isdigit0('5'));
	printf("%d\n", isalpha0('t'));

	puts("\n");
}

int isblank0(int c) {
	if (c == '\t' || c == ' ') {
		return 1;
	}
	return 0;
}

int isdigit0(int c) {
	if (c >= 48 && c <= 57) {
		return 1;
	}
	return 0;
}

int isalpha0(int c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return 1;
	}
	return 0;
}

int isalnum0(int c) {
	if (isdigit0(c) || isalpha0(c)) {
		return 1;
	}
	return 0;
}

int isxdigit0(int c) {
	if (isdigit0(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102)) {
		return 1;
	}
	return 0;
}

int islower0(int c) {
	if (c >= 97 && c <= 122) {
		return 1;
	}
	return 0;
}

int isupper0(int c) {
	if (c >= 65 && c <= 90) {
		return 1;
	}
	return 0;
}

int tolower0(int c) {
	if (isupper0(c)) {
		return c + 32;
	}
	return c;
}

int toupper0(int c) {
	if (islower0(c)) {
		return c - 32;
	}
	return c;
}

int isspace0(int c) {
	if ((c >= 9 && c <= 13) || c == ' ') {
		return 1;
	}
	return 0;
}

int iscntrl0(int c) {
	if ((c >= 0 && c <= 31) || c == 127) {
		return 1;
	}
	return 0;
}

int ispunct0(int c) {
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || 
		(c >= 91 && c <= 96) || (c >= 123 && c <= 126)) {
		return 1;
	}
	return 0;
}

int isprint0(int c) {
	if (c >= 32 && c <= 126) {
		return 1;
	}
	return 0;
}

int isgraph0(int c) {
	if (c >= 33 && c <= 126) {
		return 1;
	}
	return 0;
}
