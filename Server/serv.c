#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#endif

void* Transact_With_Client(void *pSock);
int sockNo;
void closing();
void signalHandler(int);

//void server_menu(int sock);
int main(int argc,char*argv[])
{
	pthread_t nThread_id;
	struct sockaddr_in serv,cli;
	int port,nSock1,nSock;
	port=50999;
	atexit(closing);
	signal(SIGINT,signalHandler);
	
	Create_Table();
	nSock1=socket(AF_INET,SOCK_STREAM,bZero);
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(port);
	if(bind(nSock1,(struct sockaddr*)&serv,sizeof(serv))==-1)
	{
		printf("error in bind function\n");
	}
	listen (nSock1,bListen);
	while(bOne)
	{
		int size=sizeof(cli);
		nSock=accept(nSock1,(struct sockaddr*)&cli,&size);
		printf("Accepted a connection\n");
		pthread_create(&nThread_id,NULL,Transact_With_Client,&nSock);
		//transact_with_client(nsd);
		//close(nsd);
	}
	close(nSock1);
}

void* Transact_With_Client(void *pSock)
{
	int nSock=sockNo=*(int *)pSock;
	int n,choice;

//	while(bOne)
	server_menu(nSock);
	/*while((n=recv(s,buf,sizeof(buf),0))>0)
		send(s,buf,n,0);*/
}

void closing(){
	printf("closing Socket %d...\n",sockNo);
	if(sockNo)
		close(sockNo);
}

void signalHandler(int sig){
	printf("quitting...\n");
	exit(sig);
}
