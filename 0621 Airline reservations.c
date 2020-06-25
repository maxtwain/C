#include <stdio.h>

void seatFirst(int seats[]);
void seatEcon(int seats[]);
void boardingPass(int seat);

int main(void) {

	int seats[10] = { 0 };
	int seatingFull = 0;
	while (seatingFull == 0) {

		int userInt = 0;
		seatingFull = 1;
		for (size_t index = 0; index < 10; ++index) {
			if (seats[index] == 0) seatingFull = 0;
		}
		if (seatingFull == 0) {
			char userChar = '0';
			puts("Please type 1 for \"first class\"");
			puts("Please type 2 for \"economy\"");
			scanf_s("%d", &userInt);

			if (userInt == 1) {
				seatFirst(seats);
			}
			else if (userInt == 2) {
				seatEcon(seats);
			}
		}
		else {
			puts("Seating for this flight is at capacity.\nNext flight leaves in 3 hours.\n");
		}
	}
}

void seatFirst(int seats[]) {
	// check for availability
	int firstAvailable = 0;
	for (size_t index = 0; index < 5; ++index) {
		if (seats[index] == 0) {
			firstAvailable = 1;
		}
	}

	if (firstAvailable == 1) {
		int seated = 0;
		for (size_t index = 0; index < 5 && seated == 0; ++index) {
			if (seats[index] == 0) {
				seats[index] = 1;
				seated = 1;
				boardingPass(index);
			}
		}
	}
	else {
		char userChar, c;
		printf("\n%s", "First class is full.  Is economy seating acceptable?  (y / n)  ");
		scanf(" %c", &userChar);
		c = getchar();
		if (userChar == 'y') {
			seatEcon(seats);
		}
		else {
			puts("Next flight leaves in 3 hours.\n");
		}
	}
}

void seatEcon(int seats[]) {
	// check for availability
	int econAvailable = 0;
	for (size_t index = 5; index < 10; ++index) {
		if (seats[index] == 0) {
			econAvailable = 1;
		}
	}

	if (econAvailable == 1) {
		int seated = 0;
		for (size_t index = 5; index < 10 && seated == 0; ++index) {
			if (seats[index] == 0) {
				seats[index] = 1;
				seated = 1;
				boardingPass(index);
			}
		}
	}
	else {
		char userChar, c;
		printf("\n%s", "Economy class is full.  Is first class seating acceptable?  (y / n)  ");
		scanf(" %c", &userChar);
		c = getchar();
		if (userChar == 'y') {
			seatFirst(seats);
		}
		else {
			puts("Next flight leaves in 3 hours.\n");
		}
	}
}

void boardingPass(int seat) {
	printf("\nPurchase successful.\nSeat #%d\n", seat + 1);
	if (seat < 5) {
		puts("First class\n");
	}
	else {
		puts("Economy section\n");
	}
}