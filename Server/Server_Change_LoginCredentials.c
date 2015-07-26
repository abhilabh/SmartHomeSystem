#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_Change_LoginCredentials(int nSock)
{
	char szQuery[200];
	char szBuf[200];
	char szUserName[10];
	char szPassword[15];
	char *pszRecv=NULL;
	int nFlatNo,i,numrow;
	int num_fields=bZero;
	MYSQL_RES *result=NULL;
	MYSQL *con = mysql_init(NULL);
	pszRecv=Receive_Message(nSock);
	if(con == NULL) 
	{
	      fprintf(stderr, "%s\n", mysql_error(con));
	      //exit(1);
	}
	sscanf(pszRecv,"%s %s %d ",szUserName,szPassword,&nFlatNo);
	sprintf(szQuery,"select * from Login_Credentials where FlatNo=%d",nFlatNo);
//	printf("*******%s****\n",pszRecv);
	if(mysql_real_connect(con, "localhost", "root", "labh","rll", 0, NULL, 0) == NULL) 
	{
		finish_with_error(con);
		return;
	} 
	if (mysql_query(con, szQuery)) 
	{
		finish_with_error(con);
	}
	result = mysql_store_result(con);
	if (result == NULL) 
	{
		finish_with_error(con);
	}
  	//num_fields = mysql_num_fields(result);
  	numrow = mysql_num_rows(result);
	if(numrow==1)
	{
		sprintf(szQuery,"update  Login_Credentials set LoginName='%s',LoginPwd='%s' where FlatNo=%d",szUserName,szPassword,nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
			finish_with_error(con);
		}
		Send_Message(nSock,"1");
	}
	else
		Send_Message(nSock,"0");
}
