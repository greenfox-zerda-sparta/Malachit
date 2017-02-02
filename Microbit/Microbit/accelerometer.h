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
  QVector<double> m_Heights;
  double m_HeightX;
  double m_HeightY;
  double m_HeightZ;
  double m_MaxHeight;
  double m_WidthAll;
  double m_AxisOffsetTop;
  double m_AxisOffsetRight;
  double m_AxisOffsetBottom;
  double m_AxisOffsetLeft;
  double m_Proportion;
  int m_NumberOfBars;
  void createBar(QPainter& painter, double height, double rectXCoordinate, QColor color);
  double calculateAxisXLabelPositionX(int index);
  double calculateAxisYLabelPositionY(int index);
  double calculateBarPositionOnAxisX(int index);
  double calculateBarHeight(double inputHeight);
};

#endif // ACCELEROMETER_H
