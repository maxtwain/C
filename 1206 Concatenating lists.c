#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str {
	char letters[10];
	struct str* nextPtr;
} Str, *StrPtr;

void concatenate(StrPtr s0, StrPtr s1);
void print(StrPtr s0);
void freeMemory(StrPtr s0);

int main(void) {
	StrPtr start0 = malloc(sizeof(Str));
	
	StrPtr curPtr = start0;
	strcpy(curPtr->letters, "anti");
	curPtr->nextPtr = malloc(sizeof(Str));
	
	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "dis");
	curPtr->nextPtr = malloc(sizeof(Str));
	
	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "est");
	curPtr->nextPtr = malloc(sizeof(Str));

	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "ab");
	curPtr->nextPtr = malloc(sizeof(Str));

	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "lish");
	curPtr->nextPtr = NULL;



	StrPtr start1 = malloc(sizeof(Str));

	curPtr = start1;
	strcpy(curPtr->letters, "ment");
	curPtr->nextPtr = malloc(sizeof(Str));
	
	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "ar");
	curPtr->nextPtr = malloc(sizeof(Str));

	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "i");
	curPtr->nextPtr = malloc(sizeof(Str));

	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "an");
	curPtr->nextPtr = malloc(sizeof(Str));

	curPtr = curPtr->nextPtr;
	strcpy(curPtr->letters, "ism");
	curPtr->nextPtr = NULL;

	print(start0);
	print(start1);
	concatenate(start0, start1);
	print(start0);
	freeMemory(start0);
}

void concatenate(StrPtr s0, StrPtr s1) {
	StrPtr curPtr = s0;
	while (curPtr->nextPtr != NULL) {
		curPtr = curPtr->nextPtr;
	}
	curPtr->nextPtr = s1;
}

void print(StrPtr s0) {
	StrPtr curPtr = s0;
	while (curPtr != NULL) {
		printf("%s", curPtr->letters);
		curPtr = curPtr->nextPtr;
	}
	puts("");
}

void freeMemory(StrPtr s0) {
	StrPtr curPtr = s0;
	StrPtr tempPtr;
	while (curPtr != NULL) {
		tempPtr = curPtr;
		curPtr = curPtr->nextPtr;
		free(tempPtr);
	}
}