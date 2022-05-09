//
// Created by shake on 03/01/2022.
//

#ifndef UNTITLED12_FAMILYCAR_H
#define UNTITLED12_FAMILYCAR_H


#include "Car.h"

class FamilyCar: public Car {
public:
    FamilyCar(unsigned int CarNum,int s):Car(CarNum,s){type=2;name='F';};
    virtual void setSection(int sect){cur=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}

};


#endif //UNTITLED12_FAMILYCAR_H
