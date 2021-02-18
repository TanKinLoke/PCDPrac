#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning (disable:4996)

int p3q2() {
	FILE* fptr;
	fptr = fopen("text.txt", "r");
	int ch;
	int wordCount = 0, charCount = 0, letterCount = 0, spaceCount = 0, vowelCount = 0, consonantCount = 0;

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	while ((ch = fgetc(fptr)) != EOF) {
		charCount++;
		if (ch == ' ') spaceCount++;
		if (isalpha(ch)) letterCount++;
		(ch != ' ' && toupper(ch) == 'A' || toupper(ch) == 'E' || toupper(ch) == 'I' || toupper(ch) == 'O' || toupper(ch) == 'U') ? vowelCount++ : consonantCount++;
	}

	wordCount = spaceCount++;

	fclose(fptr);

	printf("%-30s %d\n", "Total number of characters", charCount);
	printf("%-30s %d\n", "Number of letters", letterCount);
	printf("%-30s %d\n", "Number of vowels", vowelCount);
	printf("%-30s %d\n", "Number of consonants", consonantCount);
	printf("%-30s %d\n", "Number of blanks (spaces)", spaceCount);
	printf("%-30s %d\n", "Approx no. of words", wordCount);

	system("pause");
	return 0;
}