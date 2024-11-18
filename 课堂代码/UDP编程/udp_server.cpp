#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

using std::cout;
using std::endl;

int main(){
    /*
        AF_INET: IPv4
        SOCK_DGRAM: UDP
    */
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in MyAddr;
    memset(&MyAddr, 0, sizeof(MyAddr));
    MyAddr.sin_family = AF_INET;
    MyAddr.sin_port = htons(12345);
    MyAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 绑定socket
    int ret = bind(socketfd, (struct sockaddr*)&MyAddr, sizeof(MyAddr));
    if(ret == -1){
        cout << "bind error" << endl;
        return -1;
    }

    if(socketfd == -1){
        cout << "socket error" << endl;
        return -1;
    }
    cout<<"sockedfd: "<<socketfd<<endl;

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 将数据发送到地址为server_addr的socket上
    /*
        sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
        sockfd: socket文件描述符
        buf: 发送的数据
        len: 发送数据的长度
        flags: 0
        dest_addr: 目标地址
        addrlen: 目标地址的长度
    */

    // recv
    while(1){
        struct sockaddr_in sender;
        socklen_t sender_len = sizeof(sender);
        char buf[1024];

        int len = recvfrom(socketfd, buf, sizeof(buf), 0, (struct sockaddr*)&sender, &sender_len);
        if(len == -1){
            cout << "recvfrom error" << endl;
            return -1;
        }

        cout << "recv: " << buf << endl;

        char ip[16] = "";
        inet_ntop(AF_INET, &sender.sin_addr.s_addr, ip, sizeof(ip));
        cout << "from: " << ip << ":" << ntohs(sender.sin_port) << endl;

    }

    close(socketfd);
    return 0;
}