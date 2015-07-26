#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_FlatOwner_Menu(int nSock)
{
	char *pszChoice;
	int nChoice=bZero;
	printf("In FlatOwner func %d\n",nSock);
	pszChoice=Receive_Message(nSock);
	nChoice=atoi(pszChoice);
	switch(nChoice)
	{
		case REGISTER_APPLIANCE:
			printf("to register appliance\n");
			Server_Registered_Appliance(nSock);	
			break;

		case MODIFY_APPLIANCE_CONTROL:
			printf("to modify appliances\n");
			Server_Modify_ApplianceControl(nSock);
			break;

		case VIEW_APPLIANCE_STATUS:
			printf("to view the status of appliances\n");
		//	View_ApplianceStatus();
			break;

		case CONTROL_APPLIANCE:
			printf("to control appliance\n");
			Server_Control_Appliance(nSock);
			break;

		case ADD_FAMILY_MEMBERS:
			printf("to add family member\n");
			Server_Add_FamilyMembers(nSock);
			break;

		case CHANGE_LOGIN_CREDENTIALS:
			printf("to chnage login credential\n");
			Server_Change_LoginCredentials(nSock);	
			break;

		case QUIT:
			printf("to quit\n");
			server_menu(nSock);
//			exit(bOne);
			break;

		default:
			printf("wrong choice\n");
	}

	Server_FlatOwner_Menu(nSock);
}


