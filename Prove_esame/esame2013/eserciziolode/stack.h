#ifndef STACK_H
#define STACK_H
    struct nodo;
    typedef nodo* pila;
    struct nodo{
        long value;
        nodo* next;
    };
    void init(pila &x);
    void deinit(pila &x);
    bool nempty(const pila x);
    void add(pila &x, long v);
    bool shrink(pila &x);
    bool first(const pila x, long &n);
    void print(const pila x); //dall'elemento più alto all'ultimo, LIFO

#endif