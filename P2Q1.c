#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct {
	char performerName[20];
	char songName[20];
	int yearReleased;
	int totalPlayingTime;
}Songs;

int p2q1() {
	Songs songList[10] = {
		{"Ed Sheeran", "Perfect", 2019, 265},
		{"Taylor Swift", "Love", 2008, 286},
		{"Justin Bieber", "Sorry", 2018, 296},
		{"Dwayne Konny", "Goodbye", 2019, 278},
		{"Stephen James", "Nothing", 2014, 274},
		{"Jay Rolling", "Monkey", 2016, 284},
		{"Tammy Don", "Elephant", 2017, 284},
		{"David Janson", "Mango", 2020, 274},
		{"Jeff Bezos", "Apple", 2010, 256},
		{"Mandy Wade", "Orange", 2015, 273}
	};

	char keyword[20];
	int startTime, endTime;

	printf("1)Please enter performer name: ");
	scanf("%[^\n]s", &keyword);
	printf("\n2)Playing time from: ", &startTime);
	scanf("%d", &startTime);
	printf("\n2)Playing time to: ", &endTime);
	scanf("%d", &endTime);


	printf("\t\tMy Collection Songs\n");
	printf("\t\t===================\n");
	//printf("\t\tList of songs - 2015 and earlier\n");
	//printf("\t\t================================\n");
	printf("%-20s\t%-20s\t%-10s\t%-20s\n", "Performer's Name", "Song Name", "Year", "Playing Time");
	printf("--------------------------------------------------------------------------------------\n");

	//Display all
	/*for (int i = 0; i < 10; i++) {
		printf("%-20s\t%-20s\t%-10d\t%-ds\n", songList[i].performerName, songList[i].songName, songList[i].yearReleased, songList[i].totalPlayingTime);
	}*/

	//Display 2015
	/*int quantity = 0;

	for (int i = 0; i < 10; i++) {
		if (songList[i].yearReleased <= 2015) {
			printf("%-20s\t%-20s\t%-10d\t%-ds\n", songList[i].performerName, songList[i].songName, songList[i].yearReleased, songList[i].totalPlayingTime);
			quantity++;
		}
	}

	printf("%d songs listed\n", quantity);*/

	int quantity = 0;

	for (int i = 0; i < 10; i++) {
		if (strstr(songList[i].performerName, keyword) && songList[i].totalPlayingTime >= startTime && songList[i].totalPlayingTime <= endTime) {
			printf("%-20s\t%-20s\t%-10d\t%-ds\n", songList[i].performerName, songList[i].songName, songList[i].yearReleased, songList[i].totalPlayingTime);
			quantity++;
		}
	}

	if (quantity == 0) {
		printf("No record found\n");
	}
	
	system("pause");
}