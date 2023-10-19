#include<iostream>
#include"Primes.h"
using namespace std;

int main(){
    int n; 
    cin >> n;

    /*for (int i = 1; i <= (n/2); i++){
        if(findPrime(i) && findPrime(n - i))
            cout << i  << " + " << (n - i) << " = " << n << endl;
    }*/

    Fattorizzazione(n);
    


}