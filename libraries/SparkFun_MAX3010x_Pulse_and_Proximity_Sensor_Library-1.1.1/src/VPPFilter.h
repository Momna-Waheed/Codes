#ifndef VPPFILTER_H_
#define VPPFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 200 Hz

fixed point precision: 16 bits

* 0 Hz - 1 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

* 2 Hz - 4 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 5 Hz - 100 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define VPPFILTER_TAP_NUM 265

typedef struct
{
    int history[VPPFILTER_TAP_NUM];
    unsigned int last_index;
} VPPFilter;

#ifdef __cplusplus
extern "C"
{
#endif
    void VPPFilter_init(VPPFilter *f);
    void VPPFilter_put(VPPFilter *f, int input);
    int VPPFilter_get(VPPFilter *f);
#ifdef __cplusplus
}
#endif
#endif