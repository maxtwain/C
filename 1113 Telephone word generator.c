#include <stdio.h>
#include <string.h>

char* getPhoneNumber(char* userPhone);
void writeWords(char* userPhone);
void printWords();

int main(void) {

	char userPhone[100] = "";
	getPhoneNumber(userPhone);
	writeWords(userPhone);
	printWords();
}

char* getPhoneNumber(char* userPhone) {

	puts("Enter a seven digit phone number to generator words.");
	char line[100];
	fgets(line, 99, stdin);
	char* token = strtok(line, "- \n");
	strcpy(userPhone, token);
	token = strtok(NULL, "- \n");
	strcat(userPhone, token);

	return userPhone;
}

void writeWords(char* userPhone) {
	
	char match[8][3] = { { "ABC" },{ "DEF" },{ "GHI" },{ "JKL" },{ "MNO" },{ "PRS" },{ "TUV" },{ "WXY" } };

	FILE* fPtr;
	if ((fPtr = fopen("phoneWord.txt", "wb")) == NULL) {
		puts("Error opening file for wb");
		return;
	}

	char phoneWord[8] = "";
	for (int i0 = 0; i0 < 3; ++i0) {
		for (int i1 = 0; i1 < 3; ++i1) {
			for (int i2 = 0; i2 < 3; ++i2) {
				for (int i3 = 0; i3 < 3; ++i3) {
					for (int i4 = 0; i4 < 3; ++i4) {
						for (int i5 = 0; i5 < 3; ++i5) {
							for (int i6 = 0; i6 < 3; ++i6) {
								phoneWord[0] = match[userPhone[0] - '0' - 2][i0];
								phoneWord[1] = match[userPhone[1] - '0' - 2][i1];
								phoneWord[2] = match[userPhone[2] - '0' - 2][i2];
								phoneWord[3] = match[userPhone[3] - '0' - 2][i3];
								phoneWord[4] = match[userPhone[4] - '0' - 2][i4];
								phoneWord[5] = match[userPhone[5] - '0' - 2][i5];
								phoneWord[6] = match[userPhone[6] - '0' - 2][i6];
								fwrite(phoneWord, strlen(phoneWord), 1, fPtr);
							}
						}
					}
				}
			}
		}
	}

	fclose(fPtr);
}

void printWords() {
	FILE* fPtr;
	if ((fPtr = fopen("phoneWord.txt", "rb")) == NULL) {
		puts("Error opening file for rb");
		return;
	}

	char word[8] = "";
	while (fread(word, sizeof(char), 7, fPtr)) {
		printf("%s\t", word);
	}
	fclose(fPtr);
}