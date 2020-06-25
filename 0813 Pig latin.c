#include <stdio.h>
#include <string.h>

#define PSIZE 500

void printLatinWord(char word[30]);

int main(void) {
	char word[30] = "burn";
	char phrase[PSIZE] = "";

	puts("Enter a phrase.");
	fgets(phrase, PSIZE, stdin);
	phrase[strlen(phrase) - 1] = '\0';
	printf("%s was entered.\n", phrase);
	
	char* tPtr = strtok(phrase, " ");
	while (tPtr != NULL) {
		strcpy(word, tPtr);
		printLatinWord(word);
		tPtr = strtok(NULL, " ");
	}
	puts("\n");
}

void printLatinWord(char word[30]) {
	strncat(word, word, 1);
	memmove(word, word + 1, strlen(word));
	strcat(word, "ay");
	printf("%s ", word);
}