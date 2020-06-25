#include <stdio.h>

int main(void) {
	for (int i0 = 0; i0 < 10; ++i0) {
		printf("%.*g\n", i0, 9876.12345);
	}
}