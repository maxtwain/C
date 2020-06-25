#include <stdio.h>
#include <string.h>

void partA();
void partB();
void partC();
void partD();
void partE();
void partF();
void partG();

int main(void) {

	struct customer {
		char lastName[15];
		char firstName[15];
		unsigned int customerNumber;

		struct {
			char phoneNumber[11];
			char address[50];
			char city[15];
			char state[3];
			char zipCode[6];
		} personal;
	} customerRecord, *customerPtr;

	customerPtr = &customerRecord;

	// Part A
	strcpy(customerRecord.lastName, "");

	// Part B
	strcpy(customerPtr->lastName, "");

	// Part C
	strcpy(customerRecord.firstName, "");

	// Part D
	strcpy(customerPtr->firstName, "");

	// Part E
	customerRecord.customerNumber = 4;

	// Part F
	customerPtr->customerNumber = 4;

	// Part G
	strcpy(customerRecord.personal.phoneNumber, "");

	// Part H
	strcpy(customerPtr->personal.phoneNumber, "");

	// Part I
	strcpy(customerRecord.personal.address, "");

	// Part J
	strcpy(customerPtr->personal.address, "");

	// Part K
	strcpy(customerRecord.personal.city, "");

	// Part L
	strcpy(customerPtr->personal.city, "");

	// Part M
	strcpy(customerRecord.personal.state, "");

	// Part N
	strcpy(customerPtr->personal.state, "");

	// Part O
	strcpy(customerRecord.personal.zipCode, "");

	// Part P
	strcpy(customerPtr->personal.zipCode, "");


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