#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>


int main(int argc, char *argv[])
{
  int sock_fd = socket(PF_INET, SOCK_DGRAM, 0);
  char buffer[512] = {'\0', };
  socklen_t addrLen = 0;
  struct sockaddr addr;
  struct sockaddr_in add;
  ssize_t recv_len = 0;

  if(sock_fd == -1) 
  {
    printf("Error in creating socket [%d]\n", errno);
    return -1; 
  }

  memset(&add, 0x00, sizeof(add));
  
  //add.sin_addr.s_addr = inet_addr("127.0.0.1");
  add.sin_port = htons(23456);
  add.sin_family = AF_INET;
  if (inet_aton("127.0.0.1", &add.sin_addr) == -1)
  {
    printf("Error in inet_aton from socket [%d]\n", errno);
    return -1; 
  }
 
  strcpy(buffer, "Hello World!!");
  if(sendto(sock_fd, buffer, strlen(buffer), 0, (struct sockaddr*)&add, sizeof(struct sockaddr)) == -1)
  {
    printf("Error in sending from socket [%d]\n", errno);
    return -1; 
  } 
  memset(buffer, 0x00, sizeof(buffer));

  if( (recv_len = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *) &addr, &addrLen)) == -1)
  {
    printf("Error in receving from socket [%d]\n", errno);
    return -1; 
  }

  printf("Client received data: [%s]\n", buffer);
  
  return 0;
  
}
