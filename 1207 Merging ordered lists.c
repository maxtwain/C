#include <stdio.h>
#include <stdlib.h>

typedef struct intList {
	int integer;
	struct intList* nextPtr;
} IntList, *IntListPtr;

IntListPtr merge(IntListPtr s0, IntListPtr s1);
void print(IntListPtr s0);
void freeMemory(IntListPtr s0);

int main(void) {
	IntListPtr start0 = malloc(sizeof(IntList));

	IntListPtr curPtr = start0;
	curPtr->integer = 656;
	curPtr->nextPtr = malloc(sizeof(IntList));
	
	curPtr = curPtr->nextPtr;
	curPtr->integer = 730;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 593;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 548;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 884;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 275;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 441;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 652;
	curPtr->nextPtr = NULL;


	IntListPtr start1 = malloc(sizeof(IntList));

	curPtr = start1;
	curPtr->integer = 610;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 420;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 288;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 485;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 780;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 181;
	curPtr->nextPtr = malloc(sizeof(IntList));

	curPtr = curPtr->nextPtr;
	curPtr->integer = 198;
	curPtr->nextPtr = NULL;

	print(start0);
	print(start1);
	merge(start0, start1);
	print(start0);
	freeMemory(start0);
}

IntListPtr merge(IntListPtr s0, IntListPtr s1) {
	IntListPtr curPtr = s0;
	while (curPtr->nextPtr != NULL) {
		curPtr = curPtr->nextPtr;
	}
	curPtr->nextPtr = s1;

	return s0;
}

void print(IntListPtr s0) {
	IntListPtr curPtr = s0;
	while (curPtr != NULL) {
		printf("%d\n", curPtr->integer);
		curPtr = curPtr->nextPtr;
	}
	puts("");
}

void freeMemory(IntListPtr s0) {
	IntListPtr curPtr = s0;
	IntListPtr tempPtr;
	while (curPtr->nextPtr != NULL) {
		tempPtr = curPtr;
		curPtr = curPtr->nextPtr;
		free(tempPtr);
	}
}