#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif
void Change_LoginCredentials(int nsock,int nFlatNo)
{
	char szUserName[10];
	char szPassword[15];
	char szBuf[nSize];
	char *pszBuf;
	int nResult=bZero;
	char *getpass(const char* prompt);
//	struct login admin;
	printf("Admin_Login func %d\n",nsock);
	printf("Enter your new User Name\n");
	__fpurge(stdin);
	fgets(szUserName,15,stdin);

	printf("Enter your New password\n");
	__fpurge(stdin);
	sprintf(szPassword,"%s",getpass("enter:"));
//	printf("%s  %d\n",szPassword,sizeof(szPassword));
	szUserName[strlen(szUserName)-1]='\0';
//	szPassword[strlen(szPassword)-1]='\0';
	sprintf(szBuf,"%s %s %d",szUserName,szPassword,nFlatNo);
	printf("%s\n",szBuf);
	//send(nsock,szBuf,sizeof(szBuf),bZero);
	Send_Message(nsock,szBuf);
	pszBuf=Receive_Message(nsock);
	nResult=atoi(pszBuf);
	if(nResult==bOne)
	{
		printf("success change\n");
		//Admin_Menu(nsock);
	}
	else 
	{
		printf("failed\n");
	//	Admin_Login(nsock);
	}
}

