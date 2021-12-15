#include<Wire.h>
#include <math.h>
#define MPU 0x68
#define address 0x1E

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double pitch,roll;

void setup(){
Wire.begin();Wire.beginTransmission(MPU);Wire.write(0x6B);Wire.write(0);Wire.endTransmission(true);    //gyro
             Wire.beginTransmission(address);Wire.write(0x02);Wire.write(0x00);Wire.endTransmission(); //compas

Serial.begin(115200);Serial.println("\nTime, Ac_X+950, Ac_Y+300, Ac_Z, Gy_X-480, Gy_Y-170, Gy_Z-210, (Temp-1600)/340+36.53, Compas_X, Compas_Y, Compas_Z");

}
void loop(){
delay(10);
             Wire.beginTransmission(MPU);Wire.write(0x3B);Wire.endTransmission(false);Wire.requestFrom(MPU,14,true);           

int AcXoff,AcYoff,AcZoff,GyXoff,GyYoff,GyZoff;
int temp,toff;
double t,tx,tf;

//Acceleration data correction
//AcXoff = -950;
//AcYoff = -300;
//AcZoff = 0;

//Temperature correction
//toff = -1600;

//Gyro correction
//GyXoff = 480;
//GyYoff = 170;
//GyZoff = 210;

  if(14<=Wire.available()){
//read accel data
AcX=(Wire.read()<<8|Wire.read());// + AcXoff;
AcY=(Wire.read()<<8|Wire.read());// + AcYoff;
AcZ=(Wire.read()<<8|Wire.read());// + AcYoff;

//read temperature data
temp=(Wire.read()<<8|Wire.read());// + toff;
//tx=temp;
//t = tx/340 + 36.53;

//read gyro data
GyX=(Wire.read()<<8|Wire.read());// + GyXoff;
GyY=(Wire.read()<<8|Wire.read());// + GyYoff;
GyZ=(Wire.read()<<8|Wire.read());// + GyZoff;
  
//get pitch/roll
//getAngle(AcX,AcY,AcZ);

//send the data out the serial port
Serial.print(millis());Serial.print(", ");
//Serial.print(pitch);Serial.print(", ");
//Serial.print(roll); Serial.print(", ");

Serial.print(AcX);Serial.print(", ");
Serial.print(AcY);Serial.print(", ");
Serial.print(AcZ);Serial.print(", ");

Serial.print(GyX);Serial.print(", ");
Serial.print(GyY);Serial.print(", ");
Serial.print(GyZ);Serial.print(", ");

Serial.print(temp);Serial.print(", ");


  int x,y,z; //triple axis data
             Wire.beginTransmission(address);Wire.write(0x03);Wire.endTransmission();Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8;    x |= Wire.read(); 
    z = Wire.read()<<8;    z |= Wire.read(); 
    y = Wire.read()<<8;    y |= Wire.read();
  }
 
  Serial.print(x);  Serial.print(", ");
  Serial.print(y);  Serial.print(", ");
  Serial.print(z);

Serial.println();
}//if read 14 bytes from MPU
}

//convert the accel data to pitch/roll
void getAngle(int Vx,int Vy,int Vz) {
double x = Vx;
double y = Vy;
double z = Vz;

pitch = atan(x/sqrt((y*y) + (z*z)));
roll = atan(y/sqrt((x*x) + (z*z)));
//convert radians into degrees
pitch = pitch * (180.0/3.14);
roll = roll * (180.0/3.14) ;
}
