#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QWidget>
#include <QtGui>
#include <QDoubleSpinBox>

class Accelerometer : public QWidget
{
  Q_OBJECT

public:
    Accelerometer(QWidget* parent);
    ~Accelerometer();
    void setCoordinates();
    void createAxisX(QPainter& painter);
    void createAxisY(QPainter& painter);
    void setAxisTitle(QPainter& painter, QString name, int flag);
    void setAxisXlabel(QPainter& painter);
    void setAxisYlabel(QPainter& painter);
    void drawBars(QPainter& painter);
   

private slots:
  void paintEvent(QPaintEvent* e);
  void setHeightX(double x);
  void setHeightY(double y);
  void setHeightZ(double z);
  void setWidthAll(double w);


private:
  double m_HeightX;
  double m_HeightY;
  double m_HeightZ;
  double m_WidthAll;
  double m_axisOffsetTop;
  double m_axisOffsetRight;
  double m_axisOffsetBottom;
  double m_axisOffsetLeft;
  double m_proportion;
  int m_numberOfBars;
};

#endif // ACCELEROMETER_H
