#include <stdio.h>

// Global warming is boring.  I am doing a quiz on country capitals instead.

int romania();
int southAfrica();
int newZealand();
int venezuela();
int sriLanka();

int main(void) {
	int correct = 0;
	if (romania()) ++correct;
	if (southAfrica()) ++correct;
	if (newZealand()) ++correct;
	if (venezuela()) ++correct;
	if (sriLanka()) ++correct;

	if (correct == 5) puts("Excellent");
	if (correct == 4) puts("Very good");
	if (correct <= 3) puts("Time to brush up on your knowledge of world capitals");

}

int romania() {
	char answer = '0';
	char newline = '0';
	printf("%s", "What is the capital of Romania?\na) Dhaka b) Tianjin c) Bucharest d) Durban: ");
	scanf(" %c", &answer);
	newline = getchar();
	if (answer == 'c') return 1;
	return 0;
}

int southAfrica() {
	char answer = '0';
	char newline = '0';
	printf("%s", "What is the capital of South Africa?\na) Cape Town b) Johannesburg c) Pune c) New Taipei City d) Lagos: ");
	scanf(" %c", &answer);
	newline = getchar();
	if (answer == 'a') return 1;
	return 0;
}

int newZealand() {
	char answer = '0';
	char newline = '0';
	printf("%s", "What is the capital of New Zealand?\na) Manila b) Riyadh c) Saitiago d) Wellington: ");
	scanf(" %c", &answer);
	newline = getchar();
	if (answer == 'd') return 1;
	return 0;
}

int venezuela() {
	char answer = '0';
	char newline = '0';
	printf("%s", "What is the capital of Venezuela?\na) Caracas b) Kingston c) Yangon d) Lima: ");
	scanf(" %c", &answer);
	newline = getchar();
	if (answer == 'a') return 1;
	return 0;
}

int sriLanka() {
	char answer = '0';
	char newline = '0';
	printf("%s", "What is the capital of Sri Lanka?\na) Canberra b) Kiev c) Riyadh d) Columbia: ");
	scanf(" %c", &answer);
	newline = getchar();
	if (answer == 'd') return 1;
	return 0;
}