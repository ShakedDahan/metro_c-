//
// Created by shake on 03/01/2022.
//

#ifndef UNTITLED12_MASERATI_H
#define UNTITLED12_MASERATI_H


#include "SportsCar.h"
#include "LuxuryCar.h"

using namespace std;
class MASERATI : public SportsCar,public LuxuryCar{
public:
    MASERATI(unsigned int CarNum, int s) :Car(CarNum,s) { type=4;name='M';};
    virtual void setSection(int sect){cur=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};


#endif //UNTITLED12_MASERATI_H
