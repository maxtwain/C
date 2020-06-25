#include <stdio.h>

#define ROW 50
#define COL 50
#define STATESIZE 4

void drawMove(int ground[ROW][COL], int state[], int magnitude);

int main(void) {

	int command = 0;
	int magnitude = 0;
	char garbage = '0';
	int ground[ROW][COL] = { 0 };
	
	/*
		if state[0] == 3, row position is 3
		if state[1] == 8, col position is 8

		if state[2] == 0, pen is up
		if state[2] == 1, pen is down

		if state[3] == 0, direction is north
		if state[3] == 1, direction is east
		if state[3] == 2, direction is south
		if state[3] == 3, direction is west
	*/
	int state[STATESIZE] = { 0 };
	state[3] = 1;
	
	puts("Enter commands.");
	while (command != 9) {
		scanf("%d", &command);
		switch (command) {

			// pen up
		case 1:
			state[2] = 0;
			break;

			// pen down
		case 2:
			state[2] = 1;
			break;

			// turn right
		case 3:
			if (state[3] == 3) {
				state[3] = 0;
			}
			else {
				++state[3];
			}
			break;

			// turn left
		case 4:
			if (state[3] == 0) {
				state[3] = 3;
			}
			else {
				++state[3];
			}
			break;

			// move
		case 5:
			// get magnitude
			garbage = getchar();
			scanf("%d", &magnitude);
			drawMove(ground, state, magnitude);
			break;

			// print ground
		case 6:
			puts("");
			for (size_t row = 0; row < ROW; ++row) {
				for (size_t col = 0; col < COL; ++col) {
					if (ground[row][col] == 0) {
						printf(" ");
					}
					else {
						printf("%s", "@");
					}
				}
				puts("");
			}
			puts("");
		}
	}
}

void drawMove(int ground[ROW][COL], int state[], int magnitude) {

	if (state[2] == 1) {
		ground[state[0]][state[1]] = 1;
	}

	for (int pen = 1; pen <= magnitude; ++pen) {
		
		switch (state[3]) {
		// north
		case 0:
			if (state[0] - 1 >= 0) {
				--state[0];
				if (state[2] == 1) {
					ground[state[0]][state[1]] = 1;
				}
			}
			else {
				printf("Action interrupted.  Position (row, col) = (%d, %d).  Facing = north.\n", state[0], state[1]);
				return;
			}
			break;

		// east
		case 1:
			if (state[1] + 1 <= 49) {
				++state[1];
				if (state[2] == 1) {
					ground[state[0]][state[1]] = 1;
				}
			}
			else {
				printf("Action interrupted.  Position (row, col) = (%d, %d).  Facing = east.\n", state[0], state[1]);
				return;
			}
			break;
		
		// south
		case 2:
			if (state[0] + 1 <= 49) {
				++state[0];
				if (state[2] == 1) {
					ground[state[0]][state[1]] = 1;
				}
			}
			else {
				printf("Action interrupted.  Position (row, col) = (%d, %d).  Facing = south.\n", state[0], state[1]);
				return;
			}
			break;
		
		// west
		default:
			if (state[1] - 1 >= 0) {
				--state[1];
				if (state[2] == 1) {
					ground[state[0]][state[1]] = 1;
				}
			}
			else {
				printf("Action interrupted.  Position (row, col) = (%d, %d).  Facing = west.\n", state[0], state[1]);
				return;
			}
		}
	}
}