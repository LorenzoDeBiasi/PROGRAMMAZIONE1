#include<iostream>
#include<cstdlib> 
#include<time.h>
#include<cmath>
using namespace std;


//stampa
void PrintdoubleArray(const double array[], int n){
    cout << "\n ";
    for(int i = 0; i < n; i++)
        cout << "| " << array[i] << " |";
    cout << "\n";
}
void PrintArray(const int array[], int n){
    cout << "\n ";
    for(int i = 0; i < n; i++)
        cout << "| " << array[i] << " |";
    cout << "\n"; 
}



//assegnamento
void CreatedoubleArray(double array[], int n){
    for(int i = 0; i < n; i++)
        array[i] = rand()%10;
}
void CreateArray(int array[], int n){
    for(int i = 0; i < n; i++)
        array[i] = rand()%10;
}




//modifiche
void Add(int array[], int &n, int e, int p){
    if(p > n){
        cout << "\ndimensione dell'array ecceduta\n";
        return;
    }

    for(int i = n; i > p; i--)
        array[i] = array[i - 1];
    array[p] = e; 
    ++n;
}
void SwitchArray(int array[], int n){
    int temp;
    for(int i = 0; i < (n / 2); i++){
        temp = array[i];
        array[i] = array[(n - 1) - i];
        array[(n - 1) - i] = temp;        
    }
}
void moveZero(int vettore[], int n){
    //primo controllo per vedere se ci sono zei rimasti
    int control = 0;
    for(int i = 0; i < n; i++)
        if(vettore[i] != 0)
            control++;
    if(control == n)
        return;


    //controllo zeri già alla fine
    if(vettore[n - 1] == 0)
        moveZero(vettore, (n - 1));

    
    //spostamento
    else
        for(int i = (n - 1); i >= 0; i--)               //scan
            if(vettore[i] == 0)
            {                                           //verfica
                int temp = 0;                                
                for(int j = i; j < (n - 1); j++)        //spostamento
                {      
                    temp = vettore[j];
                    vettore[j] = vettore[j + 1];    
                    vettore[j + 1] = temp;
                }
                moveZero(vettore, (n - 1));
            }
}



//conversione binaria
void INTtoBIN(int vettore[8], int n, int b){
    for(int i = 0; i < 8; i++)
        vettore[i] = 0;
    if(b == 2 || b == 8)
        for(int i = 7; i >= 0; i--){
            if(n >= 0){
                vettore[i] = n % b;
                n /= b;
            }
            else return;
        }
    else{
        cerr << "base inserita non idonea";
        exit(0);
    } 
}


//Operazioni
double ProdottoScalare(double v1[], double v2[], int n){
    double res = 0;
    for (int i = 0; i < n; i++)
        res += (v1[i] * v2[i]);
    return res;
}
double Norma(double array[], int n){
    return sqrt(ProdottoScalare(array, array, n));
}
void NormalizedArray(double array[], int n){
    double N = Norma(array, n);
    for(int i = 0; i < n; i++)
        array[i] /= N;
}