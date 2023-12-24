#include<iostream>
#include"alberochar.h"
using namespace std;

void init(tree &t){
    t = new node;
    t = NULL;
}
bool empty(const tree t){
    if(t == NULL)
        return true;
    else
        return false;
}
bool insert_aux(tree &t, char v){
    if(empty(t)){
        t->left = NULL;
        t->right = NULL;
        t->value = v;
        return true;
    }
    else {
        if(v > t->value){
            if(empty(t->right))
                insert(t->right, v);  
            else if(v < t->right->value){
                tree tmp = new node;
                tmp->value = v;
                tmp->right = t->right;
                tmp->left = NULL;
                t = tmp;
                return true;
            }if(v > t->right->value){
                tree tmp = new node;
                tmp->value = v;
                tmp->left = t->right;
                tmp->right = NULL;
                t = tmp;
                return true;
            }
        }
        else if(v < t->value){
            if(empty(t->left))
                insert(t->left, v);
            else if(v < t->right->value){
                tree tmp = new node;
                tmp->value = v;
                tmp->right = t->right;
                tmp->left = NULL;
                t = tmp;
                return true;
            }if(v > t->right->value){
                tree tmp = new node;
                tmp->value = v;
                tmp->left = t->right;
                tmp->right = NULL;
                t = tmp;
                return true;
            }
        }
    }
}
bool insert(tree &t, char v){
    bool result;
    if(empty(t)){
        t = new (nothrow) node;
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
bool search(const tree t, char v){
    if(t == NULL)
        return false;
    else{
        if(v == t->value)
            return true;
        if(v < t->value)
            return search(t->left, v);
        if(v > t->value)
            return search(t->right, v);
    }
}
void print(tree radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    print(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    print(radice->left, spazio);
   }
}
void deinit(tree &t){
    if(t != NULL){
        deinit(t->left);
        deinit(t->right);
        delete t;
    }
}