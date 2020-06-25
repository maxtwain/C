#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NULL ((void*)0)
#define RANDMAX 100

typedef struct link {
	struct link *lPtr;
	int data;
	struct link *rPtr;
} Link, *LinkPtr;

void createLink(LinkPtr *inLink, int inData);
void levelOrder(LinkPtr inLink);

int main(void) {
	srand((unsigned int)time(NULL));

	LinkPtr root = malloc(sizeof(Link));
	root->data = rand() % RANDMAX;
	root->lPtr = NULL;
	root->rPtr = NULL;

	for (int i = 1 + rand() % 20; i > 0; --i) {
		createLink(&root, rand() % RANDMAX);
	}

	levelOrder(root);
}

void createLink(LinkPtr *inLink, int inData) {
	if ((*inLink)->data > inData) {
		if ((*inLink)->lPtr == NULL) {
			LinkPtr newLink = malloc(sizeof(Link));
			newLink->data = inData;
			newLink->lPtr = NULL;
			newLink->rPtr = NULL;
			(*inLink)->lPtr = newLink;
		}
		else {
			createLink(&((*inLink)->lPtr), inData);
		}
	}
	else if ((*inLink)->data < inData) {
		if ((*inLink)->rPtr == NULL) {
			LinkPtr newLink = malloc(sizeof(Link));
			newLink->data = inData;
			newLink->lPtr = NULL;
			newLink->rPtr = NULL;
			(*inLink)->rPtr = newLink;
		}
		else {
			createLink(&((*inLink)->rPtr), inData);
		}
	}
}

// Exit->Entrance->NULL/NEW
void levelOrder(LinkPtr inLink) {
	LinkPtr curLink = inLink;
	
	typedef struct q {
		struct link *toLink;
		struct q *next;
	} Q, *QPtr;

	QPtr enterQ = malloc(sizeof(Q));
	enterQ->toLink = inLink;
	enterQ->next = NULL;
	QPtr exitQ = enterQ;
	QPtr newQ = NULL;
	QPtr tempQ = NULL;

	while (exitQ != NULL) {
		curLink = exitQ->toLink;
		if (curLink->lPtr != NULL) {
			newQ = malloc(sizeof(Q));
			newQ->toLink = curLink->lPtr;
			newQ->next = NULL;

			enterQ->next = newQ;
			enterQ = newQ;
		}
		if (curLink->rPtr != NULL) {
			newQ = malloc(sizeof(Q));
			newQ->toLink = curLink->rPtr;
			newQ->next = NULL;

			enterQ->next = newQ;
			enterQ = newQ;
		}
		printf("%4d", exitQ->toLink->data);
		tempQ = exitQ;
		exitQ = exitQ->next;
		free(tempQ);
	}
}