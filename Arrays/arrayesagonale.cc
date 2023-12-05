#include<iostream>
using namespace std;

int* init(int );
void es_value(int* &, int);
void print(int*, int);
void deinit(int*);

int main(){
    int n;
    cout << "\nInserisci la dimensione dell'array: ";
    cin >> n;
    int* array = init(n);
    es_value(array, n);
    print(array, n);
}

int* init(int n){
    int* a = new int[n]; 
    return a;
}
void es_value(int* &array, int n){
    for(int i = 0; i < n; i++)
        array[i] = i*(2*i - 1);
}
void print(int* array, int n){
    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << "| " << array[i] << " |";
    cout << "\n";
}
void deinit(int* array){
    delete[] array;
}