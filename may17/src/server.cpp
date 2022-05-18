//To create the program for server
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "12.0.0.1"
#define PORTNO 8016
#define MAX 256
#include "func.cpp"
using namespace std;

int main() {
	struct sockaddr_in servaddr,cliaddr;
	char smsg[MAX] = " Hello from the server to client";
	char cmsg[MAX];
	int sockfd,mlen,slen,connfd,client_pid,ret;
	socklen_t clen;
	bool status;
	status = true;

	slen = sizeof(sockaddr_in);
	memset(&servaddr,0,slen);
	memset(&cliaddr,0,slen);
	memset(cmsg,0,MAX);


	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(const struct sockaddr *)&servaddr,slen);
	listen(sockfd,5);
	if(ret < 0) {
		fputs("Error : unable to listen sockets", stderr);
		exit(EXIT_FAILURE);
	}
	while(1) {
		connfd = accept(sockfd,(struct sockaddr *) &cliaddr,&clen);
		if(connfd < 0) {
			fputs("Error: unable to accept the connection",stderr);
			exit(EXIT_FAILURE);
		}
		client_pid = fork();
		if(client_pid == 0) {
			mlen = read(connfd,cmsg,MAX);
			write(1,"message from client: ",21);
			write(1,cmsg,strlen(cmsg));
			string s=string(cmsg);
			if(s == "Bye"){
                        	status = false;
                        	close(connfd);
                	        break;
                        	exit(EXIT_SUCCESS);
                	}
			write(1,"enter your message to the client : ",32);
			mlen = read(0,smsg,MAX);
			mlen - write(connfd,smsg,strlen(smsg));
			close(connfd); // to close the socket connection
			exit(EXIT_SUCCESS);
		}
		close(connfd);
	}
}

