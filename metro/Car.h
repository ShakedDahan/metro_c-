#ifndef UNTITLED12_CAR_H
#define UNTITLED12_CAR_H
#include <iostream>
#include <cstdlib>

using namespace std;
//אין צורך בשלושת הגדולים הדפולטיביים מספיק טובים במחלקה זו
class Car {
public:
    Car(){name=' ';type=0;cur=0;car_number=0;};
    Car(unsigned int CarNum,int s):car_number(CarNum),cur(s),type(0),name(' '){};
    virtual unsigned int getCarNumber() const {return car_number;};
    virtual int getSection() const{return cur;};
    virtual void setSection(int sect)=0;
    virtual int getType(){return type;}
    virtual char getName(){return name;}

private:
    unsigned int car_number;
protected:
    int cur;
    int type;
    char name;
};


#endif //UNTITLED12_CAR_H
