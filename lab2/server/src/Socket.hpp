#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include <assert.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

class Socket{
    friend class ChatServer;
public:
    Socket(int port, const char* ip);

private:
    struct sockaddr_in address;
    int listenfd;
};


#endif // __SOCKET_HPP__