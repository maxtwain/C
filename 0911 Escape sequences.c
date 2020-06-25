#include <stdio.h>

int main(void) {
	char a = 'z';
	printf("%c\'z\"z\?z\\z\az\bz\nz\rz\tz", a);
	puts("");
}