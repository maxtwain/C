#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct intList {
	int integer;
	struct intList* nextPtr;
} IntList, *IntListPtr;

void nextChain(IntListPtr* tarPtr);
void printList(IntListPtr s0);
int sumFun(IntListPtr s0);
void freeMemory(IntListPtr s0);

int main(void) {
	srand((unsigned int)time(0));

	IntListPtr list0 = malloc(sizeof(IntList));
	IntListPtr curPtr = list0;

	curPtr->integer = rand() % 100;
	curPtr->nextPtr = malloc(sizeof(IntList));
	for (int i = 0; i < 24; ++i) {
		nextChain(&curPtr);
	}
	curPtr->nextPtr = NULL;

	printList(list0);

	int sumInt = sumFun(list0);
	curPtr = list0;

	printf("Sum = %d\nAve = %f\n", sumInt, (float)sumInt / 25);

	freeMemory(list0);
}

void nextChain(IntListPtr* tarPtr) {
	
	*tarPtr = (*tarPtr)->nextPtr;
	(*tarPtr)->integer = rand() % 100;
	(*tarPtr)->nextPtr = malloc(sizeof(IntList));
}

void printList(IntListPtr s0) {
	IntListPtr curPtr = s0;
	while (curPtr != NULL) {
		printf("%d\n", curPtr->integer);
		curPtr = curPtr->nextPtr;
	}
	puts("");
}

int sumFun(IntListPtr s0) {
	int sum = 0;
	IntListPtr curPtr = s0;
	while (curPtr != NULL) {
		sum += curPtr->integer;
		curPtr = curPtr->nextPtr;
	}
	return sum;
}

void freeMemory(IntListPtr s0) {
	IntListPtr curPtr = s0;
	IntListPtr tempPtr;
	while (curPtr != NULL) {
		tempPtr = curPtr;
		curPtr = curPtr->nextPtr;
		free(tempPtr);
	}
}