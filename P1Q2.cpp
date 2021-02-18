#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

typedef struct {
	char bookID[10];
	char authorName[25];
	char bookTitle[50];
	char publisher[25];
	int yearOfPublication;
	int quantityInStock;
} BookInventory;

typedef struct {
	char transactionCode;
	int quantity;
} Transactions;

int p1q2() {
	BookInventory book = {
		"BK-2044", "JK Rowling", "Harry Potter and the Prisoner of Azkaban", "Bloomsbury", 1999, 25
	};
	printf("Book Details: \n");
	printf("==============\n");
	printf("%-30s:%s\n","Book ID",book.bookID);
	printf("%-30s:%s\n", "Author Name", book.authorName);
	printf("%-30s:%s\n", "Book Title", book.bookTitle);
	printf("%-30s:%s\n", "Publisher", book.publisher);
	printf("%-30s:%d\n", "Year Of Publication", book.yearOfPublication);
	printf("%-30s:%d\n", "Quantity in Stock", book.quantityInStock);

	Transactions txn;
	do {
		printf("Please enter the transaction code (S=sold, P=purchased, X=exit): ");
		rewind(stdin);
		scanf("%c", &txn.transactionCode);

		if (txn.transactionCode != 'x' && txn.transactionCode != 'X') {
			printf("Please enter the quantity: ");
			scanf("%d", &txn.quantity);
			rewind(stdin);
		}

		if (txn.transactionCode == 's' || txn.transactionCode == 'S') {
			book.quantityInStock -= txn.quantity;
			printf("Sold: %d copies of \"Harry Potter and the Prisoner of Azkaban\" by JK Rowling.\n", txn.quantity);
			printf("There are now %d copies in stock\n\n", book.quantityInStock);
		}
		else if (txn.transactionCode == 'p' || txn.transactionCode == 'P') {
			book.quantityInStock += txn.quantity;
			printf("Purchased: %d copies of \"Harry Potter and the Prisoner of Azkaban\" by JK Rowling.\n", txn.quantity);
			printf("There are now %d copies in stock\n\n", book.quantityInStock);
		} 
		else if (txn.transactionCode == 'x' || txn.transactionCode == 'X') {
			printf("Exited - End of Transaction\n");
		}
		else {
			printf("Invalid Transaction Code :(", txn.transactionCode);
			printf("There are now %d copies in stock", book.quantityInStock);
		}
	} while (txn.transactionCode != 'x' && txn.transactionCode != 'X');
	
	system("pause");

	return 0;
}