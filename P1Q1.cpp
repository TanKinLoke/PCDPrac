#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

struct Attendance {
	char studentName[25];
	char programmeCode[4];
	int yearOfStudy;
	int groupNo;
	int daysAbsent;
};

int p1q1() {
	char action[20];
	struct Attendance att;
	
	//printf("Please enter the student's name: ");
	//scanf("%[^\n]s", &att.studentName);
	//rewind(stdin);
	//printf("Please enter the programme code: ");
	//scanf("%s", &att.programmeCode);
	//printf("Please enter the year of study: ");
	//scanf("%d", &att.yearOfStudy);
	//printf("Please enter your tutorial group: ");
	//scanf("%d", &att.groupNo);
	//printf("Please enter the number of days absent: ");
	//scanf("%d", &att.daysAbsent);

	strcpy(att.studentName, "Tan Ah Kow");
	strcpy(att.programmeCode, "AACS");
	att.yearOfStudy = 2021;
	att.groupNo = 2;
	att.daysAbsent = 3;

	if (att.daysAbsent == 1 || att.daysAbsent == 2) {
		strcpy(action, "warning to student");
	} else if (att.daysAbsent == 3 || att.daysAbsent == 4) {
		strcpy(action, "inform parents");
	} else if (att.daysAbsent >= 5) {
		strcpy(action, "bar from exam");
	}
	printf("%-15s %-10s %-5s %-15s %-20s\n", "Name", "Programme", "Group", "Days Absent", "Action");
	printf("%-15s %-10s %-5d %-15d %-20s\n", &att.studentName, &att.programmeCode, att.groupNo, att.daysAbsent, action);
	system("pause");

	return 0;
}