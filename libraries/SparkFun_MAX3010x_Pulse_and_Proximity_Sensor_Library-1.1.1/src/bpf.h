#ifndef _BPF_H
#define _BPF_H


// coefficients of transfer function of LPF

static float num[3] = {0.1751,0.3502,0.1751};
static float den[3] = {1.0000,-0.5193,0.2197};

// coefficients of transfer function of HPF

static float num1[3] = {0.9150,-1.8299,0.9150};
static float den1[3] = { 1.0000,-1.8227,0.8372};

float states[2];
float states1[2];

float hp_filter(float input)
{
states[0]=0;
states[1]=0;
float tmp = (input - den1[1] * states[0] - den1[2] * states[1]) / den1[0];
float output = num1[0] * tmp + num1[1] * states[0] + num1[2] * states[1];
// save last states
states[1] = states[0];
states[0] = tmp;

states1[0]=0;
states1[1]=0;
float tmp1 = (output - den[1] * states1[0] - den[2] * states1[1]) / den[0];
float output1 = num[0] * tmp1 + num[1] * states1[0] + num[2] * states1[1];
// save last states
states1[1] = states1[0];
states1[0] = tmp1;

return output1;
}   

                            