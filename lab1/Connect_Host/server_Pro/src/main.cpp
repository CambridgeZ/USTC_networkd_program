#include "WebSocketServer.hpp"
#include <iostream>
#include <thread>

int main() {
    uint16_t port = 9002;
    WebSocketServer server;

    std::cout << "Starting WebSocket server on port " << port << std::endl;
    std::thread server_thread([&server, port]() { server.run(port); });

    // 在服务器端发送消息
    std::string input_message;
    while (true) {
        std::cout << "Enter message to broadcast: ";
        std::getline(std::cin, input_message);
        if (input_message == "exit") break;
        server.send_message_to_clients(input_message); // 调用函数发送消息
    }

    server_thread.join();
    return 0;
}