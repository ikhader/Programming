#include <stdio.h>
#include <iostream>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <errno.h>
//#include <arpa/inet.h>
//#include <string.h>
//#include <sys/socket.h>
#include "./StreamSock.h"
using namespace std;

int main(int argc, char *argv[])
{
	char buff[1024] = {0,};
	cout<<"CPP started "<<endl;
	cSocket *TCPSock = new cStreamSocket();
	TCPSock->AcceptConnection();
	int recvdsize = TCPSock->RecvData(buff, 1024);	
	if(recvdsize != -1)
		TCPSock->SendData(buff, recvdsize);
	//cStreamSocket *TCPSock = new cStreamSocket();
	cout<<"Buff: "<<buff<<endl;
	delete TCPSock;
	cout<<"DONE!!!" <<endl;
}
