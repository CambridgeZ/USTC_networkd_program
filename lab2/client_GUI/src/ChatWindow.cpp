#include "ChatWindow.hpp"

ChatWindow::ChatWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *ipLabel = new QLabel("IP Address:", this);
    layout->addWidget(ipLabel);

    ipInput = new QLineEdit(this);
    layout->addWidget(ipInput);

    QLabel *portLabel = new QLabel("Port Number:", this);
    layout->addWidget(portLabel);

    portInput = new QLineEdit(this);
    layout->addWidget(portInput);

    QPushButton *connectButton = new QPushButton("Connect", this);
    layout->addWidget(connectButton);

    connect(connectButton, &QPushButton::clicked, this, &ChatWindow::onConnectClicked);
}

void ChatWindow::onConnectClicked() {
    QString ip = ipInput->text();
    int port = portInput->text().toInt();

    ChatClient client(ip.toStdString().c_str(), port);
    client.run();
}

ChatWindow::~ChatWindow(){
    delete ipInput;
    delete portInput;
}