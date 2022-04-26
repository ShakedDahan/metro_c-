//
// Created by shake on 20/12/2021.
//

#include "City.h"

void City::run(const char *s, const char *s2) {
    files f;
    double** mat;
    string *cars;
    mat=f.getMat(s);
    cars=f.getCars(s2,f.getSize());
    Metropolis m(mat,f.getSize());
    m.setCars(cars,f.getSize());
    m.Ride(f.getSize());
}
