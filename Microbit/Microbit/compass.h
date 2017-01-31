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
	void setHeading(int);
	void paintEvent(QPaintEvent* e);
private:
	int heading;
  int offset;
  int radius;
  int azimuthHandWidth;
  QPoint azimuthHand[3];

  void paintAzimuthHand(QPainter& painter);
  void paintDegreeChart(QPainter& painter);

  void setOffsetAndRadius();
  void setAzimuthHandSize();
  void paintHalfOfAzimuthHand(QPainter& painter, const QColor& color, int degree);

protected:


};

#endif // COMPASS_H
