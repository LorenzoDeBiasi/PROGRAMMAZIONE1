#include<iostream>
#include"albero.h"
using namespace std;

static bool emptyp(const albero & t) {
  return (t==NULL);
}

void albero_init(albero &t){
    t = NULL;
}
void stampaAlbero(albero radice, int spazio){
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
void stampaAlberoOrdinato(albero t){
    if(t != NULL){
        stampaAlberoOrdinato(t->left);
        cout << t->value << " ";
        stampaAlberoOrdinato(t->right);    
    }
}
bool insert(albero &t, int v){
    bool result;
    if(emptyp(t)){
        t = new (nothrow) nodo;
        if (t==NULL)
            result = false; 
        else {
            t->value = v;
            t->left = NULL; 
            t->right = NULL; 
            result = true;
        }
    }
    else if (v <= t->value) 
        result = insert(t->left, v);
    else if (v > t->value) 
        result = insert(t->right, v);
    return result;
}
bool search(albero t, int v){
    if(t != NULL){
        if(v == t->value){
            cout << v << "\n";
            return true;
        }
        if(v <= t->value){
            cout << t->value << " sinistra ";
            return search(t->left, v);
            
        }
        else{
            cout << t->value << " destra ";
            return search(t->right, v);
        }
    }
    return false;
}

void albero_deinit(albero &t){
    if(!emptyp(t)){
        albero_deinit(t->left);
        albero_deinit(t->right);
        delete t;
    }
}