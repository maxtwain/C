#include <stdio.h>

// This program works fine, however I believe the algorithm is flawed.  The best squares to place a queen are often not those with the lowest conflict.  I have gone over the results again and again, and each time I see my program correctly choose the square with least conflict, yet from the solutions displayed online I can see it was the wrong move.  If I manually enter in the first three correct moves, only then the program can finish with all eight.

#define SIZE 8
#define QNUM 8
#define QPOS 2

void heurScore(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
int secondPass(int board[SIZE][SIZE], int row, int col);
void printBoard(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
void initQueen(int queen[QNUM][QPOS]);
void initBoard2(int board2[SIZE][SIZE]);
int moveQueen(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
int moveQueen2(int board[SIZE][SIZE], int queen[QNUM][QPOS]);
void printQueen(int queen[QNUM][QPOS]);

int main(void) {

	int board[SIZE][SIZE] = { 0 };
	// example: queen[0][0] = 2, queen[0][1] = 4.  This means queen0 is at square 2,4
	int queen[QNUM][QPOS] = { 0 };

	initQueen(queen);
	//queen[0][0] = 0;
	//queen[0][1] = 0;
	//queen[1][0] = 1;
	//queen[1][1] = 6;
	//queen[2][0] = 2;
	//queen[2][1] = 4;
	heurScore(board, queen);
	printBoard(board, queen);
	while (moveQueen2(board, queen)) {
		heurScore(board, queen);
		printBoard(board, queen);
	}
	printQueen(queen);
}

// assigns heuristic values to the board
void heurScore(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {

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

	// heuristic scores
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (board[row][col] < 922) {
				board[row][col] = 100;
				for (int pos = 1; pos < SIZE; ++pos) {

					// north, north-west, north-east
					if (row - pos >= 0) {
						if (board[row - pos][col] < 922) {
							++board[row][col];
						}
						if (col - pos >= 0) {
							if (board[row - pos][col - pos] < 922) {
								++board[row][col];
							}
						}
						if (col + pos <= 7) {
							if (board[row - pos][col + pos] < 922) {
								++board[row][col];
							}
						}
					}

					// south, south-west, south-east
					if (row + pos <= 7) {
						if (board[row + pos][col] < 922) {
							++board[row][col];
						}
						if (col - pos >= 0) {
							if (board[row + pos][col - pos] < 922) {
								++board[row][col];
							}
						}
						if (col + pos <= 7) {
							if (board[row + pos][col + pos] < 922) {
								++board[row][col];
							}
						}
					}

					// west, east
					if (col - pos >= 0) {
						if (board[row][col - pos] < 922) {
							++board[row][col];
						}
					}
					if (col + pos <= 7) {
						if (board[row][col + pos] < 922) {
							++board[row][col];
						}
					}
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

int secondPass(int board[SIZE][SIZE], int row, int col) {

	// setting sum to 1 initially allows board[row][col] to count itself.  Otherwise the last move will be 0 and be unable to place a queen
	int sum = 1;
	for (int pos = 1; pos < SIZE; ++pos) {

		// north, north-west, north-east
		if (row - pos >= 0) {
			if (board[row - pos][col] < 922) {
				sum += board[row - pos][col] - 100;
			}
			if (col - pos >= 0) {
				if (board[row - pos][col - pos] < 922) {
					sum += board[row - pos][col - pos] - 100;
				}
			}
			if (col + pos <= 7) {
				if (board[row - pos][col + pos] < 922) {
					sum += board[row - pos][col + pos] - 100;
				}
			}
		}

		// south, south-west, south-east
		if (row + pos <= 7) {
			if (board[row + pos][col] < 922) {
				sum += board[row + pos][col] - 100;
			}
			if (col - pos >= 0) {
				if (board[row + pos][col - pos] < 922) {
					sum += board[row + pos][col - pos] - 100;
				}
			}
			if (col + pos <= 7) {
				if (board[row + pos][col + pos] < 922) {
					sum += board[row + pos][col + pos] - 100;
				}
			}
		}

		// west, east
		if (col - pos >= 0) {
			if (board[row][col - pos] < 922) {
				sum += board[row][col - pos] - 100;
			}
		}
		if (col + pos <= 7) {
			if (board[row][col + pos] < 922) {
				sum += board[row][col + pos] - 100;
			}
		}
	}
	return sum;
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
void initQueen(int queen[QNUM][QPOS]) {
	for (int qNum = 0; qNum < QNUM; ++qNum) {
		for (int qPos = 0; qPos < QPOS; ++qPos) {
			queen[qNum][qPos] = 9;
		}
	}
}

void initBoard2(int board2[SIZE][SIZE]) {
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			board2[row][col] = 0;
		}
	}
}

// move an available queen to minValue square
int moveQueen(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {

	int minValue = 999;
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (minValue > board[row][col]) {
				minValue = board[row][col];
			}
		}
	}

	if (minValue < 922) {

		// a second board must be used so a summed value doesn't sum another while in the process of finding the sums
		int board2[SIZE][SIZE] = { 0 };
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (board[row][col] == minValue) {
					board2[row][col] = secondPass(board, row, col);
				}
			}
		}

		// find minValue of board2
		minValue = 999;
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (board2[row][col] > 0 && minValue > board2[row][col]) {
					minValue = board2[row][col];
				}
			}
		}

		// move queen
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (minValue == board2[row][col]) {
					for (int qNum = 0; qNum < QNUM; ++qNum) {
						if (queen[qNum][0] > 7) {
							queen[qNum][0] = row;
							queen[qNum][1] = col;
							return 1;
						}
					}
				}
			}
		}
	}
	
	return 0;
}

// alternate version of moveQueen() which discards all first pass values instead of discarding only non-min values
int moveQueen2(int board[SIZE][SIZE], int queen[QNUM][QPOS]) {

	// a second board must be used so a summed value doesn't sum another while in the process of finding the sums
	int board2[SIZE][SIZE] = { 0 };
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (board[row][col] < 922) {
				board2[row][col] = secondPass(board, row, col);
			}
		}
	}

	// find minValue of board2
	int minValue = 999;
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			if (board2[row][col] > 0 && minValue > board2[row][col]) {
				minValue = board2[row][col];
			}
		}
	}

	// move queen
	if (minValue < 922) {
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				if (minValue == board2[row][col]) {
					for (int qNum = 0; qNum < QNUM; ++qNum) {
						if (queen[qNum][0] > 7) {
							queen[qNum][0] = row;
							queen[qNum][1] = col;
							return 1;
						}
					}
				}
			}
		}
	}

	return 0;
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