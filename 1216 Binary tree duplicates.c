#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
} TreeNode, *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void) {
	TreeNodePtr rootPtr = NULL;

	srand((unsigned int)time(NULL));
	puts("The numbers being placed in the tree are:");

	for (unsigned int i = 1; i <= 10; ++i) {
		int item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}

	puts("\n\nThe preOrder traversal is:");
	preOrder(rootPtr);

	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);
	puts("\n");
}

void insertNode(TreeNodePtr *treePtr, int value) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		(*treePtr)->data = value;
		(*treePtr)->leftPtr = NULL;
		(*treePtr)->rightPtr = NULL;
	}
	else {
		if (value <= (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else {
			insertNode(&((*treePtr)->rightPtr), value);
		}
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);
	}
}