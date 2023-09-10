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
                        if (x[4] <= 579.9844055175781) {
                            if (x[2] <= 16.82194995880127) {
                                if (x[2] <= 15.119525909423828) {
                                    if (x[1] <= 4.456039190292358) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[4] <= 515.9643249511719) {
                                            if (x[5] <= 176692.79296875) {
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
                                    if (x[6] <= 88.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[6] <= 79.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[0] <= 227.96273040771484) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }
                        else {
                            if (x[1] <= 3.677666425704956) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[5] <= 127514.03125) {
                                    if (x[0] <= 238.54520416259766) {
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
                        // tree #2
                        if (x[6] <= 83.5) {
                            if (x[3] <= 233.9755630493164) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[1] <= 3.388888716697693) {
                                if (x[5] <= 164497.84375) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[2] <= 13.70342493057251) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #3
                        if (x[2] <= 18.068153381347656) {
                            if (x[2] <= 15.216664791107178) {
                                if (x[6] <= 100.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[5] <= 178537.11328125) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[4] <= 527.8479919433594) {
                                    if (x[4] <= 518.4822387695312) {
                                        if (x[3] <= 84.5920295715332) {
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
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[1] <= 2.9611001014709473) {
                                if (x[6] <= 79.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[6] <= 79.0) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #4
                        if (x[5] <= 144203.28125) {
                            if (x[4] <= 712.6767883300781) {
                                if (x[4] <= 602.1413879394531) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[4] <= 609.27392578125) {
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
                        else {
                            if (x[2] <= 17.98777198791504) {
                                if (x[1] <= 3.7326472997665405) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[3] <= 138.05717849731445) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[3] <= 99.40202331542969) {
                                    if (x[0] <= 528.8657913208008) {
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
                        // tree #5
                        if (x[2] <= 18.56069564819336) {
                            if (x[1] <= 3.6417821645736694) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 3.786386013031006) {
                                    votes[1] += 1;
                                }
                                else {
                                    if (x[6] <= 84.5) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[5] <= 155940.37109375) {
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
                            if (x[1] <= 6.517630577087402) {
                                votes[1] += 1;
                            }
                            else {
                                if (x[4] <= 648.8399353027344) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        // tree #6
                        if (x[6] <= 83.5) {
                            if (x[2] <= 27.234976768493652) {
                                votes[0] += 1;
                            }
                            else {
                                votes[1] += 1;
                            }
                        }
                        else {
                            if (x[1] <= 2.277763605117798) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[4] <= 531.8120727539062) {
                                    if (x[4] <= 525.766357421875) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                                else {
                                    if (x[5] <= 95834.83203125) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }
                        // tree #7
                        if (x[5] <= 138889.90625) {
                            if (x[4] <= 602.1413879394531) {
                                if (x[2] <= 20.392330169677734) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                            else {
                                if (x[3] <= 154.0604705810547) {
                                    votes[1] += 1;
                                }
                                else {
                                    votes[0] += 1;
                                }
                            }
                        }
                        else {
                            if (x[1] <= 3.6028655767440796) {
                                if (x[4] <= 535.9596252441406) {
                                    if (x[3] <= 39.92509841918945) {
                                        if (x[2] <= 15.42041540145874) {
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
                                    if (x[0] <= 187.12437438964844) {
                                        votes[1] += 1;
                                    }
                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[4] <= 569.4899597167969) {
                                    if (x[3] <= 156.59404754638672) {
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
                        if (x[4] <= 579.7738037109375) {
                            if (x[4] <= 544.6401672363281) {
                                if (x[6] <= 99.5) {
                                    if (x[6] <= 96.5) {
                                        if (x[6] <= 86.5) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[4] <= 537.4908447265625) {
                                                if (x[1] <= 3.943799138069153) {
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
                                    else {
                                        if (x[3] <= 52.80255889892578) {
                                            votes[0] += 1;
                                        }
                                        else {
                                            if (x[3] <= 81.12842178344727) {
                                                votes[1] += 1;
                                            }
                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                                else {
                                    if (x[1] <= 2.6022536754608154) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[2] <= 19.86520481109619) {
                                    if (x[2] <= 17.816720008850098) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        if (x[6] <= 83.0) {
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
                        }
                        else {
                            if (x[2] <= 18.82244873046875) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 3.6585097312927246) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[0] <= 491.95997619628906) {
                                        if (x[5] <= 89335.54296875) {
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
                        }
                        // tree #9
                        if (x[2] <= 16.713722229003906) {
                            if (x[1] <= 4.416100025177002) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[4] <= 527.4406433105469) {
                                    if (x[2] <= 14.536242485046387) {
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
                            if (x[5] <= 102690.0625) {
                                votes[0] += 1;
                            }
                            else {
                                if (x[1] <= 3.486794352531433) {
                                    if (x[0] <= 527.3481903076172) {
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
                        // tree #10
                        if (x[1] <= 4.192253112792969) {
                            if (x[2] <= 17.617198944091797) {
                                if (x[6] <= 101.0) {
                                    votes[0] += 1;
                                }
                                else {
                                    if (x[1] <= 2.0849572718143463) {
                                        votes[0] += 1;
                                    }
                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                            else {
                                if (x[6] <= 79.5) {
                                    votes[0] += 1;
                                }
                                else {
                                    votes[1] += 1;
                                }
                            }
                        }
                        else {
                            if (x[6] <= 80.5) {
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
