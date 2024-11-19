#define _GNU_SOURCE 1
#define BUFSIZ 1024

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <thread>
#include <atomic>
#include <mutex>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

using std::cout;
using std::endl;
using std::string;

typedef websocketpp::server<websocketpp::config::asio> server;

// WebSocket 服务端处理器
class WebSocketServer {
public:
    WebSocketServer() {
        ws_server.init_asio();

        // 设置消息处理函数
        ws_server.set_message_handler([this](websocketpp::connection_hdl hdl, server::message_ptr msg) {
            handle_message(hdl, msg);
        });

        // 设置连接建立处理函数
        ws_server.set_open_handler([this](websocketpp::connection_hdl hdl) {
            on_open(hdl);
        });

        // 设置连接关闭处理函数
        ws_server.set_close_handler([this](websocketpp::connection_hdl hdl) {
            on_close(hdl);
        });
    }

    void run(uint16_t port) {
        ws_server.listen(port);        // 监听端口
        ws_server.start_accept();     // 开始接受连接
        ws_server.run();              // 启动服务
    }

private:
    server ws_server;
    std::vector<websocketpp::connection_hdl> connections; // 连接列表
    std::mutex conn_mutex;                                // 保护 connections 的互斥锁

    // 处理新连接
    void on_open(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex); // 确保线程安全
        connections.push_back(hdl);
        cout << "Client connected" << endl;
    }

    // 处理关闭连接
    void on_close(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex); // 确保线程安全
        // 使用 owner_before 方法比较句柄
        connections.erase(std::remove_if(connections.begin(), connections.end(),
                                         [&hdl](const websocketpp::connection_hdl& conn) {
                                             return !conn.owner_before(hdl) && !hdl.owner_before(conn);
                                         }),
                          connections.end());
        cout << "Client disconnected" << endl;
    }

    // 处理消息
    void handle_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
        string received_message = msg->get_payload();
        cout << "Received: " << received_message << endl;

        // 回显消息
        std::lock_guard<std::mutex> lock(conn_mutex); // 确保线程安全
        for (auto& conn : connections) {
            try {
                ws_server.send(conn, "Echo: " + received_message, websocketpp::frame::opcode::text);
            } catch (const websocketpp::exception& e) {
                cout << "Error sending message: " << e.what() << endl;
            }
        }
    }
};
 
int main() {
    uint16_t port = 9002;
    WebSocketServer server;
    std::cout << "Starting WebSocket server on port " << port << std::endl;
    server.run(port);
    return 0;
}