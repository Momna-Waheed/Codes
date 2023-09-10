#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[2] = { 0 };
                        // tree #1
                        if (x[5] <= 582.7814331054688) {
                            if (x[6] <= 144047.0859375) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[2] <= 3.4455461502075195) {
                                    if (x[3] <= 19.854721069335938) {
                                        if (x[2] <= 1.7127976417541504) {
                                            if (x[4] <= 27.34663677215576) {
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
                                    if (x[7] <= 82.0) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        else {
                            if (x[6] <= 127514.03125) {
                                if (x[2] <= 4.764996767044067) {
                                    votes[1] += 1;
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                            else {
                                if (x[6] <= 232210.9609375) {
                                    if (x[4] <= 108.90045166015625) {
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
                        }
                        // tree #2
                        if (x[2] <= 5.2171056270599365) {
                            if (x[3] <= 19.27777862548828) {
                                if (x[4] <= 66.48387145996094) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[7] <= 96.0) {
                                        if (x[0] <= 129.3910255432129) {
                                            if (x[4] <= 103.74752807617188) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                if (x[2] <= 4.478809356689453) {
                                                    if (x[3] <= 15.545147895812988) {
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
                                            votes[0] += 1;
                                        }
                                    }
                                    else {
                                        if (x[6] <= 145016.59765625) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                            else {
                                if (x[3] <= 25.948572158813477) {
                                    votes[1] += 1;
                                }
                                else {
                                    if (x[5] <= 655.5242004394531) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        else {
                            if (x[1] <= 1120.8878173828125) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        // tree #3
                        if (x[6] <= 144122.3671875) {
                            if (x[1] <= 319.2574157714844) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[5] <= 602.1413879394531) {
                                    if (x[3] <= 20.219398498535156) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                                else {
                                    if (x[3] <= 20.058395385742188) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        else {
                            if (x[3] <= 16.480606079101562) {
                                if (x[7] <= 97.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[4] <= 99.40202331542969) {
                                    if (x[0] <= 353.51058197021484) {
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
                        }
                        // tree #4
                        if (x[6] <= 138889.90625) {
                            if (x[3] <= 20.392330169677734) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[2] <= 5.489803791046143) {
                                    votes[1] += 1;
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[7] <= 80.5) {
                                if (x[5] <= 705.8253479003906) {
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
                        // tree #5
                        if (x[7] <= 85.5) {
                            if (x[2] <= 5.811603307723999) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[2] <= 2.906389355659485) {
                                if (x[1] <= 386.25384521484375) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[6] <= 446043.6875) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[4] <= 104.65766143798828) {
                                    if (x[7] <= 96.0) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[0] <= 161.82396697998047) {
                                            votes[1] += 1;
                                        }
                                        else {
                                            if (x[1] <= 341.0011291503906) {
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
                        if (x[3] <= 19.86520481109619) {
                            if (x[7] <= 100.5) {
                                if (x[3] <= 18.186765670776367) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[0] <= 513.4493026733398) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[0] <= 224.3055877685547) {
                                    if (x[6] <= 138159.513671875) {
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
                            if (x[2] <= 2.9611001014709473) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        // tree #7
                        if (x[6] <= 144278.5625) {
                            if (x[4] <= 230.35283660888672) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[2] <= 3.558524966239929) {
                                if (x[2] <= 2.55603289604187) {
                                    if (x[5] <= 540.0903930664062) {
                                        if (x[6] <= 457251.21875) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[7] <= 80.5) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
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
                                if (x[5] <= 574.4564819335938) {
                                    if (x[0] <= 205.27992248535156) {
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
                        }
                        // tree #8
                        if (x[3] <= 18.068153381347656) {
                            if (x[3] <= 16.82194995880127) {
                                if (x[6] <= 214464.40625) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 595.9828796386719) {
                                        if (x[3] <= 14.42259168624878) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[3] <= 15.98986530303955) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[7] <= 81.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[7] <= 78.5) {
                                if (x[5] <= 705.8253479003906) {
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
                        // tree #9
                        if (x[7] <= 83.5) {
                            if (x[1] <= 2685.1705322265625) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[3] <= 14.779734134674072) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[4] <= 35.488365173339844) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #10
                        if (x[5] <= 579.7738037109375) {
                            if (x[3] <= 19.86520481109619) {
                                if (x[7] <= 98.5) {
                                    if (x[2] <= 4.390094518661499) {
                                        if (x[6] <= 481843.625) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[3] <= 15.784866333007812) {
                                                votes[0] += 1;
                                            }
                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                    else {
                                        if (x[0] <= 129.85634994506836) {
                                            if (x[3] <= 15.534022808074951) {
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
                                    if (x[2] <= 2.5748283863067627) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[6] <= 104232.11328125) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
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