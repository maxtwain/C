#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

void printMenu(int studentGrades[STUDENTS][EXAMS]);
void printArray(int studentGrades[STUDENTS][EXAMS]);
void printMin(int studentGrades[STUDENTS][EXAMS]);
void printMax(int studentGrades[STUDENTS][EXAMS]);
void printAverages(int studentGrades[STUDENTS][EXAMS]);

int main(void)
{
	int studentGrades[STUDENTS][EXAMS] =
	{ { 77, 68, 86, 73 },
	{ 96, 87, 89, 78 },
	{ 70, 90, 86, 81 } };

	printMenu(studentGrades);
}

void printMenu(int studentGrades[STUDENTS][EXAMS]) {
	int printChoice = 0;
	while (printChoice != 4) {
		printf("%s", "Enter a choice:\n");
		printf("%s%s%s%s%s",
			"  0  Print the array of grades\n",
			"  1  Find the minimum grade\n",
			"  2  Find the maximum grade\n",
			"  3  Print the average on all tests for each student\n",
			"  4  End program\n");
		scanf_s("%d", &printChoice);

		switch (printChoice) {
		case 0:
			printArray(studentGrades);
			break;
		case 1:
			printMin(studentGrades);
			break;
		case 2:
			printMax(studentGrades);
			break;
		case 3:
			printAverages(studentGrades);
		}
	}
}

void printArray(int studentGrades[STUDENTS][EXAMS]) {
	printf("%s", "                 [0]  [1]  [2]  [3]\n");
	for (int row = 0; row < STUDENTS; ++row) {
		printf("studentGrades[%d] ", row);
		for (int col = 0; col < EXAMS; ++col) {
			printf("%d   ", studentGrades[row][col]);
		}
		puts("");
	}
	puts("");
}

void printMin(int studentGrades[STUDENTS][EXAMS]) {
	int min = 99;
	for (int row = 0; row < STUDENTS; ++row) {
		for (int col = 0; col < EXAMS; ++col) {
			if (min > studentGrades[row][col]) {
				min = studentGrades[row][col];
			}
		}
	}

	printf("Lowest grade = %d\n\n", min);
}

void printMax(int studentGrades[STUDENTS][EXAMS]) {
	int max = 0;
	for (int row = 0; row < STUDENTS; ++row) {
		for (int col = 0; col < EXAMS; ++col) {
			if (max < studentGrades[row][col]) {
				max = studentGrades[row][col];
			}
		}
	}

	printf("Highest grade = %d\n\n", max);
}

void printAverages(int studentGrades[STUDENTS][EXAMS]) {
	float sum = 0.0;
	for (int student = 0; student < STUDENTS; ++student) {
		for (int test = 0; test < EXAMS; ++test) {
			sum += studentGrades[student][test];
		}
		printf("The average grade for student %d is %.2f\n", student, sum / EXAMS);
		sum = 0.0;
	}
	puts("");
}