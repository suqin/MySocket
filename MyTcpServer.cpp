#include "MyTcpServer.h"
MyTcpServer::MyTcpServer(short port)
{
	
	WSAInfo=WSAInfo->getInstance();
	Len=sizeof(ServerAddr);
	ServerAddr.sin_family=AF_INET;
	ServerAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	ServerAddr.sin_port=htons(port);
	TcpServer=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(bind(TcpServer,(sockaddr *) &ServerAddr,Len)!=0)
	{
		cout<<"TcpServer��ʼ��ʧ��"<<endl;
		exit(1);
	}
	if(0!=listen(TcpServer,SOMAXCONN))
	{
		cout<<"�޷������˿�"<<port<<endl;
		exit(2);
	}
	cout<<"����"<<port<<"�˿ڳɹ�\n";

}
MyTcpServer::~MyTcpServer(void)
{
	cout<<"�Ͽ�����:"<<ntohs(ServerAddr.sin_port)<<endl;
	WSAInfo->~MySocket();
	
}
MyTcpSocket* MyTcpServer::Accept()
{
	MyTcpSocket *Temp;
	Temp=new MyTcpSocket();
	Temp->TcpSocket=accept(TcpServer,(sockaddr *)&(Temp->SocketAddr),&Len);
	return Temp;
}
