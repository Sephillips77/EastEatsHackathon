#include "header.h"

int main(void) {

	const char* services[4] = { "Food", "Style", "Entertainment", "Other" };
	const char* location[3] = { "North Campus", "Central Campus", "South Campus" };

	Node* pHead = NULL;

	readFile(&pHead);

	main_menu(pHead, services, location);
	

	//	int success = Find_a_Service(&pHead, services, location); 

	//	Create_a_Service(&pHead);  

	//	deleteService(&pHead);    

	return 0;
}
