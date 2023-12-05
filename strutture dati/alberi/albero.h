#ifndef ALBERO_H
#define ALBERO_H

struct nodo;
typedef nodo* albero;

struct nodo {
    int value;
    albero left;
    albero right;
};


void albero_init(albero &t);
void stampaAlbero(albero radice, int spazio=0);
void stampaAlberoOrdinato(albero radice);
bool insert(albero &t, int v);
bool search(albero t, int v);
void albero_deinit(albero &t);
#endif
