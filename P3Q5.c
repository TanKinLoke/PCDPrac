#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int p3q5() {
	char fileName[20], ch, testChar[2];
	int count[27] = {0}, test;
	FILE* fptr;

	printf("Enter the filename: ");
	scanf("%[^\n]", fileName);
	strcat(fileName, ".txt");

	fptr = fopen(fileName, "r");
	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	while ((ch = fgetc(fptr)) != EOF) {
		if (ch == ' ') {
			count[26]++;
		}
		else {
			ch = toupper(ch);
			count[ch - 'A']++;
		}
	}

	printf("Letter :-\n");

	for (int i = 0; i < 26; i++) {
		printf("\t%c = %d\n", i + 65, count[i]);
	}

	printf("No. of Words = %d\n", count[26] + 1);
	fclose(fptr);
	system("pause");
	return 0;
}