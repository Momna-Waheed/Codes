
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Wire.h>
#include "MAX30105.h"
#include "EMGFilters.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;


int len;
BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t txValue = 0;
int count=0;
String v;
unsigned long int current_time=0;
unsigned long int prev_time=0;
int IMU_counter = 0;
int EMG_cnt =0;
int Hr_cnt=0;

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID           "0365a300-8d69-4066-80c7-554298a6ec5e" // UART service UUID
#define CHARACTERISTIC_UUID_RX "021b52d0-d4f6-4085-b91c-2eb99b1fab00"
#define CHARACTERISTIC_UUID_TX "cf01c075-cb75-4dea-819e-2a79dd466bcb"


MAX30105 particleSensor;
hw_timer_t * timer1 = NULL;
portMUX_TYPE timerMux1 = portMUX_INITIALIZER_UNLOCKED;
volatile int interruptCounter1;

int str_len ; 
const int HR_addr = 0x57;  //I2C address of MAX30102

//const int MPU_addr=0x68;  // I2C address of the MPU-6050
const int SensorInputPin_1=39; // input pin number for EMG
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;



void IRAM_ATTR onTimer1(){
  // Critical Code here
  portENTER_CRITICAL_ISR(&timerMux1);
  interruptCounter1++;  
  portEXIT_CRITICAL_ISR(&timerMux1);

}



class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++)
          Serial.print(rxValue[i]);

        Serial.println();
        Serial.println("*********");
      }
    }
};


void setup() {
   Serial.begin(115200);
  //pinMode(SensorInputPin_1,INPUT);
  
  Serial.println("start timer 1");
  timer1 = timerBegin(1, 80, true);  // timer 1, MWDT clock period = 12.5 ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 -> 1000 ns = 1 us, countUp
  timerAttachInterrupt(timer1, &onTimer1, true); // edge (not level) triggered 
  timerAlarmWrite(timer1, 1100, true); // 1 ms(EMG rate,1khz), autoreload true
  timerAlarmEnable(timer1); // enable


  Serial.println("Initializing...");

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



  // Create the BLE Device
  BLEDevice::init("UART Service");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pTxCharacteristic = pService->createCharacteristic(
										CHARACTERISTIC_UUID_TX,
										BLECharacteristic::PROPERTY_NOTIFY
									);
                      
  pTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
											 CHARACTERISTIC_UUID_RX,
											BLECharacteristic::PROPERTY_WRITE
										);

  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
  prev_time= millis();
}

void KHZ() 
{ EMG();
  if(interruptCounter1%20==0)
  {HR();
  IMU();
  v+="\0";
  len=v.length() + 1;
  char c[len];
  v.toCharArray(c,len);
  //Serial.println(c);
  pTxCharacteristic->setValue(c);
  pTxCharacteristic->notify();        
  v="";
  memset(c, 0, sizeof(c)); 
  }
}

void loop() {
  current_time= millis();
    // notify changed value
  //if(current_time-prev_time<2000)
  while(1)
  { 
    if (deviceConnected) 
    {
        if( interruptCounter1>0)
            { 
              portENTER_CRITICAL(&timerMux1);
              interruptCounter1--;
              portEXIT_CRITICAL(&timerMux1);
              KHZ();
              
            }
    }
    if (!deviceConnected && oldDeviceConnected) 
        {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
        }
    // connecting
    if (deviceConnected && !oldDeviceConnected) 
        {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
        }
 }
//  else
//  { 
//
//    Serial.println(EMG_cnt);Serial.println(Hr_cnt);Serial.println(IMU_counter);
//    Serial.println(current_time-prev_time);
//    delay(2000000);
//  }
    
}

void EMG()
{ v+="e"+String(analogRead(SensorInputPin_1))+",";
  EMG_cnt=EMG_cnt+1;
}

void IMU()
{ sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  v+="ax"+String(a.acceleration.x)+","+"ay"+String(a.acceleration.y)+","+"az"+String(a.acceleration.z)+",";
  v+="gx"+String(g.gyro.x)+","+"gy"+String(g.gyro.y)+","+"gz"+String(g.gyro.z)+",";
  IMU_counter=IMU_counter+1;
}
void HR()
{ v+="IR"+String(particleSensor.getIR())+","+"RED"+String(particleSensor.getRed())+",";
  Hr_cnt=Hr_cnt+1;  
}
