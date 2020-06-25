#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

int product(int inCount, ...);

int main(void) {
	srand((unsigned int)time(NULL));

	int num0 = rand() % 100;
	int num1 = rand() % 100;
	int num2 = rand() % 100;

	printf("The product of three numbers: %d\n", product(3, num0, num1, num2));

}

int product(int inCount, ...) {
	int p = 1;
	va_list ap;

	va_start(ap, inCount);

	for (int i = 0; i < inCount; ++i) {
		p *= va_arg(ap, int);
	}
	va_end(ap);
	return p;
}