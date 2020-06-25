#include <stdio.h>

int countSeconds(int hours, int minutes, int seconds);

int main(void) {
	printf("countSeconds(5, 34, 41) = %d\n", countSeconds(5, 34, 41));
	printf("Seconds between 2:45:21 and 8:36:12 = %d\n", countSeconds(8, 36, 12) - countSeconds(2, 45, 21));
}

int countSeconds(int hours, int minutes, int seconds) {
	return seconds + 60 * minutes + 60 * 60 * hours;
}