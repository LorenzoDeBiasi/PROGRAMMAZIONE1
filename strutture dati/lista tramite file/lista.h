#ifndef LISTA_H
#define LISTA_H

struct node_ls;
typedef node_ls* node;

struct node_ls{
    int value;
    node next;
};


int length(node s);
void insert_first(node &s, int v);
void insert_node(node x, node t);
void remove_first(node & s);
void insert_last(node & p, int n);
void print(node const p);
void deinit(node x);
#endif