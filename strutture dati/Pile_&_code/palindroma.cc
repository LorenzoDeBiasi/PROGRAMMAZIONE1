#include<iostream>
#include"pila.h"
#include"coda.h"
using namespace std;


int main(){
    char p[100];
    cin >> p;
    pila_init();
    coda_init();

    int np = 0;

    for(int i = 0; p[i] != '\0'; i++){
        pila_push(p[i]);
        coda_enqueue(p[i]);
        np++;
    }
    int n, m;
    char* risposta = " è palindroma\n";

        for(int i = 0; i < np + 1; i++){
            pila_top(n);
            coda_first(m);
            if(n != m)
                risposta = " non è palindroma\n";
            pila_pop();
            coda_dequeue();
        }
    
    cout << p << risposta;
}