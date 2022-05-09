
#ifndef UNTITLED12_SECTION_H
#define UNTITLED12_SECTION_H
#include <iostream>
#include "Car.h"
#include <algorithm>
#include "FamilyCar.h"
#include "SportsCar.h"
#include "LuxuryCar.h"
#include "MASERATI.h"
using namespace std;
class Section {
    //מומש בנאי העתקה לצורך עבודה במטרופולין ומומש דיסטרקטור.אין צורך באופרטור שווה
    struct Cars {
        Car* data;
        Cars *next;
        Cars(Car* data, Cars *next);
    };

public:
    struct Neighbors {
        Section* data;
        Neighbors *next;
        Neighbors(Section* data, Neighbors *next);
    };
    Section() : id(0), count(0), Ncount(0), head(NULL), Nhead(NULL) {}
    Section(int id,Cars *head, Neighbors *nhead);
    explicit Section(int i);
    void removeCar(unsigned int CarNum);
    void insertCar(unsigned int CarNum, int pos,char t);
    void insertNeighbor(int neighbor);
    int getId() const{return id;}
    int getn(int i)const;
    int getNumOfNeighbros() const{return Ncount;}
    string printCars () const;
    ~Section(){delete Nhead;delete head;}
    int id,count,Ncount;
    Cars* head;
    Neighbors* Nhead;


};


#endif //UNTITLED12_SECTION_H
