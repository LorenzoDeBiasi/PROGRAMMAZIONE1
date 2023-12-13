#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);

int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {7, 7, -5, 9, -10, 1};
    int numeroAsteroidi = 6;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}
bool push_aux (lista l, int n) {

	bool risultatoOperazione;
	lista nuovoNodo = new nodo;
	if (nuovoNodo==NULL) {
		risultatoOperazione = false;
	}
	else {
		nuovoNodo->value = n;
		nuovoNodo->next = l;
		l = nuovoNodo;
		risultatoOperazione = true;
	}
	return risultatoOperazione;
}

int controllo(int n){
    int N = n; 
    pop(); top(n);
    int res;
    if(n < 0)
        res = (N > controllo(n)) ? N : controllo(n);
    else
        return N;
    //ottenuto il primo res
    if()
}




// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    init();
    //creo la lista con tutti i meteoriti
    for(int i = 0; i < numeroAsteroidi; i++)
        push(asteroidi[i]);
    //li elimino a dovere, in modo da avere anche il numeroAsteroidirimasti
    //da usare per allocare il nuovo array da ritornare, poi faccio il delete
    //della lista e infine faccio il return
    lista aux = new nodo;
    //aggiungo la testa, se concorde col segno, ad aux
    int n; top(n);
    for(; n < 0; pop()){
        push_aux(aux, n);
        top(n);
    }
    while(!vuota()){
        //il primo è sicuramente negativo
        if(controllo(n))
            push_aux(aux, n);
    }
}
