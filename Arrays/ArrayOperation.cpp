#include"vettore.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    double v1[n], v2[n];
    srand(time(0));
    CreatedoubleArray(v1, n);
    //CreatedoubleArray(v2, n);

    PrintdoubleArray(v1, n);
    //PrintdoubleArray(v2, n);

    /*if(ProdottoScalare(v1, v2, n) == 0)
        cout << "I due vettori sono perpendicolari\n";
    else
        cout << "I due vettori non sono perpendicolari\n";
    */
    
    /*cout << "\nLa norma di v1 è: " << Norma(v1, n) << "\nmentre il vettore normalizzato diventa: \n";
    NormalizedArray(v1, n);
    PrintdoubleArray(v1, n);
    */

   Add(v1, n, 11, (n / 2));
   PrintdoubleArray(v1, n);
}
