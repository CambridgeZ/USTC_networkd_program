#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTcpSocket>
#include <QLabel>
#include <QMessageBox>

class ClientApp : public QWidget {
    Q_OBJECT
    
public:
    ClientApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Socket Client");
        
        // Layout and Widgets
        QVBoxLayout *layout = new QVBoxLayout(this);
        
        // IP and Port
        layout->addWidget(new QLabel("Server IP:"));
        ipInput = new QLineEdit(this);
        layout->addWidget(ipInput);
        
        layout->addWidget(new QLabel("Port:"));
        portInput = new QLineEdit(this);
        layout->addWidget(portInput);
        
        // Connect Button
        connectButton = new QPushButton("Connect", this);
        layout->addWidget(connectButton);
        
        // Message display area
        layout->addWidget(new QLabel("Messages:"));
        messageDisplay = new QTextEdit(this);
        messageDisplay->setReadOnly(true);
        layout->addWidget(messageDisplay);
        
        // Input and Send Button
        layout->addWidget(new QLabel("Send Message:"));
        messageInput = new QLineEdit(this);
        layout->addWidget(messageInput);
        
        sendButton = new QPushButton("Send", this);
        sendButton->setEnabled(false);
        layout->addWidget(sendButton);
        
        // Socket setup
        socket = new QTcpSocket(this);
        
        // Signals and Slots
        connect(connectButton, &QPushButton::clicked, this, &ClientApp::connectToServer);
        connect(sendButton, &QPushButton::clicked, this, &ClientApp::sendMessage);
        connect(socket, &QTcpSocket::readyRead, this, &ClientApp::readMessage);
        connect(socket, &QTcpSocket::disconnected, this, &ClientApp::onDisconnected);
    }
    
private slots:
    void connectToServer() {
        QString ip = ipInput->text();
        int port = portInput->text().toInt();
        
        socket->connectToHost(ip, port);
        
        if (socket->waitForConnected(3000)) { // 3 seconds timeout
            QMessageBox::information(this, "Success", "Connected to server!");
            connectButton->setEnabled(false);
            sendButton->setEnabled(true);
        } else {
            QMessageBox::critical(this, "Error", "Failed to connect to server.");
        }
    }
    
    void sendMessage() {
        QString message = messageInput->text();
        if (!message.isEmpty()) {
            socket->write(message.toUtf8());
            socket->flush();
            messageInput->clear();
        }
    }
    
    void readMessage() {
        QByteArray data = socket->readAll();
        messageDisplay->append("Server: " + QString(data));
    }
    
    void onDisconnected() {
        QMessageBox::information(this, "Disconnected", "Server has closed the connection.");
        connectButton->setEnabled(true);
        sendButton->setEnabled(false);
    }
    
private:
    QLineEdit *ipInput;
    QLineEdit *portInput;
    QPushButton *connectButton;
    QTextEdit *messageDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QTcpSocket *socket;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    ClientApp client;
    client.resize(400, 300);
    client.show();
    
    return app.exec();
}

#include "main.moc"