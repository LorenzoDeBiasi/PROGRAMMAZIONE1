#include<fstream>
#include<iostream>
#include"lista.h"
using namespace std;

int main(int argc, char* argv[]){
    //controlli input
    if(argc != 2){
        cerr << "\nERRORE: input a linea di comando non valido\n";
        exit(0);
    }

    fstream file;
    file.open(argv[1], ios::in);
    //controlli stream
    if(file.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }

    node x = new node_ls;
    file >> x->value;
    x->next = NULL; 

    while(!file.eof()){
        node tmp = new node_ls;
        
        char ns[10];
        file >> ns;

        tmp->value = atoi(ns);
        tmp->next = NULL;
        insert_node(x, tmp);
    }

    print(x);

    deinit(x);
}