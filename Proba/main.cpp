#include "helloqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloQT w;
    w.show();
    return a.exec();
}
