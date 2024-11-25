#include <QApplication>
#include "ClientApp.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ClientApp client;
    client.resize(400, 300);
    client.show();

    return app.exec();
}