
#include <QtCore/QCoreApplication>
#include "handler.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject myObject;
    Handler myHandler(&myObject);
    return a.exec();
}
