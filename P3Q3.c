#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//Function declaration
void displayRecords();
void addRecords();

int p2q3() {
	addRecords();
	displayRecords();

	system("pause");
	return 0;
}

//Q3
void displayRecords() {
	char name[20];
	int mark, count = 0;

	FILE* fptr;
	fptr = fopen("mixed.txt", "r");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	printf("LIST OF RECORDS - mixed.txt\n");
	printf("\t%-20s\t%-5s\n","NAME","MARK");
	printf("\t%-20s\t%-5s\n", "====", "====");

	while (!feof(fptr)) {
		fscanf(fptr,"%[^\n]\n%d\n",name,&mark);
		rewind(stdin);
		printf("\t%-20s\t%d\n", name, mark);
		count++;
	}
	printf("\n\tNumber of records = %d\n", count);

	fclose(fptr);
}

//Q4
void addRecords() {
	char answer, name[20];
	int mark, count = 0;
	FILE* fptr;
	fptr = fopen("mixed.txt", "a");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	printf("Add Records\n");
	printf("-----------\n");

	printf("Add another record (Y = yes)? ");
	scanf("%c", &answer);
	rewind(stdin);
	while (toupper(answer) == 'Y') {
		printf("\tName: ");
		scanf("%[^\n]s", name);
		rewind(stdin);
		printf("\tMark: ");
		scanf("%d", &mark);
		rewind(stdin);

		fprintf(fptr, "%s\n%d\n", name, mark);
		printf("Record successfully added...\n");
		count++;

		printf("Add another record (Y = yes)? ");
		scanf("%c", &answer);
		rewind(stdin);
	}

	printf("%d records have been added to mixed.txt\n", count);

	fclose(fptr);
}