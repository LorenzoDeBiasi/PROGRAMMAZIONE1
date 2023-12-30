#include<iostream>
#include"pila_1.h"
using namespace std;

int static statusP1 = 0;
int static lengthP1;

int static statusP2 = 0;
int static lengthP2;

int* p1 = NULL;
int* p2 = NULL;


void init(int dim){
    p1 = new int[dim];
    p2 = &(p1[dim - 1]);  
    lengthP1 = dim;
    lengthP2 = dim;
}
bool pushP1(int valore){
    if(statusP1 < lengthP1){
        p1[statusP1] = valore;
        statusP1++;
        if(statusP1 > lengthP1 - statusP2)
            statusP2--;
        return true;
    }
    return false;
}
bool pushP2(int valore){
    if(statusP2 < lengthP1){
        p2[-statusP2] = valore;
        statusP2++;
        if(statusP2 > lengthP1 - statusP1)
            statusP1--;
        return true;
    }
    else
        return false;
}
bool topP1(int& valore){
    if(p1 != NULL){
        valore = p1[statusP1 - 1];
        return true;    
    }
    else
        return false;
}
bool topP2(int& valore){
    if(p2 != NULL){
        valore = p2[-(statusP2 - 1)];
        return true;    
    }
    else
        return false;
}
bool popP1(){
    if(p1 != NULL){
        p1[statusP1 - 1] = 0;
        statusP1--;
        return true;
    }
    else
        return false;
}
bool popP2(){
    if(p2 != NULL){
        p2[-(statusP2 - 1)] = 0;
        statusP2--;
        return true;
    }
    else
        return false;
}
void deinit(){
    delete[] p1;
    p1 = NULL;
    p2 = NULL;
}
void print(){
    for(int i = 0; i < lengthP1; i++)
        cout << "| " << p1[i] << " |";
    cout << "\n";
}