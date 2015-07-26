#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void FlatOwner_Menu(int nFlatID,int nUser)
{
	char szChoice[nSize];
	int nChoice=bZero;
	printf("In FlatOwner func %d\t%u\n",nFlatID,nUser);
	printf("FlatOwner_Menu\n");
	printf("\t1.Register_Appliance\n");
	printf("\t2.Modify_ApplianceControl\n");
	printf("\t3.View_ApplianceStatus\n");
	printf("\t4.Control_Appliance\n");
	printf("\t5.Add_FamilyMembers\n");
	printf("\t6.Change_LoginCredentials\n");
	printf("\t7.Quit\n");
	printf("Enter your choice\n");
	scanf("%s",szChoice);
	Send_Message(nUser,szChoice);
	nChoice=atoi(szChoice);
	switch(nChoice)
	{
		case REGISTER_APPLIANCE:
			printf("to register appliance\n");
			Registered_Appliance(nUser,nFlatID);	
			break;

		case MODIFY_APPLIANCE_CONTROL:
			printf("to modify appliances\n");
			Modify_ApplianceControl(nUser,nFlatID);
			break;

		case VIEW_APPLIANCE_STATUS:
			printf("to view the status of appliances\n");
		//	View_ApplianceStatus();
			break;

		case CONTROL_APPLIANCE:
			printf("to control appliance\n");
			Control_Appliance(nUser,nFlatID);
			break;

		case ADD_FAMILY_MEMBERS:
			printf("to add family member\n");
			Add_FamilyMembers(nUser,nFlatID);
			break;

		case CHANGE_LOGIN_CREDENTIALS:
			printf("to chnage login credential\n");
			Change_LoginCredentials(nUser,nFlatID);	
			break;

		case QUIT:
			printf("Logout From System\n");
			//exit(bOne);
			Client_menu(nUser);
			break;

		default:
			printf("wrong choice\n");
	}

	FlatOwner_Menu(nFlatID,nUser);
}


