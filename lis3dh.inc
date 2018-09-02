#include <Wire.h>
#include <stdio.h>

const int addr = 0x18;

unsigned int readRegister(byte reg){
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.endTransmission();
}

void writeRegister(byte reg, byte data){
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}

void setup(){
    Wire.begin();
    Serial.begin(9600);

    writeRegister(0x20, 0x27);
    int res = readRegister(0x0F);
    Serial.println(res);
}

char str[256];

void loop(){
    int x,y,z;

    int h, l;

    writeRegister(0x20, 0x27)

    l = readRegister(0x28);
    h = readRegister(0x29);
    x = h <<8 | l;

    l = readRegister(0x2A);
    h = readRegister(0x2B);
    y = h << 8 | l;

    l = readRegister(0x2C);
    h = readRegister(0x2D);
    z = h << 8 | l;

    sprintf(str, "%d, %d, %d", x,y,z);
    Serial.println(str);
    sleep(1000);
}

