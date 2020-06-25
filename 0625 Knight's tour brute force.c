#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int validMove(int board[SIZE][SIZE], int knight0, int knight1, int direction);
int moveKnight0(int knight0, int direction);
int moveKnight1(int knight1, int direction);
int finished(int board[SIZE][SIZE], int knight[]);
void printBoard(int board[SIZE][SIZE], int knight[], int moveCount);

int main(void) {
	
	const int TOURLIMIT = 1'000;

	srand((unsigned int)time(NULL));
	int board[SIZE][SIZE] = { 0 };
	int knight[2] = { 0 };
	board[knight[0]][knight[1]] = 1;
	int moveCount = 0;
	int tourRecord[65] = { 0 };

	// play TOURLIMIT tours
	unsigned long long tours = 0;
	for (; finished(board, knight) != 2; ++tours) {
		moveCount = 0;

		// reset board values to 0
		for (int row = 0; row < SIZE; ++row) {
			for (int col = 0; col < SIZE; ++col) {
				board[row][col] = 0;
			}
		}

		// one tour
		while (finished(board, knight) == 1) {
			int move = rand() % 8;
			if (validMove(board, knight[0], knight[1], move)) {
				++moveCount;
				knight[0] += moveKnight0(knight[0], move);
				knight[1] += moveKnight1(knight[1], move);
				++board[knight[0]][knight[1]];
			}
		}

		// record length of every finished game.  64 is a win.
		++tourRecord[moveCount];
		// printBoard(board, knight, moveCount);
	}
	puts("");
	for (int ind = 0; ind < 65; ++ind) {
		printf("tourRecord[%2d] = %d\n", ind, tourRecord[ind]);
		printf("tours = %llu\n", tours);
	}
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

int finished(int board[SIZE][SIZE], int knight[]) {

	// if knight can move, continue game
	for (int ind = 0; ind < SIZE; ++ind) {
		if (validMove(board, knight[0], knight[1], ind)) {
			return 1;
		}
	}

	// if knight can't move, but board remains open, game is lost
	for (size_t row = 0; row < SIZE; ++row) {
		for (size_t col = 0; col < SIZE; ++col) {
			if (board[row][col] == 0) {
				return 0;
			}
		}
	}
	
	// if board is covered, game is won.
	return 2;
}

void printBoard(int board[SIZE][SIZE], int knight[], int moveCount) {
	printf("\n%s%d\n", "MOVE ", moveCount);
	printf("%s\n", "  - - - - - - - -  ");
	for (size_t row = 0; row < SIZE; ++row) {
		for (size_t col = 0; col < SIZE; ++col) {
			if (col == 0) {
				printf("%s", "|");
			}
			if (knight[0] == row && knight[1] == col) {
				printf("%2s", "K");
			}
			else if (board[row][col] == 0) {
				int kBool = 0;
				for (int ind = 0; ind < SIZE && kBool == 0; ++ind) {
					if (row == knight[0] + moveKnight0(knight[0], ind) &&
						col == knight[1] + moveKnight1(knight[1], ind)) {
						printf("%2d", ind);
						++kBool;
					}
				}
				if (kBool == 0) {
					printf("%2s", " ");
				}
			}
			else {
				printf("%2s", "+");
			}
			if (col == 7) {
				printf("%2s", "|");
			}
		}
		puts("");
	}
	printf("%s\n", "  - - - - - - - -  ");
}