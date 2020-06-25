#include <stdio.h>

// I think I much prefer this kind of programming on Linux.  This program is something I wrote on an online Linux shell at www.jdoodle.com.  If I didn't use my home computer for so many different things, I would install Linux on it, but I don't want to experiment with a dual boot and endanger what I have.

int main(int argc, char* argv[])
{
	printf("argc = %d\n", argc);

	for (int i = 1; i < argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	puts("\n");
	return 0;
}