#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void addition();
void subtraction();
void multiplication();
void mixture();

int main(void) {
	int study;
	while (1) {
		puts("Enter a number matching the arithmetic problem type you would like to study.");
		puts("0 = addition\t1 = subtraction\t2 = multiplication\t3 = mixture");
		printf("%s", "Your entry: ");
		scanf_s("%d", &study);
		switch (study) {
		case 0:
			addition();
			break;
		case 1:
			subtraction();
			break;
		case 2:
			multiplication();
			break;
		default:
			mixture();
		}
	}
}

void multiplication() {
	srand((unsigned int)time(NULL));
	int correct = 0;
	printf("%s", "Enter difficulty level (1 to 4): ");
	int difficulty;
	scanf_s("%d", &difficulty);
	difficulty = (int)pow(10, difficulty);
	for (int attempts = 0; attempts < 10;) {
		int a = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int b = difficulty / 10 + rand() % (difficulty - difficulty / 10);
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

void addition() {
	srand((unsigned int)time(NULL));
	int correct = 0;
	printf("%s", "Enter difficulty level (1 to 4): ");
	int difficulty;
	scanf_s("%d", &difficulty);
	difficulty = (int)pow(10, difficulty);
	for (int attempts = 0; attempts < 10;) {
		int a = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int b = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int answer = -1;
		int chatter;

		while (a + b != answer && attempts < 10) {
			printf("How much is %d plus %d? ", a, b);
			scanf_s("%d", &answer);
			++attempts;

			if (a + b != answer) {
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

void subtraction() {
	srand((unsigned int)time(NULL));
	int correct = 0;
	printf("%s", "Enter difficulty level (1 to 4): ");
	int difficulty;
	scanf_s("%d", &difficulty);
	difficulty = (int)pow(10, difficulty);
	for (int attempts = 0; attempts < 10;) {
		int a = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int b = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int answer = -1;
		int chatter;

		while (a - b != answer && attempts < 10) {
			printf("How much is %d minus %d? ", a, b);
			scanf_s("%d", &answer);
			++attempts;

			if (a - b != answer) {
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

void mixture() {
	srand((unsigned int)time(NULL));
	int correct = 0;
	printf("%s", "Enter difficulty level (1 to 4): ");
	int difficulty;
	scanf_s("%d", &difficulty);
	difficulty = (int)pow(10, difficulty);
	for (int attempts = 0; attempts < 10;) {
		int a = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int b = difficulty / 10 + rand() % (difficulty - difficulty / 10);
		int answer = -1;
		int chatter;

		// random operation
		int operation = rand() % 3;
		switch (operation) {
		case 0:		// addition
			while (a + b != answer && attempts < 10) {
				printf("How much is %d plus %d? ", a, b);
				scanf_s("%d", &answer);
				++attempts;

				if (a + b != answer) {
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
			break;

		case 1:		// subtraction
			while (a - b != answer && attempts < 10) {
				printf("How much is %d minus %d? ", a, b);
				scanf_s("%d", &answer);
				++attempts;

				if (a - b != answer) {
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
			break;

		default:	// multiplication
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
	}
	if ((double)correct / 10 < 0.75) puts("Please ask your teacher for help.\n");
	else puts("Congratulations, you are ready to go to the next level!\n");
}