#include<iostream>
#include<cstdlib>
using namespace std;


int* generate_numbers(int N);



int main(int argc, char* argv[]){
    //controlli
    if(argc != 2){ 
        cout << "ERRORE:\nComandi non eseguiti correttamente\n";
        return -1;        
    }
    if(atoi(argv[1]) <= 0){
        cout << "ERRORE:\nNumero inserito non valido\n";
        exit(0);        
    }


    //allocazione
    srand(time(0));
    int* array = generate_numbers(atoi(argv[1]));
    if(array == NULL){
        cout << "Errore:\nAllocazione fallita\n";
        exit(0);
    }

    //stampa
    for(int i = 0; i < (atoi(argv[1]) + 1); i++)
        cout << "| " << array[i] << " |";
    cout << "\n";


    //deallocazione
    delete[] array;


    return 0;
}



int* generate_numbers(int N){
    int* a = new (nothrow) int[N + 1];
    if(a != NULL)
        for(int i = 0; i < (N + 1); i++)
            a[i] = rand() % 100;
    return (a);
}