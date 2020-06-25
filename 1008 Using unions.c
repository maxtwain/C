#include <stdio.h>

int main(void) {

	union integer {
		char c;
		short s;
		int i;
		long b;
	};

	union integer a;
	a.c = 'a';

	printf("%c\n%d\n%d\n%ld\n", a.c, a.s, a.i, a.b);

}