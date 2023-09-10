#ifndef DICROTICFILTER_H_
#define DICROTICFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 200 Hz

fixed point precision: 16 bits

* 0 Hz - 4 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

* 5 Hz - 8 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 9 Hz - 100 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define DICROTICFILTER_TAP_NUM 221

typedef struct
{
    int history[DICROTICFILTER_TAP_NUM];
    unsigned int last_index;
} dicroticFilter;

#ifdef __cplusplus
extern "C"
{
#endif
    void dicroticFilter_init(dicroticFilter *f);
    void dicroticFilter_put(dicroticFilter *f, int input);
    int dicroticFilter_get(dicroticFilter *f);
#ifdef __cplusplus
}
#endif
#endif