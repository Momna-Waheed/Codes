
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "EMGFilters.h"
#include "MAX30105.h"
#include "Decision_tree.h"
//#include "PPGFilters.h"

//PPGFilters filter;


Eloquent::ML::Port::DecisionTree clf;

Adafruit_MPU6050 mpu;
EMGFilters myFilter_1;
MAX30105 particleSensor;

SAMPLE_FREQUENCY sampleRate = SAMPLE_FREQ_1000HZ;

NOTCH_FREQUENCY humFreq = NOTCH_FREQ_60HZ;

//sample rate for ppg
//SAMPLE_FREQUENCY sampleRate1 = SAMPLE_FREQ_50HZ;

BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t txValue = 0;

unsigned long int current_time=0;
unsigned long int prev_time=0;

#define SERVICE_UUID           "0365a300-8d69-4066-80c7-554298a6ec5e" // UART service UUID
#define CHARACTERISTIC_UUID_RX "021b52d0-d4f6-4085-b91c-2eb99b1fab00"
#define CHARACTERISTIC_UUID_TX "cf01c075-cb75-4dea-819e-2a79dd466bcb"

hw_timer_t * timer1 = NULL;
portMUX_TYPE timerMux1 = portMUX_INITIALIZER_UNLOCKED;
volatile int interruptCounter1;
float feat[8];

const int SensorInputPin_1=39; // input pin number for EMG

int32_t e_sum=0;
int e_count=0,e_zc=0;
float e_prev=0;
float e_val;
bool callibrated=0;
int avg=0;
float thresh;
float e_energy=0;
float ax,ay,az,Tmp,gx,gy,gz;
float e_acm,e_gcm,a_max=0,g_max=0;
float a_energy=0,g_energy=0,acm,gcm;
//int e_zc=0;

float IR;
float RED;
float ir_max=0;
float r_max=0;

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


void setup()
{     
  
  Serial.begin(115200);
  
  Serial.println("start timer 1");
  timer1 = timerBegin(1, 80, true);  // timer 1, MWDT clock period = 12.5 ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 -> 1000 ns = 1 us, countUp
  timerAttachInterrupt(timer1, &onTimer1, true); // edge (not level) triggered 
  timerAlarmWrite(timer1, 1100, true); // 1 ms(EMG rate,1khz), autoreload true
  timerAlarmEnable(timer1); // enable

   //ppg filter
   filter.init(sampleRate1, humFreq,false,true, true);

   Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) 
  {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
              }
  }
  Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  
  myFilter_1.init(sampleRate, humFreq, true, true, true);
  Serial.println("PLACE YOUR SENSOR...");

   while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

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
 particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); 
   // Create the BLE Device
  BLEDevice::init("Epicare");

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

if(e_count%10000==0 && callibrated==0)
    { //avg=e_sum/e_count;
      
      if(avg<200)
            { callibrated=1;
            thresh=avg;
           //String  v="Callibrated";
          //int len=v.length() + 1;
          //char c[len];
          //v.toCharArray(c,len);
          //Serial.println(c);
          int v=1;
          pTxCharacteristic->setValue((uint8_t*)&v,1);
          pTxCharacteristic->notify();        
          //v="";
          //memset(c, 0, sizeof(c)); 
            //e_count=0;
            //Serial.print("Callibrated :  ");Serial.println(thresh);
            
            }
      else
      {
        int v=0;
          pTxCharacteristic->setValue((uint8_t*)&v,1);
          pTxCharacteristic->notify();
        //Serial.print("AVG :  ");Serial.println(avg);
      }
      e_sum=0;
      e_count=0;
    }
else if(callibrated==1)
{//Serial.print("Callibrated :  ");Serial.println(thresh);
  //Serial.println(e_count%1000);
  int v=1;
  pTxCharacteristic->setValue((uint8_t*)&v,1);
 pTxCharacteristic->notify(); 
  if(e_count%20==0)
  { 
    IMU();
    HR();
  if(e_count%1000==0)
  { //Serial.print("energy : "); Serial.print(e_energy);Serial.print(" , zc :  "); Serial.println(e_zc);
  //Serial.print("energy acm: "); Serial.print(a_energy);Serial.print(" , energy gcm :  "); Serial.print(g_energy);
  //Serial.print(" , max a :  "); Serial.print(a_max);Serial.print(" , max g:  "); Serial.println(g_max);
    feat[0]=ir_max;
    feat[1]=r_max;
    feat[7]= e_zc;
    feat[6]= e_energy;
    feat[5]= a_energy;
    feat[4]= g_energy;
    feat[3]= a_max;
    feat[2]= g_max;
    Serial.print(clf.predict(feat));
    
  e_energy=0;
  e_zc=0;
  e_count=0;
  e_prev=0;
  a_max=0;g_max=0;a_energy=0;g_energy=0;
  ir_max=0;
  r_max=0;
  }
  }
}
else
{         int v=0;
          pTxCharacteristic->setValue((uint8_t*)&v,1);
          pTxCharacteristic->notify();
}

}


void loop()
{
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
   
}

void EMG()
{ 
  if (callibrated==0)
 { e_val=myFilter_1.update(analogRead(SensorInputPin_1));
  //Serial.println(e_val);
  e_count=e_count+1;
  e_sum=(abs(e_val)+e_sum);
  avg=e_sum/e_count;
 }
 else
 {  
  e_val=myFilter_1.update(analogRead(SensorInputPin_1));
  e_val=e_val-thresh;
  //Serial.println(e_val);
  e_energy=sq(e_val)+e_energy;;
  
  
 
 if(e_val *e_prev<0 && abs(e_val-e_prev)>=1.5*thresh)
  {
    e_zc=e_zc+1;
    
  }
   e_prev=e_val;
   e_count=e_count+1;
}
}

void IMU()
{ sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  ax=a.acceleration.x;
  ay=a.acceleration.y;
  az=a.acceleration.z;
  gx=g.gyro.x;
  gy=g.gyro.y;
  gz=g.gyro.z;
  acm= sqrt(sq(ax)+sq(ay)+sq(az));
  gcm= sqrt(sq(gx)+sq(gy)+sq(gz));
  a_energy=acm+a_energy;
  g_energy=gcm+g_energy;
  a_max=(a_max>acm)?a_max:acm;
  g_max=(g_max>gcm)?g_max:gcm;
}

void HR()
{ 
  IR = lo(particleSensor.getIR());
  RED = filter.update(particleSensor.getRed());
  
  ir_max=(ir_max > IR)?ir_max:IR;
  r_max=(r_max > RED)?r_max:RED;
}
