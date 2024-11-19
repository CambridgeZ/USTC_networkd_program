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
    friend class ChatClient;
public:
    Socket(int port, const char* ip);
    ~Socket();
    int getFd() const;
private:
    struct sockaddr_in server_address;
    int sockfd;
};


#endif // __SOCKET_HPP__
