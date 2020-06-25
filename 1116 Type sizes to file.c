#include <stdio.h>

typedef struct typesize {
	char type[100];
	int size;
} Typesize;

void createFile();
void printFile();

int main(void) {
	
	createFile();
	printFile();

}

void createFile() {
	
	Typesize arr[11] = { { "char", sizeof(char) },{ "unsigned char", sizeof(unsigned char) },{ "short int", sizeof(short int) },{ "unsigned short int", sizeof(unsigned short int) },{ "int", sizeof(int) },{ "unsigned int", sizeof(unsigned int) },{ "long int", sizeof(long int) },{ "unsigned long int", sizeof(unsigned long int) },{ "float", sizeof(float) },{ "double", sizeof(double) },{ "long double", sizeof(long double) } };

	FILE* fPtr;
	if ((fPtr = fopen("datasize.dat", "wb")) == NULL) {
		puts("Error opening datasize.dat for wb");
		return;
	}

	for (int i = 0; i < 11; ++i) {
		fwrite(&arr[i], sizeof(Typesize), 1, fPtr);
	}
	
	fclose(fPtr);
}

void printFile() {
	FILE* fPtr;

	if ((fPtr = fopen("datasize.dat", "rb")) == NULL) {
		puts("Error opening datasize.dat for rb");
		return;
	}

	printf("%-20s%5s\n", "Data type", "Size");
	Typesize toScreen = { "", 0 };
	while (fread(&toScreen, sizeof(Typesize), 1, fPtr)) {
		printf("%-20s%5d\n", toScreen.type, toScreen.size);
	}
	puts("");

	fclose(fPtr);
}