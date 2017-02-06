#ifndef COMPASS_H
#define COMPASS_H

#include <QWidget>
#include <QtGui>

class Compass : public QWidget
{
	Q_OBJECT

public:
	Compass(QWidget *parent);
	~Compass();

private slots:
	void paintEvent(QPaintEvent* e);
private:
	int heading;
  int offset;
  int radius;
  int numOfScales;
  int scaleLength;
  const int fullRotation;
  int azimuthHandWidth;
  QPoint scaleMarkPoints[2];
  QPoint azimuthHand[3];

  void paintAzimuthHand(QPainter& painter);
  void paintDegreeChart(QPainter& painter);

  void setOffsetAndRadius();
  void setAzimuthHandSize();
  void setScaleMarkPoints();
  void paintHalfOfAzimuthHand(QPainter& painter, const QColor& color, int degree);

public slots:
  void setHeading(int);
  void printIze(int);

};

#endif // COMPASS_H
