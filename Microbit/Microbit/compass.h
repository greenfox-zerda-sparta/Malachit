#ifndef COMPASS_H
#define COMPASS_H

#include <QWidget>
#include <QtGui>
#include "metrics.h"
#include "config.h"
#include "receiverservice.h"

class Compass : public QWidget
{
  Q_OBJECT

public:
  Compass(QWidget *parent);

  private slots:
  void paintEvent(QPaintEvent* e);
private:
  int m_Heading;
  int m_Offset;
  int m_Radius;
  QPoint scaleMarkPoints[2];
  QPoint azimuthHand[3];
  QScopedPointer<ReceiverService> m_ReceiverService;


  void paintAzimuthHand(QPainter& painter);
  void paintDegreeChart(QPainter& painter);

  void setOffsetAndRadius();
  void setAzimuthHandSize();
  void setScaleMarkPoints();
  void paintHalfOfAzimuthHand(QPainter& painter, const QColor& color, int degree);

  public slots:
  void setHeading(Metrics microbitData);
};

#endif // COMPASS_H
