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

  void paintAzimutHand();
  void paintDegreeChart();

private slots:
	void setHeading(int);
	void paintEvent(QPaintEvent* e);
private:
	int heading;
  int offset;
  QPoint azimutHand[3];

  void setOffset();
  void setAzimutHandSize();

protected:


};

#endif // COMPASS_H
