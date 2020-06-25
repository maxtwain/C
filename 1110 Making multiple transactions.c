#include <stdio.h>

void createMaster();
void createTransfer();
void createNew();
void replaceMaster();
void createTransfer2();

int main(void) {

	createMaster();
	createTransfer();
	createNew();
	replaceMaster();

	createTransfer2();
	createNew();
	replaceMaster();
}

void createMaster() {
	FILE* fPtr;
	if ((fPtr = fopen("oldMaster.dat", "w")) == NULL) {
		puts("Error opening oldMaster.dat for writing");
	}

	fprintf(fPtr, "%d %s %.2f\n", 100, "Alan Jones", (float)348.17);
	fprintf(fPtr, "%d %s %.2f\n", 300, "Mary Smith", (float)27.19);
	fprintf(fPtr, "%d %s %.2f\n", 500, "Sam Sharp", (float)0.00);
	fprintf(fPtr, "%d %s %.2f\n", 700, "Suzy Green", (float)-14.22);

	fclose(fPtr);
}

void createTransfer() {
	FILE* fPtr;
	if ((fPtr = fopen("transfer.dat", "w")) == NULL) {
		puts("Error opening transfer.dat for writing");
	}

	fprintf(fPtr, "%d %.2f\n", 100, 27.14);
	fprintf(fPtr, "%d %.2f\n", 300, 62.11);
	fprintf(fPtr, "%d %.2f\n", 400, 100.56);
	fprintf(fPtr, "%d %.2f\n", 900, 82.17);

	fclose(fPtr);
}

void createTransfer2() {
	FILE* fPtr;
	if ((fPtr = fopen("transfer.dat", "w")) == NULL) {
		puts("Error opening transfer.dat for writing");
	}

	fprintf(fPtr, "%d %.2f\n", 900, 29.54);
	fprintf(fPtr, "%d %.2f\n", 300, 17.38);
	fprintf(fPtr, "%d %.2f\n", 700, 3.21);
	fprintf(fPtr, "%d %.2f\n", 100, 11.98);
	fprintf(fPtr, "%d %.2f\n", 700, 8.37);
	fprintf(fPtr, "%d %.2f\n", 900, 5.44);

	fclose(fPtr);
}

void createNew() {
	FILE* ofPtr;
	if ((ofPtr = fopen("oldMaster.dat", "r")) == NULL) {
		puts("Error opening oldMaster.dat!");
		return;
	}

	FILE* tfPtr;
	if ((tfPtr = fopen("transfer.dat", "r")) == NULL) {
		puts("Error opening transfer.dat!");
		return;
	}

	FILE* nfPtr;
	if ((nfPtr = fopen("newMaster.dat", "w")) == NULL) {
		puts("Error opening new master.dat!");
		return;
	}

	struct record {
		int accNum;
		char firstName[10];
		char lastName[10];
		float bal;
	} old;

	struct adjust {
		int accNum;
		float bal;
	} trans;

	fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);

	while (!feof(ofPtr)) {
		fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);
		while (!feof(tfPtr)) {
			if (trans.accNum == old.accNum) {
				old.bal -= trans.bal;
			}

			fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);
		}
		
		fprintf(nfPtr, "%d %s %s %.2f\n", old.accNum, old.firstName, old.lastName, old.bal);

		fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);

		rewind(tfPtr);
	}
	rewind(ofPtr);

	fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);

	while (!feof(tfPtr)) {

		fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);

		while (!feof(ofPtr) && old.accNum != trans.accNum) {
			fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);
		}

		if (old.accNum != trans.accNum) {

			printf("Unmatched transaction record for account %d\n", trans.accNum);
		}

		fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);

		rewind(ofPtr);
	}

	fclose(ofPtr);
	fclose(tfPtr);
	fclose(nfPtr);
}

void replaceMaster() {
	if (remove("oldMaster.dat") != 0) {
		puts("Error deleting oldMaster.dat");
	}

	if (rename("newMaster.dat", "oldMaster.dat") != 0) {
		puts("Error renaming newMaster.dat");
	}
}