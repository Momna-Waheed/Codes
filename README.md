# Fyp Codes


Wearable Eppilepsy Monitoring Band Code Repo

Algorithm and Algo_Version_2 have two versions of the final esp code for RandomForest and DescisionTree Classifiers.
Librariers folder has all the libraries utilized for testing and results compariosn purposes.

Built-In Libraries are mentioned below:
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "Esp.h"

Custom libraries or those which were taken from external sources are mentioned below:
#include "EMGFilters.h"
#include "MAX30105.h"
#include "RandomForest1.h"
#include "peak.h"


Classifier libraries were deeloped using 'micromlgen' library in python.
