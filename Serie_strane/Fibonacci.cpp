#include<iostream>
using namespace std;


int Successione(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Successione(n - 1) + Successione(n - 2);
}


int main(){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
        cout << "| " << Successione(i) << " |";
    cout << "\n";  
}