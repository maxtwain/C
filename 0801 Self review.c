#include <stdio.h>
#include <ctype.h>
#include <string.h>

// There are many warnings on the internet which say to never use strcpy or strncpy, but these two functions are necessary for this chapter.

void partA(int c);
void partB(int c);
void partC(int c);
void partD(char s1[100]);
void partE(char s1[100]);
void partF(char* ptr, int c, char s1[100]);
void partG(int c);
void partH(int c);
void partI(int c);
void partJ(char* ptr, char s1[100], char s2[100]);
void partK(int c);
void partL(double d, double e, double f);
void partM(char s1[100], char s2[100]);
void partN(char* ptr, char s1[100], char s2[100]);
void partO(char s1[100], char s2[100]);
void partP(char* ptr, int c, char s1[100]);
void partQ(int x, int y, int z, char s1[100]);
void partR(char s1[100], char s2[100]);
void partS(char s1[100]);
void partT(char* ptr, char s2[100]);

int main(void) {
	int c = 'a';
	int x = -1;
	int y = 0;
	int z = 1;
	double d = -0.1;
	double e = 0.1;
	double f = 0.2;
	char* ptr = NULL;
	char s1[100] = "Elvis has left the building.";
	char s2[100] = "What goes up must come down.";

	/*
	partA(c);
	partB(c);
	partC(c);
	partD(s1);
	partE(s1);
	*/
	//partF(ptr, c, s1);
	//partG(c);
	//partH(c);
	//partI(c);
	//partJ(ptr, s1, s2);
	//partK(c);
	//partL(d, e, f);
	//partM(s1, s2);
	//partN(ptr, s1, s2);
	//partO(s1, s2);
	//partP(ptr, c, s1);
	//partQ(x, y, z, s1);
	//partR(s1, s2);
	//partS(s1);
	partT(ptr, s2);
}

void partA(int c) {
	puts("Part A");
	printf("c = %c or %d\n", c, c);
	c = toupper(c);
	printf("c = %c or %d\n", c, c);
	puts("");
}

void partB(int c) {
	puts("Part B");
	printf("c %s digit\n", isdigit(c) ? "is a" : "is not a");
	puts("");
}

void partC(int c) {
	puts("Part C");
	printf("c %s control character\n", iscntrl(c) ? "is a" : "is not a");
	puts("");
}

void partD(char s1[100]) {
	puts("Part D");
	puts("Enter a line of text.");
	fgets(s1, 100, stdin);
	printf("Entry: \"%s\"\n", s1);
	puts("");
}

void partE(char s1[100]) {
	puts("Part E");
	for (char* ptr = s1; *ptr != '\0'; ++ptr) {
		putchar(*ptr);
	}
	puts("\n");
}

void partF(char* ptr, int c, char s1[100]) {
	puts("Part F");
	printf("ptr = %p\n", ptr);
	ptr = strchr(s1, c);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %c", *ptr);
	puts("\n");
}

void partG(int c) {
	puts("Part G");
	putchar(c);
	puts("\n");
}

void partH(int c) {
	puts("Part H");
	printf("c %s letter\n", isalpha(c) ? "is a" : "is not a");
	puts("");
}

void partI(int c) {
	puts("Part I");
	printf("%s", "Enter a character: ");
	c = getchar();
	printf("%c was entered.", c);
	puts("\n");
}

void partJ(char* ptr, char s1[100], char s2[100]) {
	puts("Part J");
	printf("ptr = %p\n", ptr);
	ptr = strpbrk(s1, s2);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %c", *ptr);
	puts("\n");
}

void partK(int c) {
	puts("Part K");
	printf("c %s printing character\n", isprint(c) ? "is a" : "is not a");
	puts("");
}

void partL(double d, double e, double f) {
	puts("Part L");
	printf("d = %lf, e = %lf, f = %lf\n", d, e, f);
	sscanf_s("1.27 10.3 9.432", "%lf%lf%lf", &d, &e, &f);
	printf("d = %lf, e = %lf, f = %lf\n", d, e, f);
	puts("");
}

void partM(char s1[100], char s2[100]) {
	puts("Part M");
	printf("s1 = %s\n", s1);
	strcpy(s1, s2);
	printf("s1 = %s", s1);
	strcpy(s1, "Elvis has left the building.");
	puts("\n");
}

void partN(char* ptr, char s1[100], char s2[100]) {
	puts("Part N");
	printf("ptr = %p\n", ptr);
	ptr = strpbrk(s1, s2);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %c\n", *ptr);
	puts("");
}

void partO(char s1[100], char s2[100]) {
	puts("Part O");
	printf("s1 is alphabetized %s s2\n", strcmp(s1, s2) > 0 ? "after" : "before");
	puts("");
}

void partP(char* ptr, int c, char s1[100]) {
	puts("Part P");
	printf("ptr = %p\n", ptr);
	ptr = strchr(s1, c);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %c\n", *ptr);
	puts("");
}

void partQ(int x, int y, int z, char s1[100]) {
	puts("Part Q");
	printf("%s\n", s1);
	sprintf(s1, "%7d %7d %7d\n", x, y, z);
	printf("%s", s1);
	strcpy(s1, "Elvis has left the building.");
	puts("");
}

void partR(char s1[100], char s2[100]) {
	puts("Part R");
	printf("%s\n", s1);
	strncat(s1, s2, 10);
	printf("%s\n", s1);
	strcpy(s1, "Elvis has left the building.");
	puts("");
}

void partS(char s1[100]) {
	puts("Part S");
	printf("s1 length is %u\n", strlen(s1));
	puts("");
}

void partT(char* ptr, char s2[100]) {
	puts("Part T");
	strcpy(s2, "What,goes,up,must,come,down.");
	printf("ptr = %p\n", ptr);
	ptr = strchr(s2, ',');
	printf("ptr = %p\n", ptr);
	printf("*ptr = %c", *ptr);
	puts("");
}