
#include<iostream>
using namespace std;



bool findPrime(int n){
    for(int i = 2; i <= (n/2); i++)
        if(n % i == 0)
            return false;
    return true;
}


void showPrimes(int n){
    for(int i = 1; i < n; i++) {       
        bool prime = true;     
        for(int j = 2; j < i; j++)         
            if( i % j == 0){
                j = i;
                prime = false;
            }
        if(prime == true)
            cout << "| " << i << " |";             
    }
}