#include<fstream>
#include<iostream>
#include"lista.h"
using namespace std;

int main(int argc, char* argv[]){
    //CONTROLLO INPUT
    if(argc != 2){
        cerr << "\nERRORE: input a linea di comando non valido\n";
        exit(0);
    }

    //APERTURA STREAM
    fstream file;
    file.open(argv[1], ios::in);
    //CONTROLLO STREAM
    if(file.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }

    //ALLOCAZIONE PRIMO NODO DELLA LISTA
    node x = new node_ls;
    file >> x->value;
    x->next = NULL; 
    //ALLOCAZIONE NODI
    char ns[10];
    while(file >> ns)
        insert_last(x, atoi(ns));

    //STAMPA ORDINATA DELLA LISTA
    print(x);
    cout << "\n\n";
    
    x = primizzaLista(x);


    cout << "\n";
    print(x);
    cout << "\n";

    //DEALLOCAZIONE LISTA
    deinit(x);

    
}