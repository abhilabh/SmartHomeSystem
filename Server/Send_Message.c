#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
//#include"../Common_Api.h"
#endif

void Send_Message(int nSock,char nChoice[])
{
	send(nSock,nChoice,nSize,bZero);
}
