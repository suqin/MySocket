#include "MySocket.h"

MySocket* MySocket::instance=NULL;
int MySocket::count=0;
MySocket::MySocket(void)
{
	cout<<"�׽��ֳ�ʼ���С�����\n";
	if(WSAStartup(MAKEWORD(2, 2),&socketInfo)!=0)
	{
		cout<<"�׽��ֳ�ʼ��ʧ��\n";
		return ;
	}
	cout<<"�׽��ֳ�ʼ�����\n";

}
MySocket* MySocket::getInstance()
{
	if(instance==NULL)
	{
		instance=new MySocket;
	}
	count++;
	return instance;
}

MySocket::~MySocket(void)
{
	count--;
	if(count==0)
	{
		WSACleanup();
		cout<<"�׽��ֹر�\n";
	}
		
}
