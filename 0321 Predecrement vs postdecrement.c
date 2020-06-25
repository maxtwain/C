#include <stdio.h>

int main(void) {
	int i = 0;
	printf_s("i = %d\n", i);
	printf_s("%s", "\n");

	printf_s("i++ = %d\n", i++);
	printf_s("i++ = %d\n", i++);
	printf_s("i++ = %d\n", i++);
	printf_s("%s", "\n");

	printf_s("++i = %d\n", ++i);
	printf_s("++i = %d\n", ++i);
	printf_s("++i = %d\n", ++i);
	printf_s("%s", "\n");

	printf_s("--i = %d\n", --i);
	printf_s("--i = %d\n", --i);
	printf_s("--i = %d\n", --i);
	printf_s("%s", "\n");

	printf_s("i-- = %d\n", i--);
	printf_s("i-- = %d\n", i--);
	printf_s("i-- = %d\n", i--);
	printf_s("%s", "\n");
}