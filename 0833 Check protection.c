#include <stdio.h>

void checkProtected(double payment);

int main(void) {

	checkProtected(99.87);

	puts("\n");
}

void checkProtected(double payment) {
	char buffer[10];
	char* bufPtr = NULL;

	snprintf(buffer, sizeof(buffer), "%9.2f", payment);
	for (bufPtr = buffer; *bufPtr == ' '; ++bufPtr) {
		*bufPtr = '*';
	}
	
	printf("%s\n", buffer);
}