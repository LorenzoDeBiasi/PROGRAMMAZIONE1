#include<iostream>
#include<fstream>
using namespace std;

int* Allocazione();


int main(int argc, char* argv[]){
    //controlli  ./a.out file N
    if(argc != 4){ 
        cout << "ERRORE:\nComandi non eseguiti correttamente\n";
        return -1;        
    }
    if(atoi(argv[2]) <= 0){
        cout << "ERRORE:\nNumero inserito non valido\n";
        exit(0);        
    }



    int* array = Allocazione(argv[1], atoi(argv[3]));



    for(int i = 0; i < atoi(argv[2]); i++)
        cout << array[i];

    return 0;
}




int* Allocazione(char file[], int M){
    fstream Archivio;
    Archivio.open(file, ios::in);
    char* cn;
    int i = 0;


    int* a = new int[M];

    while(Archivio.getline(cn, 4)){   
        a[i] = atof(cn);
        i++;
    }
    for(int j = i; j < M; j++)
        a[j] = -273;
    return a;
}