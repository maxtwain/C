#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void) {

}

void printInstruct(unsigned int disk, unsigned int init, unsigned int stack, unsigned int aux) {
	unsigned int maxDisks = 0;
	for (unsigned long long int i = ULLONG_MAX; i > 2; i /= 2) {
		++maxDisks;
	}
	if (disk > maxDisks) {
		printf("Max disks = %u\nDisks exceeds max allowed\n", maxDisks);
		return;
	}

	unsigned long long moves = pow(2, disk) - 1;
	while (disk > 1) {

	}
	printf("Move disk %u from peg %u to peg %u\n", disk, init, stack);
}

/*
d = disk.  d1 = disk 1, d2 = disk 2, d3 = disk 3.  dMax = largest disk.  dStack = animated disk stack.  dFreeze = unmoved stack still remaining in initial position.  dStackMax = largest disk in animated stack.
pegs: 'L' = This is the position of the initial tower on the left side.
	'M' = This is the middle peg.
	'R' = This is the right peg where the tower will be moved.

 step 1:
	if (dMax % 2 == 0) M becomes dStack(1) destination.
			print d1 L -> M
		R becomes dStack(2) destination.
			print d2 L -> R
			print d1 M -> R
		dStack(3) -> !d3 and !dStack(2).  These are L and R so dStack(3) -> M
			print d3 L -> M
		because (dStack(2) % 2 == 0), d1 -> !d3 and !d1.  These are M and R, so
			print d1 R -> L
		d2 -> !d1 and !d2
			print d2 R -> M
		d1 stacks on d2
			print d1 L -> M
		d4 -> !d4 and !dStack(3)
			print d4 L -> R
		dStack(3) stacks on d4.  because (dStack(3) == 1), d1 -> d4 which is R
			print d1 M -> R
	else R becomes dStack destination.  print d1 => R

	I don't believe an iterative solution is possible if you only know the top disk on each peg.  I believe the only way to solve this in an iterative way is to record what disks are on each peg.  This requires data structures which are topics beyond chapter 5 unless it is known before hand how many disks there are and a varaible is created to hold the position of each disk.  At this point, in chapter 5, there are no arrays, no structs, no classes, no files.
 */