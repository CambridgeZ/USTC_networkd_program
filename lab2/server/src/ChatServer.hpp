#ifndef __CHATSERVER_HPP__
#define __CHATSERVER_HPP__

#include "Socket.hpp"
#include "client_data.hpp"
#include "config.hpp"
#include <poll.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>

class ChatServer{
public:
    ChatServer(int port, const char* ip);
private:
    void init();
    Socket sk;
    client_data* users;
    pollfd fds[USER_LIMIT+1];
    int user_counter;
    int setnonblocking(int fd){
        int old_option = fcntl(fd,F_GETFL);
        int new_option = old_option | O_NONBLOCK;
        fcntl(fd,F_SETFL,new_option);
        return old_option;
    }

public:
    void run();
};


#endif // __CHATSERVER_HPP__