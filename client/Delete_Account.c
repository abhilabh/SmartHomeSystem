#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Delete_Account(int nSock)
{	
	int nFlatNo;
	char szSend[15];
	char *pszRecv;
	printf("in Delete_Account fun %u\n",nSock);
	printf("Enter FlatNo\n");
	scanf("%d",&nFlatNo);
	sprintf(szSend,"%d",nFlatNo);
	Send_Message(nSock,szSend);
	pszRecv=Receive_Message(nSock);
	if(!strcmp(pszRecv,"1"))
		printf("Delete FlatNo %d successfully\n",nFlatNo);
	else
		printf("deletion is unsuccessfully\n");
}
