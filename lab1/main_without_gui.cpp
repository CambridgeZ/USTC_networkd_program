#define _GNU_SOURCE 1
#define BUFSIZ 1024

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cassert>
#include <thread>
#include <atomic>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

// 线程函数，用于接收消息
void receive_messages(int sockfd) {
    char buf[BUFSIZ];
    while (true) {
        bzero(buf, BUFSIZ);
        struct sockaddr_in src_addr;
        socklen_t addr_len = sizeof(src_addr);

        ssize_t n = recvfrom(sockfd, buf, BUFSIZ, 0, (struct sockaddr*)&src_addr, &addr_len);
        if (n > 0) {
            buf[n] = '\0'; // 确保字符串以 null 结尾
            char src_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &src_addr.sin_addr, src_ip, INET_ADDRSTRLEN);
            int src_port = ntohs(src_addr.sin_port);

            cout << "Received from [" << src_ip << ":" << src_port << "]: " << buf << endl;
        } else if (n < 0) {
            perror("recvfrom failed");
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        printf("usage: %s ip_address port_number [local_port]\n", basename(argv[0]));
        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    // 如果有第三个参数，则解析本地端口
    int local_port = 0;
    if (argc == 4) {
        local_port = atoi(argv[3]);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    // 创建 UDP 套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    assert(sockfd >= 0);

    // 如果指定了本地端口号，则绑定到本地地址和端口
    if (local_port > 0) {
        struct sockaddr_in local_addr;
        bzero(&local_addr, sizeof(local_addr));
        local_addr.sin_family = AF_INET;
        local_addr.sin_addr.s_addr = INADDR_ANY; // 绑定到本地任意地址
        local_addr.sin_port = htons(local_port);

        int ret = bind(sockfd, (struct sockaddr*)&local_addr, sizeof(local_addr));
        if (ret < 0) {
            perror("bind failed");
            close(sockfd);
            return 1;
        }
    }

    // 启动接收消息的线程
    std::thread receiver(receive_messages, sockfd);

    // 主线程处理发送消息
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, stdin)) {
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    }

    // 等待接收线程结束
    receiver.join();
    close(sockfd);
    return 0;
}