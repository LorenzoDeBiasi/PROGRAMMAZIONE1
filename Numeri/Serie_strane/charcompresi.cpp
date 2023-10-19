#include<iostream>
using namespace std;

void Cbetween(char a, char b){
    if(a == b)
        return;
    if(a > b)
        Cbetween(b, a);
    else{
        cout << a << " ";
        Cbetween(a + 1, b);
    }
}

int main(){
    char a, b;
    cin >> a >> b;
    Cbetween(a, b);
}