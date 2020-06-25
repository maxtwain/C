#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct link {
	char data;
	struct link *nextPtr;
} Link, *LinkPtr;

void convertToPostfix(char infix[500], char postfix[500]);
int isOperator(char c);
int precedence(char operator0, char operator1);
void push(LinkPtr *topPtr, char value);
char pop(LinkPtr *topPtr);
char stackTop(LinkPtr topPtr);
int isEmpty(LinkPtr topPtr);
void printStack(LinkPtr topPtr);

int main(void) {
	
	char infix[500] = "5 - 2 + 4 * (8 - (5 + 1)) + 9";
	char postfix[500] = "";

	convertToPostfix(infix, postfix);

	printf("%s\n", postfix);
}

// convert infix to postfix
void convertToPostfix(char infix[500], char postfix[500]) {
	
	LinkPtr list0 = malloc(sizeof(Link));
	list0->data = '(';
	list0->nextPtr = NULL;
	infix[strlen(infix)] = ')';
	infix[strlen(infix)] = '\0';

	char cur;
	for (int inI = 0, postI = 0; infix[inI] != '\0'; ++inI) {
		cur = infix[inI];
		if (isdigit(cur)) {
			postfix[postI] = cur;
			postfix[postI + 1] = ' ';
			postI += 2;
		}
		else if (cur == '(') {
			push(&list0, cur);
		}
		else if (isOperator(cur)) {
			if (!isEmpty(list0) && precedence(list0->data, cur) >= 0) {
				while (!isEmpty(list0) && isOperator(list0->data)) {
					postfix[postI] = pop(&list0);
					postfix[postI + 1] = ' ';
					postI += 2;
				}
			}
			push(&list0, cur);
		}
		else if (cur == ')') {
			while (isOperator(list0->data)) {
				postfix[postI] = pop(&list0);
				postfix[postI + 1] = ' ';
				postI += 2;
			}
			pop(&list0);
		}
	}

	postfix[strlen(postfix)] = '\0';
}

// determine whether c is an operator
int isOperator(char c) {
	if (c == 37 || c == 42 || c == 43 ||
		c == 45 || c == 47 || c == 94) {
		return 1;
	}
	return 0;
}

// % = 37
// * = 42
// + = 43
// - = 45
// / = 47
// ^ = 94

// determine whether the precedence of operator0 is less than, equal to, or greater than the precedence of operator1.  returns -1, 0, or 1
int precedence(char operator0, char operator1) {
	int p0 = 0;
	int p1 = 0;

	switch (operator0) {
	case 43:
	case 45:
		--p0;
		break;
	case 94:
		++p0;
	}

	switch (operator1) {
	case 43:
	case 45:
		--p1;
		break;
	case 94:
		++p1;
	}

	return p0 - p1;
}

// push a value on the stack
void push(LinkPtr *topPtr, char value) {
	LinkPtr newLink = malloc(sizeof(Link));
	newLink->data = value;
	newLink->nextPtr = *topPtr;
	*topPtr = newLink;
}

// pop a value off the stack
char pop(LinkPtr *topPtr) {
	LinkPtr tempPtr = (*topPtr);
	char tempChar = (*topPtr)->data;
	(*topPtr) = (*topPtr)->nextPtr;
	free(tempPtr);
	return tempChar;
}

// return the top value of the stack without popping
char stackTop(LinkPtr topPtr) {
	return topPtr->data;
}

// determine whether the stack is empty
int isEmpty(LinkPtr topPtr) {
	if (topPtr == NULL) {
		return 1;
	}
	return 0;
}

// print the stack
void printStack(LinkPtr topPtr) {
	while (topPtr->nextPtr != NULL) {
		printf("%3c", topPtr->data);
	}
}