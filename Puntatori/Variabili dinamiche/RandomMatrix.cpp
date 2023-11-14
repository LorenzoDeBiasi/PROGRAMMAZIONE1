#include<iostream>
#include<cstdlib>
using namespace std;


int** generate_matrix(int R, int C);



int main(int argc, char* argv[]){
    //controlli
    if(argc != 3){ 
        cout << "ERRORE:\nComandi non eseguiti correttamente\n";
        return -1;        
    }
    if(atoi(argv[1]) <= 0 || argv[2] <= 0){
        cout << "ERRORE:\nNumero inserito non valido\n";
        exit(0);        
    }


    //allocazione
    srand(time(0));
    int** array = generate_matrix(atoi(argv[1]), atoi(argv[2]));


    //stampa
    for(int i = 0; i < atoi(argv[1]); i++){
        for(int j = 0; j < atoi(argv[2]); j++)
            cout << "| " << array[i][j] << " |";     
        cout << "\n";
    }


    //deallocazione
    for(int i = 0; i < atoi(argv[1]); i++)
        delete[] array[i];
    delete[] array;


    return 0;
}



int** generate_matrix(int R, int C){

    //una matrice è un array di puntatori
    int** r = new int*[R];

    for(int i = 0; i < (R); i++)
        r[i] = new int[C];

    for(int i = 0; i < (R); i++)
        for(int j = 0; j < (C); j++)
            r[i][j] = rand() % 100;

    return r;
}