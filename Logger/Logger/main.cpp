#ifdef _TEST

#include <QtTest>
#include "testlogger.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestLogger testLogger;
  return QTest::qExec(&testLogger, argc, argv);
}

#endif

#ifndef _TEST

#include "logger.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logger w("Debug");
    return a.exec();
}

#endif // !_TEST