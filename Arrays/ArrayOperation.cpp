#include"vettore.h"
#include"sorting.h"
#include"searching.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;



int main(){
    int n, e, p;
    cin >> n;
    double v1[n];

    
    CreatedoubleArray(v1, n); 
    PrintdoubleArray(v1, n);
    /*
    cout << "\ninserisci un nuovo elemento e la sua posizione: \n";
    cin >> e >> p;

    Add(v1, n, e, p);
    PrintArray(v1, n);
    */








   //PrintdoubleArray(v2, n);

    
    
    
    /*if(ProdottoScalare(v1, v2, n) == 0)
        cout << "I due vettori sono perpendicolari\n";
    else
        cout << "I due vettori non sono perpendicolari\n";
    */


    
    cout << "\nLa norma di v1 è: " << Norma(v1, n) << "\nmentre il vettore normalizzato diventa: \n";
    NormalizedArray(v1, n);
    PrintdoubleArray(v1, n);
    

}
