#include <stdio.h>

int strcmp0A(const char* s1, const char* s2);
int strcmp0P(const char* s1, const char* s2);
int strncmp0A(const char* s1, const char* s2, size_t n);
int strncmp0P(const char* s1, const char* s2, size_t n);

int main(void) {
	char* word[] = { "abc", "abcd", "bcd" };

	printf("strcmp0A(abc, abc) = %d\n", strcmp0A(word[0], word[0]));
	printf("strcmp0A(abc, abcd) = %d\n", strcmp0A(word[0], word[1]));
	printf("strcmp0A(abcd, bcd) = %d\n", strcmp0A(word[1], word[2]));
	puts("");
	printf("strcmp0P(abc, abc) = %d\n", strcmp0P(word[0], word[0]));
	printf("strcmp0P(abc, abcd) = %d\n", strcmp0P(word[0], word[1]));
	printf("strcmp0P(abcd, bcd) = %d\n", strcmp0P(word[1], word[2]));

	puts("\n");
}

int strcmp0A(const char* s1, const char* s2) {
	for (int i0 = 0; 1 ; ++i0) {
		if (s1[i0] == '\0' && s2[i0] == '\0') {
			return 0;
		}
		else if (s1[i0] > s2[i0] || s2[i0] == '\0') {
			return 1;
		}
		else if (s1[i0] < s2[i0] || s1[i0] == '\0') {
			return -1;
		}
	}
	return 0;
}

int strcmp0P(const char* s1, const char* s2) {
	while (1) {
		if (*s1 == '\0' && *s2 == '\0') {
			return 0;
		}
		else if (*s1 > *s2 || *s2 == '\0') {
			return 1;
		}
		else if (*s1 < *s2 || *s1 == '\0') {
			return -1;
		}
		++s1;
		++s2;
	}
	return 0;
}

int strncmp0A(const char* s1, const char* s2, size_t n) {
	for (int i0 = 0; i0 < (int)n; ++i0) {
		if (s1[i0] == '\0' && s2[i0] == '\0') {
			return 0;
		}
		else if (s1[i0] > s2[i0] || s2[i0] == '\0') {
			return 1;
		}
		else if (s1[i0] < s2[i0] || s1[i0] == '\0') {
			return -1;
		}
	}
	return 0;
}

int strncmp0P(const char* s1, const char* s2, size_t n) {
	while (n > 0) {
		if (*s1 == '\0' && *s2 == '\0') {
			return 0;
		}
		else if (*s1 > *s2 || *s2 == '\0') {
			return 1;
		}
		else if (*s1 < *s2 || *s1 == '\0') {
			return -1;
		}
		++s1;
		++s2;
		--n;
	}
	return 0;
}
