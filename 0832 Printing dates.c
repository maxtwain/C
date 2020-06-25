#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void reprintDate(char* inDate);
void printRandomDates();
int rDay(int month, int year);

int main(void) {
	char* date[50] = { "04/24/2016", "08/10/2720", "11/23/1255", "04/07/1470", "08/10/2720", "12/24/1096", "08/05/1608", "09/20/1685", "09/21/1563", "06/01/2964", "02/05/2844", "03/16/1186", "03/01/1205", "05/01/2744", "03/06/2313", "02/08/1820", "03/28/1317", "11/16/1454", "04/02/1497", "12/23/2425", "06/10/2123", "05/14/2184", "06/19/1217", "03/29/1510", "04/05/2075", "11/22/2758", "02/21/1370", "07/19/1425", "07/20/2509", "08/14/2924", "11/24/2749", "02/17/1209", "05/23/1544", "11/08/1559", "01/31/1025", "01/28/1124", "12/02/2639", "02/25/2722", "03/01/2633", "09/25/1986", "11/18/1388", "10/04/2660", "08/09/2649", "04/18/2273", "05/19/2251", "08/24/2957", "09/04/2264", "01/19/1984", "06/23/1001", "10/22/2785" };

	reprintDate(date[0]);
	
	puts("\n");
}

void reprintDate(char* inDate) {
	char* dayPtr = NULL;
	int month = strtol(inDate, &dayPtr, 10);
	++dayPtr;
	char* yearPtr = NULL;
	int day = strtol(dayPtr, &yearPtr, 10);
	++yearPtr;
	int year = strtol(yearPtr, NULL, 10);
	char* monthName[20] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	printf("%s is %s %d, %d\n", inDate, monthName[month - 1], day, year);
}

void printRandomDates() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 50; ++i) {
		int month = 1 + rand() % 12;
		int year = 1'000 + rand() % 2000;
		int day = rDay(month, year);
		printf("\"%02d/%02d/%d\", ", month, day, year);
	}
}

int rDay(int month, int year) {
	int leapYear = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		leapYear = 1;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12) {
		return 1 + rand() % 31;
	}
	else if (month == 2 && leapYear) {
		return 1 + rand() % 29;
	}
	else if (month == 2) {
		return 1 + rand() % 28;
	}
	else {
		return 1 + rand() % 30;
	}
}



