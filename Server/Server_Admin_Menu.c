#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif

void Server_Admin_Menu(int nSock)
{
	int nChoice=bZero;
	char *pszChoice;
	pszChoice=Receive_Message(nSock);
	nChoice=atoi(pszChoice);
	switch(nChoice)
	{
		case CREATE_FLAT_ACCOUNT:
			printf("to create aflate account\n");
			Server_Create_FlatAccount(nSock);
			break;

		case DELETE_ACCOUNT:
			printf("to Delete  aflate account\n");
			Server_Delete_Account(nSock);
			break;

		case VIEW_APPLIANCE_STATUS:
			printf("to VIEW  aflate account\n");
			Server_View_ApplianceStatus(nSock);
			break;
			
		case GENERATE_REPORT:
			printf("to Delete  aflate account\n");
			Server_Generate_Report(nSock);
			break;
		case ADMIN_LOGOUT:
			server_menu(nSock);
			break;
		default:
			printf("wrong choice\n");
	}

	Server_Admin_Menu(nSock);
}

