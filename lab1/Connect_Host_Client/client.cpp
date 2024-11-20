#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::string;

typedef websocketpp::client<websocketpp::config::asio_client> client;

class WebSocketClient {
public:
    WebSocketClient(const string& uri) : uri(uri), is_open(false) {
        ws_client.init_asio();

        ws_client.set_open_handler([this](websocketpp::connection_hdl hdl) {
            on_open(hdl);
        });

        ws_client.set_close_handler([this](websocketpp::connection_hdl hdl) {
            on_close(hdl);
        });

        ws_client.set_message_handler([this](websocketpp::connection_hdl hdl, client::message_ptr msg) {
            on_message(hdl, msg);
        });
    }

    void run() {
        websocketpp::lib::error_code ec;
        client::connection_ptr con = ws_client.get_connection(uri, ec);

        if (ec) {
            cout << "Connection error: " << ec.message() << endl;
            return;
        }

        connection_hdl = con->get_handle();
        ws_client.connect(con);

        std::thread([this]() {
            ws_client.run();
        }).detach();
    }

    void send_message(const string& message) {
        if (is_open) {
            websocketpp::lib::error_code ec;
            ws_client.send(connection_hdl, message, websocketpp::frame::opcode::text, ec);
            if (ec) {
                cout << "Send error: " << ec.message() << endl;
            }
        } else {
            cout << "Connection is not open yet." << endl;
        }
    }

private:
    client ws_client;
    websocketpp::connection_hdl connection_hdl;
    string uri;
    bool is_open;
    std::mutex conn_mutex;

    void on_open(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex);
        is_open = true;
        cout << "Connected to server" << endl;
    }

    void on_close(websocketpp::connection_hdl hdl) {
        std::lock_guard<std::mutex> lock(conn_mutex);
        is_open = false;
        cout << "Disconnected from server" << endl;
    }

    void on_message(websocketpp::connection_hdl hdl, client::message_ptr msg) {
        cout << "Received: " << msg->get_payload() << endl;
    }
};

int main() {
    string uri = "ws://localhost:9002";
    WebSocketClient client(uri);

    client.run();

    string input;
    while (true) {
        cout << "Enter message: ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        client.send_message(input);
    }

    return 0;
}