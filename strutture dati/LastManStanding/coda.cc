#include<iostream>
#include"coda.h"
using namespace std;


void init(queue &Q){
    Q.Head = NULL;
}
bool empty(queue Q){
    return (Q.Head == NULL);
}
bool enqueue(queue &Q, int v){
    node* newnode = new (nothrow) node;
    bool result;
    if(newnode == NULL)
        result = false;
    else{
        newnode->value = v;
        newnode->next = NULL;
        if(empty(Q))
            Q.Head = newnode;        
        else
            Q.Tail->next = newnode;
        Q.Tail = newnode;
        result = true;
    }
    return result;
}
//il dequeue si fa sulla testa!!!
bool dequeue(queue &Q){
    bool result;
    if(empty(Q))
        result = false;
    else{
        node* tmp = Q.Head;
        Q.Head = Q.Head->next;
        delete tmp;
        result = true;
    }
    return result;
}
bool first(queue Q, int &n){
    bool result;
    if(empty(Q))
        result = false;
    else{
        n = Q.Head->value;
        result = true;
    }
    return result;
}
void print(queue Q){
    if(!empty(Q)){
        node* tmp = Q.Head;
        do{
            cout << "| " << tmp->value << " |";
            tmp = tmp->next;
        }while(tmp != NULL);
    }
}
void deinit(queue &Q){
    while(!empty(Q))
        dequeue(Q);
}