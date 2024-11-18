// udp_echo_server

#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <cstring>

using std::cout;
using std::endl;

int main(){
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1){
        cout << "socket error" << endl;
        return -1;
    }

    int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while(1){
        struct sockaddr_in sender;
        socklen_t sender_len = sizeof(sender);
        char buf[1024];

        int len = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&sender, &sender_len);
        if(len == -1){
            cout << "recvfrom error" << endl;
            return -1;
        }

        cout << "recv: " << buf << endl;

        sendto(sockfd, buf, len, 0, (struct sockaddr*)&sender, sender_len);
    }

    close(sockfd);
    return 0;
}