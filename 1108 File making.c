#include <stdio.h>

void createOld();
void createTransfer();
void createNew();

int main(void) {

	createOld();
	createTransfer();
	createNew();
}

void createOld() {
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

	// This portion of the code assume transfer.dat contains no new customer data and only update data for existing customers.

	// read first old master entry
	fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);

	// while an old master entry exists
	while (!feof(ofPtr)) {

		// retrieve first entry in transfer
		fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);

		// while records do not match and records remain in transfer
		while (old.accNum != trans.accNum && !feof(tfPtr)) {

			// retrieve next entry in transfer
			fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);
		}
		// if a record match was found
		if (old.accNum == trans.accNum) {

			// adjust existing record and save it in new master
			fprintf(nfPtr, "%d %s %s %.2f\n", old.accNum, old.firstName, old.lastName, old.bal - trans.bal);
		}
		else {
			// transfer old to new unadjusted
			fprintf(nfPtr, "%d %s %s %.2f\n", old.accNum, old.firstName, old.lastName, old.bal);
		}

		// get next old master entry
		fscanf(ofPtr, "%d %s %s %f", &old.accNum, old.firstName, old.lastName, &old.bal);

		// reset transfer file pointer
		rewind(tfPtr);
	}
	// reset old master pointer
	rewind(ofPtr);

	// get first transfer record
	fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);

	// while a transfer record exists
	while (!feof(tfPtr)) {

		// get first old master record
		fscanf(ofPtr, "%d %s %s %f", &old.accNum, &old.firstName, &old.lastName, &old.bal);

		// while an old master record exists and record do match
		while (!feof(ofPtr) && old.accNum != trans.accNum) {
			fscanf(ofPtr, "%d %s %s %f", &old.accNum, &old.firstName, &old.lastName, &old.bal);
		}
		// if an account in trans does not exist in old
		if (old.accNum != trans.accNum) {

			// print error message
			printf("Unmatched transaction record for account %d\n", trans.accNum);
		}
		// get next trans record
		fscanf(tfPtr, "%d %f", &trans.accNum, &trans.bal);
	}
}