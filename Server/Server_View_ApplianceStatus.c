#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif
void Server_View_ApplianceStatus(int nSock)
{
	char *pszRecv;
	int nFlatNo,i,numrow;
	int num_fields=bZero;
	char szQuery[200];
	char szSend[200];
	MYSQL_ROW row;
	MYSQL_RES *result=NULL;
	MYSQL *con = mysql_init(NULL);
	pszRecv=Receive_Message(nSock);
	nFlatNo=atoi(pszRecv);
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
	sprintf(szQuery,"select * from Appliance_Status where FlatNo=%d",nFlatNo);
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
		row = mysql_fetch_row(result);
		sprintf(szSend,"%s %s %s %s %s %s %s %s",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7]);
		printf("%s\n",szSend);
		Send_Message(nSock,szSend);
		mysql_free_result(result);
		mysql_close(con);
	}

}
