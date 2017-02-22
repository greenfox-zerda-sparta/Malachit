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
    return serial.read(2, ASYNC);
}

void sendData()
{
    serial.send(getMessage(), ASYNC);

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
            myLedMatrix.setLedMatrix((int)buffer.charAt(0) - 48, (int)buffer.charAt(1) - 48);
            uBit.display.print(myLedMatrix.getMatrixImage());
        }
        sendData();
        uBit.sleep(500);
    }
    
    release_fiber();
}
