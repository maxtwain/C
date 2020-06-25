#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void waitFor(unsigned int secs);
int tortMove();
int hareMove();
void printTrack(int tortPos, int harePos);
void oneTick(int *tortPtr, int *harePtr);

int main(void) {
	srand((unsigned int)time(NULL));

	puts("BANG !!!!!\nAND THEY'RE OFF !!!!!");

	int tortPos = 0;
	int harePos = 0;
	int *tortPtr = &tortPos;
	int *harePtr = &harePos;

	for (int i = 0; tortPos < 70 && harePos < 70; ++i) {
		oneTick(tortPtr, harePtr);
	}

	while (tortPos == harePos) {
		printf("A TIE!!!");
		oneTick(tortPtr, harePtr);
	}
	if (tortPos > harePos) {
		puts("TORTISE WINS!!! YAY!!!");
	}
	else{
		puts("Hare wins.  Yuch.");
	}
}

void waitFor(unsigned int secs) {
	time_t retTime = time(0) + secs;
	while (time(0) < retTime);
}

int tortMove() {
	int move = rand() % 10;
	if (move < 5) {
		return 3;
	}
	else if (move < 7) {
		return -6;
	}
	else {
		return 1;
	}
}

int hareMove() {
	int move = rand() % 10;
	if (move < 2) {
		return 0;
	}
	else if (move < 4) {
		return 9;
	}
	else if (move < 5) {
		return -12;
	}
	else if (move < 8) {
		return 1;
	}
	else {
		return -2;
	}
}

void printTrack(int tortPos, int harePos) {
	if (tortPos == harePos) {
		for (int spaces = 0; spaces < tortPos; ++spaces) {
			printf("%c", ' ');
		}
		printf("%s", "OUCH!!!");
		for (int spaces = tortPos + 6; spaces < 70; ++spaces) {
			printf("%c", ' ');
		}
	}
	else {
		for (int spaces = 0; spaces < (tortPos < harePos ? tortPos : harePos); ++spaces) {
			printf("%c", ' ');
		}
		printf("%c", (tortPos < harePos ? 'T' : 'H'));
		for (int spaces = 0; spaces < abs(tortPos - harePos); ++spaces) {
			printf("%c", ' ');
		}
		printf("%c", (tortPos > harePos ? 'T' : 'H'));
		for (int spaces = (tortPos > harePos ? tortPos : harePos) + 1; spaces < 70; ++spaces) {
			printf("%c", ' ');
		}
	}
	
	printf("%c", '|');
}

void oneTick(int *tortPtr, int *harePtr) {
	printTrack(*tortPtr, *harePtr);

	*tortPtr += tortMove();
	if (*tortPtr < 0) {
		*tortPtr = 0;
	}

	*harePtr += hareMove();
	if (*harePtr < 0) {
		*harePtr = 0;
	}

	waitFor(1);
	puts("");
}

