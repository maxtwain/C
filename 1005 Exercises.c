#include <stdio.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();
void partG();

int main(void) {


	partA();
	partB();
	partC();
	partD();
	partE();
	partF();
	partG();


}

void partA() {
	puts("Part A");

	struct inventory {
		char partName[30];
		int partNumber;
		float price;
		int stock;
		int reorder;
	};
}

void partB() {
	puts("Part B");
	union data {
		char c;
		short s;
		long b;
		float f;
		double d;
	};
}

void partC() {
	puts("Part C");

	struct address {
		char streetAddress[25];
		char city[20];
		char state[3];
		char zipCode[6];
	};
}

void partD() {
	puts("Part D");

	struct student {
		char firstName[15];
		char lastName[15];
		struct homeAddress {
			char streetAddress[25];
			char city[20];
			char state[3];
			char zipCode[6];
		};
	};
}

void partE() {
	puts("Part E");

	struct test {
		int a : 1;
		int b : 1;
		int c : 1;
		int d : 1;
		int e : 1;
		int f : 1;
		int g : 1;
		int h : 1;
		int i : 1;
		int j : 1;
		int k : 1;
		int l : 1;
		int m : 1;
		int n : 1;
		int o : 1;
		int p : 1;
	};
}

void partF() {
	puts("Part F");

}

void partG() {
	puts("Part G");

}