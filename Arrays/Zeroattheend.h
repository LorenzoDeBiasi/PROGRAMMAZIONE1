#include<iostream>
using namespace std;

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
    

