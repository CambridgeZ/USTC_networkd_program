#include "Socket.hpp"
#include <cstring>
#include <cassert>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


Socket::Socket(int port, const char* ip){
    memset(&server_address,0,sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&server_address.sin_addr);
    server_address.sin_port = htons(port);
    this->sockfd = socket(PF_INET,SOCK_STREAM,0);

    assert(sockfd >= 0);

    if(connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address)) < 0){
        printf("connection failed\n");
        close(sockfd);
        exit(1);
    }
}

Socket::~Socket(){
    close(sockfd);
}

int Socket::getFd() const{
    return sockfd;
}