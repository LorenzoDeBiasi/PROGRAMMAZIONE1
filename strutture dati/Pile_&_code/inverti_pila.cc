#include<iostream>
#include<fstream>
#include"pila.h"
#include"coda.h"
using namespace std;


int main(int argc, char* argv[]){
    //controlli input
    if(argc != 2){
        cerr << "\nERRORE: input non valido\n";
        exit(0);
    }
    //apertura stream
    fstream input;
    input.open(argv[1], ios::in);
    //controlli stream
    if(input.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(1);
    }
    //inizializzazione coda
    coda_init();
    //inizializzazione pila
    pila_init();

    //riempimento coda
    int n;
    while(input >> n)
        pila_push(n);
    //chiusura stream
    input.close();

    //stampa pila
    pila_print();
    cout << "\n";
    
    //riempimento coda
    while(pila_top(n)){
        coda_enqueue(n);
        pila_pop();
    }
    //ririempimento pila
    while(coda_first(n)){
        pila_push(n);
        coda_dequeue();
    }

    //stampa pila
    pila_print();


    coda_deinit();
    pila_deinit();
}