#include "MySocket.h"

MySocket* MySocket::instance=NULL;
int MySocket::count=0;
MySocket::MySocket(void)
{
	cout<<"套接字初始化中。。。\n";
	if(WSAStartup(MAKEWORD(2, 2),&socketInfo)!=0)
	{
		cout<<"套接字初始化失败\n";
		return ;
	}
	cout<<"套接字初始化完毕\n";

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
		cout<<"套接字关闭\n";
	}
		
}
