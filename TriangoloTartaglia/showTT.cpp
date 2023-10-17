#include<iostream>
#include<cmath>
#include"coefficienti.h"
using namespace std;



int counter = 1;


void calcola(int r){

    

    if(r < 1)
        return ;


    
    for (int i = r; i > 0; i--){
        cout << " ";
    }
    
    

    //na bea passada delle colonne che 'e va da 1 a n
    for (int c = 1; c <= counter; c++)
        cout << " " << coefficiente(counter, c) << " ";

    
    //mo famo la riga dopo
    cout << "\n";


    counter++;
    calcola(r-1);

}


int main(){
    int n;
    cin>>n;
    calcola(n);
}
