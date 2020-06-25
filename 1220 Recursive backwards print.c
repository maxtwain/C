#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct link {
	int data;
	struct link *next;
} Link, *LinkPtr;

void createLink(LinkPtr *inLink, int inData);
void printStack(LinkPtr inLink);

int main(void) {
	srand((unsigned int)time(NULL));
	
	LinkPtr top = NULL;

	for (int num = rand() % 10; num < 200; num += rand() % 10) {
		createLink(&top, num);
	}

	printStack(top);
	puts("");
}

void createLink(LinkPtr *inLink, int inData) {
	LinkPtr newLink = malloc(sizeof(Link));
	newLink->data = inData;
	newLink->next = *inLink;
	
	*inLink = newLink;
}

void printStack(LinkPtr inLink) {
	printf("%4d", inLink->data);
	if (inLink->next != NULL) {
		printStack(inLink->next);
	}
}