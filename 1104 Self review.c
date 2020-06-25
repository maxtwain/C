#include <stdio.h>

/*



*/

void partA();
void partB();
void partC();
void partD();
void partE();

int main(void) {

	partA();
	partB();
	partC();
	partD();
	partE();


}

void partA() {
	FILE* fPtr;
	// fPtr has not been opened.
	// Original code:
	// printf(fPtr, "%d%s%d\n", account, company, amount);
	// Revised:
	if ((fPtr = fopen("payables.dat", "w")) == NULL) {

	}
}

void partB() {
	FILE* fPtr;
	// Original code:
	// open("receive.dat", "r+");
	// Revised:
	if ((fPtr = fopen("receive.dat", "r+")) == NULL) {

	}
}

void partC() {
	FILE* recPtr;
	FILE* payPtr;
	if ((recPtr = fopen("receive.dat", "w")) == NULL) {

	}
	if ((payPtr = fopen("payables.dat", "r")) == NULL) {

	}
	int account;
	char company[30];
	int amount;
	// Original code:
	// scanf(recPtr, %d%s%d\n", &account, company , &amount);
	// Revised:
	fscanf(payPtr, "%d%s%d\n", &account, company , &amount);
}

void partD() {
	FILE* tfPtr;
	// Original code:
	// if ((tfPtr = fopen("tools.dat", "w")) != NULL)
	// Revised:
	if ((tfPtr = fopen("tools.dat", "a")) == NULL) {

	}
}

void partE() {
	FILE* cfPtr;
	// Original code:
	// if ((cfPtr = fopen("courses.dat", "w+")) != NULL)
	// Revised:
	if ((cfPtr = fopen("courses.dat", "a")) == NULL) {

	}
}
