#include<iostream>
#include<cmath>
using namespace std;

void inverti(int *n, int v);

int main(){
    int number;
    cin >> number;
    int *N = &number;



    int i = *N, volte = 0;
    while(i > 1){
        volte++;
        i /= 10;
    }


    inverti(N, volte);
    cout << "\n" << *N << "\n";
}


void inverti(int *n, int v){
    int num = 0;
    for(int i = 1; i <= v; i++){
        num += (*n % 10)*pow(10, (v - i));
        *n /= 10;
    }
    *n = num;
}