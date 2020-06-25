#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDMAX 100

typedef struct link {
	struct link *lPtr;
	int data;
	struct link *rPtr;
} Link, *LinkPtr;

void createLink(LinkPtr *inLink, int inData);
void outputTree(LinkPtr treePtr, int spaces);
void ordinaryTree(LinkPtr *root);

// I completed the exercise, but it does bother me that I haven't really gotten this to work yet with non-uniform trees.
int main(void) {
	srand((unsigned int)time(NULL));

	LinkPtr root = malloc(sizeof(Link));
	root->data = rand() % RANDMAX;
	root->lPtr = NULL;
	root->rPtr = NULL;

	for (int i = 1 + rand() % 20; i > 0; --i) {
		createLink(&root, rand() % RANDMAX);
	}

	//ordinaryTree(&root);
	outputTree(root, 0);
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

void outputTree(LinkPtr treePtr, int spaces) {
	if (treePtr != NULL) {
		outputTree(treePtr->rPtr, spaces + 5);
		printf("%*d", spaces, treePtr->data);
		outputTree(treePtr->lPtr, spaces + 5);
	}
	else {
		puts("");
	}
}

void ordinaryTree(LinkPtr *root) {
	(*root)->lPtr = malloc(sizeof(Link));
	(*root)->rPtr = malloc(sizeof(Link));
	
	(*root)->lPtr->lPtr = malloc(sizeof(Link));
	(*root)->lPtr->rPtr = malloc(sizeof(Link));
	(*root)->rPtr->lPtr = malloc(sizeof(Link));
	(*root)->rPtr->rPtr = malloc(sizeof(Link));

	(*root)->lPtr->lPtr->lPtr = malloc(sizeof(Link));
	(*root)->lPtr->lPtr->rPtr = malloc(sizeof(Link));
	(*root)->lPtr->rPtr->lPtr = malloc(sizeof(Link));
	(*root)->lPtr->rPtr->rPtr = malloc(sizeof(Link));
	(*root)->rPtr->lPtr->lPtr = malloc(sizeof(Link));
	(*root)->rPtr->lPtr->rPtr = malloc(sizeof(Link));
	(*root)->rPtr->rPtr->lPtr = malloc(sizeof(Link));
	(*root)->rPtr->rPtr->rPtr = malloc(sizeof(Link));

	(*root)->data = 49;
	(*root)->lPtr->data = 28;
	(*root)->rPtr->data = 83;

	(*root)->lPtr->lPtr->data = 18;
	(*root)->lPtr->rPtr->data = 40;
	(*root)->rPtr->lPtr->data = 71;
	(*root)->rPtr->rPtr->data = 97;

	(*root)->lPtr->lPtr->lPtr->data = 11;
	(*root)->lPtr->lPtr->rPtr->data = 19;
	(*root)->lPtr->rPtr->lPtr->data = 32;
	(*root)->lPtr->rPtr->rPtr->data = 44;
	(*root)->rPtr->lPtr->lPtr->data = 69;
	(*root)->rPtr->lPtr->rPtr->data = 72;
	(*root)->rPtr->rPtr->lPtr->data = 92;
	(*root)->rPtr->rPtr->rPtr->data = 99;

	(*root)->lPtr->lPtr->lPtr->lPtr = NULL;
	(*root)->lPtr->lPtr->lPtr->rPtr = NULL;
	(*root)->lPtr->lPtr->rPtr->lPtr = NULL;
	(*root)->lPtr->lPtr->rPtr->rPtr = NULL;
	(*root)->lPtr->rPtr->lPtr->lPtr = NULL;
	(*root)->lPtr->rPtr->lPtr->rPtr = NULL;
	(*root)->lPtr->rPtr->rPtr->lPtr = NULL;
	(*root)->lPtr->rPtr->rPtr->rPtr = NULL;
	(*root)->rPtr->lPtr->lPtr->lPtr = NULL;
	(*root)->rPtr->lPtr->lPtr->rPtr = NULL;
	(*root)->rPtr->lPtr->rPtr->lPtr = NULL;
	(*root)->rPtr->lPtr->rPtr->rPtr = NULL;
	(*root)->rPtr->rPtr->lPtr->lPtr = NULL;
	(*root)->rPtr->rPtr->lPtr->rPtr = NULL;
	(*root)->rPtr->rPtr->rPtr->lPtr = NULL;
	(*root)->rPtr->rPtr->rPtr->rPtr = NULL;
}