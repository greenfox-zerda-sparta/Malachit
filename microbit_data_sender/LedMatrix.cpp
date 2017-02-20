#include "LedMatrix.h"

LedMatrix::LedMatrix()
{
    for (int i = 0; i < 5; ++i)
    {
        vector<int> temp;
        
        for (int j = 0; j < 5; ++j)
        {
            temp.push_back(0);
        }
        ledMatrix.push_back(temp);
    }
}

void LedMatrix::setLedMatrix(int row, int col)
{
    ledMatrix[row][col] = ledMatrix[row][col] == 0 ? 1 : 0;
}

MicroBitImage LedMatrix::getMatrixImage()
{
    char* ledStatus = new char[50];
    
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (j != 4)
            {
            ledStatus[i*10 + j*2] = (ledMatrix[i][j] == 0 ? '0' : '1');
            ledStatus[i*10 + j*2 + 1] = ',';
            }
            else
            {
            ledStatus[i*10 + j*2] = (ledMatrix[i][j] == 0 ? '0' : '1');
            ledStatus[i*10 + j*2 + 1] = '\n';
            }
        }
    }
    MicroBitImage matrixImage(ledStatus);
    delete ledStatus;
    ledStatus = NULL;
    return matrixImage;
}