#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct {
	char studentID[6];
	char studentName[20];
	double cgpa;
} Student;

int p4q3() {
	Student stud;
	char answer;
	int count = 0;
	FILE* fptr;
	FILE* fptr2;
	fptr = fopen("Student.txt", "w");
	fptr2 = fopen("BookPrize.txt", "w");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}
	
	do {
		printf("Add students\n");
		printf("------------\n");

		//Student ID input
		printf("Student ID: ");
		scanf("%s", stud.studentID);
		rewind(stdin);

		//Student Name input
		printf("Student Name: ");
		scanf("%[^\n]", stud.studentName);
		rewind(stdin);
		
		//Student CGPA input
		printf("CGPA: ");
		scanf("%lf", &stud.cgpa);
		rewind(stdin);

		//Print into Student.txt
		fprintf(fptr, "%s|%s|%4.2lf\n", stud.studentID, stud.studentName, stud.cgpa);

		//Q5, print into BookPrize.txt
		if (stud.cgpa >= 3.5) {
			fprintf(fptr2, "%s|%s|%4.2lf\n", stud.studentID, stud.studentName, stud.cgpa);
			count++;
		}

		printf("Record added successfully.\n");

		printf("Any more records (Y/N)? ");
		scanf("%c", &answer);
		rewind(stdin);
		system("cls");
	} while (toupper(answer) == 'Y');

	printf("%d records(s) copied to BookPrize.txt\n", count);

	fclose(fptr);

	//Q4
	fptr = fopen("Student.txt", "r");
	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	printf("\t\tList of Students\n\n");
	printf("%-10s\t%-20s\t%-5s\n", "Student ID", "Name", "CGPA");
	printf("%-10s\t%-20s\t%-5s\n", "==========", "====", "====");

	while (!feof(fptr)) {
		fscanf(fptr, "%[^\|]|%[^\|]|%lf\n", stud.studentID, stud.studentName, &stud.cgpa);
		printf("%-10s\t%-20s\t%4.2lf\n", stud.studentID, stud.studentName, stud.cgpa);
	}

	fclose(fptr2);

	system("pause");
	return 0;
}