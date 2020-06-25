#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void answer(char* question);

int main(void) {
	char question[100][100] = { "How many inches are in 2 meters?",	"How many liters are in 10 quarts?", "How many feet are in 5 kilograms?" };

	answer(question[0]);

	puts("\n");
}

void answer(char* question) {
	printf("%s\n", question);

	char* length[] = { "kilometers", "hectrometers", "dekameters", "meters", "decimeters", "centimeters", "millimeters", "miles", "yards", "feet", "inches" };

	// meters in unit
	double lengthC[] = { 1000, 100, 10, 1, 0.1, 0.01, 0.001, 1609.34, 0.9144, 0.3048, 0.0254 };

	char* volume[] = { "kiloliters", "hectoliters", "dekaliters", "liters", "deciliters", "centiliters", "milliliters", "gallons", "quarts", "pints", "cups", "teaspoons" };

	// liters in unit
	double volumeC[] = { 1000, 100, 10, 1, 0.1, 0.01, 0.001, 3.78541, 0.946353, 0.473176, 0.24, 0.0147868 };

	char* weight[] = { "kilograms", "hectograms", "dekagrams", "grams", "decigrams", "centigrams", "milligrams", "tons", "pounds", "ounces" };

	// grams in unit
	double weightC[] = { 1000, 100, 10, 1, 0.1, 0.01, 0.001, 907185, 453.592, 28.3495 };

	question[strlen(question) - 1] = '\0';
	char* qPointer0 = NULL;
	char* qPointer1 = NULL;
	char* qPointer2 = strtok(question, " ");
	for (int word = 0; qPointer2 != NULL; ++word) {
		if (word == 2) {
			qPointer0 = qPointer2;
		}
		if (word == 5) {
			qPointer1 = qPointer2;
		}
		qPointer2 = strtok(NULL, " ");
	}

	double factor = strtod(qPointer1, &qPointer2);
	++qPointer2;

	int match = 0;
	for (int i0 = 0; i0 < sizeof(length) / sizeof(length[0]); ++i0) {
		if (strcmp(length[i0], qPointer0) == 0) {
			for (int i1 = 0; i1 < sizeof(length) / sizeof(length[0]); ++i1) {
				if (strcmp(length[i1], qPointer2) == 0) {
					match = 1;
					factor = (factor * lengthC[i1]) / lengthC[i0];
				}
			}
		}
	}
	if (match == 0) {
		for (int i0 = 0; i0 < sizeof(volume) / sizeof(volume[0]); ++i0) {
			if (strcmp(volume[i0], qPointer0) == 0) {
				for (int i1 = 0; i1 < sizeof(volume) / sizeof(volume[0]); ++i1) {
					if (strcmp(volume[i1], qPointer2) == 0) {
						match = 2;
						factor = (factor * volumeC[i1]) / volumeC[i0];
					}
				}
			}
		}
	}
	if (match == 0) {
		for (int i0 = 0; i0 < sizeof(weight) / sizeof(weight[0]); ++i0) {
			if (strcmp(weight[i0], qPointer0) == 0) {
				for (int i1 = 0; i1 < sizeof(weight) / sizeof(weight[0]); ++i1) {
					if (strcmp(weight[i1], qPointer2) == 0) {
						match = 3;
						factor = (factor * weightC[i1]) / weightC[i0];
					}
				}
			}
		}
	}
	if (match == 0) {
		printf("%s\n", "Unit match does not exist.");
		return;
	}
	else {
		printf("%lf\n", factor);
	}
}