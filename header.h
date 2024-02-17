#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char name[25];
	char category[15];
	char product[25];
	double price;
	char location[15];
	char seller[25];

}Data;

typedef struct node
{
	struct node* pNext;
	struct node* pPrev;
	Data data;

}Node;
