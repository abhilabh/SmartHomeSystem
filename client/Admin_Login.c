#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif
void Admin_Login(int nsock)
{
	char szUserName[10];
	char szPassword[15];
	char szBuf[nSize];
	char *pszBuf;
	int nResult=bZero;
	char *getpass(const char* prompt);
//	struct login admin;
	printf("Admin_Login func %d\n",nsock);
	printf("Enter your User Name\n");
	__fpurge(stdin);
	fgets(szUserName,15,stdin);

	printf("Enter your password\n");
	__fpurge(stdin);
	sprintf(szPassword,"%s",getpass("enter"));
//	printf("%s  %d\n",szPassword,sizeof(szPassword));
	szUserName[strlen(szUserName)-1]='\0';
//	szPassword[strlen(szPassword)-1]='\0';
	sprintf(szBuf,"%s %s",szUserName,szPassword);
	printf("%s\n",szBuf);
	//send(nsock,szBuf,sizeof(szBuf),bZero);
	Send_Message(nsock,szBuf);
	pszBuf=Receive_Message(nsock);
	nResult=atoi(pszBuf);
	if(nResult==bOne)
	{
		printf("login success\n");
		Admin_Menu(nsock);
	}
	else 
	{
		printf("login failed\n");
		Admin_Login(nsock);
	}
}

/*#ifdef DEBUG
int main(){
	Admin_Login(5);
	Admin_Login(5);

}
#endif*/
