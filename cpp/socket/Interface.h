#ifndef __INTERFACE_SOCKET__
#define __INTERFACE_SOCKET__

class cSocket
{
        public:
        virtual int CreateSocket(void) = 0;
        virtual int AcceptConnection(void) = 0;//used only server
        virtual int SendData(char*, int) = 0;
        virtual int RecvData(char*Buff, int BuffLen) = 0;
	virtual int Connect(char *Add = 0, int port = 10000) = 0;
};
#endif //__INTERFACE_SOCKET__
