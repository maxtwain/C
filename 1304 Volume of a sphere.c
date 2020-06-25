#include <stdio.h>

#define SVOLUME(x) (4.0 / 3.0 * 3.14159 * (x) * (x) * (x)) 

int main(void) {

	printf("%8s %-15s\n", "Radius", "Volume");
	for (int i = 0; i < 10; ++i) {
		printf("%8d %-15f\n", i, SVOLUME((float)i));
	}

}