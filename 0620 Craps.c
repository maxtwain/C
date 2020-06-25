#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTALGAMES 1'000

int rollDice();

int main(void) {
	srand((unsigned int)time(NULL));

	/*  record[0][0] = losses for round 1.
		record[0][1] = wins for round 1.
		record[19][1] = wins for round 20.
		record[20][1] = wins over 20 rounds
	*/
	int record[22][2] = { 0 };
	int comeOut, roll, gameLength = 0;
	size_t round;
	for (int games = 0; games < TOTALGAMES; ++games) {
		
		// point roll
		comeOut = rollDice();
		// reset variable outiside roll range
		roll = 13;
		// first round again
		round = 0;

		// first roll win
		if (comeOut == 7 || comeOut == 11)
			++record[round][1];
		// first roll loss
		else if (comeOut == 2 || comeOut == 3 || comeOut == 12)
			++record[round][0];
		// roll to match point
		else {
			while (roll != comeOut && roll != 7) {
				roll = rollDice();
				++round;
			}
			// 20+ rounds held in same memory location
			if (round > 19) {
				gameLength += round;
				round = 20;
			}
			// record point win or loose
			if (roll == 7)
				++record[round][0];
			else if (roll == comeOut)
				++record[round][1];
		}
	}

	puts("Roll\tWins\tLosses");
	for (round = 0; round < 20; ++round)
		printf("%u\t%d\t%d\n", round + 1, record[round][1], record[round][0]);
	printf("20+\t%d\t%d\n\n", record[round][1], record[round][0]);

	int wins = 0;
	for (round = 0; round < 21; ++round)
		wins += record[round][1];
	printf("Win percentage = %4.2f\n", (float)wins / TOTALGAMES);

	for (round = 0; round < 21; ++round)
		for (size_t col = 0; col < 2; ++col)
			gameLength += (round + 1) * record[round][col];
	printf("Average game length = %.2lf rolls\n\n", (double)gameLength / TOTALGAMES);
}

int rollDice() {
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	return die1 + die2;
}