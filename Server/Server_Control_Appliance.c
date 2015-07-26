#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_Control_Appliance(int nSock)
{
	char *pszRecv=NULL;
	char szQuery[200];
	char szAppliance[25];
	int nFlatNo;
	int nApNo;
	int nState;
	int numrow=0;
	MYSQL_RES *result=NULL;
	pszRecv=Receive_Message(nSock);
	printf("%s\n",pszRecv);
	sscanf(pszRecv,"%d %d %d",&nFlatNo,&nApNo,&nState);
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
	sprintf(szQuery,"select * from Appliance_Status where FlatNo=%d and Appliance%dState is NOT NULL",nFlatNo,nApNo);
	if (mysql_query(con, szQuery)) 
 	{
     		 finish_with_error(con);
	}
	result = mysql_store_result(con);
 	if (result == NULL) 
	{
     		 finish_with_error(con);
 	}
	numrow = mysql_num_rows(result);
	if(numrow==0)
		Send_Message(nSock,"0");
	else
	{
		sprintf(szQuery,"update Appliance_Status set Appliance%dState=%d where FlatNo=%d ",nApNo,nState,nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
      			finish_with_error(con);
  		}
		Send_Message(nSock,"1");
	}
}
