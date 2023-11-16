#include<iostream>
#include<cstdlib>
#include"sorting.h"
using namespace std;


void Stampa(int v[], int n);
int* Allocazione(int n);
int* Append(int* pa, int* pb, int na, int nb);

int main(int argc, char* argv[]){
    //controllo numero di parametri
    if(argc != 3){ 
        cout << "ERRORE:\nComandi non eseguiti correttamente\n";
        return -1;        
    }
    //controllo tipo dei parametri
    if(atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0){
        cout << "ERRORE:\nNumero inserito non valido\n";
        exit(0);        
    }
    srand(time(0));
    //dimensioni array
    int na = atoi(argv[1]);
    int nb = atoi(argv[2]);
    //dichiarazione e allocazione array
    int* a = Allocazione(na);
    int* b = Allocazione(nb);
    //stampa
    Stampa(a, na);
    Stampa(b, nb);
    //sorting array
    BubbleSort(a, na);
    BubbleSort(b, nb);
    //stampa
    Stampa(a, na);
    Stampa(b, nb);

    //array concatenato
    int* v = Append(a, b, na, nb);
    //Stampa
    Stampa(v, na + nb);
    //sorting
    BubbleSort(v, na + nb);
    //Stampa
    Stampa(v, na + nb);
    //deallocazione
    delete[] a;
    delete[] b;
    delete[] v;
}

void Stampa(int v[], int n){
    for(int i = 0; i < n; i++)
        cout << "| " << v[i] << " |";
    cout << "\n\n";
}
int* Allocazione(int n){
    int* v = new int[n];
    for(int i = 0; i < n; i++)
        v[i] = rand() % 10;
    return v;
}
int* Append(int* pa, int* pb, int na, int nb){
    int* v = new int[na + nb];
    for(int i = 0; i < na; i++)
        v[i] = pa[i];
    for(int j = 0; j < nb; j++)
        v[na + j] = pb[j];
    return v;
}