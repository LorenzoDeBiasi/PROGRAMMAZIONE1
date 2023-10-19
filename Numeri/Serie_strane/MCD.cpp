#include<iostream>
using namespace std;

int MCD(int a, int b){
    if(b == 0)
        return a;
    return MCD(b, a % b);
}


int main(){
    int m, n;
    cin >> m >> n;
    cout << MCD(m, n) << endl;
}