#include <stdio.h>

int main(void) {
	unsigned int N = 0;

	printf("%s", "N\t10*N\t100*N\t1000*N\n\n");
	while (N < 10) {
		printf("%u\t%u\t%u\t%u\n", ++N, N * 10, N * 100, N * 1000);
	}
}