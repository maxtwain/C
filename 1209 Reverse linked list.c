#include <stdio.h>
#include <stdlib.h>

typedef struct link {
	char letter;
	struct link* nextPtr;
} Link, *LinkPtr;

void newLink(LinkPtr *tarPtr, char inLetter);
void print(LinkPtr s0);
void freeMemory(LinkPtr s0);
int listLength(LinkPtr s0);
char getLetter(LinkPtr s0, int stopPos);

int main(void) {

	LinkPtr list0 = malloc(sizeof(Link));
	
	LinkPtr curPtr = list0;
	curPtr->letter = 'a';
	curPtr->nextPtr = malloc(sizeof(Link));

	for (int i = 0; i < 9; ++i) {
		newLink(&curPtr, 98 + i);
	}
	free(curPtr->nextPtr);
	curPtr->nextPtr = NULL;
	// list0 complete

	int list0Length = listLength(list0);
	LinkPtr list1 = malloc(sizeof(Link));

	curPtr = list1;
	curPtr->letter = getLetter(list0, list0Length);
	curPtr->nextPtr = malloc(sizeof(Link));

	for (int i = 0; i < list0Length - 1; ++i) {
		newLink(&curPtr, getLetter(list0, list0Length - 1 - i));
	}
	free(curPtr->nextPtr);
	curPtr->nextPtr = NULL;
	// list1 complete

	print(list0);
	print(list1);
	
	freeMemory(list0);
	freeMemory(list1);
}

void newLink(LinkPtr *tarPtr, char inLetter) {
	*tarPtr = (*tarPtr)->nextPtr;
	(*tarPtr)->letter = inLetter;
	(*tarPtr)->nextPtr = malloc(sizeof(Link));

}

void print(LinkPtr curPtr) {
	while (curPtr != NULL) {
		printf("%c", curPtr->letter);
		curPtr = curPtr->nextPtr;
	}
	puts("");
}

void freeMemory(LinkPtr curPtr) {
	LinkPtr tempPtr;
	while (curPtr != NULL) {
		tempPtr = curPtr;
		curPtr = curPtr->nextPtr;
		free(tempPtr);
	}
}

// first element counts as 1
int listLength(LinkPtr curPtr) {
	int length = 0;
	while (curPtr != NULL) {
		++length;
		curPtr = curPtr->nextPtr;
	}
	return length;
}

char getLetter(LinkPtr curPtr, int stopPos) {
	while (stopPos > 1) {
		curPtr = curPtr->nextPtr;
		--stopPos;
	}
	return curPtr->letter;
}