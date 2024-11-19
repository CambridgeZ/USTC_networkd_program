// mainwindow.hpp
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "ChatClient.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();
    void on_sendButton_clicked();
    void readSocket();

private:
    Ui::MainWindow *ui;
    ChatClient *client;
    QVBoxLayout *layout;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;
    QTextEdit *messageEdit;
    QPushButton *connectButton;
    QPushButton *sendButton;
};