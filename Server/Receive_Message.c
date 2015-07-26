#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
//#include"./../Common_Api.h"
#endif
char* Receive_Message(int nSock)
{
	static char *pszChoice;
	pszChoice=(char *)malloc(nSize);
	if(recv(nSock,pszChoice,nSize,bZero))
	return pszChoice;
	else
	{
		close(nSock);
		printf("closing thread.....\n");
		pthread_exit((void **)0);
	}
}
