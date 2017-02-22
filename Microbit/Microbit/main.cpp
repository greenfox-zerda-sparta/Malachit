#ifdef _TEST

#include <QtTest>
#include "testlogger.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestLogger test;
  return QTest::qExec(&test, argc, argv);
}

#endif

#ifndef _TEST

#include "mainwindow.h"
#include <QtWidgets/QApplication>

#include "servicemanager.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ServiceManager myServiceManager(&a);
  MainWindow w;
  w.show();

  return a.exec();
}

#endif