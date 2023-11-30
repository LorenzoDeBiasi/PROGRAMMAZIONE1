#include<iostream>
#include<cstring>
#include"coda.h"
using namespace std;

int main(){
    char nome[MAX_DIM], choice;
    init();

    do{
        //MENU' OPZIONI
        do{
            cout << "\nOpzioni disponibili:\nAggiungi persona in coda (A)  Smaltisci persona (S)  Mostra situazione (M)  Chiudi poste (C)\n";
            cin >> choice;
        }while(choice != 'A' && choice != 'S' && choice != 'M' && choice != 'C');

        //OPERAZIONI CODA

        //aggiunta
        if(choice == 'A'){
            cout << "\nInserire nome: ";
            cin >> nome; 
            //controllo omonimi prima dell'enqueue   
            if(!isinqueue(nome)){
                enqueue(nome);
                cout << "\nPersona inserita in coda\n";
            }
            else
                cout << "\nPersona già presente e quindi non rinserita\n";          
        }
        //Smaltimento
        if(choice == 'S'){
            if(dequeue() == 0)
                cout << "\nUfficio già vuoto\n";
            else
                cout << "\nPersona servita correttamente\n";
        }
        //Situazione
        if(choice == 'M'){
            char* n;
            if(first(n) == 0)
                cout << "\nNessuna persona da servire\n";
            else{
                cout << "\nDevono essere serviti in ordine:\n";
                print();
            }
        }

    }while(choice != 'C');

    deinit();
}