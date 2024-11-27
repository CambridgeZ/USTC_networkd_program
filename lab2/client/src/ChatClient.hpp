#ifndef __CHAT_CLIENT_HPP__
#define __CHAT_CLIENT_HPP__

#include "Socket.hpp"
#include <poll.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./config.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <poll.h>
#include <iostream>


class ChatClient{
public:
    ChatClient(const char* ip,int port);
    void run();

private:
    Socket socket;
    pollfd fds[2];
    char read_buf[BUFFER_SIZE]; // 读缓冲区
    int pipefd[2]; // 管道
};


#endif // __CHAT_CLIENT_HPP__