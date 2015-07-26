#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_Delete_Account(int nSock)
{
	int nFlatNo;
	int numrow=bZero;
	char *pszRecv;
	char szQuery[200];
	MYSQL_RES *result=NULL;
	pszRecv=Receive_Message(nSock);
	nFlatNo=atoi(pszRecv);

	printf("in Delete_Account fun %u\n",nSock);
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
	sprintf(szQuery,"select * from Login_Credentials where FlatNo=%d",nFlatNo);
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
	if(numrow==1)
	{	
		sprintf(szQuery,"delete from Appliance_Status where FlatNo=%d",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
      			finish_with_error(con);
  		}
		sprintf(szQuery,"delete from Registered_Appliances where FlatNo=%d",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
      			finish_with_error(con);
  		}
		sprintf(szQuery,"delete from Login_Credentials where FlatNo=%d",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
      			finish_with_error(con);
  		}
		sprintf(szQuery,"delete from Flat_Account where FlatNo=%d",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
      			finish_with_error(con);
  		}
		Send_Message(nSock,"1");
	}
	else
	{	
		Send_Message(nSock,"0");
	}
 	mysql_free_result(result);
	mysql_close(con);

}
