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
#include "logger.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  Logger logger("DEBUG");

  return a.exec();
}

#endif