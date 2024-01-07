#ifndef CODA_H
#define CODA_H

struct node;
struct node{
    int value;
    node* next;
};
struct queue{
    node* Head;
    node* Tail;
};

void init(queue &);
bool enqueue(queue &, int);
bool dequeue(queue &);
bool first(queue , int &);
void print(queue);
void deinit(queue &);

#endif