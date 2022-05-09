//
// Created by shake on 19/12/2021.
//

#include "files.h"

using namespace std;

double **files::getMat(const char *s) {
    stringstream l;
    string line,lline;
    int size,count=0,lcount=0;
    ifstream myfile (s);
    if (myfile.is_open())
    {
        getline (myfile,line);
        l<<line;
        l>>size;
        this->size=size;
        double** mat;
        mat= new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
        }
        while ( getline (myfile,line) ){
            stringstream d(line);
            stringstream c(line);
            while(!c.eof()){
                c>>lline;
                lcount++;
            }
            if(lcount!=size){
                cerr<<"ERROR: Invalid input.";
                return 0;
            }
            lcount=0;
            for(int i=0;i<size;i++){
                d>>mat[i][count];

            }
            count++;
        }
        if(count!=size)
            cerr<<"Invalid input.";
        myfile.close();
        return mat;
    }
    else cerr<<"ERROR: Invalid input."<<endl;
    return 0;
}

string* files::getCars(const char *s,int size) {
    string *line=new string[size];
    int i=0;
    ifstream myfile(s);
    if (myfile.is_open()) {
        while (i<size) {
            getline(myfile, line[i]);
            i++;
        }
        return line;
    }
    else{
        cerr<<"ERROR: Invalid input."<<endl;
    }
    myfile.close();
    return NULL;
}

