#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <string>
#include <netinet/in.h>

class UdpClient {
public:
    UdpClient(const std::string& serverIp, int serverPort, int localPort = 0);
    ~UdpClient();

    void sendMessage(const std::string& message);
    int getSocket() const;

private:
    int sockfd;
    struct sockaddr_in serverAddr;

    void bindToLocalPort(int localPort);
};

#endif // UDP_CLIENT_H