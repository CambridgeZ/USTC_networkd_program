#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

int main(){
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1){
        std::cerr << "socket error" << std::endl;
        return -1;
    }

    std::cout<<"socketfd "<<listenfd<<std::endl;

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int isconnect = connect(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(isconnect==-1){
        std::cerr<<"connect error"<<std::endl;
        return -1;
    }
    int irev = 0;
    char buf[1024] = {0};
    while(1){
        irev = recv(listenfd, buf, sizeof(buf), 0);
        if(irev == 0){
            // 说明连接中断了
            close(listenfd);    // 关闭连接
            break;
        }
        else if(irev > 0){
            std::cout << "recv: " << buf << std::endl;
        }
        else {
            std::cerr << "recv error" << std::endl;
            close(listenfd);
            break;
        }
    }

    return 0;

}