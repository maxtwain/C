#include <stdio.h>

void packCharacters(char a, char b, char c, char d, unsigned int* packPtr);
void printBits(unsigned int pack);
void unpackCharacters(char* aPtr, char* bPtr, char* cPtr, char* dPtr, unsigned int pack);

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
	
	char* aPtr = &a;
	char* bPtr = &b;
	char* cPtr = &c;
	char* dPtr = &d;

	a = ' ';
	b = ' ';
	c = ' ';
	d = ' ';

	printf("a = %c\tb = %c\tc = %c\td = %c\n", a, b, c, d);

	unpackCharacters(aPtr, bPtr, cPtr, dPtr, pack);

	printf("a = %c\tb = %c\tc = %c\td = %c\n", a, b, c, d);

}

void packCharacters(char a, char b, char c, char d, unsigned int* packPtr) {
	*packPtr = a;
	*packPtr <<= 8;
	*packPtr |= b;
	*packPtr <<= 8;
	*packPtr |= c;
	*packPtr <<= 8;
	*packPtr |= d;
}

void unpackCharacters(char* aPtr, char* bPtr, char* cPtr, char* dPtr, unsigned int pack) {
	unsigned int mask = 1;
	for (int i0 = 0; i0 < 7; ++i0) {
		mask <<= 1;
		mask += 1;
	}

	*dPtr = pack & mask;
	pack >>= 8;
	*cPtr = pack & mask;
	pack >>= 8;
	*bPtr = pack & mask;
	pack >>= 8;
	*aPtr = pack & mask;
}

void printBits(unsigned int pack) {

	printf("pack = %ul\n", pack);
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