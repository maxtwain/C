#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearSent(char sentence[40]);

// article, noun, verb, prep, article, noun
// 4 + 4 + 7 + 5 + 4 + 4 + 6

int main(void) {
	srand((unsigned int)time(NULL));

	char* article[5] = { "the", "a", "one", "some", "any" };
	char* noun[5][3] = { {"tractor", "actor", "factor"}, {"bear", "ware", "heir"},{"moon", "boon", "dune"}, {"rock", "stock", "dock"}, {"key", "tea", "knee"} };
	char* verb[5] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[5] = { "to", "from", "over", "under", "on" };
	char sentence[40] = "";

	int rTrip = rand() % 5;
	int rPair = rand() % 5;
	while(rTrip == rPair) {
		rPair = rand() % 5;
	}

	for (int count = 0; count < 5; ++count) {
		strcpy(sentence, article[rand() % 5]);
		sentence[0] = toupper(sentence[0]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand() % 5][rand() % 3]);
		strcat(sentence, " ");
		strcat(sentence, verb[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, preposition[rand() % 5]);
		strcat(sentence, " ");
		strcat(sentence, article[rand() % 5]);
		strcat(sentence, " ");

		switch (count) {
		case 0:
			strcat(sentence, noun[rTrip][0]);
			break;
		case 1:
			strcat(sentence, noun[rTrip][1]);
			break;
		case 2:
			strcat(sentence, noun[rPair][0]);
			break;
		case 3:
			strcat(sentence, noun[rPair][1 + rand() % 2]);
			break;
		case 4:
			strcat(sentence, noun[rTrip][2]);
		}

		strcat(sentence, ".");
		printf("%s\n", sentence);
	}
	puts("\n");
}

void clearSent(char sentence[40]) {
	for (char* ptr = sentence; *ptr != '\0'; ++ptr) {
		*ptr = '\0';
	}
}