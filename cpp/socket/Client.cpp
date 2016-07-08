#include <iostream>
#include "./StreamSock.h"

using namespace std;

int main(int argc, char * argv[])
{
  char RecvBuff[1024] = {0,};
  char Buff[] = "HELL HELL HELL";
  int cnt = 0;
  cSocket *TcpSock = new cStreamSocket(false);
  TcpSock->Connect();
  while(cnt < 2)
  {
    TcpSock->SendData(Buff, strlen(Buff));
    TcpSock->RecvData(RecvBuff, 1024);
    cout<<"Recvd buff: "<< RecvBuff<<endl;
    cnt++;
  }
  delete TcpSock;
  return 0; 
}
