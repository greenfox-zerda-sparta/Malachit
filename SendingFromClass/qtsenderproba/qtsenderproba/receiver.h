#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
  Q_OBJECT

public:
    explicit Receiver(QObject *parent = 0);


private:

  public slots :
    void printData(int);
    
};

#endif // RECEIVER_H
