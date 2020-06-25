#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

#define SIZE 8
#define PI 3.14159

int moveMode3(int board[SIZE][SIZE], int knight[], int mode);
int validMove(int board[SIZE][SIZE], int knight0, int knight1, int direction);
int sumEight(int board[SIZE][SIZE], int knight0, int knight1, int direction);
int moveKnight0(int knight0, int direction);
int moveKnight1(int knight1, int direction);

int main(void) {

	srand((unsigned int)time(NULL));
	int board[SIZE][SIZE] = { 0 };
	int heuristic[SIZE][SIZE] = { 0 };
	int knight[2] = { 0 };
	board[knight[0]][knight[1]] = 1;
	int moveCount = 0;

	int userEntry = 0;
	printf("%s%-15s%s\n%15s%s\n%15s%s\n", "At any time type -1 to quit\n", "Select mode.", "1 for manual.", " ", "2 for heuristic with random on ties", " ", "3 for second degree heuristic");
	scanf_s("%d", &userEntry);
	switch (userEntry) {
	case 1:
		printf("%s", "Enter sequential knight moves by clock hands.\n");
		while (userEntry != -1) {
			printBoard(board, knight, moveCount);
			if (finished(board, knight) == 1) {
				scanf_s("%d", &userEntry);
				if (move(board, knight, userEntry) == 1) {
					++moveCount;
				}
			}
			else if (finished(board, knight) == 0) {
				printf("%s", "NO MOVES LEFT!  YOU LOOSE!\n\n");
				userEntry = -1;
			}
			else {
				printf("%s", "CONGRATULATIONS!YOU WON!\n\n");
				userEntry = -1;
			}
		}
		break;

	case 2: {
		int wins = 0;
		int nextMoves[SIZE] = { 0 };
		for (int offset = 0; offset < 64; ++offset) {
			moveCount = 0;
			knight[0] += offset / 8;
			knight[1] += offset % 8;
			while (finished(board, knight) == 1) {
				// reset nextMoves values to 0 so the next set may be calculated
				for (size_t ind = 0; ind < SIZE; ++ind) {
					nextMoves[ind] = 0;
				}

				createHeuristic(heuristic, board, knight);
				nextHeuristicMove(heuristic, board, knight[0], knight[1], nextMoves);

				if (move(board, knight, pickHeuristicMove(nextMoves))) {
					++moveCount;
				}
			}
			if (finished(board, knight) == 2) {
				++wins;
			}
		}
		printf("\n%s%d\n", "64 simulations finished.  Wins = ", wins);
	}
			break;
			// The third mode doesn't work, even though it doesn't need to.  Mode two works every time and doesn't need improvement.
	case 3: {
		int wins = 0;
		int closedTour = 0;
		for (int offset = 0; offset < 64; ++offset) {
			moveCount = 0;
			knight[0] += offset / 8;
			knight[1] += offset % 8;

			// excessive functionality required by 6.29 description
			int startPos[2];
			startPos[0] = knight[0];
			startPos[1] = knight[1];
			
			while (finished(board, knight) == 1) {

				if (moveMode3(board, knight, userEntry)) {
					++moveCount;
				}
			}
			if (finished(board, knight) == 2) {
				++wins;
			}

			if (closedTourCheck(knight, startPos)) {
				++closedTour;
			}
		}
		printf("\n64 simulations finished.\nWins = %d\tClosed Tours = %d\n", wins, closedTour);
	}
			break;
	}
}

// picks a move to make
int moveMode3(int board[SIZE][SIZE], int knight[], int mode) {

	if (mode == 1) {
		int userEntry = 13;
		scanf_s("%d", &userEntry);
		if (validMove(board, knight[0], knight[1], userEntry)) {
			knight[0] += moveKnight0(knight[0], userEntry);
			knight[1] += moveKnight1(knight[1], userEntry);
			++board[knight[0]][knight[1]];
			return 1;
		}
		else {
			return 0;
		}
	}

	// holds move scores for eight directions
	int move[8] = { 0 };

	// saves the score for valid moves in each direction
	for (int ind = 0; ind < SIZE; ++ind) {
		if (validMove(board, knight[0], knight[1], ind)) {
			move[ind] += sumEight(board, knight[0], knight[1], ind);
		}
		else {
			move[ind] = 99;
		}
	}

	// find the smallest heuristic value of the full move set
	int smallValue = move[0];
	for (int ind = 1; ind < SIZE; ++ind) {
		if (smallValue > move[ind]) {
			smallValue = move[ind];
		}
	}

	if (mode == 3) {
		// set all large values beyond the ability of smallest to catch them in a second calculation
		// still required: move[], knight0, knight1, smallValue
		for (int ind = 0; ind < SIZE; ++ind) {
			if (move[ind] > smallValue) {
				move[ind] = 99;
			}
		}

		// count the number of moves with the same smallest value
		// still required: move[], knight0, knight1, smallValue, smallCount
		int smallCount = 0;
		for (int ind = 0; ind < SIZE; ++ind) {
			if (move[ind] == smallValue) {
				++smallCount;
			}
		}

		// if there are multiple small value moves, add to them the smallest of their second degree
		// still required: move[], knight0, knight1, smallValue, smallCount
		if (smallCount > 1) {
			int min = 99;
			// move direction index
			for (int ind = 0; ind < SIZE; ++ind) {
				if (move[ind] == smallValue) {
					// satellite index
					for (int ind2 = 0; ind2 < SIZE; ++ind2) {
						// if satellite can be moved to
						if (validMove(board,
							knight[0] + moveKnight0(knight[0], ind),
							knight[1] + moveKnight1(knight[1], ind),
							ind2)) {
							// find min satellite
							if (min > sumEight(board,
								knight[0] + moveKnight0(knight[0], ind),
								knight[1] + moveKnight1(knight[1], ind),
								ind2)) {
								min = sumEight(board,
									knight[0] + moveKnight0(knight[0], ind),
									knight[1] + moveKnight1(knight[1], ind),
									ind2);
							}
						}
					}
					move[ind] += min;
				}
			}
		}

		// find the smallest heuristic value of the move set after second pass
		// still required: move[], smallValue
		smallValue = move[0];
		for (int ind = 1; ind < SIZE; ++ind) {
			if (smallValue > move[ind]) {
				smallValue = move[ind];
			}
		}
	}

	// return after moving to smallest heuristic value
	// still required: move[], smallValue
	for (int ind = 0; ind < SIZE; ++ind) {
		if (smallValue == move[ind]) {
			knight[0] += moveKnight0(knight[0], ind);
			knight[1] += moveKnight1(knight[1], ind);
			++board[knight[0]][knight[1]];
			return 1;
		}
	}
	return 0;
}

// checks valid position at (knight0 + direction, knight1 + direction)
int validMove(int board[SIZE][SIZE], int knight0, int knight1, int direction) {

	knight0 += moveKnight0(knight0, direction);
	knight1 += moveKnight1(knight1, direction);

	if (knight0 > 7 || knight0 < 0 || knight1 > 7 || knight1 < 0) {
		return 0;
	}
	if (board[knight0][knight1] > 0) {
		return 0;
	}
	return 1;
}

// returns the sum of valid moves from (knight0 + direction, knight1 + direction)
int sumEight(int board[SIZE][SIZE], int knight0, int knight1, int direction) {

	int moveCounter = 0;

	// position to be summed
	knight0 += moveKnight0(knight0, direction);
	knight1 += moveKnight1(knight1, direction);

	// sum moves at position
	for (int ind = 0; ind < SIZE; ++ind) {
		if (validMove(board, knight0, knight1, ind)) {
			++moveCounter;
		}
	}

	return moveCounter;
}

// moves knight0 in direction
int moveKnight0(int knight0, int direction) {

	switch (direction) {
	case 0:
		return -2;
	case 1:
		return -1;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 2;
	case 5:
		return 1;
	case 6:
		return -1;
	case 7:
		return -2;
	}
	return 0;
}

// moves knight1 in direction
int moveKnight1(int knight1, int direction) {
	switch (direction) {
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 2;
	case 3:
		return 1;
	case 4:
		return -1;
	case 5:
		return -2;
	case 6:
		return -2;
	case 7:
		return -1;
	}
	return 0;
}