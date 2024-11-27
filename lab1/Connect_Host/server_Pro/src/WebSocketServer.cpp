#include "WebSocketServer.hpp"
#include <iostream>
#include <algorithm>

WebSocketServer::WebSocketServer() {
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

void WebSocketServer::run(uint16_t port) {
    ws_server.listen(port);
    ws_server.start_accept();
    ws_server.run();
}

void WebSocketServer::send_message_to_clients(const std::string& message) {
    std::lock_guard<std::mutex> lock(conn_mutex);
    for (auto& conn : connections) {
        try {
            std::string server_message = "Server: " + message;
            ws_server.send(conn, server_message, websocketpp::frame::opcode::text);
        } catch (const websocketpp::exception& e) {
            std::cout << "Error sending message: " << e.what() << std::endl;
        }
    }
}

void WebSocketServer::on_open(websocketpp::connection_hdl hdl) {
    std::lock_guard<std::mutex> lock(conn_mutex);
    connections.push_back(hdl);
    std::cout << "Client connected" << std::endl;
}

void WebSocketServer::on_close(websocketpp::connection_hdl hdl) {
    std::lock_guard<std::mutex> lock(conn_mutex);
    connections.erase(std::remove_if(connections.begin(), connections.end(),
                                     [&hdl](const websocketpp::connection_hdl& conn) {
                                         return !conn.owner_before(hdl) && !hdl.owner_before(conn);
                                     }),
                      connections.end());
    std::cout << "Client disconnected" << std::endl;
}

void WebSocketServer::handle_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
    std::string received_message = msg->get_payload();

    // 将消息保存到队列中
    {
        std::lock_guard<std::mutex> lock(msg_mutex);
        message_queue.push_back(received_message);
        if (message_queue.size() > 100) {
            message_queue.pop_front();
        }
    }

    std::cout << "Received: " << received_message << std::endl;

    // 广播消息到所有连接的客户端
    std::lock_guard<std::mutex> lock(conn_mutex);
    for (auto& conn : connections) {
        try {
            ws_server.send(conn, received_message, websocketpp::frame::opcode::text);
        } catch (const websocketpp::exception& e) {
            std::cout << "Error sending message: " << e.what() << std::endl;
        }
    }
}