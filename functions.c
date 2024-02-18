#include "header.h"


void main_menu(void)
{
	int choice = 0;
	do
	{
		system("cls");
		printf("\t\t\t\t\tCoug Connects\n");
		printf("[1] Find a Service\n\n");
		printf("[2] Create a Service\n\n");
		printf("[3] About us\n\n");
		printf("[4] Exit Application\n\n");
		scanf("%d", &choice);

	} while (choice != 4);

	system("cls");
	printf("\t\t\t\t\tSee you next time!\n\n");

	return;
}

int Find_a_Service(Node** pList, const char* services[4], const char* location[3])
{
	system("cls");
	if (*pList == NULL)
	{
		printf("There are no Services avaliable, please try again later\n\n");
		system("pause");
		return 1;
	}

	

	int success = 0;
	
	
	
	
	int choice = 0;
	printf("\t\t\t\t\tFind a Service\n\n");
	printf("Pick your Service\n\n\n");
	printf("[1] Food\n\n");
	printf("[2] Style\n\n");
	printf("[3] Entertainment\n\n");
	printf("[4] Other\n\n");
	scanf("%d", &choice);
	
	Node* pCur = *pList;
	Node* pSorted = NULL;
	printf("%s", services[choice-1]);

	while (pCur != NULL)
	{
		printf("\nloop\n");

		if (strcmp(pCur->data.category, services[choice - 1]) == 0)
		{
			Node* newNode = malloc(sizeof(Node));
			newNode->data = pCur->data;
			newNode->pNext = NULL;

			printf("anoying asf");
			if (pSorted == NULL)
			{
				printf("boom created");
				pSorted = newNode;
			}
			else
			{
				printf("added");
				Node* temp = pSorted;
				while (temp->pNext != NULL)
				{
					temp = temp->pNext;
				}
				temp->pNext = newNode;

			}
		}
		pCur = pCur->pNext;
		printf("end loop");
	}
	if (pSorted != NULL)
	{
		printf("temp has smthn!\n\n");
		while (pSorted != NULL)
		{
			printf("Name : %s\n", pSorted->data.name);
			pSorted = pSorted->pNext;

		}
	}
	else
	{
		printf("There are no Services avaliable, please try again later\n\n");

	}
	printf("u made it!");
	system("pause");
	return success;
}

int Create_a_Service(Node** pList)
{
	int success = 0;


	return success;
}

void about_us(void)
{




	return 0;
}

Node* makeNode(Data newData) {	//makes Node and allocates space

	Node* pMem = malloc(sizeof(Node));

	if (pMem != NULL) {

		pMem->pPrev = pMem->pNext = NULL;

		strcpy(pMem->data.name, newData.name);
		strcpy(pMem->data.category, newData.category);
		strcpy(pMem->data.product, newData.category);
		pMem->data.price = newData.price;  
		strcpy(pMem->data.location, newData.location);
	}

	return pMem;
}

int insertAtFront(Node** pList, Data newData) { //inserts new node at the front of the list

	int success = 0;

	Node* pMem = makeNode(newData);

	if (pMem != NULL) {

		success = 1;

		if (*pList != NULL) {

			(*pList)->pPrev = pMem;
			pMem->pNext = *pList;
		}

		*pList = pMem;
	}

	return success; 
}

void readFile(Node** pList) {	//reads in data from file

	FILE* inputFile = fopen("data.csv", "r");

	if (inputFile == NULL) {
		printf("The file could not be opened for reading...");
	}

	char line[256];

	int success = 0;

	while (fgets(line, sizeof(line), inputFile) != NULL) {

		Data data = { 0 };

		char* token = strtok(line, ",");
		strcpy(data.name, token);

		token = strtok(NULL, ",");
		strcpy(data.category, token);

		token = strtok(NULL, ","); 
		strcpy(data.product, token);

		token = strtok(NULL, ","); 
		data.price = atof(token);

		token = strtok(NULL, ",");
		strcpy(data.location, token);

		success = insertAtFront(pList, data); 
	}

	if (success == 1) {
		printf("All Records Were Loaded Successfully!");
	}

	fclose(inputFile); 
}

void Create_a_Service(Node** pList) { 

	int success = 0;
	 
	Data newData = { "", "", "", 0, "" };

	printf("Create a Service!!!");

	printf("\n\n");

	printf("Enter your name: ");

	fgets(newData.name, sizeof(newData.name), stdin); 

	printf("\n");

	printf("Pick your category:\n");
	printf("[1] Food\n");
	printf("[2] Style\n");
	printf("[3] Entertainment\n");
	printf("[4] Other\n\n");

	int choice;
	int valid=0;

	while (valid == 0) {

		scanf("%d", &choice); 

		switch (choice) {

		case 1:
			strcpy(newData.category, "Food");
			valid = 1;
			break;
		case 2:
			strcpy(newData.category, "Style");
			valid = 1;
			break;
		case 3:
			strcpy(newData.category, "Entertainment");
			valid = 1; 
			break;
		case 4:
			strcpy(newData.category, "Other");
			valid = 1;  
			break;
		default:
			printf("Invalid Option Selected, Try Again..."); 
		}
	}

	printf("\n");
	printf("Enter your product: ");

	clearBuffer(); 

	fgets(newData.product, sizeof(newData.product), stdin);  
	 
	printf("\n"); 

	printf("Enter your price: ");
	scanf("%lf", &newData.price);

	printf("\n");

	printf("Pick your location\n");
	printf("[1] North Campus\n");
	printf("[2] Central Campus\n");
	printf("[3] South Campus\n");
	
	int valid2 = 0;

	while (valid2 == 0) { 

		scanf("%d", &choice); 

		switch (choice) { 

		case 1:
			strcpy(newData.location, "North Campus"); 
			valid2 = 1;  
			break;
		case 2:
			strcpy(newData.location, "Central Campus");
			valid2 = 1; 
			break; 
		case 3:
			strcpy(newData.location, "South Campus"); 
			valid2 = 1; 
			break; 
		default:
			printf("Invalid Option Selected, Try Again..."); 
		}
	}

	success = insertAtFront(pList, newData);

	if (success == 1) {
		printf("New Service Added Successfully!!!");
	}
}

void printSpecific(Node* pList, const char* name) { 

	int count = 1;

	while (pList != NULL) {

		if (strcmp(pList->data.name, name) == 0) {
			printf("[%d] Name: %s\n   Category: %s\n   Product: %s\n   Price: %lf\n   Location: %s\n\n", count, pList->data.name, pList->data.category, pList->data.product, pList->data.price, pList->data.location);
			count++;
		}

		pList = pList->pNext; 
	}

}

void clearBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

Node* specificList(Node** pList, const char* filter) {

	Node* pCur = *pList; 
	Node* pNewList = NULL;   
	Node* pTail = NULL;      

	while (pCur != NULL) {  

		if (strcmp(pCur->data.name, filter) == 0) {    
			
			Node* newNode = (Node*)malloc(sizeof(Node));
			if (newNode == NULL) {
				printf("Memory allocation failed\n"); 
				return 1;
			}

			newNode->data = pCur->data;  
			newNode->pNext = NULL;  


			if (pNewList == NULL) { 
				pNewList = newNode; 
				pTail = newNode;
			}
			else {
				pTail->pNext = newNode;
			}

			pTail = newNode; 
		}
		pCur = pCur->pNext; 
	} 

	return pNewList; 

}
