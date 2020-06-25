#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW 4
#define COL 6

void slip(int personNum, int productNum, double sales, double record[ROW][COL]);

int main(void) {
	srand((unsigned int)time(NULL));

	// generate random values
	int powerRand = 0;
	double salesRand = 0;
	double record[ROW][COL] = { 0 };
	for (size_t slipCount = 0; slipCount < 1'000; ++slipCount) {
		powerRand = (int)pow(10, 3 + rand() % 5);
		salesRand = (double)(rand() % powerRand) / 100;
		slip(1 + rand() % 4, 1 + rand() % 5, salesRand, record);
	}

	// sum employee sales
	for (size_t person = 0; person < ROW; ++person) {
		for (size_t item = 0; item < COL - 1; ++item) {
			record[person][5] += record[person][item];
		}
	}

	// print array
	printf("%10s%11s%11s%11s%11s%11s", "Employee:", "1", "2", "3", "4", "Item Sums");
	double itemSum;
	for (size_t item = 0; item < COL; ++item) {
		itemSum = 0.0;
		if (item < COL - 1) {
			printf("\n%7s %u:", "Item", item);
		}
		else {
			printf("\n%9s:", "Sums");
		}
		for (size_t person = 0; person < ROW; ++person) {
			printf("%11.2lf", record[person][item]);
			itemSum += record[person][item];
		}
		printf("%11.2lf", itemSum);
	}
	puts("\n");
}

void slip(int personNum, int productNum, double sales, double record[ROW][COL]) {
	record[personNum - 1][productNum - 1] += sales;
}