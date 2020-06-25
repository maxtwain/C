#include <stdio.h>

void stringReverse(char data[], int size);

int main(void) {

	char arr[] = "monument";
	stringReverse(arr, sizeof(arr) / sizeof(char));
	
}

void stringReverse(char data[], int size) {

	printf("%c", data[size - 1]);
	if (size > 1) {
		stringReverse(data, size - 1);
	}
	else {
		puts("");
	}
}