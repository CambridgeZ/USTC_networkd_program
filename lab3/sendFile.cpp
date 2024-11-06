#include "config.hpp"
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
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[]){ 

    char tempIP[15];
    int port;
    
    if(argc <= 2){
        std::cout << "Usage: " << argv[0] << " <IP> <PORT>" << std::endl;
        // return 1;
        std::cout << "Using default IP and PORT" << std::endl;
        strcpy(tempIP, IP);
        port = PORT;
    }
    else{
        strcpy(tempIP, argv[1]);
        port = atoi(argv[2]);
        const char *file = argv[3];
    }

    const char *ip = tempIP;

    //获取文件名
    cout<<"Please input the file name:"<<endl;
    string filename;
    cin>>filename;

    const char *file = filename.c_str();

    int filefd = open(file, O_RDONLY);
    assert(filefd != -1);
    
    // 获取文件属性
    struct stat stat_buf;
    fstat(filefd, &stat_buf);

    // 创建socket
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);

    // 绑定
    int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    assert(ret != -1);
    ret = listen(sockfd, 5);
    assert(ret != -1);

    // 接受连接
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