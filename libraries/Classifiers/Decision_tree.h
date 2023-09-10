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
                            if (x[3] <= 16.82194995880127) {
                                if (x[6] <= 214464.40625) {
                                    return 0;
                                }

                                else {
                                    if (x[6] <= 215286.8046875) {
                                        return 1;
                                    }

                                    else {
                                        if (x[2] <= 4.009490251541138) {
                                            return 0;
                                        }

                                        else {
                                            if (x[0] <= 160.70381546020508) {
                                                return 1;
                                            }

                                            else {
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[5] <= 529.5487365722656) {
                                    return 1;
                                }

                                else {
                                    return 0;
                                }
                            }
                        }

                        else {
                            if (x[2] <= 2.9611001014709473) {
                                if (x[0] <= 309.7366409301758) {
                                    if (x[2] <= 2.49877393245697) {
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
                                if (x[6] <= 89335.54296875) {
                                    return 0;
                                }

                                else {
                                    if (x[3] <= 18.99317741394043) {
                                        if (x[5] <= 547.6500854492188) {
                                            return 1;
                                        }

                                        else {
                                            return 0;
                                        }
                                    }

                                    else {
                                        return 1;
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