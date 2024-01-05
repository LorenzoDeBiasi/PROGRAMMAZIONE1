#include<iostream>
#include"pila.h"
using namespace std;

int main(){
    cout << "\nQuanti vagoni possiede il treno: "; 
    int n; cin >> n;
    
    pila_init();
    for(int i = 1; i <= n; i++)
        pila_push(i);
    pila_print();

    cout << "\nQuale vagone vuoi rimuovere: ";
    int choice; cin >> choice;

    int j;
    pila_top(j);
    listaPila nuovaLista = NULL;
    while(choice != j){
        pila_pop(); 
        nuovaLista = new nodoPila {j, nuovaLista};
        pila_top(j);
    }
    pila_pop();
    while(nuovaLista != NULL){
        int i = nuovaLista->value;
        pila_push(i);
        nuovaLista = nuovaLista->next;
    }
    pila_print();
}