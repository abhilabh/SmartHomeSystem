#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif
void Add_FamilyMembers(int nsock,int nFlatNo)
{
	char szUserName[10];
	char szPassword[15];
	char szBuf[nSize];
	char *pszBuf;
	int nResult=bZero;
	char *getpass(const char* prompt);
	printf("Admin_Login func %d\n",nsock);
	printf("Enter your Family  User Name\n");
	__fpurge(stdin);
	fgets(szUserName,15,stdin);

	printf("Enter your Family password\n");
	__fpurge(stdin);
	sprintf(szPassword,"%s",getpass("enter:"));
	szUserName[strlen(szUserName)-1]='\0';
	sprintf(szBuf,"%s %s %d",szUserName,szPassword,nFlatNo);
	printf("%s\n",szBuf);
	Send_Message(nsock,szBuf);
	pszBuf=Receive_Message(nsock);
	nResult=atoi(pszBuf);
	if(nResult==bOne)
	{
		printf("success change\n");
	}
	else 
	{
		printf("failed\n");
	}
}

