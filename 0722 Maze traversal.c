#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "maze.h"

// pos[0][0] = row0; pos[0][1] = col0; pos[1][0] = row1; pos[1][1] = col1;
// (row0, col0) = initial position;  (row1, col1) = new position;

int main(void) {
	int maze[MSIZE][MSIZE] = { 0 };
	practiceMaze(maze);
	solveMaze(maze);
}

