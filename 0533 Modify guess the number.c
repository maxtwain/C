#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand((unsigned int)time(NULL));

	int num = 1 + rand() % 1'000, guessCount = 0;
	printf("%s\n%s\n%s", "I have a number between 1 and 1'000.", "Can you guess my number?", "Please type your first guess: ");
	char c = '0';
	for (char playAgain = 'y'; playAgain == 'y'; c = getchar()) {
		for (int guess = 0; guess != num;) {
			scanf_s("%d", &guess);
			if (num > guess) printf("%s", "Too low.  Try again: ");
			else if (num < guess) printf("%s", "Too high.  Try again: ");
			++guessCount;
		}
		if (guessCount <= 10) puts("Either you know the secret or you got lucky!");
		if (guessCount == 10) puts("Ahah!  You know the secret!");
		else if (guessCount > 10) puts("You should be able to do better!");

		printf("%s", "Would you like to play again (y or n)? ");
		// don't use scanf_s with char types yet
		// scanf_s will not read this char
		// getchar() will read a char from stdin, but it will not open buffer for writing like scanf will
		scanf("%c", &playAgain);
		// \n remains in stdin after %c read
	}
	puts("");
}

