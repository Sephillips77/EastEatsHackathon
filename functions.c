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

int Find_a_Service(Node** pList)
{
	int success = 0;


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
