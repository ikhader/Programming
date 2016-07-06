#working to build to client and server
#all:
#	g++ StreamSock.cpp Server.cpp -o Server
#	g++ StreamSock.cpp Client.cpp -o Client

all: client server

client: Client.o StreamSock.o
	g++ Client.o StreamSock.o -o client

server: Server.o StreamSock.o
	g++ Server.o StreamSock.o -o server
Server.o: Server.cpp
	g++ -c Server.cpp
 
Client.o: Client.cpp
	g++ -c Client.cpp
StreamSock.o: StreamSock.cpp
	g++ -c StreamSock.cpp


clean:
	rm -f *.o client server

