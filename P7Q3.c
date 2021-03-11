#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

int markIsValid(int, int);
int finalMark(int, int, int);

void main()
{
	int practicalMark, courseworkMark, examMark;

	do {
		printf("Enter your practical mark (0 to 30) : ");
		scanf("%d", &practicalMark);
	} while (!markIsValid(practicalMark, 30));
	printf("\n");
	do {
		printf("Enter your coursework mark (0 to 20) : ");
		scanf("%d", &courseworkMark);
	} while (!markIsValid(courseworkMark, 20));
	printf("\n");
	do {
		printf("Enter your exam mark (0 to 50) : ");
		scanf("%d", &examMark);
	} while (!markIsValid(examMark, 50));
	printf("\n");

	printf("Final Marks : %d", finalMark(practicalMark, courseworkMark, examMark));
	printf("\n");
	system("pause");
}

int markIsValid(int mark, int maxMark)
{
	int result;

	if (mark < 0 || mark > maxMark)
	{
		return 0;
	}
	else {
		return 1;
	}
	return 1;
}

int finalMark(int prac, int cw, int exam)
{
	int finalScore;

	finalScore = prac + cw + exam;

	return finalScore;
}