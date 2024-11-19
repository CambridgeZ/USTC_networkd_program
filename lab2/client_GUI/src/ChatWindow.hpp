#ifndef CHATWINDOW_HPP
#define CHATWINDOW_HPP

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "ChatClient.hpp"

class ChatWindow : public QWidget {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void onConnectClicked();

private:
    QLineEdit *ipInput;
    QLineEdit *portInput;
};

#endif // CHATWINDOW_H