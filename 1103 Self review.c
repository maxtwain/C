#include <stdio.h>

/*



*/

int main(void) {

	FILE* ofPtr;
	// Part A
	if ((ofPtr = fopen("oldmast.dat", "r")) == NULL) {
			
	}

	FILE* tfPtr;
	// Part B
	if ((tfPtr = fopen("trans.dat", "r")) == NULL) {

	}

	FILE* nfPtr;
	// Part C
	if ((nfPtr = fopen("newmast.dat", "w")) == NULL) {

	}

	struct record {
		int accountNum;
		char name[30];
		float currentBalance;
	} transferO;
	// Part D
	fscanf(ofPtr, "%d%29s%f", &transferO.accountNum, transferO.name, &transferO.currentBalance);

	struct recordT {
		int accountNum;
		float dollarAmount;
	} transferT;
	// Part E
	fscanf(tfPtr, "%d%f", &transferT.accountNum, &transferT.dollarAmount);

	// Part F
	fprintf(nfPtr, "%d%29s%f", transferO.accountNum, transferO.name, transferO.currentBalance);

}