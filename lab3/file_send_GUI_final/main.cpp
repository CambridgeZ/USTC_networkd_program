#include <QApplication>
#include "clientapp.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    ClientApp client;
    client.resize(400, 500);
    client.show();
    
    return app.exec();
}

