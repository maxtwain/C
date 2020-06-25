#include <stdio.h>

void printThis(int width);

int main(void) {
	for (int i = 0; i < 10; ++i) {
		printThis(i);
	}
}

void printThis(int width) {
	printf("%4d\t%*d\t%*f\n", width, width, 12345, width, 1.2345);
}