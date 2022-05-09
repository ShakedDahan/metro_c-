//
// Created by shake on 03/01/2022.
//

#ifndef UNTITLED12_SPORTSCAR_H
#define UNTITLED12_SPORTSCAR_H


#include "Car.h"

class SportsCar :virtual public Car{
public:
    SportsCar():Car(){type=4;name='S';};
    SportsCar(unsigned int CarNum,int s):Car(CarNum,s){type=4;name='S';};
    virtual void setSection(int sect){cur=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};


#endif //UNTITLED12_SPORTSCAR_H
