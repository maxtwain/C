#include <stdio.h>

#define SIZE 80

int main(void)
{
	int c;
	char sentence[SIZE];
	int i = 0;

	puts("Enter a line of text:");
			
	while ((i < SIZE - 1) && (c = fgetc(stdin)) != '\n') {
		sentence[i++] = c;
	}

	sentence[i] = '\0';

	fputs("\nThe line entered was:", stdin);
	puts(sentence);
}