#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_SIZE 20

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char employeeID[4];
	char name[20];
	Date date;
	char department[15];
} Employee;

void displayAll(Employee emp[], int nEmployees) {
	int quantity = 0;
	printf("\t\tEmployee Details\n");
	printf("\t\t================\n");
	printf("%-15s\t%-20s\t%-15s\t%-15s\n", "Employee ID", "Name", "Date Joined", "Department");
	for (int i = 0; i < nEmployees; i++) {
		printf("%-15s\t%-20s\t%02d/%02d/%02d\t%-15s\n", emp[i].employeeID, emp[i].name, emp[i].date.day, emp[i].date.month, emp[i].date.year, emp[i].department);
		quantity++;
	}

	printf("%d records listed\n", quantity);
}

void search(Employee emp[], int nEmployees) {
	int quantity = 0;
	int monthSearch;

	printf("Enter month: ");
	scanf("%d", &monthSearch);

	printf("\t\tEmployee Details\n");
	printf("\t\t================\n");
	printf("%-15s\t%-20s\t%-15s\t%-15s\n", "Employee ID", "Name", "Date Joined", "Department");
	for (int i = 0; i < nEmployees; i++) {
		if (emp[i].date.month == monthSearch) {
			printf("%-15s\t%-20s\t%02d/%02d/%02d\t%-15s\n", emp[i].employeeID, emp[i].name, emp[i].date.day, emp[i].date.month, emp[i].date.year, emp[i].department);
			quantity++;
		}
	}

	printf("%d records listed\n", quantity);
}

void viewRecord(Employee emp[], int nEmployees) {
	int quantity = 0;
	char idSearch[4];

	printf("Enter ID: ");
	scanf("%s", &idSearch);

	printf("\t\tEmployee Details\n");
	printf("\t\t================\n");
	printf("%-15s\t%-20s\t%-15s\t%-15s\n", "Employee ID", "Name", "Date Joined", "Department");
	for (int i = 0; i < nEmployees; i++) {
		if (strstr((emp[i].employeeID),idSearch)) {
			printf("%-15s\t%-20s\t%02d/%02d/%02d\t%-15s\n", emp[i].employeeID, emp[i].name, emp[i].date.day, emp[i].date.month, emp[i].date.year, emp[i].department);
			quantity++;
		}
	}

	printf("%d records listed\n", quantity);
}

void editRecord(Employee emp[], int nEmployees) {
	char newName[20];
	char idSearch[4];
	char newDept[15];
	int newDay, newMonth, newYear;

	printf("\t\tEmployee Details\n");
	printf("\t\t================\n");
	printf("%-15s\t%-20s\t%-15s\t%-15s\n", "Employee ID", "Name", "Date Joined", "Department");
	for (int i = 0; i < nEmployees; i++) {
		printf("%-15s\t%-20s\t%02d/%02d/%02d\t%-15s\n", emp[i].employeeID, emp[i].name, emp[i].date.day, emp[i].date.month, emp[i].date.year, emp[i].department);
	}

	printf("Enter ID to edit: ");
	scanf("%s", &idSearch);
	rewind(stdin);

	for (int i = 0; i < nEmployees; i++) {
		if (strstr((emp[i].employeeID), idSearch)) {
			printf("Please leave the field blank if you don't wanna edit it\n");
			printf("Enter new name: ");
			scanf("%[^\n]s\n", &newName);
			rewind(stdin);
			strcpy(emp[i].name, newName);
			printf("Enter new date: ");
			scanf("%d/%d/%d", &newDay, &newMonth, &newYear);
			rewind(stdin);
			emp[i].date.day = newDay;
			emp[i].date.month = newMonth;
			emp[i].date.year = newYear;
			printf("Enter new department: ");
			scanf("%[^\n]s\n", &newDept);
			strcpy(emp[i].department, newDept);
		}
	}

	printf("\t\tEmployee Details\n");
	printf("\t\t================\n");
	printf("%-15s\t%-20s\t%-15s\t%-15s\n", "Employee ID", "Name", "Date Joined", "Department");

	for (int i = 0; i < nEmployees; i++) {
		printf("%-15s\t%-20s\t%02d/%02d/%02d\t%-15s\n", emp[i].employeeID, emp[i].name, emp[i].date.day, emp[i].date.month, emp[i].date.year, emp[i].department);
	}
	
}

int p2q2() {
	Employee emp[MAX_SIZE] = {
		{"E01","Lim Panny", {5,12,2008},"R&D"},
		{"E02","Alice Chin", {9,12,2011},"IT"},
		{"E03","Vivian", {3,3,2015},"HR"},
		{"E04","Johnny", {4,4,2011},"IT"},
		{"E05","John", {5,3,2015},"HR"}
	};
	int nEmployees = 5;
	editRecord(emp,nEmployees);

	system("pause");
	return 0;
}

