//
// Created by shake on 16/12/2021.
//

#include "Road.h"

Road Road::operator++(int) {
    Road temp = *this;
    this->toxicity+=c/len;
    return temp;
}

Road &Road::operator++() {
    this->toxicity+=c/len;
    return *this;
}

Road::Road(double l, int f, int t, double ci) {
        len=l;toxicity=0;from=f;to=t;c=0;}
