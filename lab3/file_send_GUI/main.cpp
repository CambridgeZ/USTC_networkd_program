#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QByteArray>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    ClientApp(QWidget *parent = nullptr);

private slots:
    void selectFile();
    void sendFile();
    void receiveFile();

private:
    QLineEdit *fileTargetIpInput;
    QLineEdit *fileTargetPortInput;
    QPushButton *fileSelectButton;
    QPushButton *fileSendButton;

    QString selectedFilePath; // 存储选中的文件路径
    QTcpSocket *fileSocket;   // 单独的 TCP 套接字用于文件传输
    QTcpServer *fileServer;   // 文件接收服务器
    QTextEdit *messageDisplay; // 消息显示区
};

ClientApp::ClientApp(QWidget *parent) : QWidget(parent), fileSocket(nullptr), fileServer(new QTcpServer(this)) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Display area for messages
    messageDisplay = new QTextEdit(this);
    messageDisplay->setReadOnly(true);
    layout->addWidget(messageDisplay);

    // File transfer section
    layout->addWidget(new QLabel("File Transfer - Target IP:"));
    fileTargetIpInput = new QLineEdit(this);
    layout->addWidget(fileTargetIpInput);

    layout->addWidget(new QLabel("Target Port:"));
    fileTargetPortInput = new QLineEdit(this);
    layout->addWidget(fileTargetPortInput);

    fileSelectButton = new QPushButton("Select File", this);
    layout->addWidget(fileSelectButton);

    fileSendButton = new QPushButton("Send File", this);
    fileSendButton->setEnabled(false);
    layout->addWidget(fileSendButton);

    // Connect file-related buttons
    connect(fileSelectButton, &QPushButton::clicked, this, &ClientApp::selectFile);
    connect(fileSendButton, &QPushButton::clicked, this, &ClientApp::sendFile);

    // File server setup
    connect(fileServer, &QTcpServer::newConnection, this, &ClientApp::receiveFile);
    if (fileServer->listen(QHostAddress::Any, 5555)) {
        messageDisplay->append("File server listening on port 5555");
    } else {
        QMessageBox::critical(this, "Error", "Failed to start file server.");
    }

    setLayout(layout);
}

void ClientApp::selectFile() {
    selectedFilePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!selectedFilePath.isEmpty()) {
        QMessageBox::information(this, "File Selected", "File: " + selectedFilePath);
        fileSendButton->setEnabled(true);
    }
}

void ClientApp::sendFile() {
    QString targetIp = fileTargetIpInput->text();
    int targetPort = fileTargetPortInput->text().toInt();

    if (selectedFilePath.isEmpty() || targetIp.isEmpty() || targetPort <= 0) {
        QMessageBox::warning(this, "Error", "Please fill in all file transfer fields and select a file.");
        return;
    }

    fileSocket = new QTcpSocket(this);
    fileSocket->connectToHost(targetIp, targetPort);

    if (fileSocket->waitForConnected(3000)) {
        QFile file(selectedFilePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, "Error", "Failed to open the file.");
            return;
        }

        // Send file metadata
        QByteArray metadata;
        QString fileName = QFileInfo(file).fileName();
        qint64 fileSize = file.size();
        metadata.append(QString("FILE:%1:%2").arg(fileName).arg(fileSize).toUtf8());
        fileSocket->write(metadata);
        fileSocket->flush();

        // Send file data
        while (!file.atEnd()) {
            QByteArray buffer = file.read(4096);
            fileSocket->write(buffer);
            fileSocket->flush();
        }

        file.close();
        fileSocket->disconnectFromHost();
        QMessageBox::information(this, "Success", "File sent successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to connect to target client.");
    }
}

void ClientApp::receiveFile() {
    QTcpSocket *incomingFileSocket = fileServer->nextPendingConnection();

    connect(incomingFileSocket, &QTcpSocket::readyRead, [this, incomingFileSocket]() {
        static QFile file;
        static bool receivingFile = false;
        static qint64 remainingBytes = 0;

        while (incomingFileSocket->bytesAvailable() > 0) {
            if (!receivingFile) {
                QByteArray header = incomingFileSocket->readLine();
                if (header.startsWith("FILE:")) {
                    QStringList parts = QString(header).split(':');
                    if (parts.size() == 3) {
                        QString fileName = parts[1];
                        remainingBytes = parts[2].toLongLong();
                        file.setFileName(QDir::homePath() + "/" + fileName);

                        if (!file.open(QIODevice::WriteOnly)) {
                            QMessageBox::critical(this, "Error", "Failed to open file for writing.");
                            incomingFileSocket->disconnectFromHost();
                            return;
                        }

                        receivingFile = true;
                        messageDisplay->append("Receiving file: " + fileName);
                    }
                }
            } else {
                QByteArray data = incomingFileSocket->read(qMin(remainingBytes, qint64(4096)));
                file.write(data);
                remainingBytes -= data.size();

                if (remainingBytes <= 0) {
                    file.close();
                    messageDisplay->append("File received successfully.");
                    incomingFileSocket->disconnectFromHost();
                    receivingFile = false;
                }
            }
        }
    });
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ClientApp clientApp;
    clientApp.show();
    return app.exec();
}
