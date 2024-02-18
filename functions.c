#include "header.h" 

void main_menu(Node* pList, const char* services[4], const char* location[3])                         
{
	int choice = 0;

	do
	{
		system("cls");
		printf("\t\t\t   ______                     ______                            __      \n");
		printf("\t\t\t  / ____/___  __  ______ _   / ____/___  ____  ____  ___  _____/ /______\n");
		printf("\t\t\t / /   / __ \\/ / / / __ `/  / /   / __ \\/ __ \\/ __ \\/ _ \\/ ___/ __/ ___/\n");
		printf("\t\t\t/ /___/ /_/ / /_/ / /_/ /  / /___/ /_/ / / / / / / /  __/ /__/ /_(__  ) \n");
		printf("\t\t\t\\____/\\____/\\__,_/\\__, /   \\____/\\____/_/ /_/_/ /_/\\___/\\___/\\__/____/  \n");
		printf("\t\t\t                 /____/                                                 \n");

		printf("[1] Find a Service\n\n");
		printf("[2] Create a Service\n\n");
		printf("[3] Delete a Service\n\n");
		printf("[4] Exit Application\n\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: Find_a_Service(&pList, services, location); break;
		case 2: Create_a_Service(&pList); updateFile(pList); break;
		case 3: deleteService(&pList); updateFile(pList); break;
		}



	} while (choice != 4);

	system("cls");
	printf("\t\t\t\t\tSee you next time!\n\n");

	return;
}

Node* makeNode(Data newData) {	//makes Node and allocates space                             

	Node* pMem = malloc(sizeof(Node));

	if (pMem != NULL) {

		pMem->pPrev = pMem->pNext = NULL;

		strcpy(pMem->data.name, newData.name);
		strcpy(pMem->data.category, newData.category);
		strcpy(pMem->data.product, newData.product);
		pMem->data.price = newData.price;
		strcpy(pMem->data.location, newData.location);
		strcpy(pMem->data.contact_info, newData.contact_info);
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

		token = strtok(NULL, "\n");
		strcpy(data.contact_info, token);

		success = insertAtFront(pList, data);
	}

	if (success == 1) {
		printf("All Records Were Loaded Successfully!\n\n");
	}

	fclose(inputFile);
}

void Create_a_Service(Node** pList) {                                                      
	system("cls");
	int success = 0;

	Data newData = { "", "", "", 0, "" };

	printf("\t\t\t   ______                __                   _____                 _         \n");
	printf("\t\t\t  / ____/_______  ____ _/ /____     ____ _   / ___/___  ______   __(_)_______ \n");
	printf("\t\t\t / /   / ___/ _ \\/ __ `/ __/ _ \\   / __ `/   \\__ \\/ _ \\/ ___/ | / / / ___/ _ \\\n");
	printf("\t\t\t/ /___/ /  /  __/ /_/ / /_/  __/  / /_/ /   ___/ /  __/ /   | |/ / / /__/  __/\n");
	printf("\t\t\t\\____/_/   \\___/\\__,_/\\__/\\___/   \\__,_/   /____/\\___/_/    |___/_/\\___/\\___/ \n");

	printf("\n\n");

	printf("Enter your name: ");

	clearBuffer();

	fgets(newData.name, sizeof(newData.name), stdin);
	newData.name[strcspn(newData.name, "\n")] = '\0';
	printf("\n");

	printf("Pick your category:\n");
	printf("[1] Food\n");
	printf("[2] Style\n");
	printf("[3] Entertainment\n");
	printf("[4] Other\n\n");

	int choice;
	int valid = 0;

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

	newData.product[strcspn(newData.product, "\n")] = '\0';

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

	printf("Enter your contact information: ");
	clearBuffer();

	fgets(newData.contact_info, sizeof(newData.contact_info), stdin);

	newData.contact_info[strcspn(newData.contact_info, "\n")] = '\0';

	printf("\n");

	success = insertAtFront(pList, newData);

	if (success == 1) {
		printf("New Service Added Successfully!!!");
		system("pause");
	}


}

void deleteService(Node** pList) {                                                                          

	system("cls");


	printf("\t\t\t    ____       __     __                   _____                 _         \n");
	printf("\t\t\t   / __ \\___  / /__  / /____     ____ _   / ___/___  ______   __(_)_______ \n");
	printf("\t\t\t  / / / / _ \\/ / _ \\/ __/ _ \\   / __ `/   \\__ \\/ _ \\/ ___/ | / / / ___/ _ \\\n");
	printf("\t\t\t / /_/ /  __/ /  __/ /_/  __/  / /_/ /   ___/ /  __/ /   | |/ / / /__/  __/\n");
	printf("\t\t\t/_____/\\___/_/\\___/\\__/\\___/   \\__,_/   /____/\\___/_/    |___/_/\\___/\\___/ \n");
	char name[100];
	int choice;
	int found = 0;
	int count = 1;

	while (found == 0) {

		printf("Enter your name: ");
		clearBuffer();

		fgets(name, sizeof(name), stdin);

		name[strcspn(name, "\n")] = '\0'; //removes the newline created by fgets and replaces it with '\0'


		found = printSpecific(*pList, name, 1);
	}

	printf("Choose which service to delete: ");
	scanf("%d", &choice);

	Node* newList = specificList(pList, name);

	printf("\n");
	getchar();

	Node* current = newList;
	Node* previous = NULL;

	Data tempData;

	while (current != NULL) {

		if (count == choice) {

			tempData = current->data;

			free(current);
			break;
		}

		previous = current;
		current = current->pNext;
		count++;
	}

	Node* cur2 = *pList;
	Node* temp2 = NULL;
	while (strcmp(cur2->data.name, tempData.name) != 0 || strcmp(cur2->data.product, tempData.product) != 0)
	{
		cur2->pPrev = cur2;
		cur2 = cur2->pNext;
	}

	if (cur2->pPrev == NULL)
	{
		temp2 = cur2;
		*pList = cur2->pNext;
		free(temp2);
	}
	else
	{
		temp2 = cur2;

		cur2->pPrev->pNext = cur2->pNext;

		free(temp2);

	}





}

void updateFile(Node* pList) {                                                                          

	FILE* outputFile = fopen("data.csv", "w");

	if (outputFile == NULL) {
		printf("File was not opened properly...");
		return;
	}

	while (pList != NULL) {
		fprintf(outputFile, "%s,%s,%s,%2lf,%s,%s\n", pList->data.name, pList->data.category, pList->data.product, pList->data.price, pList->data.location, pList->data.contact_info);
		pList = pList->pNext;
	}



	fclose(outputFile);
	printf("File has been updated.\n");
}

void printList(Node* pList) {                                                 

	int count = 1;

	while (pList != NULL) {

		printf("[%d] Name: %s\n   Category: %s\n   Product: %s\n   Price: %lf\n   Location: %s\n\n", count, pList->data.name, pList->data.category, pList->data.product, pList->data.price, pList->data.location, pList->data.contact_info);
		count++;

		pList = pList->pNext;
	}
}

int printSpecific(Node* pList, const char* base, int choice) {                                

	system("cls");

	int count = 1;
	int found = 0;
	switch (choice)
	{
	case 1: printf("\t\t\t\t\tName : %s\n\n", base); break;
	case 2: printf("\t\t\t\t\tService : %s\n\n", base); break;

	}
	while (pList != NULL) {

		switch (choice)
		{
		case 1:
			if (strcmp(pList->data.name, base) == 0) {
				printf("[%d] Name: %s\n   Category: %s\n   Product: %s\n   Price: $%.2lf\n   Location: %s\n   Contact Information: %s\n\n", count, pList->data.name, pList->data.category, pList->data.product, pList->data.price, pList->data.location, pList->data.contact_info);
				count++;
				found = 1;
			}
			break;
		case 2:
			if (strcmp(pList->data.category, base) == 0) {
				printf("[%d] Name: %s\n   Category: %s\n   Product: %s\n   Price: $%.2lf\n   Location: %s\n   Contact Information: %s\n\n", count, pList->data.name, pList->data.category, pList->data.product, pList->data.price, pList->data.location, pList->data.contact_info);
				count++;
				found = 1;
			}
		}

		pList = pList->pNext;
	}

	if (found == 0) {
		printf("Name was not found, please try again...\n\n");
	}

	return found;
}

void clearBuffer() {                                                              
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int Find_a_Service(Node** pList, const char* services[4], const char* location[3]) {                  

	const char* sort[4] = { "Price Low to High", "Price High to Low", "Name", "Location" };
	int sort_choice = 0;


	system("cls");
	if (*pList == NULL)
	{
		printf("There are no Services avaliable, please try again later\n\n");
		system("pause");
		return 1;
	}



	int success = 0;


	int choice = 0;
	printf("\t\t\t    _______           __            _____                 _         \n");
	printf("\t\t\t   / ____(_)___  ____/ /  ____ _   / ___/___  ______   __(_)_______ \n");
	printf("\t\t\t  / /_  / / __ \\/ __  /  / __ `/   \\__ \\/ _ \\/ ___/ | / / / ___/ _ \\\n");
	printf("\t\t\t / __/ / / / / / /_/ /  / /_/ /   ___/ /  __/ /   | |/ / / /__/  __/\n");
	printf("\t\t\t/_/   /_/_/ /_/\\__,_/   \\__,_/   /____/\\___/_/    |___/_/\\___/\\___/ \n");
	printf("Pick your Service\n\n\n");
	printf("[1] Food\n\n");
	printf("[2] Style\n\n");
	printf("[3] Entertainment\n\n");
	printf("[4] Other\n\n");
	scanf("%d", &choice);

	Node* pCur = *pList;
	Node* pSorted = NULL;
	printf("\t\t\t\t\tService : %s\n\n", services[choice - 1]);
	while (pCur != NULL)
	{


		if (strcmp(pCur->data.category, services[choice - 1]) == 0)
		{
			Node* newNode = malloc(sizeof(Node));
			newNode->data = pCur->data;
			newNode->pNext = NULL;


			if (pSorted == NULL)
			{

				pSorted = newNode;
			}
			else
			{

				Node* temp = pSorted;
				while (temp->pNext != NULL)
				{
					temp = temp->pNext;
				}
				temp->pNext = newNode;

			}
		}
		pCur = pCur->pNext;

	}
	
	if (pSorted != NULL)
	{
	
				printSpecific(pSorted, services[choice - 1], 2);

		
	}
	else
	{
		printf("There are no Services avaliable, please try again later\n\n");

	}
	free(pSorted);
	system("pause");
	return success;
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
