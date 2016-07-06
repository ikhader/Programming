#include <stdio.h>
#include <iostream>
#include "./StreamSock.h"
using namespace std;

int main(int argc, char *argv[])
{
  char buff[1024] = {0,};
  bool bDone = false;
  cout<<"CPP started "<<endl;
  cSocket *TCPSock = new cStreamSocket();
  TCPSock->AcceptConnection();
  while(!bDone)
  {
    int recvdsize = TCPSock->RecvData(buff, 1024);	
    if(recvdsize <= 0)
      bDone = true; 
    else
      TCPSock->SendData(buff, recvdsize);
    cout<<"Buff: "<<buff<<endl;
  }
  delete TCPSock;
  cout<<"DONE!!!" <<endl;
}
