#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct {
	char name[20];
	char gender;
	char playerType;
	char countryCode[4];
	int ranking;
} Player;

int p4q1() {
	Player p;
	FILE* fptr;

	fptr = fopen("badmintonPlayers.txt", "w");
	if (fptr == NULL) {
		printf("Unable to open file.\n");
		exit(-1);
	}

	for (int i = 1; ; i++) {
		//Player number
		printf("Player %d\n", i);
		printf("---------\n");

		//Player name input
		printf("Enter name: ");
		scanf("%[^\n]", p.name);
		rewind(stdin);
		if (strcmp(p.name,"XXX") == 0) break; //If player name is XXX, stop the program

		//Player gender input
		printf("Enter gender (M/F): ");
		scanf("%c", &p.gender);
		rewind(stdin);

		//Player type input
		printf("Enter player type (S = singles, D = doubles, X = mixed doubles): ");
		scanf("%c", &p.playerType);
		rewind(stdin);

		//Player country code input
		printf("Enter country code: ");
		scanf("%s", p.countryCode);
		rewind(stdin);

		//Player ranking Input
		printf("Enter ranking: ");
		scanf("%d", &p.ranking);
		rewind(stdin);

		fprintf(fptr, "%s|%c|%c|%s|%d\n", p.name, p.gender, p.playerType, p.countryCode, p.ranking);
		printf("\nRecord added successfully\n");
		system("pause");
		system("cls");
	}

	fclose(fptr);

	//Q2
	int playerCount = 0;

	printf("\t\tList of Players\n\n");
	printf("%-20s\t%-10s\t%-10s\t%-20s\t%-10s\n", "Name", "Gender", "Country", "Game Type", "Ranking");
	printf("----------------------------------------------------------------------------------------\n");
	
	fptr = fopen("badmintonPlayers.txt", "r");
	if (fptr == NULL) {
		printf("Unable to open file.\n");
		exit(-1);
	}

	while (!feof(fptr)) {
		char gameType[20] = ""; //Reset string gameType
		fscanf(fptr, "%[^\|]|%c|%c|%[^\|]|%d\n", &p.name, &p.gender, &p.playerType, &p.countryCode, &p.ranking);

		//Create gameType sentence
		strcat(gameType, (toupper(p.gender) == 'M') ? "Men's " : "Women's ");
		if (p.playerType == 'S') strcat(gameType, "Singles");
		else if (p.playerType == 'D') strcat(gameType, "Doubles");
		else if (p.playerType == 'X') strcat(gameType, "Mixed Doubles");

		printf("%-20s\t%-10c\t%-10s\t%-20s\t%-10d\n",p.name,p.gender,p.countryCode,gameType,p.ranking);
		playerCount++;
	}

	printf("\t%d players listed\n", playerCount);
	fclose(fptr);

	system("pause");
	return 0;
}