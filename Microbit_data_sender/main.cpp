#include "MicroBit.h"

MicroBit uBit;
MicroBitSerial serial(USBTX, USBRX);
MicroBitI2C i2c(I2C_SDA0, I2C_SCL0); 

MicroBitAccelerometer accelerometer(i2c); 

MicroBitStorage storage; 

MicroBitCompass compass(i2c, accelerometer, storage); 

int main()
{
    uBit.init();

    while (1) {
      int heading = compass.heading();
      int x = uBit.accelerometer.getX();
      int y = uBit.accelerometer.getY();
      int z = uBit.accelerometer.getZ();
      ManagedString message = (ManagedString)heading + ',' + (ManagedString)x + ',' + (ManagedString)y + ',' + (ManagedString)z;
      serial.send(message);
      uBit.sleep(500);
    }
    
    release_fiber();
}

