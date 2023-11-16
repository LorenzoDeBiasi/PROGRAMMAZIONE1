#include<iostream>
#include<cstdlib>
using namespace std;


struct lista{
    int dato;
    lista* next;
    void Assegnadato(){cin >> dato;}
};



int main(){
    lista* x = new lista;
    x->Assegnadato();
    x->next = NULL;

}