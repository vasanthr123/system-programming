//program function to create a tcp socket
#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#define PORTNO 8016
using namespace std;
int handlingErr(int flag, const char errmsg[])
  {
         if(flag < 0)   //check error 
         {
                 perror(errmsg);
                 exit(EXIT_FAILURE);
         }
         return 0;
  }

  int create_socket(string ip_addr, int port_num)
  {

           struct sockaddr_in servaddr;
           int sockfd;
           int slen;
           int ret;


           slen = sizeof(servaddr);

           servaddr.sin_family = AF_INET;
           servaddr.sin_port = htons(PORTNO);
           servaddr.sin_addr.s_addr = INADDR_ANY;

           sockfd = socket(AF_INET, SOCK_STREAM, 0);
           handlingErr(sockfd, "Error: Unable to  create TCP socket");

           ret = bind(sockfd, (struct sockaddr *) &servaddr, slen);
           handlingErr(ret, "Error: Unable to  bind TCP socket");
           ret = listen(sockfd, 5);
           handlingErr(ret, "Error: Unable to  listen on TCP socket");
           return sockfd;

  }
