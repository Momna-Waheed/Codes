#pragma once
#include <cstdarg>
namespace Eloquent1 {
    namespace ML1 {
        namespace Port1 {
            class DecisionTree1 {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict1(float *x) {
                        if (x[1] <= 83.5) {
                            if (x[0] <= 1490643.1875) {
                                return 0;
                            }
                            else {
                                if (x[0] <= 1989804.875) {
                                    return 1;
                                }
                                else {
                                    return 0;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 135897.5078125) {
                                if (x[1] <= 103.5) {
                                    if (x[0] <= 121392.00390625) {
                                        return 0;
                                    }
                                    else {
                                        if (x[0] <= 126853.98046875) {
                                            return 1;
                                        }
                                        else {
                                            return 0;
                                        }
                                    }
                                }
                                else {
                                    return 1;
                                }
                            }
                            else {
                                if (x[1] <= 94.5) {
                                    if (x[1] <= 93.5) {
                                        return 1;
                                    }
                                    else {
                                        if (x[0] <= 383543.28125) {
                                            return 1;
                                        }
                                        else {
                                            if (x[0] <= 491894.546875) {
                                                return 0;
                                            }
                                            else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                                else {
                                    return 1;
                                }
                            }
                        }
                    }
                protected:
                };
            }
        }
    }