#include "UdpClient.h"
#include "MessageReceiver.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " ip_address port_number [local_port]\n";
        return 1;
    }

    std::string ip = argv[1];
    int port = std::stoi(argv[2]);
    int localPort = (argc == 4) ? std::stoi(argv[3]) : 0;

    UdpClient client(ip, port, localPort);
    MessageReceiver receiver(client.getSocket());

    receiver.start();

    std::string message;
    while (std::getline(std::cin, message)) {
        client.sendMessage(message);
    }

    receiver.stop();
    return 0;
}