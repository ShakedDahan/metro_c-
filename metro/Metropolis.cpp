
#include "Metropolis.h"
Metropolis::Cars::Cars(Car *d, Metropolis::Cars *n) {
    data=d;
    next=n;
}

Metropolis::Sections::Sections(Section *d, Metropolis::Sections *n) {
    data=d;
    next=n;
}
Metropolis::Roads::Roads(Road *d, Metropolis::Roads *n) {
    data=d;
    next=n;
}
void Metropolis::insertCar(int CarNum, int pos,char t) {
    Car *c1=NULL;
    if(t=='F')
        c1=new FamilyCar(CarNum,pos);
    else if(t=='L')
        c1=new LuxuryCar(CarNum,pos);
    else if(t=='S')
        c1=new SportsCar(CarNum,pos);
    else
        c1= new MASERATI(CarNum, pos);
    map.insert(CarNum,pos);
    CarsHead=new Cars(c1,CarsHead);
    CarsCount++;
}

void Metropolis::insertSection(const Section& pos) {
    Section* s1;
    s1=new Section(pos.id,pos.head,pos.Nhead);
    SectionHead=new Sections(s1,SectionHead);
    SectionCount++;
}
void Metropolis::insertRoad(double len,int from,int to,int c) {
    Road* r1=new Road(len,from,to,c);
    RoadHead=new Roads(r1,RoadHead);
    RoadCount++;
}

void Metropolis::incRoad(int from, int to,int t) {
    Roads *temp=RoadHead;
    while(temp!=NULL){
        if(temp->data->getFrom()==from&&temp->data->getTo()==to) {
            (*(temp->data)).setC(t);
            (*(temp->data))++;
        }
        temp=temp->next;
    }
}

void Metropolis::Ride(int size) {
    Cars *temp = CarsHead;
    Sections *p=SectionHead;
    Sections *s=SectionHead;
    int to,r,times;
    cin>>times;
    for(int i=0;i<times;i++) {
        while (temp != NULL) {
            while (p->data->getId() != temp->data->getSection()) {
                p = p->next;
            }
            if(temp->data->getName()=='F') {
                if (p->data->getNumOfNeighbros() > 0)
                r = rand() % ((p->data->getNumOfNeighbros() - 0) + 1) + 0;
                else
                    r=0;
            }
            else if(temp->data->getName()=='L') {
                r = rand() % ((1 - 0) + 1) + 0;
                if (r!=0) {
                    if (p->data->getNumOfNeighbros() > 0)
                    r = rand() % ((p->data->getNumOfNeighbros() - 1) + 1) + 1;
                    else
                        r=0;
                }
            }
            else if(temp->data->getName()=='S'||temp->data->getName()=='M') {
                if (p->data->getNumOfNeighbros() > 0)
                    r = rand() % ((p->data->getNumOfNeighbros() - 1) + 1) + 1;
                else
                    r = 0;
            }
            if (r != 0) {

                p->data->removeCar(temp->data->getCarNumber());
                to = p->data->getn(r);
                while (s->data->getId() != to)
                    s = s->next;
                s->data->insertCar(temp->data->getCarNumber(), s->data->getId(),temp->data->getName());
                incRoad(temp->data->getSection(), s->data->getId(),temp->data->getType());
                temp->data->setSection(s->data->getId());
            }
            temp = temp->next;
            s = SectionHead;
            p = SectionHead;
        }
        temp=CarsHead;
    }
    printTox(size);
    printCars(size);
        }



Section * Metropolis::getSection(int cur) {
    Sections *temp=SectionHead;
    while(temp!=NULL){
        if(temp->data->getId()==cur)
            return temp->data;
        temp=temp->next;
    }
    return NULL;
}

Metropolis::Metropolis(double **graph, unsigned int size) {

        Section *s;
        CarsCount = 0;
        SectionCount = 0;
        RoadCount = 0;
        RoadHead=NULL;
        CarsHead=NULL;
        SectionHead=NULL;
        for (unsigned int i = 0; i < size; i++) {
            s=new Section(i+1);
            for (unsigned int j = 0; j < size; j++) {
                if (graph[j][i] != 0) {

                    s->insertNeighbor(j+1);
                    insertRoad(graph[j][i], i+1, j+1, 0);
                }
            }
            insertSection(*s);


        }

    }

void Metropolis::setCars(string* st,int cu) {
    for(int i=0;i<cu;i++) {
        st[i] = st[i].substr(2);
        if (!st[i].empty()) {
            stringstream s(st[i]);
            string car;
            while (!(s.eof())) {
                s >> car;
                insertCar(atoi(car.substr(1).c_str()), i+1,car[0] );
                getSection(i+1)->insertCar(atoi(car.substr(1).c_str()), i+1,car[0]);
            }
        }
    }
}

void Metropolis::printTox(int size) {
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++) {
            if(j+1==size)
            cout << getToxRoad(i, j);
            else
                cout << getToxRoad(i, j) << " ";
        }
        cout<<endl;
        }

}

void Metropolis::printCars(int size) {
    string st;
for(int i=1;i<size+1;i++)
{
    cout<<i<<":";
    st=getSection(i)->printCars();
    cout<<st;
    cout<<endl;
}

}

double Metropolis::getToxRoad(int from, int to) {
    Roads *r=RoadHead;
    while(r!=NULL){
        if(r->data->getTo()==to&&r->data->getFrom()==from)
            return r->data->getTox();
        r=r->next;
    }
    return 0;
}



