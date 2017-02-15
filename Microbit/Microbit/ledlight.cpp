#include "ledlight.h"

LedLight::LedLight(int x, int y, QPushButton * parent) : QPushButton(parent) {
  coordinates.row = x;
  coordinates.column = y;
  connect(this, SIGNAL(clicked()), this, SLOT(onClicked()));
}

void LedLight::onClicked()
{
  emit stateChanged(coordinates.row, coordinates.column);
}