#include "receiver.h"
#include <QDebug>
Receiver::Receiver(QObject *parent)
  : QObject(parent)
{

}


void Receiver::printData(int num)
{
  qDebug() << num;
}