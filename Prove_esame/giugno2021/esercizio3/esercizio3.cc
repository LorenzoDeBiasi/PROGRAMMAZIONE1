#include <iostream>
#include <cstdlib>

using namespace std;

struct list{
    int value;
    list* next;
};

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;
albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);

albero creaAlberoDiRicercaBinario(albero radice);
void inserisciRicorsivo(albero nuovaRadice, nodo* nodo);
void inserisciNodoInAlberoDiRicercaBinaria(albero radice, int valore);
void StampaAlberoInOrdine(albero radice);
void stampaAlbero(albero, int);
nodo* creaNodo(int valore);
void deallocaAlbero(albero radice);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    stampaAlbero(alberoBinario, 0);
    cout << endl;

    //deallocaAlbero(alberoIniziale);
    //deallocaAlbero(alberoBinario);

    return 0;
}
albero generaAlbero(int numeroDiNodi) {
    
    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo* nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i<numeroDiNodi; i++) {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2*i + 1)<numeroDiNodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < numeroDiNodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }

    return nodi[0];
}
void stampaAlbero(albero radice, int spazio) {

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}


/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
*/
void crea_list(albero t, list* &l){
    if(t != NULL){
        if(t->value % 2 != 0)
            l = new list {t->value, l};
        crea_list(t->left, l);
        crea_list(t->right, l);
    }
}
albero creaAlberoDiRicercaBinario_aux(albero trb, list* l){
    if(l != NULL)
        trb = new nodo {l->value, NULL, NULL};
    else
        return trb;
    if(trb->value <= l->next->value)
        creaAlberoDiRicercaBinario_aux(trb->left, l->next);
    else if(trb->value > l->next->value)
        creaAlberoDiRicercaBinario_aux(trb->right, l->next);
        
}

albero creaAlberoDiRicercaBinario(albero t){
    //creo una lista con gli elementi dispari necessari
    list* l = NULL;
    crea_list(t, l);
/*    for(list* tmp = l; tmp != NULL; tmp = tmp->next){
        for(list* tmp2 = l; tmp2 != tmp; tmp2 = tmp2->next)
            if(tmp->value < tmp2->value){
                int t = tmp->value;
                tmp->value = tmp2->value;
                tmp2->value = t;
            }
    }
*/
    albero trb = NULL;
    trb = creaAlberoDiRicercaBinario_aux(trb, l);
    return trb;
}
