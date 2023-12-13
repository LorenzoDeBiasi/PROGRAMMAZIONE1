#include<iostream>
using namespace std;

int calcola_ric(int, int);
int main(){
    int x, y;
    cin >> x >> y;
    cout << calcola_ric(x, y) << "\n";
}
int calcola_aux(int , int , int );
int calcola_ric(int x, int y){
    return calcola_aux(x, y, 0);
}
int calcola_aux(int x, int y, int i){
    if(x < y)
        return i;
    else{
        return calcola_aux(x - y, y, i + 1);
    }
}
