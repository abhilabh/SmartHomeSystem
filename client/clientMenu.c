#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Client_menu(int sock)
{
	char cChoice[nSize];
	char *pszChoice=NULL;
	int nChoice=bZero;
	int nfChoice=bZero;
	char pszfChoice[nSize];
	printf("Login as\n");
	printf("\t1.Admin\n");
	printf("\t2.Flat owner\n");
	printf("\t3.Exit\n");
	scanf("%s",cChoice);
	printf("********%s\n",cChoice);
	Send_Message(sock,cChoice);
	nChoice=atoi(cChoice);
	switch(nChoice)
	{
		case ADMIN:
			printf("enter as admin\n");
			Admin_Login(sock);
			break;

	
		case FLAT_OWNER:
			printf("enter as flat owner\n");
			printf("Login as\n");
			printf("\t1.FlatOwner\n");
			printf("\t2.FamilyMember\n");
			scanf("%s",pszfChoice);
			printf("*********%s\n",pszfChoice);
			Send_Message(sock,pszfChoice);
			nfChoice=atoi(pszfChoice);
			if(nfChoice==bOne)
				FlatOwner_Login(sock);
			else if(nfChoice==bTwo)
				FamilyMember_Login(sock);
			else
				printf("wrong choice entered\n");
			break;
		
		case EXIT:
			printf("exiting\n");
			exit(bOne);
			break;

		default :
			printf("wrong choice\n");

		
	}
	Client_menu(sock);

}
