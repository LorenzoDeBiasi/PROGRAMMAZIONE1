#ifndef LISTA_H
#define LISTA_H

struct node;
typedef node* list;

struct node{
    int value;
    node* prev;
    node* next;
};

void init(list );
bool insert(list &, int );
bool remove_occurences(list &, int );
void print(list );
void deinit(list );

#endif