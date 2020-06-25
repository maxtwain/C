#include <stdio.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();
void partG();
void partH();
void partI();

main(void) {

	//partA();
	//partB();
	//partC();
	//partD();
	//partE();
	//partF();
	//partG();
	//partH();
	partI();



}

void partA() {
	puts("Part A");
	printf("%15u\n", 40000);
}

void partB() {
	puts("Part B");
	int hex;
	scanf("%x", &hex);
	printf("%x\n", hex);
}

void partC() {
	puts("Part C");
	printf("%i\t%+i\n", 200, 200);
}

void partD() {
	puts("Part D");
	printf("%#x\n", 100);
}

void partE() {
	puts("Part E");
	char s[9];
	scanf("%8[^p]\n", s);
	printf("%s\n", s);
}

void partF() {
	puts("Part F");
	printf("%09.3f\n", 1.234);
}

void partG() {
	puts("Part G");
	int hour;
	int minute;
	int second;
	scanf("%d%*c%d%*c%d", &hour, &minute, &second);
	printf("%d\t%d\t%d\n", hour, minute, second);
}

void partH() {
	puts("Part H");
	char str[20] = { "" };
	scanf("%*c%[^\"]", str);
	printf("%s\n", str);
}

void partI() {
	puts("Part I");
	int hour;
	int minute;
	int second;
	scanf("%2d:%2d:%2d", &hour, &minute, &second);
	printf("%d\t%d\t%d\n", hour, minute, second);
}