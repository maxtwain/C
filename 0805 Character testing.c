#include <stdio.h>
#include <ctype.h>

int main(void) {
	char c;
	printf("%s", "Enter a character: ");
	scanf("%c", &c);
	printf("%c was entered.\n", c);

	printf("isblank(c) returns %d\n", isblank(c));
	printf("isdigit(c) returns %d\n", isdigit(c));
	printf("isalpha(c) returns %d\n", isalpha(c));
	printf("isalnum(c) returns %d\n", isalnum(c));
	printf("isxdigit(c) returns %d\n", isxdigit(c));
	printf("islower(c) returns %d\n", islower(c));
	printf("isupper(c) returns %d\n", isupper(c));
	printf("tolower(c) returns %d\n", tolower(c));
	printf("toupper(c) returns %d\n", toupper(c));
	printf("isspace(c) returns %d\n", isspace(c));
	printf("iscntrl(c) returns %d\n", iscntrl(c));
	printf("ispunct(c) returns %d\n", ispunct(c));
	printf("isprint(c) returns %d\n", isprint(c));
	printf("isgraph(c) returns %d\n", isgraph(c));
	
	puts("\n");
}