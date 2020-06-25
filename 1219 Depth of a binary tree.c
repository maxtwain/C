#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct link {
	struct link *lPtr;
	int data;
	struct link *rPtr;
} Link, *LinkPtr;

void createLinkPair(LinkPtr *inLink, int size);
int treeSize(LinkPtr *treeRoot);

int main(void) {
	srand((unsigned int)time(NULL));
	int size = 1 + rand() % 8;

	LinkPtr root = malloc(sizeof(Link));
	root->lPtr = NULL;
	root->rPtr = NULL;

	createLinkPair(&root, size);
	printf("Tree Size: %d\n", treeSize(&root));

}

void createLinkPair(LinkPtr *inLink, int size) {
	LinkPtr newLink0 = malloc(sizeof(Link));
	newLink0->lPtr = NULL;
	newLink0->rPtr = NULL;

	LinkPtr newLink1 = malloc(sizeof(Link));
	newLink1->lPtr = NULL;
	newLink1->rPtr = NULL;

	(*inLink)->lPtr = newLink0;
	(*inLink)->rPtr = newLink1;

	if (size > 0) {
		createLinkPair(&newLink0, size - 1);
		createLinkPair(&newLink1, size - 1);
	}
}

int treeSize(LinkPtr *treeRoot) {
	int size = 1;
	LinkPtr tempPtr = (*treeRoot);
	while (tempPtr->lPtr != NULL) {
		++size;
		tempPtr = tempPtr->lPtr;
	}
	return size;
}