#include "test.h"
#include "matrix.h"

Test::Test(QObject *parent)
	: QObject(parent)
{

}

void Test::testIfThereAreTwentyfiveButtons()
{
	int count = 0;
	QWidget dummy;
	Matrix myMatrix(&dummy);
	QVector<QVector<QPushButton*>> matrix = myMatrix.getMatrix();
	for (unsigned int i = 0; i < matrix.size(); ++i) {
		for (unsigned int j = 0; j < matrix[i].size(); ++j) {
			++count;
		}
	}
	QCOMPARE(count, 25);
}

