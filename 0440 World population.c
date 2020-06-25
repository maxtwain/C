#include <stdio.h>

int main(void) {
	const double pChange = 1.0111;
	unsigned long long newPop, lastPop = 7'521'337'750;
	printf("%s\t%s\t%s\n", "Year", "Population", "Increase");
	for (unsigned int year = 1; year <= 75; ++year) {
		newPop = lastPop * pChange;
		printf("%u\t%llu\t%llu\n", year, newPop, newPop - lastPop);
		lastPop = newPop;
	}
	puts("");
}