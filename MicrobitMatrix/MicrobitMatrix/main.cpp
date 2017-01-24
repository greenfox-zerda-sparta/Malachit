#ifdef _TEST

#include <QtTest>
#include "testmatrix.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestMatrix testMatrix;
  return QTest::qExec(&testMatrix, argc, argv);
}

#endif

#ifndef _TEST
#include "microbitmatrix.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MicrobitMatrix w;
    w.show();
    return a.exec();
}

#endif