#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif


void server_menu(int nSock)
{
	char *pszChoice;
	int nChoice;
	int oChoice=bZero;
	printf("****************\n");
	while(1)
	{
		pszChoice=Receive_Message(nSock);
		nChoice=atoi(pszChoice);
		switch(nChoice)
		{
			case ADMIN:
				printf("you enter as a admin\n");
				Server_Admin_Login(nSock);
				break;
			case FLATE_OWNER:
				printf("you enter as a  owner\\ family\n");
				oChoice=atoi(Receive_Message(nSock));
				if(oChoice==1)
				{
					printf("you enter as a flat owner\n");
					Server_FlatOwner_Login(nSock);
				}
				else if(oChoice==2)
				{
					printf("you enter as a family Member\n");
					Server_FamilyMember_Login(nSock);
				}
				else
				printf("Wrong choice \n");
			
				break;

			case EXIT:
				printf("you exit from apps\n");
				return;
			
		}
	}
}

