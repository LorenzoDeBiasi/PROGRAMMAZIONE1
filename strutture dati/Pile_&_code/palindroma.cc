#include<iostream>
#include"pila.h"
#include"coda.h"
using namespace std;


int main(){
    char p[100];
    char q[100];
    cin >> p >> q;
    pila_init();
    coda_init();

    int np = 0;
    int nq = 0;

    for(int i = 0; p[i] != '\0'; i++){
        pila_push(p[i]);
        np++;
    }

    for(int i = 0; q[i] != '\0'; i++){
        coda_enqueue(q[i]);
        nq++;
    }
    int n, m;
    char* risposta = " sono palindrome\n";
    if(np == nq){
        for(int i = 0; i < np + 1; i++){
            pila_top(n);
            coda_first(m);
            if(n != m)
                risposta = " non sono palindrome\n";
            pila_pop();
            coda_dequeue();
        }
    }
    else
        risposta = " non sono palindrome\n";
    
    cout << p << " e " << q << risposta;
}