#include "testmatrix.h"
#include "microbitmatrix.h"

TestMatrix::TestMatrix(QObject * parent) : QObject(parent)
{

}

void TestMatrix::test_if_there_is_twentyfive_buttons()
{
  int count = 0;
  MicrobitMatrix microbitMatrix;
  QVector<QVector<QPushButton*>> matrix = microbitMatrix.get_matrix();
  for (unsigned int i = 0; i < matrix.size(); ++i) {
    for (unsigned int j = 0; j < matrix[i].size(); ++j) {
      ++count;
    }
  }
  QCOMPARE(count, 25);
}