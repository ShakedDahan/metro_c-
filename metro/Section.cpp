//
// Created by shake on 16/12/2021.
//

#include <sstream>
#include "Section.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "SportsCar.h"
#include "MASERATI.h"

void Section::removeCar(unsigned int CarNum) {
    if (!head) { return; }
    Cars* temp = head;
    if (temp->data->getCarNumber()== CarNum) {
        head = head->next;
        delete temp;
        count--;
        return;
    }
    while (temp->next && temp->next->data->getCarNumber() != CarNum) {
        temp = temp->next;
    }
    if (temp->next) {
        Cars* del = temp->next;
        temp->next = del->next;
        delete del;
        count--;
    }
}

void Section::insertCar(unsigned int CarNum, int pos,char t) {
    Car *c1=NULL;
    if(t=='F')
        c1=new FamilyCar(CarNum,pos);
    else if(t=='L')
        c1=new LuxuryCar(CarNum,pos);
    else if(t=='S')
        c1=new SportsCar(CarNum,pos);
    else
        c1= new MASERATI(CarNum, pos);
    head=new Cars(c1,head);
    count++;
}

void Section::insertNeighbor(int pos) {
    Section* s1=new Section(pos);
    Nhead=new Neighbors(s1,Nhead);
    Ncount++;
}
Section::Section(int i) : id(i), count(0), Ncount(0), head(NULL), Nhead(NULL) {

}
int Section::getn(int i)const {
    Neighbors* temp=Nhead;
    i--;
    while(i>0) {
        temp = temp->next;
        i--;

    }
    return temp->data->getId();
}

Section::Section(int id, Cars *head,Neighbors *nhead) : id(id), count(0),
                                                                                                  Ncount(0),head(NULL),Nhead(NULL){
    while(head!=NULL) {
        insertCar(head->data->getCarNumber(), head->data->getSection(),head->data->getName());
        head = head->next;
    }
    while(nhead!=NULL) {
        insertNeighbor(nhead->data->getId());
        nhead=nhead->next;
    }
    }
string Section::printCars()const {
    Cars *c=head;
    string st="";
    while(c!=NULL){
        if(c->data->getCarNumber()!=10)
        st+=(c->data->getCarNumber())+'0';
        else
            st+="01";
        st+=c->data->getName();
        st+=" ";
        c=c->next;
    }
    std::reverse(st.begin(), st.end());
    return st;
}
Section::Cars::Cars(Car *d, Section::Cars *n) {
    data=d;
    next=n;

}

Section::Neighbors::Neighbors(Section* d, Section::Neighbors *n) {
    data=d;
    next=n;
}
