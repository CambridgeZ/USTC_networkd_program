#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

using std::cerr;
using std::cout;

int main(){
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1){
        std::cerr << "socket error" << std::endl;
        return -1;
    }

    cout<<"socketfd "<<listenfd<<std::endl;

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    int isend = send(listenfd, "hello", sizeof("hello"), 0);

    return 0;
}