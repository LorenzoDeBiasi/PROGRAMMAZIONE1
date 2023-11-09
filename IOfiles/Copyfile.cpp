#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


void copyfile(char *files[]){
    fstream Input;
    fstream Output;

    //apertura stream
    Input.open(files[1], ios::in);
    Output.open(files[2], ios::out);



    //controlli
    if(Input.fail()){
        cerr << "ce sta u problema\n";
        exit(0);
    }
    if(Output.fail()){
        cerr << "ce sta u problema\n";
        exit(0);
    } 


    //trascrittura
    char c;    
    while(!Input.eof()){
        Input.get(c);
        Output << c;
    }


    //chiusura stream   
    Input.close();
    Output.close();       
}




int main(int argc, char* argv[]){

    //controllo presenza input ed output
    if(argc < 3){
        cerr << "ERRORE: \nfile mancanti \nModalità d'uso: ./Pf file1 file2\n";
        exit(0);
    }

    copyfile(argv);

    return 0;
}