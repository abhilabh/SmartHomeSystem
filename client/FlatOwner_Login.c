#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void FlatOwner_Login(int nsock)
{
	char szUserName[10];
	char szPassword[15];
	int nFlatNo=bZero;
	char szBuf[nSize];
	char *pszBuf;
	int nResult=bZero;
//	struct login admin;
	printf("FlatOwner_Login func %d\n",nsock);
	printf("Enter your User Name\n");
	__fpurge(stdin);
	fgets(szUserName,10,stdin);
	printf("Enter your password\n");
	__fpurge(stdin);
	fgets(szPassword,15,stdin);
	printf("Enter your FlatNo\n");
	__fpurge(stdin);
	scanf("%d",&nFlatNo);
	szUserName[strlen(szUserName)-1]='\0';
	szPassword[strlen(szPassword)-1]='\0';
	sprintf(szBuf,"%s %s %d",szUserName,szPassword,nFlatNo);
	printf("%s\n",szBuf);
	//send(nsock,szBuf,sizeof(szBuf),bZero);
	Send_Message(nsock,szBuf);
	pszBuf=Receive_Message(nsock);
	nResult=atoi(pszBuf);
	if(nResult==bOne)
	{
		printf("login success\n");
		FlatOwner_Menu(nFlatNo,nsock);
	}
	else 
	{
		printf("login failed\n");
		FlatOwner_Login(nsock);
	}
}
