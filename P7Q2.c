#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

void dayOfWeek(int);

void p7q2()
{
	int input;
	printf("Please enter a number between 0 and 6: ");
	scanf("%d", &input);

	while (input < 0 || input > 6)
	{
		printf("Invalid number. Please enter a number between 0 and 6: ");
		scanf("%d", &input);
	}
	printf("\n");
	dayOfWeek(input);
	printf("\n");
	system("pause");
}

void dayOfWeek(int input)
{
	switch (input)
	{
	case 0:
		printf("Sunday.");
		break;
	case 1:
		printf("Monday.");
		break;
	case 2:
		printf("Tuesday.");
		break;
	case 3:
		printf("Wednesday.");
		break;
	case 4:
		printf("Thursday.");
		break;
	case 5:
		printf("Friday.");
		break;
	case 6:
		printf("Saturday.");
		break;
	default:
		printf("???");
		break;

	}
}