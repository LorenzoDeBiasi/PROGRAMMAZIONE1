#include<iostream>
#include<cmath>
using namespace std;

//non funziona più

double Pi(int N, double i = 1){   

    if(i < N)
        return (1 / ( (i)*(i) ) + Pi(N, i + 1)); 
}


//dfgvsg


int main(){
    int k;
    cin >> k;
    cout << Pi(k) << "\n";
}