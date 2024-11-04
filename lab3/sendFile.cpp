#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>


int main(int argc, char *argv[]){
    if(argc <= 3){
        std::cout << "Usage: " << argv[0] << " <IP> <PORT> <FILE>" << std::endl;
        return 1;
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);
    const char *file = argv[3];

    int filefd = open(file, O_RDONLY);
    assert(filefd != -1);
    struct stat stat_buf;
    fstat(filefd, &stat_buf);
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);
    int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    assert(ret != -1);
    ret = listen(sockfd, 5);
    assert(ret != -1);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if(connfd < 0){
        std::cout << "errno is: " << errno << std::endl;
    }else{
        sendfile(connfd, filefd, NULL, stat_buf.st_size);
        close(connfd);
    }
    close(sockfd);
    return 0;
}