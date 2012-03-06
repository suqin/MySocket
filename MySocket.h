#ifndef MYSOCKET_H
#define MYSOCKET_H
#include <winsock2.h>
#include <iostream>
#include <sstream> 
#include <windows.h>
#include <process.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib" )   
#pragma comment(lib, "wininet.lib")
using namespace std;
class MySocket
{
private:
	WSADATA socketInfo;
	static MySocket *instance;
	static int count;//引用计数
public:
	static MySocket *getInstance();
	MySocket(void);
	//GetSocketVersion();
	~MySocket(void);
};
#endif

