#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QPushButton>
#include <QtGui>
class Matrix : public QWidget
{
	Q_OBJECT

public:
	Matrix(QWidget *parent);
	~Matrix();

	void fillQVector();

private:
	QVector<QVector<QPushButton*>> vector;
};

#endif // MATRIX_H
