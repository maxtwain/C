#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void clearSent(char sentence[40]);

// article, noun, verb, prep, article, noun
// 4 + 4 + 7 + 5 + 4 + 4 + 6

int main(void) {
	srand((unsigned int)time(NULL));

	char* article[5] = { "the", "a", "one", "some", "any" };
	char* noun[5] = { "boy", "girl", "dog", "town", "car" };
	char* verb[5] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[5] = { "to", "from", "over", "under", "on" };
	char sentence[40] = "";

	for (int count = 0; count < 20; ++count) {
		strcpy(sentence, article[rand() % 5]);
		sentence[0] = toupper(sentence[0]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, verb[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, preposition[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, article[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand() % 5]);
		strcat(sentence, ".  ");
		printf("%s", sentence);
	}
	puts("\n");
}

void clearSent(char sentence[40]) {
	for (char* ptr = sentence; *ptr != '\0'; ++ptr) {
		*ptr = '\0';
	}
}