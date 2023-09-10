#pragma once
#include <cstdarg>
namespace Eloquent1 {
    namespace ML1 {
        namespace Port1 {
            class RandomForest1 {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict1(float *x) {
                        uint8_t votes[2] = { 0 };
                        // tree #1
                        if (x[1] <= 83.5) {
                            if (x[1] <= 69.5) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 70.5) {
                                    if (x[0] <= 1191668.078125) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 121392.00390625) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 94.5) {
                                    if (x[1] <= 93.5) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        if (x[0] <= 383543.28125) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            if (x[0] <= 536919.921875) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #2
                        if (x[0] <= 137661.171875) {
                            if (x[0] <= 109336.84375) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 99.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 444569.9375) {
                                if (x[1] <= 83.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[0] <= 390673.71875) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        if (x[1] <= 93.5) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            if (x[1] <= 95.0) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 1053168.8125) {
                                    if (x[0] <= 921500.28125) {
                                        if (x[0] <= 714138.84375) {
                                            if (x[0] <= 615940.28125) {
                                                if (x[1] <= 80.0) {
                                                    votes[0] += 1;
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                        else {
                                            if (x[1] <= 82.5) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #3
                        if (x[0] <= 137616.4609375) {
                            if (x[0] <= 121954.74609375) {
                                if (x[1] <= 103.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[0] <= 122640.734375) {
                                    votes[1] += 1;
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 1037279.75) {
                                if (x[1] <= 83.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 94.5) {
                                        if (x[1] <= 93.5) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            if (x[0] <= 383543.28125) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                if (x[0] <= 491894.546875) {
                                                    votes[0] += 1;
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[1] <= 68.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #4
                        if (x[0] <= 184004.9296875) {
                            if (x[0] <= 137616.4609375) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[0] <= 142476.59375) {
                                    votes[1] += 1;
                                }
                                else {
                                    if (x[1] <= 85.0) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        else {
                            if (x[0] <= 237376.7734375) {
                                if (x[0] <= 211908.53125) {
                                    if (x[1] <= 79.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                                else {
                                    if (x[0] <= 214425.65625) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[0] <= 219198.609375) {
                                            if (x[1] <= 81.0) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                        else {
                                            if (x[0] <= 220498.109375) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                if (x[1] <= 83.5) {
                                                    votes[0] += 1;
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 443907.5625) {
                                    if (x[1] <= 83.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[1] <= 94.5) {
                                            if (x[1] <= 93.5) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                if (x[0] <= 383543.28125) {
                                                    votes[1] += 1;
                                                }
                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                                else {
                                    if (x[1] <= 80.0) {
                                        if (x[0] <= 1490643.1875) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[0] <= 1989804.875) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        // tree #5
                        if (x[1] <= 83.5) {
                            if (x[0] <= 1490643.1875) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 68.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[1] <= 98.5) {
                                if (x[0] <= 138916.515625) {
                                    if (x[1] <= 93.5) {
                                        if (x[0] <= 102322.828125) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[1] <= 102.5) {
                                    if (x[1] <= 100.5) {
                                        if (x[1] <= 99.5) {
                                            if (x[0] <= 121772.4453125) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        if (x[1] <= 101.5) {
                                            if (x[0] <= 152082.83203125) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                        else {
                                            if (x[0] <= 102830.912109375) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #6
                        if (x[1] <= 85.5) {
                            if (x[1] <= 83.5) {
                                if (x[1] <= 69.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 70.5) {
                                        if (x[0] <= 1133040.59375) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 234141.44140625) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[1] <= 98.5) {
                                if (x[1] <= 97.5) {
                                    if (x[1] <= 95.5) {
                                        if (x[0] <= 119884.91796875) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        if (x[0] <= 126828.94921875) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                                else {
                                    if (x[0] <= 121538.1015625) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 121072.94140625) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #7
                        if (x[0] <= 144965.03125) {
                            if (x[1] <= 102.0) {
                                if (x[0] <= 121954.74609375) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 84.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[0] <= 126853.98046875) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[0] <= 467527.375) {
                                if (x[0] <= 457303.53125) {
                                    if (x[0] <= 183449.90625) {
                                        if (x[1] <= 82.0) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        if (x[0] <= 359641.9375) {
                                            if (x[0] <= 319513.84375) {
                                                if (x[0] <= 314141.0625) {
                                                    if (x[1] <= 84.0) {
                                                        votes[0] += 1;
                                                    }
                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                            else {
                                                if (x[1] <= 82.0) {
                                                    votes[0] += 1;
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                        else {
                                            if (x[1] <= 83.5) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                if (x[1] <= 94.5) {
                                                    if (x[0] <= 397368.15625) {
                                                        if (x[1] <= 93.0) {
                                                            votes[1] += 1;
                                                        }
                                                        else {
                                                            votes[0] += 1;
                                                        }
                                                    }
                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                            else {
                                if (x[0] <= 1037279.75) {
                                    if (x[1] <= 80.0) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                                else {
                                    if (x[0] <= 2007350.625) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        if (x[0] <= 2047485.4375) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }
                        // tree #8
                        if (x[0] <= 144203.28125) {
                            if (x[0] <= 138889.90625) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[0] <= 142401.3125) {
                                    votes[1] += 1;
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 420511.203125) {
                                if (x[1] <= 83.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 94.5) {
                                        if (x[0] <= 388637.828125) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            if (x[1] <= 93.5) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[1] <= 69.0) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #9
                        if (x[0] <= 144122.3671875) {
                            if (x[1] <= 101.0) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[0] <= 444569.9375) {
                                if (x[1] <= 83.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[0] <= 1084160.375) {
                                    if (x[0] <= 794150.625) {
                                        if (x[1] <= 80.0) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        if (x[1] <= 83.0) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                                else {
                                    if (x[0] <= 1989804.875) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        if (x[1] <= 80.0) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }
                        // tree #10
                        if (x[0] <= 149051.8671875) {
                            if (x[1] <= 98.5) {
                                if (x[1] <= 91.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 93.5) {
                                        if (x[0] <= 119224.71875) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 106411.7421875) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[0] <= 1049340.875) {
                                if (x[0] <= 911969.15625) {
                                    if (x[0] <= 467527.375) {
                                        if (x[0] <= 414812.328125) {
                                            if (x[0] <= 279403.09375) {
                                                if (x[1] <= 81.5) {
                                                    votes[0] += 1;
                                                }
                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                            else {
                                                if (x[0] <= 319513.84375) {
                                                    if (x[0] <= 296443.0625) {
                                                        votes[0] += 1;
                                                    }
                                                    else {
                                                        if (x[0] <= 300105.234375) {
                                                            votes[1] += 1;
                                                        }
                                                        else {
                                                            if (x[0] <= 314141.0625) {
                                                                if (x[0] <= 310411.28125) {
                                                                    if (x[0] <= 307006.015625) {
                                                                        if (x[0] <= 302972.59375) {
                                                                            votes[0] += 1;
                                                                        }
                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                    else {
                                                                        votes[0] += 1;
                                                                    }
                                                                }
                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                            else {
                                                                if (x[0] <= 317630.0) {
                                                                    votes[0] += 1;
                                                                }
                                                                else {
                                                                    if (x[0] <= 318623.9375) {
                                                                        votes[1] += 1;
                                                                    }
                                                                    else {
                                                                        votes[0] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else {
                                                    if (x[1] <= 80.5) {
                                                        votes[0] += 1;
                                                    }
                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                        else {
                                            if (x[1] <= 83.0) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        if (x[1] <= 80.0) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                                else {
                                    if (x[1] <= 83.0) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 2007350.625) {
                                    votes[1] += 1;
                                }
                                else {
                                    if (x[1] <= 83.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
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
                };
            }
        }
    }
