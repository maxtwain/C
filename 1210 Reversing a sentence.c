#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link {
	char word[30];
	struct link *nextPtr;
} Link, *LinkPtr;

void stackWord(LinkPtr *curPtr, char inWord[30]);
void printList(LinkPtr curPtr);
void freeStack(LinkPtr *curPtr);

int main(void) {

	char buffer[500] = "The quick brown fox jumps over the lazy dog.";
	LinkPtr list0 = malloc(sizeof(Link));

	char* token = strtok(buffer, " ");
	strcpy(list0->word, token);
	list0->nextPtr = NULL;

	token = strtok(NULL, " ");
	while (token != NULL) {
		stackWord(&list0, token);
		token = strtok(NULL, " ");
	}

	printList(list0);

	freeStack(&list0);
}

void stackWord(LinkPtr *curPtr, char inWord[30]) {
	LinkPtr newLink = malloc(sizeof(Link));
	strcpy(newLink->word, inWord);
	newLink->nextPtr = *curPtr;
	*curPtr = newLink;
}

void printList(LinkPtr curPtr) {
	printf("%s", curPtr->word);
	curPtr = curPtr->nextPtr;
	while (curPtr != NULL) {
		printf(" %s", curPtr->word);
		curPtr = curPtr->nextPtr;
	}
	puts("");
}

void freeStack(LinkPtr *curPtr) {
	LinkPtr tempPtr = *curPtr;
	while ((*curPtr)->nextPtr != NULL) {
		*curPtr = (*curPtr)->nextPtr;
		free(tempPtr);
		tempPtr = *curPtr;
	}
	free(*curPtr);
}