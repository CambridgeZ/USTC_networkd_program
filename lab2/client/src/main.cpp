#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "ChatClient.hpp"

class ChatWindow : public QWidget {
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr) : QWidget(parent) {
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

private slots:
    void onConnectClicked() {
        QString ip = ipInput->text();
        int port = portInput->text().toInt();

        ChatClient client(ip.toStdString().c_str(), port);
        client.run();
    }

private:
    QLineEdit *ipInput;
    QLineEdit *portInput;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ChatWindow window;
    window.show();

    return app.exec();
}
