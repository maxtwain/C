#include <stdio.h>

int main(void) {
	int count = 0;
start:
	if (count < 5 || count > 19 || count % 5 == 0 || count % 5 == 4) {
		printf("%s", "*");
	}
	else {
		printf("%s", " ");
	}
	++count;

	if (count % 5 == 0) {
		printf("%s", "\n");
	}

	if (count < 25) {
		goto start;
	}
	puts("\n");
}