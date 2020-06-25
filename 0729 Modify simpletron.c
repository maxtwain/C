#include <stdio.h>

// The book instructions seem to want this program to become more and more difficult to work on.  Instead of solving a problem it seems to be making one.  Last exercise it wanted to change all the variables to pointers for no reason.  Now it wants to change the instruction numbers to hex for no reason.

void printIntro();
void load(int* memoryPtr, int* insRegPtr, int* insCPtr);
void execute(int* memory, int* acc, int* opCode, int* oper, int* insReg, int* insC);
void dump(int* memory, int* accPtr, int* insCPtr, int* insRegPtr, int* opCodePtr, int* operPtr);

int main(void) {
	int memory[1000] = { 0 };
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
	while (*insRegPtr != -99999 && *insCPtr < 1000) {
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

	for (*insCPtr = 0; *insCPtr < 1000 && *insRegPtr != -99999; ++*insCPtr) {
		*insRegPtr = memory[*insCPtr];
		*opCodePtr = *insRegPtr / 100;
		*operPtr = *insRegPtr % 100;
		switch (*opCodePtr) {
		case 00:
			*insRegPtr = -99999;
		// read
		case 10:
			printf("%s", "Value: ");
			scanf_s("%d", &memory[*operPtr]);
			break;
		// write
		case 11:
			printf("Result: %d", memory[*operPtr]);
			break;
		// newline
		case 12:
			puts("");
			break;
		// load to acc
		case 20:
			*accPtr = memory[*operPtr];
			break;
		// store from acc
		case 21:
			memory[*operPtr] = *accPtr;
			break;
		// addition
		case 30:
			*accPtr += memory[*operPtr];
			break;
		// subtraction
		case 31:
			*accPtr -= memory[*operPtr];
			break;
		// division
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
		// multiplication
		case 33:
			*accPtr *= memory[*operPtr];
			break;
		// remainder
		case 34:
			*accPtr %= memory[*operPtr];
			break;
		// exponent
		case 35:
			{
				int result = 1;
				for (int exp = memory[*operPtr]; exp > 0; --exp) {
					result *= *accPtr;
				}
				*accPtr = result;
			}
		// branch
		case 40:
			*insCPtr = *operPtr - 1;
			break;
		// branchneg
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
			*insCPtr = 1000;
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
	for (int hunds = 0; hunds < 1000; hunds += 10) {
		printf("%3d", hunds);
		for (int ones = 0; ones < 10; ++ones) {
			printf("  %+05d", memory[hunds + ones]);
		}
		puts("");
	}
}