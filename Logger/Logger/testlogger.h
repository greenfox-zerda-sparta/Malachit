#pragma once
#include <QObject>
#include <QTest>
#include <QDebug>

class TestLogger : public QObject {
	Q_OBJECT

public:
	TestLogger(QObject * parent = Q_NULLPTR);

private slots:
  void test_debug();
  void test_info();
  void test_warning();
  void test_critical();
};
