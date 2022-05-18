//Program to communicate with client
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "12.0.01"
#define PORTNO 8016
#define MAX 256
#include "func.cpp"
using namespace std;

int main() {
	struct sockaddr_in servaddr;
	char cmsg[MAX] = " Hello from client to server";
	char smsg[MAX];
	int sockfd,mlen,structlen; //defining variables
	socklen_t servaddrlen;

	structlen = sizeof(sockaddr_in);
	memset(&servaddr,0,structlen);
	memset(smsg,0,MAX);
	//defining ip ports and addresses
	servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
        connect(sockfd,(struct sockaddr *) &servaddr,structlen);
        write(1,"enter your message to server: ",31);
        mlen=read(0,cmsg,MAX);
        mlen=write(sockfd,cmsg,strlen(cmsg));
        write(1,"message sent from the client: ",31);
        write(1,cmsg,strlen(cmsg));
        mlen=read(sockfd,smsg,MAX);
        write(1,smsg,strlen(smsg));
        close(sockfd);
        }
