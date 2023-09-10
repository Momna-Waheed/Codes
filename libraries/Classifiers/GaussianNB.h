#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class GaussianNB {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float votes[2] = { 0.0f };
                        float theta[8] = { 0 };
                        float sigma[8] = { 0 };
                        theta[0] = 173.477674598858; theta[1] = 329.475411638273; theta[2] = 1.296493456255; theta[3] = 11.44173767656; theta[4] = 36.56287549331; theta[5] = 519.054684913568; theta[6] = 96330.15952340493; theta[7] = 69.737179487179;
                        sigma[0] = 60503.09739645798; sigma[1] = 164298.31819270173; sigma[2] = 155.455663362049; sigma[3] = 156.631663074086; sigma[4] = 2156.048579980736; sigma[5] = 397.718878322556; sigma[6] = 14792465800.928015; sigma[7] = 190.970566073445;
                        votes[0] = 0.8 - gauss(x, theta, sigma);
                        theta[0] = 961.356447129231; theta[1] = 1853.32499228547; theta[2] = 5.604263309175; theta[3] = 26.797138527991; theta[4] = 177.201645816709; theta[5] = 741.024305006838; theta[6] = 643361.7257615385; theta[7] = 96.435897435897;
                        sigma[0] = 435036.9919136874; sigma[1] = 1427697.5728650542; sigma[2] = 154.561090122776; sigma[3] = 171.654388584489; sigma[4] = 3146.292905483366; sigma[5] = 20481.66921706004; sigma[6] = 468246761334.6135; sigma[7] = 174.710745231894;
                        votes[1] = 0.2 - gauss(x, theta, sigma);
                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];
                        for (uint8_t i = 1; i < 2; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }
                        return classIdx;
                    }
                protected:
                    /**
                    * Compute gaussian value
                    */
                    float gauss(float *x, float *theta, float *sigma) {
                        float gauss = 0.0f;
                        for (uint16_t i = 0; i < 8; i++) {
                            gauss += log(sigma[i]);
                            gauss += abs(x[i] - theta[i]) / sigma[i];
                        }
                        return gauss;
                    }
                };
            }
        }
    }