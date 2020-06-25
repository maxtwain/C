#include <stdio.h>

void packCharacters(char a, char b, char c, char d, unsigned int* packPtr);
void printBits(unsigned int pack);

int main(void) {

	char str[5] = "blah";

	char a = str[0];
	char b = str[1];
	char c = str[2];
	char d = str[3];

	unsigned int pack = 0;
	unsigned int* packPtr = &pack;
	printf("sizeof(unsigned int) = %d bytes, or %d bits\n", sizeof(unsigned int), sizeof(unsigned int) * 8);
	packCharacters(a, b, c, d, packPtr);



}

void packCharacters(char a, char b, char c, char d, unsigned int* packPtr) {
	printBits(*packPtr);
	*packPtr = a;
	*packPtr <<= 8;
	printBits(*packPtr);
	*packPtr |= b;
	*packPtr <<= 8;
	printBits(*packPtr);
	*packPtr |= c;
	*packPtr <<= 8;
	printBits(*packPtr);
	*packPtr |= d;
	printBits(*packPtr);


}

void printBits(unsigned int pack) {
	unsigned int mask = 1 << 31;

	for (unsigned int c = 1; c <= 32; ++c) {
		putchar(pack & mask ? '1' : '0');
		pack <<= 1;

		if (c % 4 == 0) {
			putchar(' ');
		}
		if (c % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");
}