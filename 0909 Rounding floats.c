#include <stdio.h>

void printThis(int width);

int main(void) {
	for (int i0 = 0; i0 < 5; ++i0) {
		printThis(i0);
	}
}

void printThis(int width) {
	printf("%.*f\n", width, 100.453627);
}