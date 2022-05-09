//
// Created by shake on 16/12/2021.
//

#ifndef UNTITLED12_METROPOLIS_H
#define UNTITLED12_METROPOLIS_H
#include <sstream>
#include "Section.h"
#include "Road.h"
#include <cstdlib>
#include "generic_map.h"
#include <algorithm>

class Metropolis {
    //מומש דיסטרקור לצורך מחיקת הפוינטרים,אין צרוך בבנאי העתקה יש עיר 1,אין צורך באופרטור =
    struct Cars {
        Car* data;
        Cars *next;
        Cars(Car* data, Cars *next);
    };
    struct Sections {
        Section* data;
        Sections *next;
        Sections(Section* data, Sections *next);
    };
    struct Roads {
        Road* data;
        Roads *next;
        Roads(Road* data,Roads *next);
    };
public:
    Metropolis (double** graph, unsigned int size);
    Metropolis():CarsCount(0),SectionCount(0),RoadCount(0),RoadHead(NULL),SectionHead(NULL),CarsHead(NULL){};
    void Ride(int size);
    void incRoad(int from,int to,int t);
    double getToxRoad(int from,int to);
    Section* getSection(int cur);
    void printTox(int size);
    void printCars(int size);
    void insertCar(int CarNum, int pos,char t);
    void insertSection(const Section& s);
    void insertRoad(double len, int from, int to, int c);
    void setCars(string *st,int section);
    ~Metropolis(){delete RoadHead;delete SectionHead;delete CarsHead;}
    void printMap(){map.print();}
private:
    int CarsCount,SectionCount,RoadCount;
    Roads *RoadHead ;
    Sections *SectionHead;
    Cars *CarsHead;
    generic_map<int,int> map;
};


#endif //UNTITLED12_METROPOLIS_H
