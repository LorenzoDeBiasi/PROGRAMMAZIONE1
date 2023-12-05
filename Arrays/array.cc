#include<iostream>
using namespace std;
#define MAX_DIM 100

bool Palindromo(int*, int , int i = 0);

int main(){
    int dim;
    do{
        cout << "\nInserisci la dimensione dell'array: ";
        cin >> dim;
    }while(dim > MAX_DIM);
    
    int array[dim];
    cout << "\nInserisci l'array: ";
    for(int i = 0; i < dim; i++)
        cin >> array[i];

    if(Palindromo(array, dim))
        cout << "\nQuesto array è palindromo\n";
    else
        cout << "\nQuesto array non è palindromo\n";
}


bool Palindromo(int* array, int n, int i){
    if(i < (n/2)){
        if(array[i] == array[n - 1 - i])
            return Palindromo(array, n, i + 1);
        else
            return false;        
    }
}