#pragma once
#include <QObject>
#include <QTest>
#include "logger.h"

class TestLogger : public QObject {
  Q_OBJECT

private:
  QString* buffer;
  QString* buffer2;
  QTextStream* mockCout;
  QTextStream* mockCerr;
  void dummyLogging(Logger& logger);

private slots:
  void init();
  void cleanup();
  void testDebugLevel();
  void testInfoLevel();
  void testWarningLevel();
  void testCriticalLevel();
};
