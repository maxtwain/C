#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// The instructions ask for a letter count in words, yet they want to include ' as a letter, which it isn't.  It would be easy to include, but I am forgoing this.  This is another exmaple of the book writers not paying attention to what they are doing.

#define SENTENCECOUNT 20
#define ALPHABET 26
#define UNIQUESIZE 1000

void countLetter(char** sentence, int* letterCount);
void printLetterCount(int* letterCount);
void countWordLength(char** sentence, int* wordLength);
void printWordLength(int* wordLength);
void countUnique(char** sentence, char** uniqueWord, int* uniqueCount);
void printUnique(char** uniqueWord, int* uniqueCount);

int main(void) {
	char* sentence[SENTENCECOUNT] = { "I am never at home on Sundays.", "Abstraction is often one floor above you.", "I am counting my calories, yet I really want dessert.", "Should we start class now, or should we wait for everyone to get here ?", "She did her best to help him.", "She works two jobs to make ends meet; at least, that was her reason for not having time to join us.", "This is a Japanese doll.", "She wrote him a long letter, but he didn't read it.", "If Purple People Eaters are real... where do they find purple people to eat ?", "I checked to make sure that he was still alive.", "How was the math test ?", "I often see the time eleven eleven or twelve thirty-four on clocks.", "Last Friday in three week’s time I saw a spotted striped blue worm shake hands with a legless lizard.", "I was very proud of my nickname throughout high school but today I couldn’t be any different to what my nickname was.", "Christmas is coming.", "He turned in the research paper on Friday; otherwise, he would have not passed the class.", "We have never been to Asia, nor have we visited Africa.", "It was getting dark, and we weren’t there yet.", "Writing a list of random sentences is harder than I initially thought it would be.", "Where do random thoughts come from ?" };

	int letterCount[ALPHABET] = { 0 };
	countLetter(sentence, letterCount);
	printLetterCount(letterCount);
	puts("\n");

	int wordLength[20] = { 0 };
	countWordLength(sentence, wordLength);
	printWordLength(wordLength);
	puts("\n");

	char* uniqueWord[UNIQUESIZE] = { "" };
	int uniqueCount[UNIQUESIZE] = { 0 };
	countUnique(sentence, uniqueWord, uniqueCount);
	printUnique(uniqueWord, uniqueCount);
	puts("\n");
}

void countLetter(char** sentence, int* letterCount) {
	for (int i0 = 0; i0 < SENTENCECOUNT; ++i0) {
		for (int i1 = 0; sentence[i0][i1] != '\0'; ++i1) {
			if (sentence[i0][i1] >= 65 && sentence[i0][i1] <= 90) {
				++letterCount[sentence[i0][i1] - 65];
			}
			else if (sentence[i0][i1] >= 97 && sentence[i0][i1] <= 122) {
				++letterCount[sentence[i0][i1] - 97];
			}
		}
	}
}

void printLetterCount(int* letterCount) {
	puts("Letter Count");
	printf("%8s", "Letter:");
	for (int i = 65; i < 78; ++i) {
		printf("%4c", (char)i);
	}
	printf("\n%8s", "Count:");
	for (int i = 0; i < ALPHABET / 2; ++i) {
		printf("%4d", letterCount[i]);
	}
	printf("\n\n%8s", "Letter:");
	for (int i = 78; i <= 90; ++i) {
		printf("%4c", (char)i);
	}
	printf("\n%8s", "Count:");
	for (int i = ALPHABET / 2; i < ALPHABET; ++i) {
		printf("%4d", letterCount[i]);
	}
	puts("");
}

void countWordLength(char** sentence, int* wordLength) {
	int length = 0;
	for (int i0 = 0; i0 < SENTENCECOUNT; ++i0) {
		length = 0;
		for (int i1 = 0; sentence[i0][i1] != '\0'; ++i1) {
			if (length > 19) {
				++wordLength[19];
			}
			// if A to Z or a to z
			else if ((sentence[i0][i1] >= 65 && sentence[i0][i1] <= 90) || 
				(sentence[i0][i1] >= 97 && sentence[i0][i1] <= 122)) {
				++length;
			}
			// skip hyphen or aposterphe
			else if (sentence[i0][i1] != 39 || sentence[i0][i1] != 45) {
				++wordLength[length];
				length = 0;
			}
		}
	}
}

void printWordLength(int* wordLength) {
	puts("Lengths Of Words");
	printf("%8s", "Length:");
	for (int i0 = 1; i0 < 10; ++i0) {
		printf("%4d", i0);
	}
	printf("\n%8s", "Count:");
	for (int i0 = 1; i0 < 10; ++i0) {
		printf("%4d", wordLength[i0]);
	}
	puts("\n");
	printf("%8s", "Length:");
	for (int i0 = 10; i0 < 19; ++i0) {
		printf("%4d", i0);
	}
	printf("%4s", "19+");
	printf("\n%8s", "Count:");
	for (int i0 = 10; i0 < 20; ++i0) {
		printf("%4d", wordLength[i0]);
	}
	puts("");
}

void countUnique(char** sentence, char** uniqueWord, int* uniqueCount) {
	int maxUIndex = 0;
	for (int sent = 0; sent < SENTENCECOUNT; ++sent) {
		char* sentExtract = malloc(strlen(sentence[sent]) * sizeof(char));
		strcpy(sentExtract, sentence[sent]);
		char* tokenPtr = strtok(sentExtract, " ?.,;");
		while (tokenPtr != NULL) {
			tokenPtr[0] = tolower(tokenPtr[0]);
			// search for tokenPtr inside uniqueWord array
			int found = 0;
			for (int uIndex = 0; uIndex < maxUIndex && uIndex < UNIQUESIZE; ++uIndex) {
				if (strcmp(tokenPtr, uniqueWord[uIndex]) == 0) {
					++uniqueCount[uIndex];
					found = 1;
					uIndex = maxUIndex;
				}
			}
			// make new unique entry
			if (found == 0) {
				uniqueWord[maxUIndex] = tokenPtr;
				++uniqueCount[maxUIndex];
				++maxUIndex;
			}
			tokenPtr = strtok(NULL, " ?.,;");
		}
	}
}

void printUnique(char** uniqueWord, int* uniqueCount) {
	puts("Word Frequency");
	printf("%4s %-12s%4s %-12s%4s %-12s%6s %s\n", "freq", "word", "freq", "word", "freq", "word", "freq", "word");
	for (int i0 = 0; uniqueWord[i0] != '\0'; ++i0) {
		if (i0 > 0 && i0 % 4 == 0) {
			puts("");
		}
		printf("%4d %-12s", uniqueCount[i0], uniqueWord[i0]);
	}
	puts("");
}