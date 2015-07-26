#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Admin_Menu(int nSock)
{
	char szChoice[nSize];
	int nChoice=bZero;
	printf("in Admin_Menu func %u\n",nSock);
	printf("Admin_Menu\n");
	printf("\t1.Create Flat Account\n");
	printf("\t2.Delete Account\n");
	printf("\t3.View Appliance Status\n");
	printf("\t4.Generate Report\n");
	printf("\t5.Logout\n");
	printf("Enter your choice\n");
	scanf("%s",szChoice);
	Send_Message(nSock,szChoice);
	nChoice=atoi(szChoice);
	
	switch(nChoice)
	{
		case CREATE_FLAT_ACCOUNT:
			printf("to create an account\n");
			Create_FlatAccount(nSock);
			break;

		case DELETE_ACCOUNT:
			printf("to delete an account\n");
			Delete_Account(nSock);
			break;
		
		case VIEW_APPLIANCE_STATUS:
			printf("to view appliance status\n");
			View_ApplianceStatus(nSock);
			break;

		case GENERATE_REPORT:
			printf("to generate report\n");
			Generate_Report(nSock);
			break;
		case ADMIN_LOGOUT:
			Client_menu(nSock);
			break;

		default :
			printf("wrong choice\n");
	}

	Admin_Menu(nSock);
	
}

