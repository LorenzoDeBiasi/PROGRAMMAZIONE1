#ifndef ALBEROCHAR_H
#define ALBEROCHAR_H

struct node;
typedef node* tree; 
struct node{
    char value;
    node* left;
    node* right;
};
void init(tree &t);
bool empty(const tree t);
bool insert(tree &t, char v);
bool search(const tree t, char v);
void print(const tree t, int spazio);
void deinit(tree &t);

#endif