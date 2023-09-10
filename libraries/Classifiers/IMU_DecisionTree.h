#pragma once
#include <cstdarg>
namespace Eloquent2 {
    namespace ML2 {
        namespace Port2 {
            class DecisionTree2 {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict2(float *x) {
                        if (x[1] <= 18.068153381347656) {
                            if (x[1] <= 16.82194995880127) {
                                if (x[1] <= 15.216664791107178) {
                                    if (x[0] <= 4.456039190292358) {
                                        return 0;
                                    }
                                    else {
                                        if (x[0] <= 4.46658182144165) {
                                            return 1;
                                        }
                                        else {
                                            return 0;
                                        }
                                    }
                                }
                                else {
                                    if (x[3] <= 527.8479919433594) {
                                        if (x[1] <= 15.637207508087158) {
                                            return 1;
                                        }
                                        else {
                                            return 0;
                                        }
                                    }
                                    else {
                                        return 0;
                                    }
                                }
                            }
                            else {
                                if (x[3] <= 529.5487365722656) {
                                    return 1;
                                }
                                else {
                                    return 0;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 2.9611001014709473) {
                                if (x[2] <= 63.01468467712402) {
                                    if (x[0] <= 2.49877393245697) {
                                        return 0;
                                    }
                                    else {
                                        return 1;
                                    }
                                }
                                else {
                                    return 0;
                                }
                            }
                            else {
                                if (x[1] <= 18.99317741394043) {
                                    if (x[3] <= 547.6500854492188) {
                                        return 1;
                                    }
                                    else {
                                        return 0;
                                    }
                                }
                                else {
                                    if (x[0] <= 6.517630577087402) {
                                        return 1;
                                    }
                                    else {
                                        if (x[0] <= 6.532015562057495) {
                                            return 0;
                                        }
                                        else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                protected:
                };
            }
        }
    }
