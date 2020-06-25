#include <stdio.h>
#include <string.h>

int main(void) {
	// input text
	puts("Enter the text subject.");
	char line[500] = "Elvis has left the building in the park under the sky by the car.";
	//fgets(line, 500, stdin);

	int count = 0;
	char* ptr = strtok(line, " .,-");
	while (ptr != '\0') {
		++count;
		ptr = strtok(NULL, " .,-");
	}
	printf("count = %d\n", count);
	puts("\n");
}