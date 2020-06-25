#include <stdio.h>

void printChar(char sample);

int main(void) {
	printChar('A');
	printChar('B');
	printChar('C');
	printChar('a');
	printChar('b');
	printChar('c');
	printChar('0');
	printChar('1');
	printChar('2');
	printChar('$');
	printChar('*');
	printChar('+');
	printChar('/');
	printChar(' ');
}

void printChar(char sample) {
	printf("%c = %d\n", sample, sample);
}