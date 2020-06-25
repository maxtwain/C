#include <stdio.h>
#include <string.h>

int main(void) {
	puts("Enter the text subject.");
	char line[500] = "Elvis has left the building in the park under the sky by the car.";
	fgets(line, 500, stdin);

	puts("Enter the search text.");
	char search[500] = "the";
	fgets(line, 500, stdin);

	char* searchPtr = strstr(line, search);
	while (searchPtr != '\0') {
		printf("%s\n", searchPtr);
		searchPtr = strstr(searchPtr + 1, search);
	}
	puts("\n");
}