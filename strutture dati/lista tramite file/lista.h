#ifndef LISTA_H
#define LISTA_H

struct node_ls;
typedef node_ls* node;

struct node_ls{
    int value;
    node next;
};




void insert_first(node &x, int v);
void insert_last(node &x, int n);
void insert_node(node x, node t);

void remove_first(node &x);
void search_remove(node &x, int val);

void print(node const x);
void reverse_print(node const x);

void deinit(node x);

int length(node x);
node primizzaLista(node &x);



#endif