#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER buffer1

typedef struct link {
	unsigned char letter;
	struct link *nextPtr;
} Link, *LinkPtr;

void stackLetter(LinkPtr *curPtr, unsigned char inLetter);

int main(void) {

	unsigned char buffer0[500] = "The quick brown fox jumps over the lazy dog.";
	unsigned char buffer1[500] = "Madam, in Eden, I m Adam.";
	unsigned char buffer2[500] = "ada.";

	LinkPtr list0 = malloc(sizeof(Link));
	list0->letter = BUFFER[0];
	list0->nextPtr = NULL;

	for (int i = 1; BUFFER[i] != '\0'; ++i) {
		stackLetter(&list0, BUFFER[i]);
	}
	
	int bufInd = 0;
	LinkPtr tempPtr = NULL;
	int isPal = 1;
	while (list0->nextPtr != NULL) {

		while (!isalpha(BUFFER[bufInd]) && BUFFER[bufInd] != '\0') {
			++bufInd;
		}
		while (!isalpha(list0->letter) && list0->nextPtr != NULL) {
			tempPtr = list0;
			list0 = list0->nextPtr;
			free(tempPtr);
		}

		if (tolower(BUFFER[bufInd]) != tolower(list0->letter)) {
			isPal = 0;
			break;
		}
		else {
			++bufInd;
			list0 = list0->nextPtr;	
		}
	}
	free(list0);

	if (isPal) {
		printf("%s\nis a palindrome.\n", BUFFER);
	}
	else {
		printf("%s\nis NOT a palindrome.\n", BUFFER);
	}
}

void stackLetter(LinkPtr *curPtr, unsigned char inLetter) {
	LinkPtr newLink = malloc(sizeof(Link));
	newLink->letter = inLetter;
	newLink->nextPtr = *curPtr;
	*curPtr = newLink;
}

