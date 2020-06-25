#include <stdio.h>
#include <math.h>

int mystery(int a, int b);

int main(void) {
	printf("%s", "Enter two integers: ");
	int x;
	int y;
	scanf("%d%d", &x, &y);

	printf("The result is %d\n", mystery(x, y));
}

// sums a + a recursively
int mystery(int a, int b) {
	if (abs(b) != b) {
		a = -a;
		b = -b;
	}
	if (1 == b) {
		return a;
	}
	else {
		return a + mystery(a, b - 1);
	}
}