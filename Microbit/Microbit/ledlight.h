#pragma once
#include <QObject>
#include <QPushButton>

struct Coordinates
{
  int row;
  int column;
};

class LedLight : public QPushButton {
  Q_OBJECT

public:
  LedLight(int, int, QPushButton * parent = Q_NULLPTR);

signals:
  void stateChanged(int, int);

public slots:
  void onClicked();

private:
  Coordinates coordinates;
};
