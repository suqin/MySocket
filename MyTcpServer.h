#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include "MySocket.h"
#include "MyTcpSocket.h"
class MyTcpServer
{
public:
	MyTcpServer(short port);
	~MyTcpServer(void);
	MyTcpSocket* Accept();
private:
	SOCKET TcpServer;
	SOCKADDR_IN ServerAddr;
	int Len;
	MySocket *WSAInfo;

};
#endif


