#include<iostream>
using namespace std;

void PrintArray(int array[], int n){
    cout << "\n ";
    for(int i = 0; i < n; i++)
        cout << "| " << array[i] << " |";
}