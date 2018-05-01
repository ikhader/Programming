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
  add.sin_addr.s_addr = INADDR_ANY;
  add.sin_port = htons(23456);
  add.sin_family = AF_INET;

  if(bind(sock_fd, (struct sockaddr*)&add, sizeof(struct sockaddr_in)) == -1)
  {
    printf("Error in binding socket [%d]\n", errno);
    return -1; 
  }

  memset(&addr, 0x00, sizeof(struct sockaddr));
  addrLen = sizeof(addr);
  recv_len = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *) &addr, &addrLen);
  if( recv_len == -1)
  {
    printf("Error in receving from socket [%d]\n", errno);
    return -1; 
  }
  printf("Buffer of len[%ld] with string[%s]recevived \n", recv_len, buffer);
  memset(buffer, 0x00, sizeof(buffer));
  strcpy(buffer, "hello this is server!!");

  if(sendto(sock_fd, buffer, strlen(buffer), 0, &addr, sizeof(struct sockaddr)) == -1)
  {
    printf("Error in sending from socket [%d]\n", errno);
    return -1; 
  } 
  
  return 0;
  
}
