#pragma once

#include <QWidget>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    bool bindUdpSocket(int port);
    void retryUdpBinding(const QString &ip, int port);
    void sendMessage();
    void readMessage();
    void onDisconnected();
    void sendPrivateMessage();
    void receivePrivateMessage();

private:
    QLineEdit *ipInput;
    QLineEdit *portInput;
    QPushButton *connectButton;
    QTextEdit *messageDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;

    // Private chat widgets
    QLineEdit *targetIpInput;
    QLineEdit *targetPortInput;
    QLineEdit *privateMessageInput;
    QPushButton *privateSendButton;

    QTcpSocket *socket;
    QUdpSocket *udpSocket; // UDP Socket
    int retryCount;

    int udpPortToTcpPort(int udpPort);
    int tcpPortToUdpPort(int tcpPort);
};