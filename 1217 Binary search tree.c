#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct treeNode {
	struct treeNode *leftPtr;
	char word[20];
	struct treeNode *rightPtr;
} TreeNode, *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, char inWord[20]);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void) {
	TreeNodePtr rootPtr = NULL;
	char sentence[] = "If the Easter Bunny and the Tooth Fairy had babies would they take your teeth and leave chocolate for you?";

	srand((unsigned int)time(NULL));
	puts("The words being placed in the tree are:");

	char* item = strtok(sentence, " ");
	while (item != NULL) {
		printf("%10s", item);
		insertNode(&rootPtr, item);
		item = strtok(NULL, " ");
	}

	puts("\n\nThe preOrder traversal is:");
	preOrder(rootPtr);

	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);
	puts("\n");
}

void insertNode(TreeNodePtr *treePtr, char inWord[20]) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		strcpy((*treePtr)->word, inWord);
		(*treePtr)->leftPtr = NULL;
		(*treePtr)->rightPtr = NULL;
	}
	else {
		if (strcmp((*treePtr)->word, inWord) <= 0) {
			insertNode(&((*treePtr)->leftPtr), inWord);
		}
		else {
			insertNode(&((*treePtr)->rightPtr), inWord);
		}
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%10s", treePtr->word);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%10s", treePtr->word);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%10s", treePtr->word);
	}
}