#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

char *Appliance[]={"Geyser","Hall_Light","Bedroom_Light","Bedroom_Light","Kitchen_Light","Bedroom_Ac","Hall_Ac","Refrigerator"};
void Registered_Appliance(int nSock,int nFlatNo)
{
	int nChoice;
	char szBuf[200];
	printf("\n\t\tSelect the Appliance you want to register:\n");
	printf("\t1. Geyser\n");
	printf("\t2. Hall Light\n");
	printf("\t3. Bedroom Light\n");
	printf("\t4. Kitchen Light\n");
	printf("\t5. Bedroom AC\n");
	printf("\t6. Hall AC\n");
	printf("\t7. Refrigerator\n");
	scanf("%d",&nChoice);
	sprintf(szBuf,"%d %s %d",nFlatNo,Appliance[nChoice-bOne],nChoice);
	Send_Message(nSock,szBuf);
	printf(" Registered_Appliance fun %u\n",nSock);
}
