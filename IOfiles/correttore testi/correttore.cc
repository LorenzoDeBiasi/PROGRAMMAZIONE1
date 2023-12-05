#include<iostream>
#include<fstream>
using namespace std;


int main(int argc, char* argv[]){
    //controlli input
    if(argc != 3){
        cerr << "\nERRORE: input non inserito correttamente\n";
        exit(0);
    }
    //apertura stream
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    //controlli stream
    if(input.fail() || output.fail()){
        cerr << "\nERRORE: stream non aperto correttamente\n";
        exit(0);
    }
    char c;
    input >> noskipws;
    bool Maiuscola = true;
    while(input >> c){
        if(!Maiuscola)
            output << c;
        if(Maiuscola){
            c = toupper(c);
            output << c;
            if(c != ' ')
                Maiuscola = false;         
        }        
        if(c == '.' || c == '!' || c == '?')
            Maiuscola = true;
    }
    //chiusura stream
    input.close();
    output.close();
}