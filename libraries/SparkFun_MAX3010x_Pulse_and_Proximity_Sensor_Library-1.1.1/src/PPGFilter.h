#ifndef PPGFILTER_H_
#define PPGFILTER_H_
#define MAX30100

#ifdef MAX30102
/*

sampling frequency: 200 Hz

fixed point precision: 16 bits

* 0 Hz - 0.3 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

* 1.3 Hz - 8.3 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 10.3 Hz - 100 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define PPGFILTER_TAP_NUM 213
#endif

#ifdef MAX30100
/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 200 Hz

fixed point precision: 16 bits

* 0 Hz - 7 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 10 Hz - 100 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define PPGFILTER_TAP_NUM 75
#endif

typedef struct
{
    int history[PPGFILTER_TAP_NUM];
    unsigned int last_index;
} PPGFilter;

#ifdef __cplusplus
extern "C"
{
#endif
    void PPGFilter_init(PPGFilter *f);
    void PPGFilter_put(PPGFilter *f, int input);
    int PPGFilter_get(PPGFilter *f);
#ifdef __cplusplus
}
#endif
#endif