#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype
unsigned int oneGame();

int main(void)
{
	int bankBalance = 1000;
	while ( bankBalance > 0) {
		printf("Bank balance: $%d\nEnter wager: $", bankBalance);
		int wager;
		scanf_s("%d", &wager);
		while (wager > bankBalance) {
			printf("%s", "Invalid entry.  Wager: $");
			scanf_s("%d", &wager);
		}
		if (wager == 0) break;

		int chatter = rand() % 3;
		if (chatter == 0) printf("%s\n", "Oh, you're going for broke, huh?");
		else if (chatter == 1) printf("%s\n", "Aw cmon, take a chance!");
		else printf("%s\n", "You're up big.  Now's the time to cash in your chips!");
		
		if (oneGame()) bankBalance += wager;
		else bankBalance -= wager;
	}
	if (bankBalance == 0) {
		printf("%s\n", "Sorry, You busted!");
	}
}

// roll dice, calculate sum and display results
int rollDice(void)
{
	int die1 = 1 + (rand() % 6); // pick random die1 value
	int die2 = 1 + (rand() % 6); // pick random die2 value

								 // display results of this roll
	printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
	return die1 + die2; // return sum of dice
}

unsigned int oneGame() {
	// randomize random number generator using current time
	srand((unsigned int)time(NULL));

	int myPoint; // player must make this point to win
	enum Status gameStatus; // can contain CONTINUE, WON, or LOST
	int sum = rollDice(); // first roll of the dice

						  // determine game status based on sum of dice
	switch (sum) {

		// win on first roll
	case 7: // 7 is a winner
	case 11: // 11 is a winner          
		gameStatus = WON;
		break;

		// lose on first roll
	case 2: // 2 is a loser
	case 3: // 3 is a loser
	case 12: // 12 is a loser
		gameStatus = LOST;
		break;

		// remember point
	default:
		gameStatus = CONTINUE; // player should keep rolling
		myPoint = sum; // remember the point
		printf("Point is %d\n", myPoint);
		break; // optional
	}

	// while game not complete
	while (CONTINUE == gameStatus) { // player should keep rolling
		sum = rollDice(); // roll dice again

						  // determine game status
		if (sum == myPoint) { // win by making point
			gameStatus = WON;
		}
		else {
			if (7 == sum) { // lose by rolling 7
				gameStatus = LOST;
			}
		}
	}

	// display won or lost message
	if (WON == gameStatus) { // did player win?
		puts("Player wins\n");
		return 1;
	}
	else { // player lost
		puts("Player loses\n");
		return 0;
	}
}