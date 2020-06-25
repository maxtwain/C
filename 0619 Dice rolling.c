#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll();

int main(void) {
	srand((unsigned int)time(NULL));
	
	int record[11] = { 0 };

	for (int rolls = 0; rolls < 36'000; ++rolls) {
		++record[roll() - 2];
	}

	for (size_t index = 0; index < 11; ++index) {
		printf("Rolls of %02u:\t%4d\n", index + 2, record[index]);
	}
}

int roll() {
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	return die1 + die2;
}