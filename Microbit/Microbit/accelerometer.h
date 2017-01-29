#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QWidget>
#include <QtGui>
#include <QDoubleSpinBox>

class Accelerometer : public QWidget
{
  Q_OBJECT

public:
    Accelerometer(QWidget *parent);
    ~Accelerometer();
    void drawBars();
    void createAxisX();
    void createAxisY();
   

private slots:
  void paintEvent(QPaintEvent *e);
  void setHeightX(double x);
  void setHeightY(double y);
  void setHeightZ(double z);
  void setWidthAll(double w);


private:
  double m_HeightX;
  double m_HeightY;
  double m_HeightZ;
  double m_WidthAll;

};

#endif // ACCELEROMETER_H
