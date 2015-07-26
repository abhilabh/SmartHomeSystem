#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_Registered_Appliance(int nSock)
{
	char *pszRecv=NULL;
	char szQuery[200];
	char szAppliance[25];
	int nFlatNo;
	int nApNo;
	pszRecv=Receive_Message(nSock);
	printf("%s\n",pszRecv);
	sscanf(pszRecv,"%d %s %d",&nFlatNo,szAppliance,&nApNo);
	sprintf(szQuery,"update Registered_Appliances set Appliance%d='%s' where FlatNo=%d ",nApNo,szAppliance,nFlatNo);
	printf("%s\n",szQuery);
	MYSQL *con = mysql_init(NULL);
	if(con == NULL) 
	{
	      fprintf(stderr, "%s\n", mysql_error(con));		    
	      //exit(1);
	}
	if(mysql_real_connect(con, "localhost", "root", "labh","rll", 0, NULL, 0) == NULL) 
  	{
      		finish_with_error(con);
		return;
  	} 
	if (mysql_query(con, szQuery)) 
	{
      		finish_with_error(con);
  	}
	sprintf(szQuery,"update Appliance_Status set Appliance%dState=0 where FlatNo=%d ",nApNo,nFlatNo);
	if (mysql_query(con, szQuery)) 
	{
      		finish_with_error(con);
  	}
}
