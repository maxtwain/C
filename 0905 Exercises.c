#include <stdio.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();
void partG();
void partH();

main(void) {

	//partA();
	//partB();
	//partC();
	//partD();
	//partE();
	partF();
	partG();
	partH();



}

void partA() {
	puts("Part A");
	printf("%-10d\n", 10000);
}

void partB() {
	puts("Part B");
	/*Original code:
		printf("%c\n", "This is a string");
	Correction:*/
	printf("%s\n", "This is a string");
}

void partC() {
	puts("Part C");
	printf("%*.*lf\n", 8, 3, 1024.987654);
}

void partD() {
	puts("Part D");
	printf("%#o\n%#X\n%#e\n", 17, 17, 1008.83689);
}

void partE() {
	puts("Part E");
	printf("% ld\n%+ld\n", 1000000, 1000000);
}

void partF() {
	puts("Part F");
	printf("%10.2E\n", 444.93738);
}

void partG() {
	puts("Part G");
	printf("%10.2g\n", 444.93718);
}

void partH() {
	puts("Part H");
	/*Original code:
		printf("%d\n", 10.987);
	Correction:*/
	printf("%f\n", 10.987);
}
