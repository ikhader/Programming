#include "./StreamSock.h"
using namespace std;
int cStreamSocket::CreateSocket(void)
{

	cout <<"CreateSocket in cStreamSocket Class"<<endl;
	m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(m_sockfd == -1)
        {
        	cout<<"Error in creating socket"<< errno<<endl;//"des: "<<strerror(errno);
       		return -1;
        }
        if(m_bisServer)
        {
		
		struct sockaddr_in add;
                add.sin_addr.s_addr = INADDR_ANY;
                add.sin_port = htons(m_iPortNum);
                add.sin_family = AF_INET;
                if(bind(m_sockfd,(struct sockaddr*)&add, sizeof(struct sockaddr_in)) == -1)
                {
                	cout<<"Error in biding socket"<< errno<<endl;
                        return -1;
                }
                if(listen(m_sockfd, 10) == -1)
                {
                        cout<<"Error in listening to socket"<< errno<<endl;
                        return -1;
                }
        }
	else
		m_ConnFd = m_sockfd;
        return 0;
}
cStreamSocket::cStreamSocket(bool isServer , int portNum ):
 m_bisServer(isServer), m_iPortNum(portNum),m_sockfd(0),m_ConnFd(0), m_pstFromAddr(NULL)
{
	cout <<"Constructor  cStreamSocket Class"<<endl;
       	CreateSocket();
       	m_pstFromAddr =(struct sockaddr_in*) malloc(sizeof( struct sockaddr_in));
}
cStreamSocket::~cStreamSocket()
{
	cout <<"Destructor  cStreamSocket Class"<<endl;
        free (m_pstFromAddr);
        if(!m_sockfd)
        	close(m_sockfd);
	if(!m_ConnFd && m_bisServer)
      		close(m_ConnFd);
}
int cStreamSocket::AcceptConnection(void)
{
	if(!m_sockfd)
		if(CreateSocket()== -1)
			return -1;
	cout<<"Waiting for incomming connections "<<endl;
	m_ConnFd = accept(m_sockfd,(struct sockaddr*)m_pstFromAddr, &m_FrmAddrLen);
	if(m_ConnFd == -1)
		return -1;
	return 0;
}
int cStreamSocket::RecvData(char*Buff, int BuffLen)
{
	if(!m_ConnFd)
		return -1;
	return recv(m_ConnFd, Buff, BuffLen,0);
}
int cStreamSocket::SendData(char * buff, int len)
{
	if(!m_ConnFd)
		return -1;
	return send(m_ConnFd, buff, len, 0);
}
int cStreamSocket::Connect(char * DestAdd , int port )
{
	struct sockaddr_in to;
	if(DestAdd)
		to.sin_addr.s_addr = inet_addr(DestAdd);
	else
		to.sin_addr.s_addr = inet_addr("127.0.0.1");
	to.sin_port = htons(port);
	to.sin_family = AF_INET;
	return connect(m_sockfd,(struct sockaddr*) &to, sizeof(struct sockaddr_in));
}
