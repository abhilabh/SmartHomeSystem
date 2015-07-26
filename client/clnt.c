#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include "Header.h"
#include "Method.h"
#endif
static void Transact_With_Serv(int nSock);
int nSockNo;
void closing(void);
void signalHandler(int);

int main(void)
{
	struct sockaddr_in serv;
	int nport;
	int nSock;
	int nret;

	nport=50999;
	atexit(closing);
	signal(SIGINT,signalHandler);
	nSock=socket(AF_INET,SOCK_STREAM,bZero);
	memset(&serv,bZero,sizeof(struct sockaddr_in));
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(nport);
	if(connect(nSock,(struct sockaddr*)&serv,sizeof(serv))==-1)
	{
		printf("error in connect func\n");
	}
	Transact_With_Serv(nSock);
	nret=close(nSock);
	return 0;
}
void Transact_With_Serv(int nSock)
{
	Client_menu(nSock);
}

void closing(void)
{
	int nret2;
	printf("closing socket....%d\n",nSockNo);
	if(nSockNo)
		nret2=close(nSockNo);
}
void signalHandler(int sig)
{
	printf("quitting....\n");
	exit(sig);
}
