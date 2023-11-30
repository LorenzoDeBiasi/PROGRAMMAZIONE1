#include<iostream>
#include<fstream>
#include"lista.h"
using namespace std;

bool static numeroPrimo(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= (n/2); i++)
        if(n % i == 0)
            return false;
    return true;

}

//FUNZIONI DI INSERIMENTO
void insert_first(node &x, int v) {
    node n = new node_ls;
    n->value = v;
    n->next = x;
    x = n;
}
void insert_node(node x, node t) {
    t -> next = x -> next;
    x -> next = t;
}
void insert_last(node &x, int n) {
    node r = new node_ls;
    r->value = n;
    r->next = NULL;
    if (x != NULL) {
        node q = x;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = r;
    }
    else {
        x = r;
    }
}
//FUNZIONI DI RIMOZIONE
void remove_first(node &x) {
    node n = x;
    if (x != NULL) {
        x = x->next;
        delete n;
    }
}
void search_remove(node &x, int val){
    if (x != NULL) {
        node q = x;
        if (q->value == val) {
            x = x->next;
            delete q;
        }
        else {
            while(q->next != NULL) {
                if (q->next->value == val) {
                    node r = q->next;
                    q->next = q->next->next;
                    delete r;
                    return;
                }
                if (q->next != NULL) {
                    q = q->next;
                }
            }
        }
    }
}
//FUNZIONI DI STAMPA
void print(node const x){
    if(x == NULL)
        return;
    else{
        cout << x->value << " ";
        print(x->next);
    }
}
void reverse_print(node const x){
    if(x != NULL){
        if(x->next != NULL)
            reverse_print(x->next);
        cout << x->value << " ";
    }
         
}
//FUNZIONE DI DEALLOCAZIONE
void deinit(node x){
    if(x != NULL){
        deinit(x->next);
        delete x;
    }
}
//FUNZIONI AGGIUNTIVE
int length (node x) {
    int l = 0;
    for( ; x != NULL; x = x->next) l++;
    return l;
}
node primizzaLista(node &x) {
    node ret = x;
    node prev = NULL;
    for (node nodoCorrente = x; nodoCorrente != NULL;) {
        bool primo = numeroPrimo(nodoCorrente->value);
        if (!primo) {
            if (nodoCorrente == x) {
                ret = nodoCorrente->next;
                delete nodoCorrente;
                nodoCorrente = ret;
            } else {
                prev->next = nodoCorrente->next;
                delete nodoCorrente;
                nodoCorrente = prev->next;
            }
        } else {
            prev = nodoCorrente;
            nodoCorrente = nodoCorrente->next;
        }
    }
    return ret;
}


