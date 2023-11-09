#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

void Substitute(char file[], char character){
    fstream s;
    s.open(file, ios::in);
    char c;
    if(s.fail()){
        cout <<"ERRORE";
        exit(0);
    }
    while(s.get(c)){
        if(c == character)
            cout << "?";
        else
            cout << c;
    }
    s.close();
}


int main(int argc, char* argv[]){
    //controlli
    if(argc != 3){
        cerr << "ERRORE: \nModalità d'uso: ./SubsC file carattere\n";
        exit(0);
    }
    if(strlen(argv[2]) != 1){
        cerr << "ERRORE: \nCarattere inserita non valida\n";
        exit(0);
    }
    char c = *argv[2];
    
    
    Substitute(argv[1], c);
    
}
