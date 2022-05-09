//
// Created by shake on 19/12/2021.
//

#ifndef UNTITLED12_FILES_H
#define UNTITLED12_FILES_H
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Metropolis.h"
using namespace std;

class files {
    //אין צורך בשלושת הגדולים הדפולטיביים מחלקה לצורך עבודה עם קבצים
public:
    files():size(0){};
double** getMat(const char* s);
int getSize() const{return size;}
string * getCars(const char* s, int size);
private :
    int size;
};


#endif //UNTITLED12_FILES_H
