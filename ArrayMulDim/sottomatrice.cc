#include<iostream>
#include<cstdlib>
#include"matrice.h"
using namespace std;


int main(){
    int r, c;
    cout << "\nInserisci le dimensioni della matrice: "; cin >> r >> c;
    int** matrice = m_init(r, c);
    srand(time(0));
    m_value(matrice, r, c);
    m_print(matrice, r, c);

    int i, j;
    do{
        cout << "\nInserisci l'elemento iniziale della sottomatrice: "; cin >> i >> j;
    }while(i < 0 || i > r || j < 0 || j > c);
    int newr, newc;
    do{
        cout << "\nOra inserisci le dimensioni della sottomatrice: "; cin >> newr >> newc;
    }while(newr > (r - i) || newc > (c - j));

    int** sottomatrice = m_init(newr, newc);
    sottom_value(matrice, sottomatrice, newr, newc, i, j);
    m_print(sottomatrice, newr, newc);



    m_deinit(matrice, r, c);
    m_deinit(sottomatrice, newr, newc); 
}