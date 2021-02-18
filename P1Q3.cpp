#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

typedef struct{
	int hours;
	int minutes;
} Time;

int p1q3() {
	Time current;
	Time nextMin;

	printf("Enter the current time: ");
	scanf("%d:%d",&current.hours,&current.minutes);
	nextMin.hours = current.hours;
	nextMin.minutes = current.minutes;

	nextMin.minutes += 1;

	if (nextMin.minutes > 59) {
		nextMin.minutes -= 60;
		nextMin.hours += 1;
	}

	if (nextMin.hours > 12) {
		nextMin.hours -= 12;
	}

	printf("It is now  %02d:%02d. The next minute is %02d:%02d\n", current.hours, current.minutes, nextMin.hours, nextMin.minutes);
	system("pause");
	return 0;
}