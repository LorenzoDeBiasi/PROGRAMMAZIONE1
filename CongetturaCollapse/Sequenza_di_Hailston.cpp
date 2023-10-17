#include<iostream>
using namespace std;


void stampa(int k){
    cout << k << "\n";
}

int Sequenza(int k){
    stampa(k);
    if(k==1)
        return 1;
    else
        if(k%2 == 0)
            Sequenza(k/2);
        else
            Sequenza(3*k+1);
}


int main(){
    int n;
    cin >> n; 
    cout << "\n"; 
    Sequenza(n);
}