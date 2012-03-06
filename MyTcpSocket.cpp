#include "MyTcpSocket.h"
HANDLE SendEvent;
HANDLE RecvEvent;
static unsigned  WINAPI sendFunc(void* soc)
{
	CRITICAL_SECTION SendSection;
	InitializeCriticalSection(&SendSection);
	EnterCriticalSection(&SendSection);
	MyTcpSocket *Sender;
	Sender=(MyTcpSocket *) soc;
	send(Sender->TcpSocket,Sender->Buff->c_str(),Sender->Buff->size(),MSG_OOB);
	LeaveCriticalSection(&SendSection);
	DeleteCriticalSection(&SendSection);
	SetEvent(SendEvent);
	_endthreadex(0);
	return 0;
}
static unsigned  WINAPI RecvFunc(void* soc)
{
	MyTcpSocket *Reciver;
	Reciver=(MyTcpSocket *) soc;
	char buff[128];
	memset(buff,0,128);
	if(recv(Reciver->TcpSocket,buff,128,0)<=0)
	{
		cout<<"连接错误"<<endl;
		exit(7);
	}
	CRITICAL_SECTION RecvSection;
	InitializeCriticalSection(&RecvSection);
	EnterCriticalSection(&RecvSection);
	int i=0;
	while(buff[i]!=0)
	{
		Reciver->Buff->push_back(buff[i]);
		i++;
	}
	LeaveCriticalSection(&RecvSection);
	DeleteCriticalSection(&RecvSection);
	SetEvent(RecvEvent);
	_endthreadex(0);
	return 0;
}
MyTcpSocket::MyTcpSocket()
{
	WSAInfo=WSAInfo->getInstance();
	TcpSocket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}
MyTcpSocket::MyTcpSocket(const MyTcpSocket *socket)
{
	WSAInfo=WSAInfo->getInstance();
	TcpSocket=socket->TcpSocket;
	SocketAddr=socket->SocketAddr;
	Len=socket->Len;
}
bool MyTcpSocket::Connect(const string Ip,const short port)
{
	SocketAddr.sin_family=AF_INET;
	SocketAddr.sin_port=htons(port);
	SocketAddr.sin_addr.s_addr=inet_addr(Ip.c_str());
	Len=sizeof(SocketAddr);
	if(0!=connect(TcpSocket,(sockaddr *) &SocketAddr,Len))
	{
		cout<<"无法连接到目标"<<endl;
		return false;
	}
	cout<<"连接到"<<port<<"成功"<<endl;
	return true;

}
int MyTcpSocket::Send(const string buff)
{
	SendEvent=CreateEvent(NULL,0,0,NULL);
	Buff=new string(buff);
	if(_beginthreadex(NULL,0,sendFunc,this,0,&SendThreadId)==0)
		cout<<"ssss";
	WaitForSingleObject(SendEvent,INFINITE);
	return 0;
}
int MyTcpSocket::Recive(string *buff)
{
	RecvEvent=CreateEvent(NULL,0,0,NULL);
	Buff=buff;
	_beginthreadex(NULL,0,RecvFunc,this,0,&SendThreadId);
	WaitForSingleObject(RecvEvent,INFINITE);
	return 0;
}
MyTcpSocket::~MyTcpSocket(void)
{

}
