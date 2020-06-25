#include <stdio.h>
#include <string.h>

int main(void) {
	puts("Enter the text subject.");
	char line[500] = "Elvis has left the building in the park under the sky by the car.";
	fgets(line, 500, stdin);

	puts("Enter the search text.");
	char search = 't';
	fgets(line, 500, stdin);

	int count = 0;
	char* searchPtr = strchr(line, search);
	while (searchPtr != '\0') {
		++count;
		searchPtr = strchr(searchPtr + 1, search);
	}
	printf("count = %d\n", count);
	puts("\n");
}