#ifndef CLIENTAPP_HPP
#define CLIENTAPP_HPP

#include <QWidget>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget *parent = nullptr);
    ~ClientApp();

private slots:
    void connectToServer();
    void sendMessage();
    void readMessage();
    void onDisconnected();

private:
    QLineEdit *ipInput;
    QLineEdit *portInput;
    QPushButton *connectButton;
    QTextEdit *messageDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QTcpSocket *socket;
};

#endif // CLIENTAPP_HPP