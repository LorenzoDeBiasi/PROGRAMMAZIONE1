#include<iostream>
#include<cstring>
#include"pila.h"
using namespace std;


int main(){
    char sequenza[50];
    cin >> sequenza;

    //inizializzazione pila
    pila_init();
    //creazione pila

    for(int i = 0; i < strlen(sequenza); i++){
        if(sequenza[i] != '(' && sequenza[i] != ')' && sequenza[i] != ' '){
            cerr << "\nERRORE: input non accettabile\n";
            exit(0);
        }
        if(sequenza[i] == '(')
            pila_push(0);
        else if(sequenza[i] == ')')
            pila_push(1);
    }
    
    int n; int counter_o = 0; int counter_c = 0;
    while(pila_top(n)){
        if(n == 0)//parentesi aperte
            counter_o++;
        if(n == 1)//parentesi chiuse
            counter_c++;
        
        
        //se le parentesi aperte cominciano ad essere di più,
        //il numero può tornare anche ad essere uguale, ma non sono bilanciate
        //deve aumentare prima il numero di quelle chiuse
        //LO STACK VIENE LETTO DA TOP A PARTIRE DALL'ULTIMO NUMERO INSERITO
        if(counter_c < counter_o){
            cout << "\nParentesi non bilanciate\n";
            return 0;
        }
        pila_pop();
    }

    pila_print();

    if(counter_c != counter_o)
        cout << "\nParentesi non bilanciate\n";
    else
        cout << "\nParentesi bilanciate\n";

    pila_deinit();
}