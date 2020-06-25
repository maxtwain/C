#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int mWidthQuery();
int mHeightQuery();
void initMaze(int** maze, int height, int width);
void outerWalls(int** maze, int height, int width);
void backtrackMaze(int** maze, int height, int width);
void initCellList(int** cellList, int height, int width);
void entryExit(int** maze, int height, int width);
void fillInWalls(int** maze, int height, int width);
void listBacktrack(int** cellList);
void advanceList(int** cellList, int facing);
void recordCell(int** maze, int** cellList);
int moveCount(int** maze, int** cellList);
int validPath(int** maze, int** cellList, int facing);
int listIndex(int** cellList);
void randStart(int** cellList, int height, int width);

void solveMaze(int** maze, int height, int width);
void advanceSnake(int snake[2][2], int facing);
int validMove(int** maze, int snake[2][2], int facing);
int rightFacing(int facing);
int rotateFacing(int facing);
int findFacing(int snake[2][2]);
void findStart(int** maze, int height, int snake[2][2]);

void printMaze(int** maze, int height, int width);
void printTraversal(int** maze, int height, int width, int snake[2][2]);
void waitFor(unsigned int secs);

void freeCellList(int** cellList, int height, int width);
void freeMaze(int** maze, int height, int width);

/*
within the 2D array maze:
if maze[row][col] = -1, this is an unmarked cell.
if maze[row][col] = 0, this is a wall.
if maze[row][col] = 1, this is a path.
*/

int main(void) {
	srand((unsigned int)time(NULL));

	int mHeight = mHeightQuery();
	int mWidth = mWidthQuery();
	int** maze = malloc(mHeight * sizeof(int*));
	initMaze(maze, mHeight, mWidth);
	outerWalls(maze, mHeight, mWidth);

	backtrackMaze(maze, mHeight, mWidth);
	printMaze(maze, mHeight, mWidth);

	solveMaze(maze, mHeight, mWidth);

	freeMaze(maze, mHeight, mWidth);
}

void solveMaze(int** maze, int height, int width) {
	// snake[0] is head, snake[1] is tail
	int snake[2][2] = { 0 };
	findStart(maze, height, snake);
	int facing = 1;
	printTraversal(maze, height, width, snake);
	// while the last cell in cellList is not at max maze width
	while (snake[0][1] != width - 1) {
		facing = rightFacing(facing);
		while (!validMove(maze, snake, facing)) {
			facing = rotateFacing(facing);
		}
		advanceSnake(snake, facing);
		printTraversal(maze, height, width, snake);
		waitFor(1);
	}
}

void waitFor(unsigned int secs) {
	time_t retTime = time(0) + secs;
	while (time(NULL) < retTime);
}

void advanceSnake(int snake[2][2], int facing) {
	snake[1][0] = snake[0][0];
	snake[1][1] = snake[0][1];

	switch (facing) {
	case 0:
		--snake[0][0];
		break;
	case 1:
		++snake[0][1];
		break;
	case 2:
		++snake[0][0];
		break;
	case 3:
		--snake[0][1];
	}
}

int validMove(int** maze, int snake[2][2], int facing) {
	int row = snake[0][0];
	int col = snake[0][1];

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

	if (maze[row][col] != 0) {
		return 1;
	}
	return 0;
}

int rotateFacing(int facing) {
	--facing;
	if (facing < 0) {
		facing = 3;
	}
	return facing;
}

int rightFacing(int facing) {
	++facing;
	if (facing > 3) {
		facing = 0;
	}
	return facing;
}

int findFacing(int snake[2][2]) {
	if (snake[0][0] < snake[1][0]) {
		return 0;
	}
	else if (snake[0][1] > snake[1][1]) {
		return 1;
	}
	else if (snake[0][0] > snake[1][0]) {
		return 2;
	}
	else {
		return 3;
	}
}

void findStart(int** maze, int height, int snake[2][2]) {
	// columns
	snake[0][1] = 1;
	snake[1][1] = 0;

	for (int row = 0; snake[0][0] == 0; ++row) {
		if (maze[row][0] == 1) {
			snake[0][0] = row;
			snake[1][0] = row;
		}
	}
}

void backtrackMaze(int** maze, int height, int width) {
	int** cellList = malloc(height * width * sizeof(int*));
	initCellList(cellList, height, width);
	randStart(cellList, height, width);
	// facing (0 = north, 1 = east, 2 = south, 3 = west)
	int facing = rand() % 4;
	while (!validPath(maze, cellList, facing)) {
		facing = rand() % 4;
	}
	recordCell(maze, cellList);

	// while cellList contains elements, maze is unfinished
	while (listIndex(cellList) > -1) {
		if (moveCount(maze, cellList)) {
			facing = rand() % 4;
			while (!validPath(maze, cellList, facing)) {
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
	fillInWalls(maze, height, width);
	entryExit(maze, height, width);

	freeCellList(cellList, height, width);
}

void freeCellList(int** cellList, int height, int width) {
	for (int index = 0; index < height * width; ++index) {
		free(cellList[index]);
	}
	free(cellList);
}

void freeMaze(int** maze, int height, int width) {
	for (int row = 0; row < height; ++row) {
		free(maze[row]);
	}
	free(maze);
}

void entryExit(int** maze, int height, int width) {
	int entCount = 0;
	int exitCount = 0;
	for (int row = 1; row < height - 2; ++row) {
		if (maze[row][1] == 1) {
			++entCount;
		}
		if (maze[row][height - 2] == 1) {
			++exitCount;
		}
	}
	int entRand = rand() % entCount;
	int exitRand = rand() % exitCount;
	int entry = 0;
	int exit = 0;

	for (int row = 1; row < height - 2; ++row) {
		if (maze[row][1] == 1 && entRand > -1) {
			entry = row;
			--entRand;
		}
		if (maze[row][width - 2] == 1 && exitRand > -1) {
			exit = row;
			--exitRand;
		}
	}

	maze[entry][0] = 1;
	maze[exit][width - 1] = 1;
}

void fillInWalls(int** maze, int height, int width) {
	for (int row = 1; row < height - 2; ++row) {
		for (int col = 1; col < width - 1; ++col) {
			if (maze[row][col] == -1) {
				maze[row][col] = 0;
			}
		}
	}
}

void listBacktrack(int** cellList) {
	int index = listIndex(cellList);

	cellList[index][0] = -1;
	cellList[index][1] = -1;
}

void advanceList(int** cellList, int facing) {
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

void recordCell(int** maze, int** cellList) {
	int row = cellList[listIndex(cellList)][0];
	int col = cellList[listIndex(cellList)][1];

	maze[row][col] = 1;
}

// counts the number of valid paths from a cell
int moveCount(int** maze, int** cellList) {
	int count = 0;
	for (int facing = 0; facing < 4; ++facing) {
		if (validPath(maze, cellList, facing)) {
			++count;
		}
	}
	return count;
}

// checks to see if advancing one cell in the facing direction is a valid path.
// first, the prospective cell is checked to make sure it is not a path or a wall.
// second, the three neighbors are checked to make sure they are not paths.
// this second check improves the quality of the maze by making backtracking the only way intersections are formed.
// also, it is assumed diagonal paths are not traversable.  This is a part of the book instructions.
// if diagonals are deemed distasteful, the two aditional corners could be checked as well.
int validPath(int** maze, int** cellList, int facing) {

	int row = cellList[listIndex(cellList)][0];
	int col = cellList[listIndex(cellList)][1];

	switch (facing) {
	// north
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
	// east
	case 1:
		if (maze[row][col + 1] == -1) {
			if (maze[row - 1][col + 1] != 1 && maze[row + 1][col + 1] != 1 && maze[row][col + 2] != 1) {
				return 1;
			}
		}
		break;
	// south
	case 2:
		if (maze[row + 1][col] == -1) {
			if (maze[row + 1][col - 1] != 1 && maze[row + 1][col + 1] != 1 && maze[row + 2][col] != 1) {
				return 1;
			}
		}
		break;
	// west
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
int listIndex(int** cellList) {
	int size = 0;
	while (cellList[size][0] > -1) {
		++size;
	}
	return size - 1;
}

void randStart(int** cellList, int height, int width) {
	cellList[0][0] = 1 + rand() % (height - 2);
	cellList[0][1] = 1 + rand() % (width - 2);
}

void outerWalls(int** maze, int height, int width) {
	// row = 0 and height - 1
	for (int col = 0; col < width; ++col) {
		maze[0][col] = 0;
		maze[height - 1][col] = 0;
	}

	// col = 0 and width - 1
	for (int row = 0; row < height; ++row) {
		maze[row][0] = 0;
		maze[row][width - 1] = 0;
	}
}

int mWidthQuery() {
	printf("%s", "Maze width: ");
	int width = 0;
	scanf_s("%d", &width);
	return width;
}

int mHeightQuery() {
	printf("%s", "Maze height: ");
	int height = 0;
	scanf_s("%d", &height);
	return height;
}

void initMaze(int** maze, int height, int width) {
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			maze[row] = malloc(width * sizeof(int));
		}
	}

	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			maze[row][col] = -1;
		}
	}
}

void initCellList(int** cellList, int height, int width) {
	for (int index = 0; index < height * width; ++index) {
		cellList[index] = malloc(2 * sizeof(int));
	}

	for (int index = 0; index < height * width; ++index) {
		for (int dim = 0; dim < 2; ++dim) {
			cellList[index][dim] = -1;
		}
	}
}

void printMaze(int** maze, int height, int width) {
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
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

void printTraversal(int** maze, int height, int width, int snake[2][2]) {
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			if ((row == snake[0][0] && col == snake[0][1])) {
				printf("%s", "H");
			}
			else if ((row == snake[1][0] && col == snake[1][1])) {
				printf("%s", "T");
			}
			else if (maze[row][col] == 0) {
				printf("%s", "#");
			}
			else {
				printf("%s", " ");
			}
			printf("%s", " ");
		}
		puts("");
	}
	puts("");
}