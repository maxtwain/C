#include <stdio.h>
#include <string.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();

int main(void) {


	partA();
	partB();
	partC();
	partD();
	partE();
	partF();
}

void partA() {
	puts("Part A");

	struct card {
		char* face;
		char* suit;
	} c = { "Jack", "Hearts" };

	struct card* cPtr = &c;

	// Original code:
	// printf("%s\n", *cPtr->face);
	// Correction:
	printf("%s\n", cPtr->face);
}

void partB() {
	puts("Part B");

	struct card {
		char* face;
		char* suit;
	} hearts[13];

	hearts[10].face = "Jack";
	hearts[10].suit = "Hearts";

	// Original code:
	// printf("%s\n", hearts.face);
	// Correction:
	printf("%s\n", hearts[10].face);

}

void partC() {
	puts("Part C");

	union values {
		char w;
		float x;
		double y;
	};

	// Original code:
	// union values v = {1.27};
	// correction:
	
	union values v = { .y = 1.27 };

	printf("%.2f\n", v.y);

}

void partD() {
	puts("Part D");

	/* Original Code:
	struct person {
		char lastName[15];
		char firstName[15];
		unsigned int age;
	}
	*/
	// Correction:
	struct person {
		char lastName[15];
		char firstName[15];
		unsigned int age;
	};

}

void partE() {
	puts("Part E");
	
	struct person {
		char lastName[15];
		char firstName[15];
		unsigned int age;
	};

	// Original code:
	// person d;
	// Correction:
	struct person d;

	d.age = 55;

}

void partF() {
	puts("Part F");

	struct person {
		char lastName[15];
		char firstName[15];
		unsigned int age;
	} p;

	struct card {
		char* face;
		char* suit;
	} c = { "Jack", "Hearts" };

	// Original code:
	// p = c;
	// Correction:
	strcpy(p.lastName, c.face);
	strcpy(p.firstName, c.suit);

	printf("%s\n%s\n", p.lastName, p.firstName);
}
