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

}Data;

typedef struct node 
{
	struct node* pNext; 
	struct node* pPrev; 
	Data data; 

}Node;

Node* makeNode(Data newData);
int insertAtFront(Node** pList, Data newData); 
void readFile(Node** pList);  
void Create_a_Service(Node** pList);  
void deleteService(Node** pList);
void clearBuffer();
int printSpecific(Node* pList, const char* name);
void updateFile(Node* pList); 
int Find_a_Service(Node** pList, const char* services[4], const char* location[3]);
Node* specificList(Node** pList, const char* filter);
void printList(Node* pList);

