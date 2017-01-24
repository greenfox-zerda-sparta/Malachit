#ifndef COMPASS_H
#define COMPASS_H

#include <QWidget>
#include <QtGui>

class compass : public QWidget
{
	Q_OBJECT

public:
	compass(QWidget *parent);
	~compass();

private slots:
	void setHeading(int);
	void paintEvent(QPaintEvent* e);
private:
	int heading;
protected:
	

};

#endif // COMPASS_H
