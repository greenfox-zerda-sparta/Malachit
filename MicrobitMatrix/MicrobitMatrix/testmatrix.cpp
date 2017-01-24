#include "testmatrix.hpp"
#include "microbitmatrix.h"

TestMatrix::TestMatrix(QObject * parent) : QObject(parent) {
	
}

void TestMatrix::test_is_there_is_twentyfive_buttons() {
  int count = 0;
  MicrobitMatrix microbitMatrix;
  QVector<QVector<QPushButton*>> vector = microbitMatrix.get_vector();
  for (unsigned int i = 0; i < vector.size(); ++i) {
    for (unsigned int j = 0; j < vector[i].size(); ++j) {
      ++count;
    }
  }
  QCOMPARE(count, 25);
}

TestMatrix::~TestMatrix() {
	
}
