#include "UdpClient.h"
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cassert>

UdpClient::UdpClient(const std::string& serverIp, int serverPort, int localPort) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    assert(sockfd >= 0);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, serverIp.c_str(), &serverAddr.sin_addr);
    serverAddr.sin_port = htons(serverPort);

    if (localPort > 0) {
        bindToLocalPort(localPort);
    }
}

UdpClient::~UdpClient() {
    close(sockfd);
}

void UdpClient::bindToLocalPort(int localPort) {
    struct sockaddr_in localAddr;
    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = INADDR_ANY;
    localAddr.sin_port = htons(localPort);

    int ret = bind(sockfd, (struct sockaddr*)&localAddr, sizeof(localAddr));
    if (ret < 0) {
        perror("bind failed");
        close(sockfd);
        exit(1);
    }
}

void UdpClient::sendMessage(const std::string& message) {
    sendto(sockfd, message.c_str(), message.size(), 0, 
           (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

int UdpClient::getSocket() const {
    return sockfd;
}