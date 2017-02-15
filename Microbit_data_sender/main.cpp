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
    vector<ManagedString> accelerometerVectors;
    accelerometerVectors.push_back((ManagedString)uBit.accelerometer.getX());
    accelerometerVectors.push_back((ManagedString)uBit.accelerometer.getY());
    accelerometerVectors.push_back((ManagedString)uBit.accelerometer.getZ());
    for (int i = 0; i < accelerometerVectors.size(); ++i)
    {
        accelerometerVectorsString = accelerometerVectorsString + accelerometerVectors[i] + ',';
    }
    return accelerometerVectorsString;
}

ManagedString getMessage()
{
    return getCompassHeading() + getAccelerometerVectors();
}

int main()
{
    uBit.init();

    while (1)
    {
      serial.send(getMessage());
      uBit.sleep(500);
    }
    
    release_fiber();
}

