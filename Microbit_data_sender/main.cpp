#include "MicroBit.h"
#include <vector>

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

void readData()
{
    ManagedString s = serial.read(2, ASYNC);
    uBit.display.print(s);
}

void sendData()
{
    serial.send(getMessage(), ASYNC);
}
    

int main()
{
    uBit.init();
    
    while(1)
    {
        readData();
        sendData();
        uBit.sleep(500);
    }
    
    release_fiber();
}
