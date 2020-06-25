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

	partA();
	partB();
	partC();
	partD();
	partE();
	partF();
	partG();
	partH();
	partI();


}

void partA() {
	puts("Part A");
	//Original code:
	//printf("%s\n", 'Happy Birthday');
	//Correction:
	printf("%s\n", "Happy Birthday");
}

void partB() {
	puts("Part B");
	//Original code:
	//printf("%c\n", 'Hello');
	//Correction:
	printf("%s\n", "Hello");
}

void partC() {
	puts("Part C");
	//Original code:
	//printf("%c\n", "This is a string");
	//Correction:
	printf("%s\n", "This is a string");
}

void partD() {
	puts("Part D");
	//Original code:
	//printf(""%s"", "Bon Voyage");
	//Correction:
	printf("\"%s\"", "Bon Voyage");
}

void partE() {
	puts("Part E");
	//Original code:
	//char day[] = "Sunday";
	//printf("%s\n", day[3]);
	//Correction:
	char day[] = "Sunday";
	printf("%c\n", day[3]);
}

void partF() {
	puts("Part F");
	//Original code:
	//puts('Enter your name: ');
	//Correction:
	puts("Enter your name: ");
}

void partG() {
	puts("Part G");
	//Original code:
	//printf(%f, 123.456);
	//Correction:
	printf("%f", 123.456);
}

void partH() {
	puts("Part H");
	//Original code:
	//printf("%s%s\n", 'O', 'K');
	//Correction:
	printf("%c%c\n", 'O', 'K');
}

void partI() {
	puts("Part I");
	//Original code:
	//char s[10];
	//scanf("%c", s[7]);
	//I don't know what this is trying to do.
}