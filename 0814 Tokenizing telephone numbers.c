#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

// this takes phone numbers in the form "(555) 555-5555"

int main(void) {
	char pStr[SIZE] = "(123) 456-7890";
	printf("%s", "Enter a telephone number: ");
	fgets(pStr, SIZE, stdin);

	int aCode = 0;
	long seven = 0;
	char* remPtr = NULL;
	
	char* ptr = strtok(pStr, "() -");
	char* tok0 = ptr;

	ptr = strtok(NULL, "() -");
	char* tok1 = ptr;

	ptr = strtok(NULL, "() -");
	char* tok2 = ptr;

	aCode = strtol(tok0, &remPtr, 10);
	strcat(tok1, tok2);
	seven = strtol(tok1, &remPtr, 10);
	printf("%d %d\n", aCode, seven);

	puts("\n");
}