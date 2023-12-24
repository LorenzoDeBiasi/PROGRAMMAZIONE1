#include<iostream>
#include"stack.h"
using namespace std;


void init(pila &x){
    x = new nodo;
    x = NULL;
}
void deinit(pila &x){
    if(x->next != NULL){
        deinit(x->next);
        delete x;
    }
}
bool nempty(const pila x){
    if(x != NULL)
        return true;
    else
        return false;
}
void add(pila &x, long v){
    nodo* tmp = new nodo;
    tmp->value = v;
    tmp->next = x;
    x = tmp;
}
bool shrink(pila &x){
    if(x != NULL){
        nodo* first = x;
        x = x->next;
        delete first; 
        return true;
    }
    else
        return false;
}
bool first(const pila x, long &n){
    if(x != NULL){
        n = x->value;
        return true;
    }
    else
        return false; 
}
void print(const pila x){
    if(x != NULL){
        cout << "| " << x->value << " |";
        print(x->next);
    }
}
