#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif

/*void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
 // exit(1);        
}*/

void Server_FlatOwner_Login(int nSock)
{
	char *pszRecv;
	char szUserName[10];
	char szPassword[15];
	char szQuery[200];
	int nFlatNo,i,numrow;
	int num_fields=bZero;
	MYSQL_RES *result=NULL;
	MYSQL *con = mysql_init(NULL);
	if(con == NULL) 
	{
     		 fprintf(stderr, "%s\n", mysql_error(con));
     		 //exit(1);
	}


	printf("In func login %u\n",nSock);
	pszRecv=Receive_Message(nSock);
	printf("*******%s****\n",pszRecv);
	sscanf(pszRecv,"%s %s %d",szUserName,szPassword,&nFlatNo);
	sprintf(szQuery,"select * from Login_Credentials where FlatNo=%d and LoginName='%s' and LoginPwd='%s'",nFlatNo,szUserName,szPassword);
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
  	num_fields = mysql_num_fields(result);
  	numrow = mysql_num_rows(result);
  	if(numrow==0)
	{
  		Send_Message(nSock,"0");
 		Server_FlatOwner_Login(nSock);
	}
  	else
  	{
		Send_Message(nSock,"1");
	 	Server_FlatOwner_Menu(nSock);
	}
	printf("*****length field=%d**\n",numrow);

  	MYSQL_ROW row;
  	while ((row = mysql_fetch_row(result))) 
 	{ 
     	 for(i = 0; i < num_fields; i++) 
     	 { 
        	  printf("%s ", row[i] ? row[i] : "NULL"); 
     	 } 
  	  printf("\n"); 
 	} 
  	mysql_free_result(result);
	mysql_close(con);
	printf("MySQL client version: %s\n", mysql_get_client_info());

}
