#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable:4996)

//Function declaration
void addProduct();
void displayProducts();
void modifyProduct(int modifyCount);
void deleteProduct();

typedef struct {
	char productCode[6];
	int expiryYear;
	char country[26];
} Product;
int modifiedProd;

int main() {
	int option;
	modifiedProd = 0;

	do {
		//Main Menu
		printf("Main Menu:\n");
		printf("----------\n");
		printf("1) Add product\n");
		printf("2) Display product\n");
		printf("3) Modify product\n");
		printf("4) Delete product\n");
		printf("5) Exit\n\n");

		//Option Input
		printf("Option: ");
		scanf("%d", &option);
		rewind(stdin);

		if (option == 1) {
			system("cls");
			addProduct();
		}
		else if (option == 2) {
			system("cls");
			displayProducts();
		}
		else if (option == 3) {
			modifyProduct(0);
		}
		else if (option == 4) {
			deleteProduct();
		}
		else if (option == 5) {
			break;
		}
		else {
			printf("Please insert a valid option.\n");
		}
	} while (option != 5);

	system("pause");
	return 0;
}

//Q1
void addProduct() {
	FILE* fptr;
	Product prod;
	char option;

	fptr = fopen("product.dat", "ab");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	do {
		//Product code input
		printf("Enter product code: ");
		scanf("%s", prod.productCode);
		rewind(stdin);

		//Expiry year input
		printf("Enter expiry year: ");
		scanf("%d", &prod.expiryYear);
		rewind(stdin);

		//Country input
		printf("Enter country: ");
		scanf("%[^\n]", prod.country);
		rewind(stdin);

		//Write into binary file
		fwrite(&prod, sizeof(prod), 1, fptr);
		printf("Record added successfully.\n");

		//Ask user to continue or not
		printf("Would you like to add more product (Y/N)? ");
		scanf("%c", &option);
		rewind(stdin);
		system("cls");
	} while (toupper(option) == 'Y');

	fclose(fptr);
}

//Q2
void displayProducts() {
	int count = 0;
	FILE* fptr;
	Product prod;

	//Create system time object and get local time
	SYSTEMTIME t;
	GetLocalTime(&t);

	printf("Product Details - as at %d-%d-%d %d:%d\n\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);

	printf("%-15s\t%-15s\t%-25s\n", "Product Code", "Expiry Year", "Country");
	printf("%-15s\t%-15s\t%-25s\n", "============", "===========", "=======");

	//Store date into prod from binary file and print out
	fptr = fopen("product.dat", "rb");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	while (fread(&prod, sizeof(prod), 1, fptr) != 0) {
		printf("%-15s\t%-15d\t%-25s\n", prod.productCode, prod.expiryYear, prod.country);
		count++;
	}

	fclose(fptr);

	printf("\n%d products listed\n", count);
	system("pause");
	system("cls");
}

//Q3
void modifyProduct(int modifyCount) {
	Product p[20], tempProd;
	int pCount = 0;
	char continueModify;
	FILE* fptr;

	system("cls");
	fptr = fopen("product.dat", "rb");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	pCount = fread(p, sizeof(Product), 20, fptr);

	printf("%-15s\t%-15s\t%-25s\n", "Product Code", "Expiry Year", "Country");
	printf("%-15s\t%-15s\t%-25s\n", "============", "===========", "=======");
	for (int i = 0; i < pCount; i++) {
		printf("%-15s\t%-15d\t%-25s\n", p[i].productCode, p[i].expiryYear, p[i].country);
	}
	fclose(fptr);

	printf("\nEnter product code to edit: ");
	scanf("%s", tempProd.productCode);
	rewind(stdin);

	for (int i = 0; i < pCount; i++) {
		if (strcmp(p[i].productCode, tempProd.productCode) == 0) {
			char editOption, continueOption, modifyOption;
			do {
				//Show details of the product selected
				printf("\nProduct code: %s\n", p[i].productCode);
				printf("Expiry year: %d\n", p[i].expiryYear);
				printf("Country: %s\n", p[i].country);

				//Ask user edit expiry year or country
				printf("Which details would you like to edit (E = Expiry Year/C = Country/D = Done)? ");
				scanf("%c", &editOption);
				rewind(stdin);

				if (toupper(editOption) == 'E') {
					//Edit expiry year
					printf("Enter new expiry year: ");
					scanf("%d", &tempProd.expiryYear);
					rewind(stdin);

					//Confirmation before modify
					printf("Sure to Modify (Y = yes)? ");
					scanf("%c", &modifyOption);
					rewind(stdin);
					if (toupper(modifyOption) == 'Y') {
						p[i].expiryYear = tempProd.expiryYear;
						printf("Modify successfully.\n");
					}
				}
				else if (toupper(editOption) == 'C') {
					//Edit country
					printf("Enter new country: ");
					scanf("%[^\n]", &tempProd.country);
					rewind(stdin);

					//Confirmation before modify
					printf("Sure to Modify (Y = yes)? ");
					scanf("%c", &modifyOption);
					rewind(stdin);
					if (toupper(modifyOption) == 'Y') {
						strcpy(p[i].country, tempProd.country);
						printf("Modify successfully.");
					}
				}
				else if (toupper(editOption) == 'D') {
					break;
				}
				else {
					//Other option given
					printf("Please enter a valid option\n");
				}
			} while (toupper(editOption) != 'D');	
		}
	}

	//Write into file
	fptr = fopen("product.dat", "wb");
	fwrite(p, sizeof(Product), pCount, fptr);
	fclose(fptr);

	modifyCount++; 
	printf("%d products modified\n", modifyCount);
	printf("\nWould you like to modify more (Y/N)? "); //Continue or not
	scanf("%c", &continueModify);
	rewind(stdin);
	if (toupper(continueModify) == 'Y') modifyProduct(modifyCount); //Recursive function :D

	system("cls");
}

//Q4
void deleteProduct() {
	Product p[20];
	int pCount = 0, delYear;
	char continueDelete, deleteConfirm;
	FILE* fptr;

	system("cls");
	fptr = fopen("product.dat", "rb");

	if (fptr == NULL)
	{
		printf("Unable to open file.\n");
		exit(-1);
	}

	pCount = fread(p, sizeof(Product), 20, fptr);

	printf("%-15s\t%-15s\t%-25s\n", "Product Code", "Expiry Year", "Country");
	printf("%-15s\t%-15s\t%-25s\n", "============", "===========", "=======");
	for (int i = 0; i < pCount; i++) {
		printf("%-15s\t%-15d\t%-25s\n", p[i].productCode, p[i].expiryYear, p[i].country);
	}
	fclose(fptr);

	//User input expiry year to delete
	printf("\nEnter expiry year to delete: ");
	scanf("%d", &delYear);
	rewind(stdin);

	//Confirmation before delete
	printf("Sure to Delete (Y = yes)? ");
	scanf("%c", &deleteConfirm);
	rewind(stdin);
	if (toupper(deleteConfirm) == 'Y') {
		//Check every product in p array
		for (int i = 0; i < pCount; i++) {
			//If expiry year matches
			if (p[i].expiryYear == delYear) {
				//For loop to move everything behind upfront
				for (int z = i; z < pCount; z++) {
					//Move to front 1
					strcpy(p[z].productCode, p[z+1].productCode);
					p[z].expiryYear = p[z + 1].expiryYear;
					strcpy(p[z].country, p[z + 1].country);

					//Empty the p[z+1] array
					p[z + 1] = (Product) { 0 };
				}
				pCount--; //Number of records in p array minus 1
			}
		}
		printf("Modify successfully.");
	}

	//Write into file
	fptr = fopen("product.dat", "wb");
	fwrite(p, sizeof(Product), pCount, fptr);
	fclose(fptr);

	printf("\nWould you like to delete more (Y/N)? "); //Continue or not
	scanf("%c", &continueDelete);
	rewind(stdin);
	if (toupper(continueDelete) == 'Y') deleteProduct(); //Another recursive function :D

	system("cls");
}