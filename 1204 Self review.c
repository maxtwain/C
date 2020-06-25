#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gradeNode {
	char lastName[20];
	double grade;
	struct gradeNode *nextPtr;
} GradeNode, *GradeNodePtr;

int main(void) {

	// Part A
	GradeNodePtr startPtr = NULL;

	// Part B
	/*
	GradeNodePtr newPtr;
	newPtr = malloc(sizeof(GradeNode));
	strcpy(newPtr->lastName, "Jones");
	newPtr->grade = 91.5;
	newPtr->nextPtr = NULL;
	*/

	startPtr = malloc(sizeof(GradeNode));
	strcpy(startPtr->lastName, "Jones");
	startPtr->grade = 91.5;

	// Part C
	// Records
	startPtr->nextPtr = malloc(sizeof(GradeNode));
	strcpy(startPtr->nextPtr->lastName, "Smith");
	startPtr->nextPtr->grade = 88.4;
	startPtr->nextPtr->nextPtr = NULL;

	GradeNodePtr previousPtr = NULL;
	GradeNodePtr currentPtr = NULL;

	GradeNodePtr newPtr;
	newPtr = malloc(sizeof(GradeNode));
	strcpy(newPtr->lastName, "Adams");
	newPtr->grade = 85.0;
	newPtr->nextPtr = NULL;

	// Solution
	previousPtr = NULL;
	currentPtr = startPtr;
	startPtr = newPtr;
	newPtr->nextPtr = currentPtr;

	// New record
	newPtr = malloc(sizeof(GradeNode));
	strcpy(newPtr->lastName, "Thompson");
	newPtr->grade = 73.5;
	newPtr->nextPtr = NULL;

	// Solution
	previousPtr = startPtr->nextPtr->nextPtr;
	currentPtr = NULL;
	newPtr->nextPtr = currentPtr;
	previousPtr->nextPtr = newPtr;

	// New record
	newPtr = malloc(sizeof(GradeNode));
	strcpy(newPtr->lastName, "Pritchard");
	newPtr->grade = 66.5;
	newPtr->nextPtr = NULL;

	// Solution
	previousPtr = startPtr->nextPtr;
	currentPtr = previousPtr->nextPtr;
	newPtr->nextPtr = currentPtr;
	previousPtr->nextPtr = newPtr;

	// Part D
	currentPtr = startPtr;
	printf("%-20s%5s\n", "Last Name", "Grade");
	while (currentPtr != NULL) {
		printf("%-20s%5.1f\n", currentPtr->lastName, currentPtr->grade);
		currentPtr = currentPtr->nextPtr;
	}
	
	// Part E
	GradeNodePtr tempPtr = NULL;
	currentPtr = startPtr;
	while (currentPtr != NULL) {
		tempPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
		free(tempPtr);
	}
}