#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

//Function declaration
void addQuestion();
void ansQuestion();

int p4q6() {
	int option;

	do {
		//Main Menu
		printf("Main Menu:\n");
		printf("----------\n");
		printf("1) Add more Question and Answers to the Quiz\n");
		printf("2) Answer the Quiz\n");
		printf("3) Exit\n\n");

		//Option Input
		printf("Option: ");
		scanf("%d", &option);
		rewind(stdin);

		if (option == 1) {
			system("cls");
			addQuestion();
		}
		else if (option == 2) {
			system("cls");
			ansQuestion();
		}
		else if (option == 3) {
			break;
		}
		else {
			printf("Please insert a valid option.\n");
		}

		system("cls");
	} while (option != 3);

	system("pause");
	return 0;
	
}

//Q7
void addQuestion() {
	FILE *fptr;
	FILE* fptr2;
	char question[100], answer[100], reply;

	do {
		fptr = fopen("Questions.txt", "a");
		fptr2 = fopen("Answers.txt", "a");

		if (fptr == NULL)
		{
			printf("Unable to open file.\n");
			exit(-1);
		}

		if (fptr2 == NULL)
		{
			printf("Unable to open file.\n");
			exit(-1);
		}

		//Question input
		printf("Question: ");
		scanf("%[^\n]", question);
		rewind(stdin);

		//Answer input
		printf("Answer: ");
		scanf("%[^\n]", answer);
		rewind(stdin);

		//Print into Question.txt and Answer.txt
		fprintf(fptr, "%s\n", question);
		fprintf(fptr2, "%s\n", answer);
		printf("Question and answer added successfully.\n");

		//Continue or not
		printf("Any more questions to add (Y/N)? ");
		scanf("%c", &reply);
		rewind(stdin);
		system("cls");
	} while (toupper(reply) == 'Y');
	
	fclose(fptr);
	fclose(fptr2);
}

void ansQuestion() {
	FILE* fptr;
	FILE* fptr2;
	char question[100], answer[100], userAnswer[100], reply;
	int noOfQuestion = 0, noOfCorrect = 0, score;

	fptr = fopen("Questions.txt", "r");
	fptr2 = fopen("Answers.txt", "r");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	if (fptr2 == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	while (!feof(fptr) && !feof(fptr2)) {
		fscanf(fptr, "%[^\n]\n", question);
		fscanf(fptr2, "%[^\n]\n", answer);

		//Print the question
		printf("Question: %s\n", question);
		noOfQuestion++;

		//User input answer
		printf("Answer: ");
		scanf("%[^\n]", userAnswer);
		rewind(stdin);

		//Compare user's answer with the answer
		if (strcmp(answer, userAnswer) == 0) {
			printf("Correct!\n");
			noOfCorrect++;
		}
		else {
			printf("Wrong! The answer should be %s\n\n", answer);
		}

		//Ask if continue if there is next question
		if (!feof(fptr) && !feof(fptr2)) {
			printf("Continue (Y/N)? ");
			scanf("%c", &reply);
			rewind(stdin);
			
			if (toupper(reply) != 'Y') goto outer; //End while loop
			else system("cls");
		}	
		
	}

	outer:
	score = (double)noOfCorrect / noOfQuestion * 100;

	printf("Thanks for answering the questions\n");
	printf("Number of correct answers = %d\n", noOfCorrect);
	printf("Total number of questions = %d\n", noOfQuestion);
	printf("\tYour score: %d%%\n", score);
	system("pause");

	fclose(fptr);
	fclose(fptr2);
}