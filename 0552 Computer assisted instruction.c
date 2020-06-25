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
	int correct = 0;
	for (int attempts = 0; attempts < 10;) {
		int a = rand() % 10;
		int b = rand() % 10;
		int answer = -1;
		int chatter;

		while (a * b != answer && attempts < 10) {
			printf("How much is %d times %d? ", a, b);
			scanf_s("%d", &answer);
			++attempts;

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
			else {
				++correct;
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
		}
	}
	if ((double)correct / 10 < 0.75) puts("Please ask your teacher for help.\n");
	else puts("Congratulations, you are ready to go to the next level!\n");
}