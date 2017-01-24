#include "compass.h"

compass::compass(QWidget *parent)
	: QWidget(parent)
{
	heading = 0;
}

compass::~compass()
{

}
void compass::setHeading(int angle) {
	heading = angle;
	update();
}
void compass::paintEvent(QPaintEvent* e) {

	static const QPoint azimutHand[3] = {
		QPoint(6, 7),
		QPoint(-6, 7),
		QPoint(0, -90)
	};

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(this->width() / 2, this->height() / 2);  //stred

	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::red);
	painter.save();
	painter.rotate(heading);
	painter.drawConvexPolygon(azimutHand, 3);
	painter.restore();

	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::blue);

	painter.save();
	painter.rotate(heading + 180);
	painter.drawConvexPolygon(azimutHand, 3);
	painter.restore();

	painter.setPen(Qt::black);

	for (int j = 0; j < 60; ++j)
	{
		painter.drawLine(100, 0, 95, 0);
		painter.rotate(6.0);
	}

}