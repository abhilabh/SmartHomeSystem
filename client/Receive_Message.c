#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
//#include"../Common_Api.h"
#endif


char* Receive_Message(int nSock)
{
	static char *pszChoice;
	pszChoice=(char *)malloc(nSize);
	recv(nSock,pszChoice,nSize,bZero);
	return pszChoice;
}
