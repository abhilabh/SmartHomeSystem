#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif

void Server_Create_FlatAccount(int nSock)
{
	char szQuery[200];
	char szBuf[200];
	char szUserName[10];
	char szPassword[15];
	char szFlatOwnerName[10];
	char szResidingDate[15];
	char szDetails[nSize];
	char *pszRecv=NULL;
	int nContactNo=bZero;
	int nMembers=bZero;
	int nResult=bZero;
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
	nFlatNo=atoi(pszRecv);
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
 	if(numrow==0)
	{
  		Send_Message(nSock,"1");
		pszRecv=Receive_Message(nSock);
		sscanf(pszRecv,"%s %d %s %d ",szFlatOwnerName,&nContactNo,szResidingDate,&nMembers);
		sprintf(szQuery,"insert into Flat_Account values(%d,'%s','%d','%s',%d)",nFlatNo,szFlatOwnerName,nContactNo,szResidingDate,nMembers);
		printf("%s\n",szQuery);
		if (mysql_query(con, szQuery)) 
		{
			finish_with_error(con);
		}
		sprintf(szUserName,"%.2s%d",szFlatOwnerName,nContactNo%1000);
		srand(time(NULL));
		sprintf(szPassword,"%d",rand()%10000);
		sprintf(szBuf,"%s %s\n",szUserName,szPassword);
		sprintf(szQuery,"insert into Login_Credentials(FlatNo,FlatOwner,LoginName,LoginPwd) values(%d,'%s','%s','%s')",nFlatNo,szFlatOwnerName,szUserName,szPassword);
		printf("%s\n",szQuery);
		printf("%s\n",szBuf);
		if (mysql_query(con, szQuery)) 
		{
			finish_with_error(con);
		}
		sprintf(szQuery,"insert into Registered_Appliances (FlatNo) values (%d)",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
			finish_with_error(con);
		}
		sprintf(szQuery,"insert into Appliance_Status (FlatNo) values (%d)",nFlatNo);
		if (mysql_query(con, szQuery)) 
		{
			finish_with_error(con);
		}
		Send_Message(nSock,szBuf);


	}
  	else
  	{
		Send_Message(nSock,"0");
	 	Server_Create_FlatAccount(nSock);
	}
	printf("in create_flatacc fun %u\n",nSock);
	mysql_close(con);
}
