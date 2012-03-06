#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include "MySocket.h"
using namespace std;

class MyTcpSocket
{
public:
	MyTcpSocket();                                 //���캯��
	MyTcpSocket(const MyTcpSocket *socket);        //�������캯��
	int Send(const string buff);                   //�����ַ���buff
	int Recive(string *buff);                      //�����ַ���������buff��
	bool Connect(const string Ip,const short port);//��������
	~MyTcpSocket(void);                            //��������
	SOCKET TcpSocket;                              //�׽��־��
	SOCKADDR_IN SocketAddr;                        //�׽��ֵ�ַ�˿���Ϣ
	int Len;                                       //�׽��ֵ�ַ�˿���Ϣ����
	unsigned int SendThreadId;
	string *Buff;
private:
	MySocket *WSAInfo;                             //ȫ���׽�����Ϣ
};
#endif

