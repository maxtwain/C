#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tool {
	int recNum;
	char toolName[100];
	int quant;
	int cost;
} Tool;

void blank100();
void newTool();
void printHardware();
void generateToolList();
void deleteRecord();

int main(void) {
	
	blank100();
	//newTool();
	generateToolList();
	printHardware();
	deleteRecord();
	printHardware();
}

// Creates 100 blank entries
void blank100() {
	FILE* fPtr;
	if ((fPtr = fopen("hardware.dat", "wb")) == NULL) {
		puts("Error opening hardware.dat for wb");
		return;
	}

	Tool blank = { 0, "", 0, 0 };
	/*for (int i = 0; i < 100; ++i) {
		fwrite(&blank, sizeof(Tool), 1, fPtr);
	}*/

	for (blank.recNum = 0; blank.recNum < 100; ++blank.recNum) {
		fwrite(&blank, sizeof(Tool), 1, fPtr);
	}
	fclose(fPtr);
}

// Allows user to enter new tools or update existing
void newTool() {
	FILE* fPtr;
	if ((fPtr = fopen("hardware.dat", "rb+")) == NULL) {
		puts("Error opening hardware.dat for rb+");
		return;
	}

	Tool user = { 0, "", 0, 0 };
	char line[100] = "";
	char* token = NULL;
	user.recNum = 0;

	puts("Enter record for new data or 0 to quit:\nRecordNumber, ToolName, Quantity, Cost");
	while (1) {
		
		fgets(line, 100, stdin);
		token = strtok(line, ", \n");
		user.recNum = strtol(token, NULL, 0);
		while (user.recNum < 0 || user.recNum > 99) {
			puts("Record number must be between 0 and 100.  Please reenter data.");
			fgets(line, 100, stdin);
			token = strtok(line, ", \n");
			user.recNum = strtol(token, NULL, 0);
		}

		if (user.recNum == 0) {
			break;
		}

		token = strtok(NULL, ", \n");
		strcpy(user.toolName, token);
		token = strtok(NULL, ", \n");
		user.quant = strtol(token, NULL, 0);
		token = strtok(NULL, ", \n");
		user.cost = (int)(strtod(token, NULL) * 100);

		fseek(fPtr, user.recNum * sizeof(Tool), SEEK_SET);
		fwrite(&user, sizeof(Tool), 1, fPtr);
	}

	puts("");
	fclose(fPtr);
}

// Prints hardware records
void printHardware() {
	FILE* fPtr;
	if ((fPtr = fopen("hardware.dat", "rb")) == NULL) {
		puts("Error opening hardware.dat for rb");
		return;
	}

	Tool toScreen = { 0, "", 0, 0 };
	
	printf("%-10s%-20s%-10s%s\n", "Record #", "Tool name", "Quantity", "Cost");
	while (fread(&toScreen, sizeof(Tool), 1, fPtr)) {
		if (toScreen.recNum > 0) {
			printf("%-10d%-20s%-10d%.2f\n", toScreen.recNum, toScreen.toolName, toScreen.quant, (double)toScreen.cost / 100);
		}
	}
	puts("");
	fclose(fPtr);
}

void generateToolList() {

	FILE* fPtr;
	if ((fPtr = fopen("hardware.dat", "rb+")) == NULL) {
		puts("Error opening hardware.dat for rb+");
	}

	Tool t0 = { 3, "Electric sander", 7, 5798 };
	Tool t1 = { 17, "Hammer", 76, 1199 };
	Tool t2 = { 24, "Jig saw", 21, 1100 };
	Tool t3 = { 39, "Lawn mower", 3, 7950 };
	Tool t4 = { 56, "Power saw", 18, 9999 };
	Tool t5 = { 68, "Screwdriver", 106, 699 };
	Tool t6 = { 77, "Sledge hammer", 11, 2150 };
	Tool t7 = { 83, "Wrench", 34, 750 };

	fseek(fPtr, t0.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t0, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t1.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t1, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t2.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t2, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t3.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t3, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t4.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t4, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t5.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t5, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t6.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t6, sizeof(Tool), 1, fPtr);
	fseek(fPtr, t7.recNum * sizeof(Tool), SEEK_SET);
	fwrite(&t7, sizeof(Tool), 1, fPtr);

	fclose(fPtr);
}

void deleteRecord() {
	FILE* fPtr;
	if ((fPtr = fopen("hardware.dat", "rb+")) == NULL) {
		puts("Error opening hardware.dat for rb+");
		return;
	}

	int recNum = 0;
	char line[100] = "";
	char* token = NULL;
	Tool blank = { 0, "", 0, 0 };

	puts("Enter record to delete or 0 to quit:");
	while (1) {

		fgets(line, 100, stdin);
		token = strtok(line, ", \n");
		recNum = strtol(token, NULL, 0);
		while (recNum < 0 || recNum > 99) {
			puts("Record number must be between 0 and 100.  Please reenter data.");
			fgets(line, 100, stdin);
			token = strtok(line, ", \n");
			recNum = strtol(token, NULL, 0);
		}

		if (recNum == 0) {
			break;
		}

		fseek(fPtr, recNum * sizeof(Tool), SEEK_SET);
		fwrite(&blank, sizeof(Tool), 1, fPtr);
	}

	puts("");
	fclose(fPtr);
}