
#ifndef UNTITLED14_GENERIC_MAP_H
#define UNTITLED14_GENERIC_MAP_H
#include <iostream>
using namespace std;
template<class T,class E>
struct map {
    T key;
    E value;
    map<T,E> *next;
};
template<class T,class E>
class generic_map {
    public:
        generic_map<T,E>(){head=NULL;last=NULL;count=0;}
        void insert(T k, E val);
        void print() const;
        map<T,E>* search(T k)const;
        void del(T k);
        void clear();
        int getCount(){return count;}
private:
    map<T,E> *head;
    map<T,E> *last;
    int count;


};
template<class T, class E>
void generic_map<T, E>::print()const {
    map<T,E> *m=head;
    while(m!=NULL){
        cout<<m->key<<" "<<m->value<<endl;
        m=m->next;
    }
}
template<class T, class E>
void generic_map<T, E>::clear(){
    while(head){
        del(head->key);
    }


}
template<class T, class E>
void generic_map<T, E>::del(T k){
    map<T,E> *h=head;
    map<T,E> *t=NULL;
    if(h->key==k){
        t=h;
        head=h->next;
        delete t;
        count--;
        return;
    }
    while(h->next){
        if(h->next->key==k) {
            t=h->next;
            h->next = h->next->next;
            delete t;
            count--;
            return;
        }
        h=h->next;
    }
}
template<class T, class E>
map<T,E>* generic_map<T, E>::search(T k) const{
    map<T,E> *h=head;
    while(h){
        if(h->key==k)
            return h;
        h=h->next;
    }
    return NULL;
}
template<class T, class E>
void generic_map<T, E>::insert(T k, E val) {
    if(!head) {
        head=new map<T,E>;
        head->value = val;
        head->key = k;
        head->next=NULL;
        last=head;
        count++;
        return;
    }
    else{
        map<T,E> *h=head;
        if(h->key>k){
            last=new map<T,E>;
            last->value = val;
            last->key = k;
            last->next=h;
            head=last;
            count++;
            return;
        }
        while(h->next){
            if(h->key==k) {
                h->value=val;
                return;
            }
            else if(h->key<k&&h->next->key>k){
                last=new map<T,E>;
                last->value = val;
                last->key = k;
                last->next=h->next;
                h->next=last;
                count++;
                return;
            }
            h=h->next;
        }
        last=new map<T,E>;
        last->value = val;
        last->key = k;
        last->next=NULL;
        h->next=last;
        count++;
    }

}

#endif //UNTITLED14_GENERIC_MAP_H
