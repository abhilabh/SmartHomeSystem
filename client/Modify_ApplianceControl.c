
#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Modify_ApplianceControl(int nSock,int nFlatNo)
{
	int nChoice;
	char szBuf[200];
	int nState;
	char *pszRecv;
	printf("\n\t\tSelect the Appliance you want to unregister:\n");
	printf("\t1. Geyser\n");
	printf("\t2. Hall Light\n");
	printf("\t3. Bedroom Light\n");
	printf("\t4. Kitchen Light\n");
	printf("\t5. Bedroom AC\n");
	printf("\t6. Hall AC\n");
	printf("\t7. Refrigerator\n");
	scanf("%d",&nChoice);
	sprintf(szBuf,"%d %d",nFlatNo,nChoice);
	Send_Message(nSock,szBuf);
	printf(" Registered_Appliance fun %u\n",nSock);
	
	pszRecv=Receive_Message(nSock);
	if(!strcmp(pszRecv,"0"))
		printf("unsuccessful\n");
	else
	{
		printf("Successfully Modified\n");
	}
}
