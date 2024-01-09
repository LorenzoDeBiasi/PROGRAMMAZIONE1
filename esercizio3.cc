#include <iostream>
#include "lista.h"

using namespace std;

const int POS_AL_SECONDO = 2;
const int DIM_COLORI = 3;
const int MAX_BAMBINI = 10;

const char* nomi[24] = {"Luca", "Giulia", "Marco", "Sophia", "Alessandro", "Isabella", "Giovanni", "Emily", "Matteo", "Olivia", "Francesco", "Liam", "Chiara", "Elena", "Roberto", "Mia", "Lorenzo", "Emma", "Federico", "Eva", "Antonio", "Lucas", "Maria", "Carlos"};

const color colori[DIM_COLORI] = {rosso, blu, giallo};

// Inserire QUI sotto la dichirazione delle funzioni coloraPartecipante e cerca.
lista cerca(lista L, char* v);
lista coloraPartecipante(lista L, int k, int i);
// Inserire QUI sopra la dichirazione delle funzioni coloraPartecipante e cerca.

int main() {
    lista cerchio = NULL;

    unsigned int seed = time(NULL);
    // Commentare la riga sotto per non avere sempre lo stesso seed
    seed = 1703945587;
    std::cout << "Seed: " << seed << std::endl;
    srand(seed);
    
    int numero_bambini = rand() % MAX_BAMBINI + 2;
    for (int i = 0; i < numero_bambini; i++) {
        char* nome = (char*)nomi[rand() % 18];
        if (cerca(cerchio, nome) == NULL) {
            insert_in(cerchio, nome, 0);
        } else {
            i--;
        }
    }

    cout << "Ci sono " << size(cerchio) << " bambini nella lista." << endl;
    print(cerchio);

    int i = 0;
    int durata;
    bool finished = false;

    while (!empty(cerchio) && !finished) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Giro numero " << ++i << endl;
        
        cout << "La canzone durerà per " << (durata = rand() % 60 + 10) << " secondi." << endl;

        int sedia_rimossa = rand() % size(cerchio);
        cout << "Fermo il bambino alla sedia numero " << sedia_rimossa << "." << endl;

        lista eliminato = coloraPartecipante(cerchio, durata, sedia_rimossa);

        if (eliminato != NULL) {
            cout << eliminato->nome << " ha ricevuto il colore " << eliminato->colore << endl;
        } else {
            cout << "Tutti i bambini hanno un colore. Ho finito." << endl;
            finished = true;
        }
        print(cerchio);
    }

    // Controllo che non ci siano colori adiacenti
    for (lista m = cerchio; m != cerchio; m = m->next) {
        if (m->colore == m->next->colore) {
            cout << "ERROR: colori adiacenti!" << endl;
            exit(1);
        }
        if (m->colore == nero) {
            cout << "ERROR: C'è un colore nero!" << endl;
            exit(1);
        }
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Tutti i bambini hanno un colore. Ho finito." << endl;

    return 0;
}

// Inserire QUI sotto la definizione delle funzioni coloraPartecipante e cerca.
bool str_cmp(char* str, char* c_str){
    if(strlen(str) != strlen(c_str))
        return false;
    for(int i = 0; i < strlen(str); i++)
        if(tolower(str[i]) != tolower(c_str[i]))
            return false;
    return true;
}
lista cerca(lista L, char* v){
    lista res = NULL;
    for(lista i = L; i != NULL; i = i->next){
        if(str_cmp(v, i->nome) == true)
            res = i;
    }
    return res;
}
lista coloraPartecipante(lista L, int k, int i){
    lista tmp = L;
    if(L == NULL)
        return NULL;
    
    lista prev;
    int j = 0;
    for(; j < k*2 + i; j++){
        lista prev = tmp;
        tmp = tmp->next;
    }
    while(tmp->colore != nero){
        if(tmp->next != NULL){
            prev = tmp;
            tmp = tmp->next;
        }
        else
            return NULL;
    }

    do{
        int n = rand() % 5;
        switch (n)
        {
        case 0:
            tmp->colore = rosso;
            break;
        case 1:
            tmp->colore = verde;
            break;
        case 2:
            tmp->colore = blu;
            break;
        case 3:
            tmp->colore = giallo;
            break;
        default:
            break;
        }
    }while(prev->colore == tmp->colore || tmp->next->colore == tmp->colore);
    

    return tmp;
}