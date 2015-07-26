#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Create_FlatAccount(int nsock)
{
	char szFlatNo[15];
	char szUserName[10];
	char szPassword[15];
	char szFlatOwnerName[10];
	char szResidingDate[15];
	char szDetails[nSize];
	char *pszRecv=NULL;
	int nContactNo=bZero;
	int nMembers=bZero;
	int nResult=bZero;
	printf("in create_flatacc fun %u\n",nsock);
	printf("Enter your FlatNo:");
	scanf("%s",szFlatNo);
	Send_Message(nsock,szFlatNo);
	pszRecv=Receive_Message(nsock);
	nResult=atoi(pszRecv);
	if(nResult==bOne)
	{
		printf("FlatNo available\n");
		printf("Enter Flat Owner Name\n");
		__fpurge(stdin);	
		fgets(szFlatOwnerName,10,stdin);
		printf("Enter your contact number\n");
		scanf("%d",&nContactNo);
		printf("Enter the residing from date\n");
		__fpurge(stdin);
		fgets(szResidingDate,15,stdin);
		printf("Enter No.of.Members in family\n");
		scanf("%d",&nMembers);
		szFlatOwnerName[strlen(szFlatOwnerName)-1]='\0';
		szResidingDate[strlen(szResidingDate)-1]='\0';
		sprintf(szDetails,"%s %d %s %d ",szFlatOwnerName,nContactNo,szResidingDate,nMembers);
		Send_Message(nsock,szDetails);
		pszRecv=Receive_Message(nsock);
		printf("++++++++++++++++\n");
		//fputs(pszRecv,stdout);
		printf("%s\n",pszRecv);
	}
	else
	{
		printf("FlatNo not available\n");
		Create_FlatAccount(nsock);
	}
}
