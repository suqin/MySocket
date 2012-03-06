#include "main.h"
using namespace std;
int main()
{
	MyTcpServer sss(4321);
	MyTcpSocket *con=sss.Accept();
	con->Send("fuck");
	sss.~MyTcpServer();
	/*MyTcpSocket *connect;
	connect=new MyTcpSocket;
	string buff;
	connect->Connect("127.0.0.1",4321);
	connect->Send("zzzzz");
	while(1)
	{
		string buff;
		connect->Recive(&buff);
		cout<<buff;
	}*/
	return 0;
}