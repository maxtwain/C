#include <stdio.h>
#include <string.h>

#define SIZE 500

void printReverse(char* ptr);

int main(void) {
	puts("Enter a sentence.");
	char sentence[SIZE] = "";
	fgets(sentence, SIZE, stdin);
	sentence[strlen(sentence) - 1] = '\0';

	char* ptr = strtok(sentence, " .");
	printReverse(ptr);
	puts("\n");
}

void printReverse(char* ptr) {
	char* word = ptr;

	if (ptr == '\0') {
		return;
	}
	else {
		ptr = strtok(NULL, " .");
		printReverse(ptr);
		printf("%s ", word);
	}
}