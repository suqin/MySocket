#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include "MySocket.h"
using namespace std;

class MyTcpSocket
{
public:
	MyTcpSocket();                                 //构造函数
	MyTcpSocket(const MyTcpSocket *socket);        //拷贝构造函数
	int Send(const string buff);                   //发送字符串buff
	int Recive(string *buff);                      //接收字符串并存在buff里
	bool Connect(const string Ip,const short port);//建立连接
	~MyTcpSocket(void);                            //析构函数
	SOCKET TcpSocket;                              //套接字句柄
	SOCKADDR_IN SocketAddr;                        //套接字地址端口信息
	int Len;                                       //套接字地址端口信息长度
	unsigned int SendThreadId;
	string *Buff;
private:
	MySocket *WSAInfo;                             //全局套接字信息
};
#endif

