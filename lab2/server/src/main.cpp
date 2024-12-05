#define _GNU_SOURCE 1

#include "ChatServer.hpp"
#include "config.hpp"


int main(int argc, char *argv[]){
    if(argc <= 2){
        printf("usage: %s ip_address port_number\n",basename(argv[0]));
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

    ChatServer server(port, ip);
    server.run();

    return 0;
}