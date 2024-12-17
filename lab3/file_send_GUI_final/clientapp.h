#ifndef CLIENTAPP_H
#define CLIENTAPP_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QUdpSocket>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

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
    void sendFile();
    void acceptFileConnection();
    void receiveFile();

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

    // File transfer widgets
    QLineEdit *filePathInput;
    QPushButton *sendFileButton;

    QTcpSocket *socket;
    QUdpSocket *udpSocket;
    QTcpServer *fileServer;
    QTcpSocket *fileSocket;
    int retryCount;

    int udpPortToTcpPort(int udpPort);
    int tcpPortToUdpPort(int tcpPort);
};

#endif // CLIENTAPP_H
