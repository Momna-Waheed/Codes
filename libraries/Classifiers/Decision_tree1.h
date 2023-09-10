#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[3] <= 18.068153381347656) {
                            if (x[7] <= 100.5) {
                                if (x[3] <= 16.82194995880127) {
                                    return 0;
                                }
                                else {
                                    if (x[6] <= 204284.2578125) {
                                        return 0;
                                    }
                                    else {
                                        return 1;
                                    }
                                }
                            }
                            else {
                                if (x[2] <= 2.6022536754608154) {
                                    return 0;
                                }
                                else {
                                    return 1;
                                }
                            }
                        }
                        else {
                            if (x[7] <= 78.5) {
                                if (x[6] <= 1131895.078125) {
                                    return 0;
                                }
                                else {
                                    return 1;
                                }
                            }
                            else {
                                return 1;
                            }
                        }
                    }
                protected:
                };
            }
        }
    }