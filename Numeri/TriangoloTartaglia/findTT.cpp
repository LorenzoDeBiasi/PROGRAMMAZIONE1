#include<iostream>
#include<cmath>
#include"coefficienti.h"
using namespace std;

int main(){
    int r, c;
    
    do{
        do{
            cin >> r >> c;
            //la riga n contiene i coefficienti di un binomio alla n-1. Mi dispiace
        }while (r < c || r < 0 || c < 1);
        
        cout << coefficiente(r, c) << "\n";  
        
    } while (true);
    


}



