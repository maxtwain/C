#include <stdio.h>

int main(void) {
	unsigned int A = 0;
	printf("%s", "A\tA+2\tA+4\tA+6\n\n");
	while (A < 15) {
		printf("%u\t%u\t%u\t%u\n", A += 3, A + 2, A + 4, A + 6);
	}
}