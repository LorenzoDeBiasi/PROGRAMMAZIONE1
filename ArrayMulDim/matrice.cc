#include<iostream>
#include<cstdlib>
#include"matrice.h"
using namespace std;

int** m_init(int r, int c){
    int** a = new int*[r];
    for(int i = 0; i < r; i++)
        a[i] = new int[c];
    return a;
}
void m_value(int** &m, int r, int c){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            m[i][j] = rand() % 10;
}
void sottom_value(int** m, int** &sottom, int newr, int newc, int coor_r, int coor_c){
    for(int i = coor_r; i < (newr + coor_r); i++)
        for(int j = coor_c; j < (newc + coor_c); j++)
            sottom[i - coor_r][j - coor_c] = m[i][j];
}
void m_print(int** m, int r, int c){
        for(int i = 0; i < r; i++){
            cout << "\n";
            for(int j = 0; j < c; j++)
                cout << "| " << m[i][j] << " |";
        }
        cout << "\n";
}
void m_deinit(int** m, int r, int c){
    for(int i = 0; i < r; i++)
        delete[] m[i];
    delete[] m;
}