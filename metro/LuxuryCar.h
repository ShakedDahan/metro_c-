//
// Created by shake on 03/01/2022.
//

#ifndef UNTITLED12_LUXURYCAR_H
#define UNTITLED12_LUXURYCAR_H


#include "Car.h"

class LuxuryCar: virtual public Car {
public:
    LuxuryCar():Car(){type=3;name='L';}
    LuxuryCar(unsigned int CarNum,int s):Car(CarNum,s){type=3;name='L';};
    virtual void setSection(int sect){cur=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};


#endif //UNTITLED12_LUXURYCAR_H
