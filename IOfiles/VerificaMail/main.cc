#include<iostream>
#include<fstream>
#include"isamail.h"
using namespace std;


int main(int argc, char* argv[]){
    //controlli input
    if(argc != 3){
        cerr << "\nERRORE: input non corretto\n";
        exit(0);
    }


    fstream parole, stati;
    parole.open(argv[1], ios::in);

    //controllo stream
    if(parole.fail()){ 
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }

    char p[100];
    while(!parole.eof()){

        //archivio stati
        stati.open(argv[2], ios::in);
        //controllo archivio
        if(stati.fail()){
            cerr << "\nERRORE: stream non aperto correttamente\n";
            exit(0);
        }

        parole >> p;
        if(address(p, stati))
            cout << "\nPotenziale indirizzo mail: " << p << "\n ";
        
        stati.close();
    }
    parole.close();
}