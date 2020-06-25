#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcpy0A(char* s1, const char* s2);
char* strcpy0P(char* s1, const char* s2);
char* strcat0A(char* s1, const char* s2);
char* strcat0P(char* s1, const char* s2);

int main(void) {
	char* word0 = "truck";
	char word1[] = "copper";

	printf("strcpy0A = %s\n", strcpy0A(word1, word0));

	char word2[] = "tenuous";
	printf("strcpy0P = %s\n", strcpy0P(word2, word0));

	char word3[] = "cloistered";
	printf("strcat0A = %s\n", strcat0A(word3, word0));

	char word4[] = "vagabond";
	printf("strcat0P = %s\n", strcat0P(word4, word0));

	puts("\n");
}

char* strcpy0A(char* s1, const char* s2) {
	for (int i0 = 0; s2[i0] != '\0'; ++i0) {
		s1[i0] = s2[i0];
	}
	return s1;
}

char* strcpy0P(char* s1, const char* s2) {
	char* start = s1;
	while (*s2 != '\0') {
		*s1 = *s2;
		++s1;
		++s2;
	}
	return start;
}

// malloc not free
char* strcat0A(char* s1, const char* s2) {
	int s1Size = 0;
	while (s1[s1Size] != '\0') {
		++s1Size;
	}
	int s2Size = 0;
	while (s2[s2Size] != '\0') {
		++s2Size;
	}
	char* s3 = malloc((s1Size + s2Size) * sizeof(char));
	for (int i0 = 0; s1[i0] != '\0'; ++i0) {
		s3[i0] = s1[i0];
	}
	for (int i0 = 0; s1[i0] != '\0'; ++i0) {
		s3[s1Size + i0] = s2[i0];
	}
	s3[s1Size + s2Size] = '\0';
	return s3;
}

// malloc not free
char* strcat0P(char* s1, const char* s2) {
	char* s3 = malloc((strlen(s1) + strlen(s2)) * sizeof(char));
	char* start = s3;
	while (*s1 != '\0') {
		*s3 = *s1;
		++s1;
		++s3;
	}
	while (*s2 != '\0') {
		*s3 = *s2;
		++s2;
		++s3;
	}
	*s3 = '\0';
	return start;
}
