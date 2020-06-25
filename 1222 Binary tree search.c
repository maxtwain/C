#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDMAX 10

typedef struct link {
	struct link *lPtr;
	int data;
	struct link *rPtr;
} Link, *LinkPtr;

void createLink(LinkPtr *inLink, int inData);
int* search(LinkPtr inLink, int find);

int main(void) {
	srand((unsigned int)time(NULL));

	LinkPtr root = malloc(sizeof(Link));
	root->data = rand() % RANDMAX;
	root->lPtr = NULL;
	root->rPtr = NULL;
	
	for (int i = 1 + rand() % 20; i > 0; --i) {
		createLink(&root, rand() % RANDMAX);
	}

	int* p = search(root, rand() % RANDMAX);

	printf("%s\n", p == NULL ? "Number found" : "Number not found");
	
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

int* search(LinkPtr inLink, int find) {
	if (inLink->data == find) {
		return &(inLink->data);
	}
	else if (inLink->data > find) {
		if (inLink->lPtr == NULL) {
			return NULL;
		}
		else {
			search(inLink->lPtr, find);
		}
	}
	else {
		if (inLink->rPtr == NULL) {
			return NULL;
		}
		else {
			search(inLink->rPtr, find);
		}
	}
}