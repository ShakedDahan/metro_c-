//
// Created by shake on 16/12/2021.
//

#ifndef UNTITLED12_ROAD_H
#define UNTITLED12_ROAD_H
#include "iostream"
//אין צורך בשלושת הגדולים הדפולטיביים מספיק טובים במחלקה זו
using namespace std;
class Road {
public:
Road(double l,int f,int t,double ci);

Road& operator++();
Road  operator++(int);
int getFrom() const{return from;}
int getTo() const{return to;}
double getTox() const{return toxicity;}
void setC(double ci){c=ci;}
private:
    int from;
    int to;
double len;
double c;
double toxicity;
};


#endif //UNTITLED12_ROAD_H
