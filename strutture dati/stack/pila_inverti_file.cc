#include<iostream>
#include<fstream>
#include"pila.h"
using namespace std;


int main(int argc, char* argv[]){
    //controllo linea di comando: main.out a.txt file2.txt
    if(argc != 3){
        cerr << "\nERRORE: input non valido\n";
        exit(0);
    }
    //creazione stream input ed output
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    //controlli stream
    if(input.fail() || output.fail()){
        cerr << "\nERRORE: stream non aperto correttamente";
        exit(0);
    }
    
    pila_init();
    int n;

    while(input >> n)
        pila_push(n);

    while(pila_top(n)){
        output << n << "\n";
        pila_pop();
    }

    pila_deinit();

    input.close();
    output.close();

}