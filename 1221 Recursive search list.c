#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct link {
	int data;
	struct link *next;
} Link, *LinkPtr;

void createLink(LinkPtr *inLink, int inNum);
int* findValue(LinkPtr inLink, int find);

int main(void) {
	srand((unsigned int)time(NULL));

	LinkPtr top = NULL;

	for (int num = rand() % 2; num < 20; num += rand() % 10) {
		createLink(&top, num);
	}

	int* ptr = findValue(top, 10);

	if (ptr == NULL) {
		puts("Value not found");
	}
	else {
		puts("Value found");
	}

}

void createLink(LinkPtr *inLink, int inNum) {
	LinkPtr newLink = malloc(sizeof(Link));
	newLink->data = inNum;
	newLink->next = *inLink;
	*inLink = newLink;
}

int* findValue(LinkPtr inLink, int find) {
	if (inLink->data == find) {
		return &(inLink->data);
	}
	else if (inLink->next != NULL) {
		findValue(inLink->next, find);
	}
	else {
		return NULL;
	}
}