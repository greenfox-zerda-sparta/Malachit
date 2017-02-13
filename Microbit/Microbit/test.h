#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTest>
#include <QVector>
#include <QPushButton>

class Test : public QObject
{
  Q_OBJECT

public:
  Test(QObject *parent = Q_NULLPTR);

  private slots:
  void testIfThereAreTwentyfiveButtons();
};

#endif // TEST_H
