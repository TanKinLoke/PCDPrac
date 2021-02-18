#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int p3q1() {

	FILE* fptr;
	FILE* fptr2;
	fptr = fopen("numbers.txt", "r");
	fptr2 = fopen("results.txt", "w");
	int num, sum = 0, count = 0;
	double average;

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	while (fscanf(fptr, "%d", &num) != EOF)
	{
		sum += num;
		count++;
	}

	average = (double)sum / count;
	fclose(fptr);

	printf("Total = %d \n", sum);
	printf("Average = %.2lf \n", average);
	fprintf(fptr2, "Total is %d and Average is %.2lf", sum, average);

	fclose(fptr2);

	printf("Process completed :D\n");

	system("pause");

	return 0;
}