#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

double inchToCm(double);

void p7q1()
{
	double input, result;
	printf("Enter length in inches: ");
	scanf("%lf", &input);
	printf("\n");
	result = inchToCm(input);
	printf("Entered length in CM: %.2lf\n", result);
	system("pause");
}

double inchToCm(double input)
{
	double result;

	result = input * 2.54;

	return result;
}