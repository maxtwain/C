#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main(void) {
	printf("distance( 3.0, 4.0, 5.0, 4.0) = %lf\n", distance(3, 4, 5, 4));
	printf("distance( 10, 14, 26, 37) = %lf\n", distance(10, 14, 26, 37));
	printf("distance( .3, .04, .56, .87) = %lf\n", distance(.3, .04, .56, .87));
	printf("distance( -3.45, 4, -6.4, .07) = %lf\n", distance(-3.45, 4, -6.4, .07));
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}