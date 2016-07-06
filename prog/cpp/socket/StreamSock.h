#include "Interface.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
class cStreamSocket:public  cSocket
{
	private:
	        bool m_bisServer;
       		int m_iPortNum;
	        int m_sockfd, m_ConnFd;
	        struct sockaddr_in *m_pstFromAddr;
       		socklen_t m_FrmAddrLen ;
	        int CreateSocket(void);
	public:
        	cStreamSocket(bool isServer = true, int portNum = 10000);
	        ~cStreamSocket();
       		int AcceptConnection(void);
	        int RecvData(char*Buff, int BuffLen);
	        int SendData(char * buff, int len);
		int Connect(char * DestAdd = 0, int port = 10000);
};
