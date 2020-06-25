#include <stdio.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();
void partG();

int main(void) {
	// Part A
	struct part {
		unsigned int partNumber;
		char partName[25];
	};
	
	// Part B
	typedef struct part Part;

	// Part C
	Part a, b[10], *ptr;

	// Part D
	scanf("%d%24s", &a.partNumber, a.partName);

	// Part E
	b[3] = a;

	// Part F
	ptr = b;

	// Part G
	//printf("%d\n%s\n", ptr[3].partNumber, ptr[3].partName);
	printf("%d\n%s\n", (ptr + 3)->partNumber, (ptr + 3)->partName);



	/*partA();
	partB();
	partC();
	partD();
	partE();
	partF();
	partG();*/


}

void partA() {
	puts("Part A");

}

void partB() {
	puts("Part B");

}

void partC() {
	puts("Part C");

}

void partD() {
	puts("Part D");

}

void partE() {
	puts("Part E");

}

void partF() {
	puts("Part F");

}

void partG() {
	puts("Part G");

}