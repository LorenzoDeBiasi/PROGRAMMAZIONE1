#include<iostream>
#include<fstream>
#include"lista.h"
using namespace std;

int length (node s) {
    int l = 0;
    for( ; s != NULL; s = s->next) l++;
    return l;
}
void insert_first(node &s, int v) {
    node n = new node_ls;
    n->value = v;
    n->next = s;
    s = n;
}
void insert_node(node x, node t) {
    t -> next = x -> next;
    x -> next = t;
}
void remove_first(node & s) {
    node n = s;
    if (s != NULL) {
        s = s->next;
        delete n;
    }
}
void insert_last(node & p, int n) {
    node r = new node_ls;
    r->value = n;
    r->next = NULL;
    if (p != NULL) {
        node q = p;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = r;
    }
    else {
        p = r;
    }
}
void print(node const p){
    if(p == NULL)
        return;
    else
        cout << p->value << "\n";
        print(p->next);
}
void deinit(node x){
    if(x->next == NULL)
        delete x;
    else
        deinit(x->next);
}