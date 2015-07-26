#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif

void Server_Admin_Login(int nSock)
{

	int nResult=bZero;
	char *pszBuf;
	char szUserName[10];
	char szPassword[15];
	struct login admin;
	struct login admin1;
	FILE *pFilePointer;
	//	printf("++++++++++++++=\n");
	pFilePointer=fopen("Admin.txt","rb");
	pszBuf=Receive_Message(nSock);
//	if(recv(nSock,pszBuf,sizeof(pszBuf),bZero)==0)
//		printf("recv Failed\n");
	//printf(pszBuf);
//		printf("******************\n");
	sscanf(pszBuf,"%s %s",szUserName,szPassword);
	fread(&admin1,sizeof(struct login),bOne,pFilePointer);
	if(!strncmp(szUserName,admin1.strUserName,10) && !strncmp(szPassword,admin1.strUserPassword,15))
	{
		nResult=bOne;
	}
	fclose(pFilePointer);
	if(nResult==bOne)
	{
		Send_Message(nSock,"1");
		Server_Admin_Menu(nSock);
		printf("******************\n");
	}
	else
	{
		printf("******************\n");
		Send_Message(nSock,"0");
		Server_Admin_Login(nSock);
	}
//	printf("nResult==%d\n",nResult);
}
