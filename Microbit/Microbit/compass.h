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
protected:


};

#endif // COMPASS_H
