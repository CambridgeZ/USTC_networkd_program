#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTcpSocket>
#include <QUdpSocket>
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

        // Private chat section
        layout->addWidget(new QLabel("Private Chat - Target IP:"));
        targetIpInput = new QLineEdit(this);
        layout->addWidget(targetIpInput);

        layout->addWidget(new QLabel("Target Port:"));
        targetPortInput = new QLineEdit(this);
        layout->addWidget(targetPortInput);

        privateMessageInput = new QLineEdit(this);
        privateMessageInput->setPlaceholderText("Enter private message here...");
        layout->addWidget(privateMessageInput);

        privateSendButton = new QPushButton("Send Private Message", this);
        privateSendButton->setEnabled(true);
        layout->addWidget(privateSendButton);

        // Socket setup
        socket = new QTcpSocket(this);
        udpSocket = new QUdpSocket(this); // UDP Socket for private chat
        
        // Signals and Slots
        connect(connectButton, &QPushButton::clicked, this, &ClientApp::connectToServer);
        connect(sendButton, &QPushButton::clicked, this, &ClientApp::sendMessage);
        connect(socket, &QTcpSocket::readyRead, this, &ClientApp::readMessage);
        connect(socket, &QTcpSocket::disconnected, this, &ClientApp::onDisconnected);
        connect(privateSendButton, &QPushButton::clicked, this, &ClientApp::sendPrivateMessage);
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

    void sendPrivateMessage() {
        QString targetIp = targetIpInput->text();
        int targetPort = targetPortInput->text().toInt();
        QString privateMessage = privateMessageInput->text();

        if (!targetIp.isEmpty() && targetPort > 0 && !privateMessage.isEmpty()) {
            QByteArray data = privateMessage.toUtf8();
            udpSocket->writeDatagram(data, QHostAddress(targetIp), targetPort);
            privateMessageInput->clear();
            messageDisplay->append("You (private): " + privateMessage);
        } else {
            QMessageBox::warning(this, "Error", "Please fill in all private chat fields.");
        }
    }
    
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
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    ClientApp client;
    client.resize(400, 400); // Increased height for private chat
    client.show();
    
    return app.exec();
}

#include "main.moc"