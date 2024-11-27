#ifndef WEBSOCKET_SERVER_HPP
#define WEBSOCKET_SERVER_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <deque>
#include <mutex>
#include <string>
#include <vector>

// 类型别名
typedef websocketpp::server<websocketpp::config::asio> server;

class WebSocketServer {
public:
    WebSocketServer();
    void run(uint16_t port);
    void send_message_to_clients(const std::string& message);

private:
    server ws_server;
    std::vector<websocketpp::connection_hdl> connections;
    std::mutex conn_mutex;
    std::deque<std::string> message_queue;
    std::mutex msg_mutex;

    void on_open(websocketpp::connection_hdl hdl);
    void on_close(websocketpp::connection_hdl hdl);
    void handle_message(websocketpp::connection_hdl hdl, server::message_ptr msg);
};

#endif // WEBSOCKET_SERVER_HPP