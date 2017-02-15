#include "MicroBit.h"

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
    int x = uBit.accelerometer.getX();
    int y = uBit.accelerometer.getY();
    int z = uBit.accelerometer.getZ();
    return (ManagedString)x + ',' + (ManagedString)y + ',' + (ManagedString)z + ',';
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

