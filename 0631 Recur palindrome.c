#include <stdio.h>
#include <ctype.h>

int isPal(char test[], int size);
int isPalR(char test[], int size);
int charMatch(char test[], int start, int end);

int main(void) {

	char test0[] = "radar";
	char test1[] = "able was i ere i saw elba.";
	char test2[] = "a man a plan a canal panama.";
	char test3[] = "this is not a palindrome!";

	printf("test2: isPal = %d\n", isPal(test2, sizeof(test2)));
	printf("test3: isPal = %d\n", isPal(test3, sizeof(test3)));

	printf("test2: isPalR = %d\n", isPalR(test2, sizeof(test2)));
	printf("test3: isPalR = %d\n", isPalR(test3, sizeof(test3)));
}

int isPal(char test[], int size) {
	
	int isPal = 1;
	for (int start = 0, end = size - 2; start < end; ) {
		while (!isalpha(test[start])) {
			++start;
		}
		while (!isalpha(test[end])) {
			--end;
		}
		if (test[start] != test[end]) {
			isPal = 0;
		}
		++start;
		--end;
	}

	return isPal;
}

int isPalR(char test[], int size) {

	int start = 0;
	int end = size - 2;

	return charMatch(test, start, end);
}

int charMatch(char test[], int start, int end) {

	if (!isalpha(test[start])) {
		++start;
	}
	else if (!isalpha(test[end])) {
		--end;
	}

	if (test[start] != test[end]) {
		return 0;
	}
	if (start >= end) {
		return 1;
	}
	return charMatch(test, start + 1, end - 1);

}