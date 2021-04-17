#include <Wire.h>
#include "MAX30105.h"
#include <WiFi.h>
//#include <FirebaseESP32.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

//


unsigned long int current_time=0;
unsigned long int prev_time=0;
//Define FirebaseESP32 data object
//FirebaseData firebaseData;
//FirebaseJson json;
MAX30105 particleSensor;
//hw_timer_t * timer0 = NULL;
hw_timer_t * timer1 = NULL;
//hw_timer_t * timer2 = NULL;
//int s_t=0;
//portMUX_TYPE timerMux0 = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE timerMux1 = portMUX_INITIALIZER_UNLOCKED;
//portMUX_TYPE timerMux2 = portMUX_INITIALIZER_UNLOCKED;

//volatile int interruptCounter0;
volatile int interruptCounter1;
//volatile int interruptCounter2;

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
const int SensorInputPin_1=39; // input pin number for EMG


int i_count=0,e_count=0,h_count=0;

void IRAM_ATTR onTimer1(){
  // Critical Code here
  portENTER_CRITICAL_ISR(&timerMux1);
  interruptCounter1++;  
  portEXIT_CRITICAL_ISR(&timerMux1);
}


void setup() {
  
  Serial.begin(115200);
  //pinMode(SensorInputPin_1,INPUT);
  
  Serial.println("start timer 1");
  timer1 = timerBegin(1, 80, true);  // timer 1, MWDT clock period = 12.5 ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 -> 1000 ns = 1 us, countUp
  timerAttachInterrupt(timer1, &onTimer1, true); // edge (not level) triggered 
  timerAlarmWrite(timer1, 1000, true); // 1 ms(EMG rate,1khz), autoreload true
  timerAlarmEnable(timer1); // enable

   while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  
 
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
 
  Serial.println("Initializing...");
  
//  Wire.begin();
//  Wire.setClock(400000L);
//  Wire.beginTransmission(MPU_addr);
//  Wire.write(0x6B);  // PWR_MGMT_1 register
//  Wire.write(0);     // set to zero (wakes up the MPU-6050)
//  Wire.endTransmission(true);
 // Initialize HR sensor
  Serial.println("MAX30105 Basic Readings Example");

  // Initialize sensor
  if (particleSensor.begin() == false)
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }

//Setup to sense up to 18 inches, max LED brightness
  byte ledBrightness = 0xFF; //Options: 0=Off to 255=50mA
  byte sampleAverage = 1; //Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 2; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  int sampleRate = 100; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411; //Options: 69, 118, 215, 411
  int adcRange = 16384; //Options: 2048, 4096, 8192, 16384
////
 particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure senso
//  particleSensor.setup(); //Configure sensor with default settings
//  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
//  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  //particleSensor.setSampleRate(100);

prev_time=millis();
}

void KHZ() 
{  EMG();
  if (interruptCounter1%20==0)
    { 
      HR();
      IMU();
    }
 
}

void loop() {
  current_time = millis();
  if(current_time-prev_time<1000000)
 { 
  if( interruptCounter1>0)
  { portENTER_CRITICAL(&timerMux1);
    interruptCounter1--;
    portEXIT_CRITICAL(&timerMux1);
    KHZ();
  }
 }
else{

   // Firebase.pushArray(firebaseData, path + "/", emg);
    Serial.print("Hcount");Serial.println(h_count);Serial.print("ecount");Serial.println(e_count);Serial.print("i count");Serial.println(i_count);   
    delay(5000000000);     //delay added to check total samples received
     }
}

//function definitions
void IMU()
{ sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
//    Serial.print("Acceleration X: ");
//  Serial.print(a.acceleration.x);
//  Serial.print(" ");
//  Serial.print(a.acceleration.y);
//  Serial.print(" ");
//  Serial.println(a.acceleration.z);
//  AcZ=a.acceleration.z;
//  AcY=a.acceleration.y;
//  AcX=a.acceleration.x;
//  AcZ=g.gyro.z;
//  AcY=g.gyro.y;
//  AcX=g.gyro.x;
  Serial.print(AcX);Serial.print(" "); Serial.print(AcY);Serial.print(" "); Serial.print(AcZ);Serial.println();
  
// Wire.beginTransmission(MPU_addr);
// Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
// Wire.endTransmission(false);
// Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
//
  i_count=i_count+1;
//AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
//AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
//AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
// 
//GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
//GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
//GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
 //IMU_counter++;
// Serial.print(" IMU_cnt: ");Serial.print(IMU_counter); //count samples in 20 sec 
 
// Serial.print("Accel: ");
// Serial.print("AcX: "); Serial.print(AcX); Serial.print(" AcY: "); Serial.print(AcY); Serial.print(" AcZ: "); Serial.print(AcZ);   
// Serial.println(" Gyro: ");
// Serial.print("GyX: "); Serial.print(GyX); Serial.print(" GyY: "); Serial.print(GyY); Serial.print(" GyZ: "); Serial.print(GyZ);
}
// 
void EMG()

{ 
  analogRead(SensorInputPin_1);
    e_count=e_count+1;
    
}

void HR()
{ 
  
  Serial.print(particleSensor.getIR());//Serial.print(" ");
  //Serial.println(particleSensor.getRed());
 h_count=h_count+1;

}
