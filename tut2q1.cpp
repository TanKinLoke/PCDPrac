#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int year;
	char name[25];
	double price;
} Prod;

int tut2q1() {
	Prod product[3] = { 
		{1111,2011, "AAA", 12.50}, 
		{2222,2012,"BBB",50.00},	
		{3333, 2010, "CCC", 38.50} 
	};

	printf("Product[1].year = %d\n", product[1].year);
	printf("Product[2].id = %d\n", product[2].id);
	printf("Product[0].name = %s\n", product[0].name);

	system("pause");
	return 0;
}