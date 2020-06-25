#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MSIZE 12



void snakeHeadBacktrack(int maze[MSIZE][MSIZE]);
void fillInWalls(int maze[MSIZE][MSIZE]);
void entryExit(int maze[MSIZE][MSIZE]);
void listBacktrack(int cellList[MSIZE * MSIZE][2]);
void advanceList(int cellList[MSIZE * MSIZE][2], int facing);
void recordCell(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2]);
int moveCount(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2]);
int validMove(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2], int facing);
int listIndex(int cellList[MSIZE * MSIZE][2]);
void outerWalls(int maze[MSIZE][MSIZE]);
void negCellList(int cellList[MSIZE * MSIZE][2]);
void negMaze(int maze[MSIZE][MSIZE]);
void randStart(int cellList[MSIZE * MSIZE][2]);
void printMaze(int maze[MSIZE][MSIZE]);

/*
within the 2D array maze:
	if maze[row][col] = -1, this is an unmarked cell.
	if maze[row][col] = 0, this is a wall.
	if maze[row][col] = 1, this is a path.
*/
int main(void) {
	srand((unsigned int)time(NULL));
	int maze[MSIZE][MSIZE] = { 0 };
	negMaze(maze);
	outerWalls(maze);

	snakeHeadBacktrack(maze);
	printMaze(maze);
	
	
}

void snakeHeadBacktrack(int maze[MSIZE][MSIZE]) {
	
	// initialization
	int cellList[MSIZE * MSIZE][2] = { 0 };
	negCellList(cellList);
	randStart(cellList);
	// facing (0 = north, 1 = east, 2 = south, 3 = west)
	int facing = rand() % 4;
	while (!validMove(maze, cellList, facing)) {
		facing = rand() % 4;
	}
	recordCell(maze, cellList);

	// while cellList contains elements, maze is unfinished
	while (listIndex(cellList) > -1) {
		if (moveCount(maze, cellList)) {
			facing = rand() % 4;
			while (!validMove(maze, cellList, facing)) {
				facing = rand() % 4;
			}
			advanceList(cellList, facing);
			recordCell(maze, cellList);
		}
		else {
			if (listIndex(cellList) > -1) {
				listBacktrack(cellList);
			}
		}
	}
	fillInWalls(maze);
	entryExit(maze);
}

void entryExit(int maze[MSIZE][MSIZE]) {
	int entCount = 0;
	int exitCount = 0;
	for (int row = 1; row < MSIZE - 2; ++row) {
		if (maze[row][1] == 1) {
			++entCount;
		}
		if (maze[row][MSIZE - 2] == 1) {
			++exitCount;
		}
	}
	int entRand = rand() % entCount;
	int exitRand = rand() % exitCount;
	int entry = 0;
	int exit = 0;

	for (int row = 1; row < MSIZE - 2; ++row) {
		if (maze[row][1] == 1 && entRand > -1) {
			entry = row;
			--entRand;
		}
		if (maze[row][MSIZE - 2] == 1 && exitRand > -1) {
			exit = row;
			--exitRand;
		}
	}
	
	maze[entry][0] = 1;
	maze[exit][MSIZE - 1] = 1;
}

void fillInWalls(int maze[MSIZE][MSIZE]) {
	for (int row = 1; row < MSIZE - 1; ++row) {
		for (int col = 1; col < MSIZE - 1; ++col) {
			if (maze[row][col] == -1) {
				maze[row][col] = 0;
			}
		}
	}
}

void listBacktrack(int cellList[MSIZE * MSIZE][2]) {
	int index = listIndex(cellList);

	cellList[index][0] = -1;
	cellList[index][1] = -1;
}

void advanceList(int cellList[MSIZE * MSIZE][2], int facing) {
	int index = listIndex(cellList);
	int row = cellList[index][0];
	int col = cellList[index][1];

	switch (facing) {
	case 0:
		--row;
		break;
	case 1:
		++col;
		break;
	case 2:
		++row;
		break;
	case 3:
		--col;
	}
	
	cellList[index + 1][0] = row;
	cellList[index + 1][1] = col;
}

void recordCell(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2]) {

	int row = cellList[listIndex(cellList)][0];
	int col = cellList[listIndex(cellList)][1];

	maze[row][col] = 1;
}

// counts the number of valid moves from a cell
int moveCount(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2]) {
	int count = 0;
	for (int facing = 0; facing < 4; ++facing) {
		if (validMove(maze, cellList, facing)) {
			++count;
		}
	}
	return count;
}

// checks to see if advancing one cell in the facing direction is a valid move.
// first, the prospective cell is checked to make sure it is not a path or a wall.
// second, the three neighbors are checked to make sure they are not paths.
// this second check improves the quality of the maze by making backtracking the only way intersections are formed.
// also, it is assumed diagonal paths are not traversable.  This is a part of the book instructions.
// if diagonals are deemed distasteful, the two aditional corners could be checked as well.
int validMove(int maze[MSIZE][MSIZE], int cellList[MSIZE * MSIZE][2], int facing) {
	
	int row = cellList[listIndex(cellList)][0];
	int col = cellList[listIndex(cellList)][1];

	switch (facing) {
	case 0:
		// prospective check
		if (maze[row - 1][col] == -1) {
			// neighbor check
			if (maze[row - 1][col - 1] != 1 && maze[row - 1][col + 1] != 1 && maze[row - 2][col] != 1) {
				// potential additional corner check would go here.

				return 1;
			}
		}
		break;
	case 1:
		if (maze[row][col + 1] == -1) {
			if (maze[row - 1][col + 1] != 1 && maze[row + 1][col + 1] != 1 && maze[row][col + 2] != 1) {
				return 1;
			}
		}
		break;
	case 2:
		if (maze[row + 1][col] == -1) {
			if (maze[row + 1][col - 1] != 1 && maze[row + 1][col + 1] != 1 && maze[row + 2][col] != 1) {
				return 1;
			}
		}
		break;
	case 3:
		if (maze[row][col - 1] == -1) {
			if (maze[row - 1][col - 1] != 1 && maze[row + 1][col - 1] != 1 && maze[row][col - 2] != 1) {
				return 1;
			}
		}
	}
	return 0;
}

// returns the index of the last cellList element.
// *** Warning *** can equal -1
int listIndex(int cellList[MSIZE * MSIZE][2]) {
	int size = 0;
	while (cellList[size][0] > -1) {
		++size;
	}
	return size - 1;
}

// creates outer walls on the maze
void outerWalls(int maze[MSIZE][MSIZE]) {
	// row = 0 and MSIZE - 1
	for (int col = 0; col < MSIZE; ++col) {
		maze[0][col] = 0;
		maze[MSIZE - 1][col] = 0;
	}

	// col = 0 and MSIZE - 1
	for (int row = 0; row < MSIZE; ++row) {
		maze[row][0] = 0;
		maze[row][MSIZE - 1] = 0;
	}
}

void negCellList(int cellList[MSIZE * MSIZE][2]) {
	for (int row = 0; row < MSIZE * MSIZE; ++row) {
		for (int col = 0; col < 2; ++col) {
			cellList[row][col] = -1;
		}
	}
}

void negMaze(int maze[MSIZE][MSIZE]) {
	for (int row = 0; row < MSIZE; ++row) {
		for (int col = 0; col < MSIZE; ++col) {
			maze[row][col] = -1;
		}
	}
}

// enters a random row and col into the start of cellList.
void randStart(int cellList[MSIZE * MSIZE][2]) {
	cellList[0][0] = 1 + rand() % (MSIZE - 2);
	cellList[0][1] = 1 + rand() % (MSIZE - 2);
}

void printMaze(int maze[MSIZE][MSIZE]) {
	for (int row = 0; row < MSIZE; ++row) {
		for (int col = 0; col < MSIZE; ++col) {
			if (maze[row][col] == 0) {
				printf("%s", "#");
			}
			else {
				printf("%s", ".");
			}
			printf("%s", " ");
		}
		puts("");
	}
	puts("");
}

