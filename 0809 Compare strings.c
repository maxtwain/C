#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void) {
	puts("Enter two strings.");
	char str1[SIZE];
	char str2[SIZE];
	fgets(str1, SIZE, stdin);
	fgets(str2, SIZE, stdin);

	str1[strlen(str1) - 1] = '\0';
	str2[strlen(str2) - 1] = '\0';

	puts("");
	printf("Entries:\n%s\n%s\n\n", str1, str2);

	int compare = strcmp(str1, str2);
	if (compare == 0) {
		printf("%s is equal to %s\n", str1, str2);
	}
	else {
		printf("%s is %s %s\n", str1, compare < 0 ? "less than" : "greater than", str2);
	}
	
	puts("");
}