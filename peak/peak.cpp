/*
 Optical Heart Rate Detection (PBA Algorithm)
 By: Nathan Seidle
 SparkFun Electronics
 Date: October 2nd, 2016
 
 Given a series of IR samples from the MAX30105 we discern when a heart beat is occurring

 Let's have a brief chat about what this code does. We're going to try to detect
 heart-rate optically. This is tricky and prone to give false readings. We really don't
 want to get anyone hurt so use this code only as an example of how to process optical
 data. Build fun stuff with our MAX30105 breakout board but don't use it for actual
 medical diagnosis.

 Excellent background on optical heart rate detection:
 http://www.ti.com/lit/an/slaa655/slaa655.pdf

 Good reading:
 http://www.techforfuture.nl/fjc_documents/mitrabaratchi-measuringheartratewithopticalsensor.pdf
 https://fruct.org/publications/fruct13/files/Lau.pdf

 This is an implementation of Maxim's PBA (Penpheral Beat Amplitude) algorithm. It's been 
 converted to work within the Arduino framework.
*/

/* Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
* 
*/

#include "peak.h"

int16_t IR_AC_Max1 = 20;
int16_t IR_AC_Min1 = -20;

int16_t IR_AC_Signal_Current1 = 0;
int16_t IR_AC_Signal_Previous1;
int16_t IR_AC_Signal_min1 = 0;
int16_t IR_AC_Signal_max1 = 0;
int16_t IR_Average_Estimated1;

int16_t positiveEdge1 = 0;
int16_t negativeEdge1 = 0;
int32_t ir_avg_reg1= 0;

int16_t cbuf1[32];
uint8_t offset1 = 0;

static const uint16_t FIRCoeffs1[12] = {172, 321, 579, 927, 1360, 1858, 2390, 2916, 3391, 3768, 4012, 4096};

//  Heart Rate Monitor functions takes a sample value and the sample number
//  Returns true if a beat is detected
//  A running average of four samples is recommended for display on the screen.
int16_t checkFor_Beat(int32_t sample)
{
  bool beatDetected = false;

  //  Save current state
  IR_AC_Signal_Previous1 = IR_AC_Signal_Current1;
  
  //This is good to view for debugging
  //Serial.print("Signal_Current: ");
  //Serial.println(IR_AC_Signal_Current);

  //  Process next data sample
  IR_Average_Estimated1 = averageDCEstimator1(&ir_avg_reg1, sample);
  IR_AC_Signal_Current1 = lowPassFIRFilter1(sample - IR_Average_Estimated1);
return IR_AC_Signal_Current1; 
//    Detect positive zero crossing (rising edge)
 //if ((IR_AC_Signal_Previous1 < 0) & (IR_AC_Signal_Current1 >= 0))
  //{
  
  // IR_AC_Max1 = IR_AC_Signal_max1; //Adjust our AC max and min
//    IR_AC_Min1 = IR_AC_Signal_min1;

    //positiveEdge1= 1;
  //  negativeEdge1 = 0;
//    IR_AC_Signal_max1 = 0;

   // if ((IR_AC_Max - IR_AC_Min) > 100 & (IR_AC_Max - IR_AC_Min) < 1000)
  //if ((IR_AC_Max1 - IR_AC_Min1) > 20 & (IR_AC_Max1 - IR_AC_Min1) < 1000)
   //{
      //Heart beat!!!
    // beatDetected = true;
  //  }
// }

    //Detect negative zero crossing (falling edge)
  //if ((IR_AC_Signal_Previous1 > 0) & (IR_AC_Signal_Current1 <= 0))
  //{
  //positiveEdge1 = 0;
    //negativeEdge1 = 1;
  //  IR_AC_Signal_min1 = 0;
//  }

    //Find Maximum value in positive cycle
  //if (positiveEdge1 & (IR_AC_Signal_Current1 > IR_AC_Signal_Previous1))
  //{
  //  IR_AC_Signal_max1 = IR_AC_Signal_Current1;
// }

   // Find Minimum value in negative cycle
  //if (negativeEdge1 & (IR_AC_Signal_Current1 < IR_AC_Signal_Previous1))
  //{
   // IR_AC_Signal_min1 = IR_AC_Signal_Current1;
 //}
//return(IR_AC_Signal_max1);
	//if(beatDetected == true)
      //{return(IR_AC_Signal_max1);}
//else
//	{return 0;}

}

//  Average DC Estimator
int16_t averageDCEstimator1(int32_t *p, uint16_t x)
{
  *p += ((((long) x << 15) - *p) >> 4);
  return (*p >> 15);
}

//  Low Pass FIR Filter
int16_t lowPassFIRFilter1(int16_t din)
{  
  cbuf1[offset1] = din;

  int32_t z = mul16_1(FIRCoeffs1[11], cbuf1[(offset1 - 11) & 0x1F]);
  
  for (uint8_t i = 0 ; i < 11 ; i++)
  {
    z += mul16_1(FIRCoeffs1[i], cbuf1[(offset1 - i) & 0x1F] + cbuf1[(offset1 - 22 + i) & 0x1F]);
  }

  offset1++;
  offset1 %= 32; //Wrap condition

  return(z >> 15);
}

//  Integer multiplier
int32_t mul16_1(int16_t x, int16_t y)
{
  return((long)x * (long)y);
}
