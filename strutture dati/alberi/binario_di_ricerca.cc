#include<fstream>
#include<iostream>
#include"albero.h"
using namespace std;


int main(int argc, char* argv[]){
    //controllo input
    if(argc != 2){
        cerr << "\nERRORE: input non valido\n";
        exit(0);
    }
    //apertura stream
    fstream input;
    input.open(argv[1], ios::in);
    //controllo stream
    if(input.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }
    albero T;
    albero_init(T);
    //cattura numeri
    int n;
    while(input >> n){
        insert(T, n);
    }
    stampaAlbero(T, 0);
    cout << "\n";
    stampaAlberoOrdinato(T);
    cout << "\n";


    int k; cin >> k;
    if(!search(T, k))
        cout << "\n" << k << " non è presente\n";
    albero_deinit(T);
}