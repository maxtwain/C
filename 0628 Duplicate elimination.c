#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a quote from microsoft: "Variable length arrays are not currently supported in Visual C++."  Found here: "https://msdn.microsoft.com/en-us/library/zb1574zs.aspx"

void foo(int size);

int main(void) {

	srand((unsigned)time(NULL));
	int unique = 0;
	for (int count = 0; count < 20; ++count) {
		int num = 1 + rand() % 20;
		int numbers1[count] = { 0 };
	}

	int n;
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	int board[n][n];
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			board[i][j] = 0;
		}
}

void foo(int size) {
	int array[size];
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}
}