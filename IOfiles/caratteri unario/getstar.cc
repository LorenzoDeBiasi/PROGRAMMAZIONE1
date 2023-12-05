#include<fstream>
#include<iostream>
using namespace std;


int main(int argc, char* argv[]){
    //controlli input
    if(argc != 2){
        cerr << "\nERRORE: input non valido\n";
        exit(0);
    }
    //apertura stream
    fstream file;
    file.open(argv[1], ios::in);
    //controllo stream
    if(file.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }
    char c;
    int n = 0;
    file >> noskipws;
    int somma = 0;
    int div = 0;
    while(file >> c){
        if(c == '*')
            n++;
        else if(c == ' ' || c == '\n'){
            somma += n;
            div++;
            n = 0;
        }
    }
    file.close();
    float media = (float)somma / div;
    
    //riapertura file in append
    file.open(argv[1], ios::app);
    //controllo stream
    if(file.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }
    file << "\n";
    cout << media;
    for(int i = 0; i < (int)media; i++)
        file << '*';
    file.close();



}