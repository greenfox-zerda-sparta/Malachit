#pragma once
#include <QObject>
#include <QTest>
#include <QVector>
#include <QPushButton>

class TestMatrix : public QObject {
	Q_OBJECT

public:
	TestMatrix(QObject * parent = Q_NULLPTR);
  void test_is_there_is_twentyfive_buttons();
	~TestMatrix();

private:
	
};

