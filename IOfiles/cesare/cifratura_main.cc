#include<fstream>
#include<iostream>
#include"cifratura.h"
using namespace std;

int main(int argc, char const *argv[]){
    //input ./a.out file_lettura file_scrittura chiave
    
    
    //controlli input
    if(argc != 4){
        cerr << "\nERRORE: numero di input non idoneo\n";
        exit(0);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    //controlli stream
    if(input.fail() || output.fail()){
        cerr << "\nERRORE: apertura stream non riuscita\n";
        exit(0);
    }
    
    
    char choice;
    do{
        cout << "\nVuoi cryptare (c) o decryptare (d) il messaggio? "; 
        cin >> choice;
    }while(choice != 'c' && choice != 'd');

    
    char stringa[30];
    int chiave = atoi(argv[3]);
    while(!input.eof()){
        input >> stringa;
        if(choice == 'c'){
            crypt(stringa, chiave);
            output << stringa << " ";
        }
            
        else if(choice == 'd'){
            decrypt(stringa, chiave);
            output << stringa << " ";
        }
            
    }
    

    input.close();
    output.close();
    return 0;
}
