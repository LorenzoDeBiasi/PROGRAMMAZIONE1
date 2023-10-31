#include<iostream>
#include<cstdlib>
using namespace std;
const int r = 3, c = 4, q = 3;


void Inizializza(int m[r][c]){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            m[i][j] = rand() % 10;
}
void InizializzaQuadrata(int m[q][q]){
    for(int i = 0; i < q; i++)
        for(int j = 0; j < q; j++)
            m[i][j] = rand() % 10;
}

void Stampa(int m[r][c]){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << "| " << m[i][j] << " |";
        cout << endl;   
    } 
}
void StampaQuadrata(int m[q][q]){
    for(int i = 0; i < q; i++){
        for(int j = 0; j < q; j++)
            cout << "| " << m[i][j] << " |";
        cout << endl;   
    }     
}
void StampaQuadrata(double m[q][q]){
    for(int i = 0; i < q; i++){
        for(int j = 0; j < q; j++)
            cout << "| " << m[i][j] << " |";
        cout << endl;   
    }     
}
void StampaTrasposta(int t[c][r]){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++)
            cout << "| " << t[i][j] << " |";
        cout << endl;   
    }     
}

void trasposta(int m[r][c]){
    int t[c][r];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            t[j][i] = m[i][j];
    StampaTrasposta(t);
}

int SommaTriSup(int m[q][q]){
    int s = 0;
    for(int i = 0; i < q; i++)
        for(int j = 0; j < q; j++)
            if(j >= i)
                s += m[i][j];
    return s;
}
void FiltroMedio(int m[q][q]){
    double fm[q][q];
    double n = 4.0, s = 0.0;
    for(int i = 0; i < q; i++)
        for(int j = 0; j < q; j++){
            //NORD
            if( i - 1 < 0)          
                n--;
            else    
                s += m[i - 1][j];
            //OVEST
            if( j - 1 < 0)          
                n--;
            else    
                s += m[i][j - 1];
            //SUD
            if( i + 1 > (q - 1) )   
                n--;
            else    
                s += m[i + 1][j];
            //EST    
            if( j + 1 > (q - 1) )   
                n--;
            else    
                s += m[i][j + 1];


            fm[i][j] =  (s / n);
            s = 0.0, n = 4.0;    
        }


    StampaQuadrata(fm);



}




int main(){
    srand(time(0));
    /*
    int m[r][c];
    Inizializza(m);
    Stampa(m);
    cout << endl;
    trasposta(m);
    */
    /*
    int msqr[q][q];
    InizializzaQuadrata(msqr);
    StampaQuadrata(msqr);
    cout << "\nLa somma del triangolo superiore e': " << SommaTriSup(msqr) << "\n";
    */
    int m[q][q];
    InizializzaQuadrata(m);
    StampaQuadrata(m);
    cout << endl;
    FiltroMedio(m);
}

