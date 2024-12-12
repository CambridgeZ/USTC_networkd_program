#include "MessageReceiver.h"
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define BUFSIZ 1024

MessageReceiver::MessageReceiver(int sockfd) : sockfd(sockfd), running(false) {}

MessageReceiver::~MessageReceiver() {
    stop();
}

void MessageReceiver::start() {
    running = true;
    receiverThread = std::thread(&MessageReceiver::receiveMessages, this);
}

void MessageReceiver::stop() {
    if (running) {
        running = false;
        if (receiverThread.joinable()) {
            receiverThread.join();
        }
    }
}

void MessageReceiver::receiveMessages() {
    char buf[BUFSIZ];
    while (running) {
        bzero(buf, BUFSIZ);
        struct sockaddr_in srcAddr;
        socklen_t addrLen = sizeof(srcAddr);

        ssize_t n = recvfrom(sockfd, buf, BUFSIZ, 0, (struct sockaddr*)&srcAddr, &addrLen);
        if (n > 0) {
            buf[n] = '\0';
            char srcIp[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &srcAddr.sin_addr, srcIp, INET_ADDRSTRLEN);
            int srcPort = ntohs(srcAddr.sin_port);

            std::cout << "Received from [" << srcIp << ":" << srcPort << "]: " << buf << std::endl;
        } else if (n < 0) {
            perror("recvfrom failed");
            break;
        }
    }
}