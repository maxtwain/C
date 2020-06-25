#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplication();

int main(void) {
	while (1) {
		multiplication();
	}
}

void multiplication() {
	srand((unsigned int)time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int answer = -1;
	int chatter;
	while (a * b != answer) {
		printf("How much is %d times %d? ", a, b);
		scanf_s("%d", &answer);

		if (a * b != answer) {
			chatter = rand() % 4;
			switch (chatter) {
			case 0:
				puts("No.  Please try again.");
				break;
			case 1:
				puts("Wrong.  Try once more.");
				break;
			case 2:
				puts("Don't give up!");
				break;
			default:
				puts("No.  Keep trying.");
			}
		}
	}

	chatter = rand() % 4;
	switch (chatter) {
	case 0:
		puts("Very good!");
		break;
	case 1:
		puts("Excellent!");
		break;
	case 2:
		puts("Nice work!");
		break;
	default:
		puts("Keep up the good work!");
	}	
}