#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRIVAL rand() % 3 + 1
#define SERVICE rand() % 3 + 1

typedef struct link {
	int arrival;
	int departure;
	struct link *nextPtr;
} Link, *LinkPtr;

void push(LinkPtr *head, LinkPtr *tail, int inArrival);
int pop(LinkPtr *head, LinkPtr *tail);

int main(void) {

	srand((unsigned)time(NULL));
	int nextArrival = ARRIVAL;

	LinkPtr head = malloc(sizeof(Link));
	head->arrival = nextArrival;
	head->departure = head->arrival + SERVICE;
	head->nextPtr = NULL;
	LinkPtr tail = head;

	int maxWait = 0;
	int maxLineSize = 1;
	int lineSize = 1;
	for (int openTime = 0; openTime < 720; ++openTime) {
		if (nextArrival == openTime) {
			printf("%5d%20s\n", openTime, "New Customer");
			push(&head, &tail, openTime);
			nextArrival = openTime + ARRIVAL;
			++lineSize;
		}

		if (maxLineSize < lineSize) {
			maxLineSize = lineSize;
		}

		if (head != NULL && head->departure - openTime == 0) {
			printf("%5d%20s\n", openTime, "Service Complete");

			if (maxWait < head->departure - head->arrival) {
				maxWait = head->departure - head->arrival;
			}

			pop(&head, &tail);
			--lineSize;
		}
	}

	printf("\nMax Line Size: %d customers\nMax Wait: %d minutes\n\n", maxLineSize, maxWait);
}

void push(LinkPtr *head, LinkPtr *tail, int inArrival) {
	LinkPtr newLink = malloc(sizeof(Link));
	newLink->arrival = inArrival;
	if (*head == NULL) {
		newLink->departure = inArrival + SERVICE;
		*head = newLink;
		*tail = *head;
	}
	else {
		newLink->departure = (*tail)->departure + SERVICE;
		(*tail)->nextPtr = newLink;
		*tail = newLink;
	}
	newLink->nextPtr = NULL;
}

int pop(LinkPtr *head, LinkPtr *tail) {
	int retValue = (*head)->departure;
	LinkPtr tempPtr = *head;

	if ((*head)->nextPtr == NULL) {
		*head = NULL;
	}
	else {
		*head = (*head)->nextPtr;
	}
	free(tempPtr);

	return retValue;
}