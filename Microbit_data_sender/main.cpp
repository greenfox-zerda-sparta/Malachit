#include "LedMatrix.h"

MicroBit uBit;
MicroBitSerial serial(USBTX, USBRX);
MicroBitI2C i2c(I2C_SDA0, I2C_SCL0); 
MicroBitAccelerometer accelerometer(i2c); 
MicroBitStorage storage; 
MicroBitCompass compass(i2c, accelerometer, storage);

ManagedString getCompassHeading()
{
    int heading = compass.heading();
    return (ManagedString)heading + ',';
}

ManagedString getAccelerometerVectors()
{
    ManagedString accelerometerVectorsString = "";
    vector<int> accelerometerVectors;
    accelerometerVectors.push_back(uBit.accelerometer.getX());
    accelerometerVectors.push_back(uBit.accelerometer.getY());
    accelerometerVectors.push_back(uBit.accelerometer.getZ());
    for (int i = 0; i < accelerometerVectors.size(); ++i)
    {
        accelerometerVectorsString = accelerometerVectorsString + (ManagedString)accelerometerVectors[i] + ',';
    }
    return accelerometerVectorsString;
}

ManagedString getMessage()
{
    return getCompassHeading() + getAccelerometerVectors();
}

ManagedString readData()
{
    int messageSize = 2;
    return serial.read(messageSize, ASYNC);
}

void sendData()
{
    serial.send(getMessage(), ASYNC);
}  

void switchLedMatrix(ManagedString buffer, LedMatrix& myLedMatrix)
{
    int offsetToGetInt = 48;
    myLedMatrix.setLedMatrix((int)buffer.charAt(0) - offsetToGetInt, (int)buffer.charAt(1) - offsetToGetInt);
    uBit.display.print(myLedMatrix.getMatrixImage());
}


int main()
{
    uBit.init();
    LedMatrix myLedMatrix;
    while(1)
    {   
        ManagedString buffer = readData();
        if (buffer.length() != 0)
        {
            switchLedMatrix(buffer, myLedMatrix);
        }
        sendData();
        uBit.sleep(500);
    }
    
    release_fiber();
}