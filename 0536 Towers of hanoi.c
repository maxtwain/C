#include <stdio.h>

void printInstruct(unsigned int disksMoved, unsigned int initThread, unsigned int stackThread, unsigned int auxThread);

int main(void) {
	printInstruct(3, 1, 3, 2);
}

void printInstruct(unsigned int disk, unsigned int init, unsigned int stack, unsigned int aux) {
	if (disk == 1) {
		printf("Move disk %u from peg %u to peg %u\n", disk, init, stack);
		return;
	}
	printInstruct(disk - 1, init, aux, stack);
	printf("Move disk %u from peg %u to peg %u\n", disk, init, stack);
	printInstruct(disk - 1, aux, stack, init);
}

// 64 DISKS FROM A TO C
// move 64 a to c
// move 63 disks a to b
// move 62 disks b to a
// move 63 b to c

// c is always aux while init and stack always exchange?