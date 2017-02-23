#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include "MicroBit.h"
#include <vector>
#include <string>

class LedMatrix {
private:
    vector<vector<int> > ledMatrix;
public:
    LedMatrix();
    void setLedMatrix(int row, int col);
    MicroBitImage getMatrixImage(); 
};

#endif