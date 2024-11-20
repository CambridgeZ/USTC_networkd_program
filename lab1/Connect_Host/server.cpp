#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <mutex>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;

typedef websocketpp::server<websocketpp::config::asio> server;

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

    // 用于发送消息到所有客户端
    void send_message_to_clients(const string& message) {
        std::lock_guard<std::mutex> lock(conn_mutex);
        for (auto& conn : connections) {
            try {
                string server_message = "Server: " + message; // 加前缀标识为服务器消息
                ws_server.send(conn, server_message, websocketpp::frame::opcode::text);
            } catch (const websocketpp::exception& e) {
                cout << "Error sending message: " << e.what() << endl;
            }
        }
    }

private:
    server ws_server;
    vector<websocketpp::connection_hdl> connections; // 保存当前连接的客户端
    std::mutex conn_mutex;                           // 保护 connections 的互斥锁
    deque<string> message_queue;                     // 保存收到的消息队列
    std::mutex msg_mutex;                            // 保护消息队列的互斥锁

    void on_open(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex);
        connections.push_back(hdl);
        cout << "Client connected" << endl;
    }

    void on_close(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex);
        connections.erase(std::remove_if(connections.begin(), connections.end(),
                                         [&hdl](const websocketpp::connection_hdl& conn) {
                                             return !conn.owner_before(hdl) && !hdl.owner_before(conn);
                                         }),
                          connections.end());
        cout << "Client disconnected" << endl;
    }

    void handle_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
        string received_message = msg->get_payload();

        // 将消息保存到队列中
        {
            std::lock_guard<std::mutex> lock(msg_mutex);
            message_queue.push_back(received_message);
            if (message_queue.size() > 100) { // 保留最近的100条消息
                message_queue.pop_front();
            }
        }

        cout << "Received: " << received_message << endl;

        // 广播消息到所有连接的客户端
        std::lock_guard<std::mutex> lock(conn_mutex);
        for (auto& conn : connections) {
            try {
                ws_server.send(conn, received_message, websocketpp::frame::opcode::text);
            } catch (const websocketpp::exception& e) {
                cout << "Error sending message: " << e.what() << endl;
            }
        }
    }
};

int main() {
    uint16_t port = 9002;
    WebSocketServer server;

    cout << "Starting WebSocket server on port " << port << endl;
    std::thread server_thread([&server, port]() { server.run(port); });

    // 在服务器端发送消息
    string input_message;
    while (true) {
        cout << "Enter message to broadcast: ";
        std::getline(std::cin, input_message);
        if (input_message == "exit") break;
        server.send_message_to_clients(input_message); // 调用函数发送消息
    }

    server_thread.join();
    return 0;
}