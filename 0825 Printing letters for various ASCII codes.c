#include <stdio.h>

int main(void) {

	printf("%s", "Enter ASCII code: ");
	int num = 0;
	scanf_s("%d", &num);
	printf("Character = %c\n", (char)num);
	
	puts("\n");
}