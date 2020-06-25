#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define QNUM 8
#define QPOS 2

void printBoard(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
void zeroQueen(int queen[QNUM][QPOS]);
void zeroBoard(int board[SIZE][SIZE]);
void printQueen(int queen[QNUM][QPOS]);
void boardRecord(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
int moveRandom(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
void moveSeq(int board[SIZE][SIZE], int queen[QNUM][QPOS], int qNum);

int main(void) {

	srand((unsigned)time(NULL));
	int board[SIZE][SIZE] = { 0 };
	// example: queen[0][0] = 2, queen[0][1] = 4.  This means queen0 is at square 2,4
	int queen[QNUM][QPOS] = { 0 };

	// random queen placement
	/*zeroQueen(queen);
	while (moveRandom(board, queen)) {
		boardRecord(board, queen);
		printBoard(board, queen);
	}
	printQueen(queen);*/

	// tries every possible sequence of queens.  This is actually a great way to get solutions.
	zeroQueen(queen);
	moveSeq(board, queen, 7);
}

// prints the board
void printBoard(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {
	for (int ind = 0; ind < 10; ++ind) {
		printf("%4s", "-");
	}
	puts("");
	for (size_t row = 0; row < SIZE; ++row) {
		for (size_t col = 0; col < SIZE; ++col) {
			if (col == 0) {
				printf("%4s", "|");
			}
			if (board[row][col] == 922) {
				printf("%4s", "Q");
			}
			else if (board[row][col] == 999) {
				printf("%4s", "+");
			}
			else if (board[row][col] > 0) {
				printf("%4d", board[row][col] - 100);
			}
			else {
				printf("%4s", " ");
			}
			if (col == 7) {
				printf("%4s", "|");
			}
		}
		puts("\n\n");
	}
	for (int ind = 0; ind < 10; ++ind) {
		printf("%4s", "-");
	}
	puts("");
}

// sets the queen positions off board range
void zeroQueen(int queen[QNUM][QPOS]) {
	for (int qNum = 0; qNum < QNUM; ++qNum) {
		for (int qPos = 0; qPos < QPOS; ++qPos) {
			queen[qNum][qPos] = 9;
		}
	}
}

void zeroBoard(int board[SIZE][SIZE]) {
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			board[row][col] = 0;
		}
	}
}

void printQueen(int queen[QNUM][QPOS]) {

	puts("\n");
	printf("%4s", "quen");
	for (int qNum = 0; qNum < QNUM; ++qNum) {
		printf("%4d", qNum);
	}
	puts("");
	for (int qPos = 0; qPos < QPOS; ++qPos) {
		for (int qNum = 0; qNum < QNUM; ++qNum) {
			if (qNum == 0) {
				if (qPos == 0) {
					printf("%4s", "row");
				}
				else if (qPos == 1) {
					printf("%4s", "col");
				}
			}
			printf("%4d", queen[qNum][qPos]);
		}
		puts("");
	}
	puts("\n");
}

int moveRandom(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {

	int minValue = 999;
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (minValue > board[row][col]) {
				minValue = board[row][col];
			}
		}
	}

	if (minValue < 922) {
		for (int qNum = 0; qNum < QNUM; ++qNum) {
			if (queen[qNum][0] > 7) {
				int row, col;
				do {
					row = rand() % 8;
					col = rand() % 8;
				} while (board[row][col] >= 922);
				queen[qNum][0] = row;
				queen[qNum][1] = col;
				return 1;
			}
		}
	}
	return 0;
}

// call with (QNUM - 1).  This is actually a recursive repair algorithm which tries every sequence of queens.  When one doesn't work, it retracts a move and chooses an alternative.
void moveSeq(int board[SIZE][SIZE], int queen[QNUM][QPOS], int qNum) {

	if (qNum == 0) {
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (board[row][col] < 922) {
					queen[qNum][0] = row;
					queen[qNum][1] = col;
					boardRecord(board, queen);

					printBoard(board, queen);
					printQueen(queen);
				}
			}
		}

		// reset queen position
		queen[qNum][0] = 9;
		queen[qNum][1] = 9;
		boardRecord(board, queen);
	}
	else {
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (board[row][col] < 922) {
					queen[qNum][0] = row;
					queen[qNum][1] = col;
					boardRecord(board, queen);

					moveSeq(board, queen, qNum - 1);
				}
			}
		}

		// reset queen position
		if (qNum < 7) {
			queen[qNum + 1][0] = 9;
			queen[qNum + 1][1] = 9;
			boardRecord(board, queen);
		}
	}
}

// assigns heuristic values to the board
void boardRecord(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {

	zeroBoard(board);

	// queen attack squares
	for (int qNum = 0; qNum < QNUM; ++qNum) {
		if (queen[qNum][0] >= 0 && queen[qNum][1] >= 0 &&
			queen[qNum][0] <= 7 && queen[qNum][1] <= 7) {
			// strait marking
			for (int bPos = 0; bPos < SIZE; ++bPos) {
				// queen row, board col
				board[queen[qNum][0]][bPos] = 999;
				// board row, queen col
				board[bPos][queen[qNum][1]] = 999;

				// north-east marking
				if (queen[qNum][0] - bPos >= 0 &&
					queen[qNum][1] + bPos <= 7) {
					board[queen[qNum][0] - bPos][queen[qNum][1] + bPos] = 999;
				}
				// south-east marking
				if (queen[qNum][0] + bPos <= 7 &&
					queen[qNum][1] + bPos <= 7) {
					board[queen[qNum][0] + bPos][queen[qNum][1] + bPos] = 999;
				}
				// south-west marking
				if (queen[qNum][0] + bPos <= 7 &&
					queen[qNum][1] - bPos >= 0) {
					board[queen[qNum][0] + bPos][queen[qNum][1] - bPos] = 999;
				}
				// north-west marking
				if (queen[qNum][0] - bPos >= 0 &&
					queen[qNum][1] - bPos >= 0) {
					board[queen[qNum][0] - bPos][queen[qNum][1] - bPos] = 999;
				}
			}
		}
	}

	// queen position squares
	for (int qNum = 0; qNum < QNUM; ++qNum) {
		if (queen[qNum][0] >= 0 && queen[qNum][1] >= 0 &&
			queen[qNum][0] <= 7 && queen[qNum][1] <= 7) {
			board[queen[qNum][0]][queen[qNum][1]] = 922;
		}
	}
}