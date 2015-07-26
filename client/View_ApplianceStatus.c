#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif
extern char *Appliance[7];
void DisplayStatus(int nSock,char pszRecv[]);

void View_ApplianceStatus(int nSock)
{
	printf(" View_ApplianceStatus fun %u\n",nSock);
	int nFlatNo;
	char szSend[15];
	char *pszRecv;
	int x;
	char y[10],z[10];
	printf("in Delete_Account fun %u\n",nSock);
	printf("Enter FlatNo\n");
	scanf("%d",&nFlatNo);
	sprintf(szSend,"%d",nFlatNo);
	Send_Message(nSock,szSend);
	pszRecv=Receive_Message(nSock);
	if(!strcmp(pszRecv,"0"))
		printf("unsuccessful\n");
	else
	{
		DisplayStatus(nSock,pszRecv);
		printf("%s\n",pszRecv);
	//	sscanf(pszRecv,"%d  %s  %s ",&x,y,z);
	//	printf("%d %s %s",x,y,z);
	}
}

void DisplayStatus(int nSock,char pszRecv[])
{
	char pszAppliance_State[7][10];
	int nFlatNo;
	int i;
	sscanf(pszRecv,"%d %s %s %s %s %s %s %s",&nFlatNo,pszAppliance_State[0],pszAppliance_State[1],pszAppliance_State[2],pszAppliance_State[3],pszAppliance_State[4],pszAppliance_State[5],pszAppliance_State[6]);
	printf("\n\nAppliance\t\tStatus\n");
	for(i=bZero;i<7;i++)
	{
		printf("%s  \t\t",Appliance[i]);
		if(!strcmp(pszAppliance_State[i],"1"))
			printf("ON\n");
		else if(!strcmp(pszAppliance_State[i],"0"))
			printf("OFF \n");
		else
			printf("Unregistered\n");
	}
	printf("\n\n");
}
