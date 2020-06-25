#include <stdio.h>
#include <string.h>

// I did not follow the directions exactly on this one because the directions seemed to ask for two loops.  The first loop would select each line character.  The second loop would go through every letter of the alphabet to find a matching letter.  I believe my solution below to be superior.  I may not have used strchr like asked to, but I did use fgets.

int main(void) {
	// input text
	puts("Enter the text subject.");
	char line[500] = "Elvis has left the building in the park under the sky by the car.";
	fgets(line, 500, stdin);

	// count letters
	int alphabet[26] = { 0 };
	char* searchPtr = &line[0];
	while (*searchPtr != '\0') {
		if (*searchPtr >= 65 && *searchPtr <= 90) {
			++alphabet[*searchPtr - 65];
		}
		else if (*searchPtr >= 97 && *searchPtr <= 122) {
			++alphabet[*searchPtr - 97];
		}
		++searchPtr;
	}

	// print
	for (int alpha = 0; alpha < 26; ++alpha) {
		printf("%-3c", alpha + 65);
	}
	puts("");
	for (int alpha = 0; alpha < 26; ++alpha) {
		printf("%-3d", alphabet[alpha]);
	}
	puts("\n");
}