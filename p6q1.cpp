#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

void displaySquaresCubes();
double triangleArea();
void displayCircleInfo();
void welcome();
void displayCinemaMenu();
void bookATicket();
void displaySeatLayout();
int getValidMark();


int p6q1() {
	double area1;

	area1 = triangleArea();
	printf("Area of 1st triangle =%.2lf\n\n", area1);

	printf("Area of 2st triangle =%.2lf\n\n", triangleArea());
	system("pause");
	return 0;
}

void displaySquaresCubes() {
	printf("%10s\t%10s\t%10s\n","Number","Square","Cube");
	printf("%10s\t%10s\t%10s\n", "======", "======", "====");
	for (int i = 1; i <= 10; i++) {
		printf("%10d\t%10.0lf\t%10.0lf\n",i,pow(i,2),pow(i,3));
	}
}

double triangleArea() {
	double a, b, area;
	printf("Length of side A: ");
	scanf("%lf", &a);
	printf("Length of side B: ");
	scanf("%lf", &b);
	area = 0.5 * a * b;
	return area;
}

void displayCircleInfo() {
	double radius, diameter, circumference, area;
	printf("Length of radius: ");
	scanf("%lf", &radius);
	diameter = 2 * radius;
	circumference = 2 * 3.14159 * radius;
	area = 3.14159 * pow(radius,2);
	printf("Diameter: %.1lf\n", diameter);
	printf("Circumference: %.1lf\n", circumference);
	printf("Area: %.1lf\n", area);
}

void welcome() {
	printf("Welcome!\n");
	printf("This program will calculate\n");
	printf("a circle's diameter,\n");
	printf("circumference and area.\n");
	printf("=======================\n\n");
}

void displayCinemaMenu() {
	int option;
	printf("Cinema Menu\n\n");
	printf("1.Book a ticket\n");
	printf("2.Display Seat Layout\n");
	printf("3.Exit\n\n");
	printf("Choose an option: ");
	scanf("%d", &option);

	if (option == 1) {
		bookATicket();
	}
	else if (option == 2) {
		displaySeatLayout();
	}
	else if (option == 3) {
		exit(1);
	}
	else {
		printf("Please insert a valid option.\n");
		displayCinemaMenu();
	}
}

void bookATicket() {
	printf("Under construction.\n");
}

void displaySeatLayout() {
	printf("Under construction.\n");
}

int getValidMark() {
	int marks;
	printf("Marks: ");
	scanf("%d", &marks);
	if (marks >= 0 && marks <= 100) {
		return marks;
	}
	else {
		printf("Please insert a valid value.\n");
		getValidMark();
	}
}