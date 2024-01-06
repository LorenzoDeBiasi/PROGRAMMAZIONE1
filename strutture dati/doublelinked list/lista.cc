#include<iostream>
#include"lista.h"
using namespace std;

void init(list l){
    l = NULL;
}
bool static empty(list l){
    return (l == NULL);
}
bool insert(list &l, int v){
    bool result;
    list newnode = new (nothrow) node;

    if(newnode == NULL)
        result = false;
    else{
        if(empty(l)){
            newnode->prev = NULL;
            newnode->next = NULL;
            newnode->value = v;
        }
        else{
            newnode->next = l;
            newnode->prev = NULL;
            l->prev = newnode;
            newnode->value = v;
        }
        l = newnode;
        result = true;
    }
    return result;
}
bool remove_occurences(list &l, int v){
    bool result = false;
    for(list tmp = l; tmp != NULL; )
        if(tmp->value == v){
            list sacrifice = tmp;
            if(tmp->prev != NULL)
                tmp->prev->next = tmp->next;
            else
                l = tmp->next;
            if(tmp->next != NULL)
                tmp->next->prev = tmp->prev;
            tmp = tmp->next;
            result = true;
        }
        else
            tmp = tmp->next;
    return result;
}
void print(list l){
    for(list tmp = l; tmp != NULL; tmp = tmp->next)
        cout << "| " << tmp->value << " |";
}
void deinit(list l){
    if(l->next == NULL)
        delete l;
    else{
        deinit(l->next);
        delete l;
    }
}