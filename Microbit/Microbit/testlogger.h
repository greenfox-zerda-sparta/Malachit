#pragma once
#include <QObject>
#include <QTest>
#include "logger.h"

class TestLogger : public QObject {
	Q_OBJECT

public:
	TestLogger(QObject * parent = Q_NULLPTR);

private slots:
  void testDebugLevel();
  void testInfoLevel();
  void testWarningLevel();
  void testCriticalLevel();
};
