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
#include <QApplication>

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

ClientApp::ClientApp(QWidget *parent)
    : QWidget(parent), retryCount(0) {
    setWindowTitle("Socket Client");

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

    // File transfer section
    layout->addWidget(new QLabel("File Path:"));
    filePathInput = new QLineEdit(this);
    layout->addWidget(filePathInput);

    sendFileButton = new QPushButton("Send File", this);
    sendFileButton->setEnabled(false);
    layout->addWidget(sendFileButton);

    // Sockets and server
    socket = new QTcpSocket(this);
    udpSocket = new QUdpSocket(this);
    fileServer = new QTcpServer(this);

    // Signals and Slots
    connect(connectButton, &QPushButton::clicked, this, &ClientApp::connectToServer);
    connect(sendButton, &QPushButton::clicked, this, &ClientApp::sendMessage);
    connect(socket, &QTcpSocket::readyRead, this, &ClientApp::readMessage);
    connect(socket, &QTcpSocket::disconnected, this, &ClientApp::onDisconnected);
    connect(privateSendButton, &QPushButton::clicked, this, &ClientApp::sendPrivateMessage);
    connect(udpSocket, &QUdpSocket::readyRead, this, &ClientApp::receivePrivateMessage);
    connect(sendFileButton, &QPushButton::clicked, this, &ClientApp::sendFile);
    connect(fileServer, &QTcpServer::newConnection, this, &ClientApp::acceptFileConnection);
}

void ClientApp::connectToServer() {
    QString ip = ipInput->text();
    int port = portInput->text().toInt();

    socket->connectToHost(ip, port);

    if (socket->waitForConnected(3000)) {
        QMessageBox::information(this, "Success", "Connected to server!");
        connectButton->setEnabled(false);
        sendButton->setEnabled(true);
        sendFileButton->setEnabled(true);

        int localPort = socket->localPort();
        if (!bindUdpSocket(localPort)) {
            retryUdpBinding(ip, localPort);
        }

        if (!fileServer->listen(QHostAddress::Any, localPort + 2)) {
            QMessageBox::warning(this, "Error", "Failed to start file server.");
        } else {
            messageDisplay->append("File server started on port " + QString::number(localPort + 2));
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to connect to server.");
    }
}

bool ClientApp::bindUdpSocket(int port) {
    quint16 udpPort = port + 1;
    if (udpSocket->bind(QHostAddress::Any, udpPort)) {
        messageDisplay->append(QString("UDP socket bound to port %1").arg(udpPort));
        retryCount = 0;
        return true;
    } else {
        messageDisplay->append("Failed to bind UDP socket. Retrying...");
        return false;
    }
}

void ClientApp::retryUdpBinding(const QString &ip, int port) {
    while (retryCount < 3) {
        retryCount++;
        socket->disconnectFromHost();
        socket->connectToHost(ip, port);

        if (socket->waitForConnected(3000)) {
            int localPort = socket->localPort();
            if (bindUdpSocket(localPort)) {
                return;
            }
        }
    }

    QMessageBox::critical(this, "Error", "Failed to bind UDP socket after 3 attempts. Exiting.");
    QApplication::quit();
}

void ClientApp::sendMessage() {
    QString message = messageInput->text();
    if (!message.isEmpty()) {
        socket->write(message.toUtf8());
        socket->flush();
        messageInput->clear();
    }
}

void ClientApp::readMessage() {
    QByteArray data = socket->readAll();
    messageDisplay->append("Server: " + QString(data));
}

void ClientApp::onDisconnected() {
    QMessageBox::information(this, "Disconnected", "Server has closed the connection.");
    connectButton->setEnabled(true);
    sendButton->setEnabled(false);
    sendFileButton->setEnabled(false);
}

void ClientApp::sendPrivateMessage() {
    QString targetIp = targetIpInput->text();
    int targetPort = tcpPortToUdpPort(targetPortInput->text().toInt());
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

void ClientApp::receivePrivateMessage() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(udpSocket->pendingDatagramSize());

        QHostAddress senderIp;
        quint16 senderPort;

        udpSocket->readDatagram(buffer.data(), buffer.size(), &senderIp, &senderPort);

        QString message = QString::fromUtf8(buffer);
        messageDisplay->append(QString("Private (%1:%2): %3")
                               .arg(senderIp.toString())
                               .arg(udpPortToTcpPort(senderPort))
                               .arg(message));
    }
}

void ClientApp::sendFile() {
    QString targetIp = targetIpInput->text();
    int targetPort = tcpPortToUdpPort(targetPortInput->text().toInt()) + 1; // 文件端口
    
    QString filePath = filePathInput->text();
    if (filePath.isEmpty() || targetIp.isEmpty() || targetPort <= 0) {
        QMessageBox::warning(this, "Error", "Invalid file path or target details.");
        return;
    }
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Cannot open file.");
        return;
    }
    
    QTcpSocket fileSender;
    fileSender.connectToHost(targetIp, targetPort);
    if (!fileSender.waitForConnected(3000)) {
        QMessageBox::warning(this, "Error", "Failed to connect to target file server.");
        return;
    }
    
    QByteArray fileData = file.readAll();
    fileSender.write(fileData);
    fileSender.waitForBytesWritten();
    fileSender.disconnectFromHost();
    
    messageDisplay->append("File sent to " + targetIp + ":" + QString::number(targetPort));
}


void ClientApp::acceptFileConnection() {
    fileSocket = fileServer->nextPendingConnection();
    connect(fileSocket, &QTcpSocket::readyRead, this, &ClientApp::receiveFile);
}

void ClientApp::receiveFile() {
    static QFile receivedFile("received_file"); // 每次覆盖，实际应用可动态生成文件名
    if (!receivedFile.isOpen()) {
        if (!receivedFile.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "Error", "Cannot open file for writing.");
            return;
        }
    }
    
    receivedFile.write(fileSocket->readAll());
    
    if (fileSocket->bytesAvailable() == 0) {
        receivedFile.close();
        QMessageBox::information(this, "File Received", "File saved as 'received_file'.");
        fileSocket->disconnectFromHost();
    }
}

int ClientApp::udpPortToTcpPort(int udpPort) {
    return udpPort - 1;
}

int ClientApp::tcpPortToUdpPort(int tcpPort) {
    return tcpPort + 1;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    ClientApp client;
    client.resize(400, 500);
    client.show();
    
    return app.exec();
}

#include "main.moc"