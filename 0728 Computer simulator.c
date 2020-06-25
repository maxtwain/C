#include <stdio.h>

// This program is poorly written because, again, the book instructs the program to be written in this way.

void printIntro();
void load(int* memoryPtr, int* insRegPtr, int* insCPtr);
void execute(int* memory, int* acc, int* opCode, int* oper, int* insReg, int* insC);
void dump(int* memory, int* accPtr, int* insCPtr, int* insRegPtr, int* opCodePtr, int* operPtr);

int main(void) {
	int memory[100] = { 0 };
	// acc is accumulator
	int acc = 0;
	// opCode is operationCode
	int opCode = 0;
	// oper is operand
	int oper = 0;
	// insReg is instructionRegister
	int insReg = 0;
	// insC is instructionCounter
	int insC = 0;

	int* memoryPtr = memory;
	int* accPtr = &acc;
	int* opCodePtr = &opCode;
	int* operPtr = &oper;
	int* insRegPtr = &insReg;
	int* insCPtr = &insC;

	load(memoryPtr, insRegPtr, insCPtr);
	execute(memory, accPtr, opCodePtr, operPtr, insRegPtr, insCPtr);
	dump(memory, accPtr, insCPtr, insRegPtr, opCodePtr, operPtr);
}

void printIntro() {
	puts("*** Welcome to Simpletron! ***");
	puts("*** Please enter your program one instruction ***");
	puts("*** (or data word) at a time. I will type the ***");
	puts("*** location number and a question mark (?).  ***");
	puts("*** You then type the word for that location. ***");
	puts("*** Type the sentinel -99999 to stop entering ***");
	puts("*** your program. ***\n");
}

void load(int* memoryPtr, int* insRegPtr, int* insCPtr) {
	printIntro();
	printf("%02d ? ", *insCPtr);
	scanf_s("%d", insRegPtr);
	while (*insRegPtr != -99999 && *insCPtr < 100) {
		while ((*insRegPtr > 9999 || *insRegPtr < -9999) && *insRegPtr != -99999) {
			puts("*** Invalid entry ***");
			printf("%02d ? ", *insCPtr);
			scanf_s("%d", insRegPtr);
		}
		if (*insRegPtr != -99999) {
			memoryPtr[*insCPtr] = *insRegPtr;
			++*insCPtr;
			printf("%02d ? ", *insCPtr);
			scanf_s("%d", insRegPtr);
		}
	}
	puts("*** Program loading completed ***");
	puts("*** Program execution begins  ***");
}

void execute(int* memory, int* accPtr, int* opCodePtr, int* operPtr, int* insRegPtr, int* insCPtr) {
	*insRegPtr = 0;

	for (*insCPtr = 0; *insCPtr < 100 && *insRegPtr != -99999; ++*insCPtr) {
		*insRegPtr = memory[*insCPtr];
		*opCodePtr = *insRegPtr / 100;
		*operPtr = *insRegPtr % 100;
		switch (*opCodePtr) {
		case 00:
			*insRegPtr = -99999;
		case 10:
			printf("%s", "Value: ");
			scanf_s("%d", &memory[*operPtr]);
			break;
		case 11:
			printf("Result: %d", memory[*operPtr]);
			break;
		case 20:
			*accPtr = memory[*operPtr];
			break;
		case 21:
			memory[*operPtr] = *accPtr;
			break;
		case 30:
			*accPtr += memory[*operPtr];
			break;
		case 31:
			*accPtr -= memory[*operPtr];
			break;
		case 32:
			if (*operPtr != 0) {
				*accPtr /= memory[*operPtr];
				break;
			}
			else {
				puts("*** Attempt to divide by zero ***");
				puts("*** Simpletron execution abnormally terminated ***");
				*insRegPtr = -99999;
				break;
			}
		case 33:
			*accPtr *= memory[*operPtr];
			break;
		case 40:
			*insCPtr = *operPtr - 1;
			break;
		case 41:
			if (*accPtr < 0) {
				*insCPtr = *operPtr - 1;
			}
			break;
		case 42:
			if (*accPtr == 0) {
				*insCPtr = *operPtr - 1;
			}
			break;
		case 43:
			*insRegPtr = -99999;
			printf("%s", "\n*** Simpletron execution terminated ***\n");
			break;
		// silent termination
		case 45:
			*insCPtr = 100;
			break;
		default:
			puts("*** Invalid operation code ***");
			puts("*** Simpletron execution abnormally terminated ***");
			*insRegPtr = -99999;
		}
		if (*accPtr > 9999 || *accPtr < -9999) {
			puts("*** Accumulator overflow ***");
			puts("*** Simpletron execution abnormally terminated ***");
			*insRegPtr = -99999;
		}
	}
}

void dump(int* memory, int* accPtr, int* insCPtr, int* insRegPtr, int* opCodePtr, int* operPtr) {
	puts("REGISTERS:");
	printf("%-25s%+05d\n", "accumulator", *accPtr);
	printf("%-28s%02d\n", "instructionCounter", *insCPtr);
	printf("%-24s%+06d\n", "instructionRegister", *insRegPtr);
	printf("%-28s%02d\n", "operationCode", *opCodePtr);
	printf("%-28s%02d\n\n", "operand", *operPtr);
	
	puts("MEMORY:");
	printf("%2s", " ");
	for (int ones = 0; ones < 10; ++ones) {
		printf("%7d", ones);
	}
	puts("");
	for (int tens = 0; tens < 91; tens += 10) {
		printf("%2d", tens);
		for (int ones = 0; ones < 10; ++ones) {
			printf("  %+05d", memory[tens + ones]);
		}
		puts("");
	}
}