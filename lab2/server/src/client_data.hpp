#ifndef __CLIENT_DATA_HPP__
#define __CLIENT_DATA_HPP__

#include <arpa/inet.h>
#include <string.h>
#include "config.hpp"

struct client_data{
    sockaddr_in address;
    char* write_buf;
    char buf[BUFFER_SIZE];
};

#endif // __CLIENT_DATA_HPP__