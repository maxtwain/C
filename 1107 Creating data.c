#include <stdio.h>
#include <string.h>

void setRecord(int* accNumR, char nameR[50], float* balanceR, int accNum, char name[20], float balance);

int main(void) {

	typedef struct record {
		int accNum;
		char name[20];
		float balance;
	} Record;

	Record r;

	FILE* fPtr;
	if ((fPtr = fopen("data.txt", "w")) == NULL) {
		puts("File open error.");
		return 1;
	}

	setRecord(&r.accNum, r.name, &r.balance, 100, "Alan Jones", (float)348.17);
	fprintf(fPtr, "%d %s %.2f\n", r.accNum, r.name, r.balance);

	setRecord(&r.accNum, r.name, &r.balance, 300, "Mary Smith", (float)27.19);
	fprintf(fPtr, "%d %s %.2f\n", r.accNum, r.name, r.balance);

	setRecord(&r.accNum, r.name, &r.balance, 500, "Sam Sharp", (float)0.00);
	fprintf(fPtr, "%d %s %.2f\n", r.accNum, r.name, r.balance);

	setRecord(&r.accNum, r.name, &r.balance, 700, "Suzy Green", (float)-14.22);
	fprintf(fPtr, "%d %s %.2f\n", r.accNum, r.name, r.balance);

}

void setRecord(int* accNumR, char nameR[50], float* balanceR, int accNum, char name[20], float balance) {
	*accNumR = accNum;
	strncpy(nameR, name, 19);
	*balanceR = balance;
}