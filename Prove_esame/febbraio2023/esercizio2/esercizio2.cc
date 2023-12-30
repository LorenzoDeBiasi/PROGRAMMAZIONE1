#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 100

// NON MODIFICARE IL CODICE SOTTO FINO A "NON MODIFICARE IL CODICE SOPRA"
struct list {
  int info;
  list * next;
};

struct tree {
  int info;
  tree * left;
  tree * right;
};

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				*result = {num, NULL, NULL};
		} else if (result->info > num) {
				insert(result->left, num);
		} else {
				insert(result->right, num);
		}
}

tree * crea_tree(const int num) {
		tree * result = NULL;
		for(int i = 0; i < num; i++) {
				insert(result, rand()%MAXVALUE);
		}
		return result;
}

void print_tree(const tree * root){
		if (root != NULL) {
				print_tree(root->right);
				std::cout << " " << root->info;
				print_tree(root->left);
  }
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void print_array(const int l[], const int l_size) {
  for(int i = 0; i < l_size; i++)
    std::cout << " " << l[i];
  std::cout << std::endl;
}

// NON MODIFICARE IL CODICE SOPRA

// Add hereafter the declaration of estrai
void estrai(tree* t, int* &l1, int &l1_size, int* &l2, int &l2_size);
// Add here above the declaration of estrai

// NON MODIFICARE IL MAIN
int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);
		std::cout << "Initial tree content: ";
		print_tree(root); std::cout << std::endl;
  int * l1;
  int l1_size;
  int * l2;
  int l2_size;
  estrai(root, l1, l1_size, l2, l2_size);
  delete_tree(root);
		std::cout << "L1 =";
  print_array(l1, l1_size);
		std::cout << "L2 =";
  print_array(l2, l2_size);
  delete [] l1;
  delete [] l2;
}
// NON MODIFICARE IL MAIN
void bubblesort(int* v, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if( v[i] < v[j] ){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
}
void scan_aux(tree* t, int &l1_size, int &l2_size){
    if(t->left == NULL && t->right == NULL){
        if(t->info % 2 == 0)    l1_size++;
        else                    l2_size++;       
        return;
    }
    else if(t->left == NULL){
        if(t->info % 2 == 0)    l1_size++;
        else                    l2_size++;
        scan_aux(t->right, l1_size, l2_size);
    }
    else if(t->right == NULL){
        if(t->info % 2 == 0)    l1_size++;
        else                    l2_size++;
        scan_aux(t->left, l1_size, l2_size);
    }
    else{
        if(t->info % 2 == 0)    l1_size++;
        else                    l2_size++;
        scan_aux(t->left, l1_size, l2_size);
        scan_aux(t->right, l1_size, l2_size);
    }
}
void estrai_aux(tree* t, int* &l1, int* &l2, int &i1, int &i2){
    if(t->left == NULL && t->right == NULL){
        if(t->info % 2 == 0)    {l1[i1] = t->info;    i1++;}
        else                    {l2[i2] = t->info;   i2++;}
        return;
    }
    else if(t->left == NULL){
        if(t->info % 2 == 0)    {l1[i1] = t->info;    i1++;}
        else                    {l2[i2] = t->info;   i2++;}
        estrai_aux(t->right, l1, l2, i1, i2);
    }
    else if(t->right == NULL){
        if(t->info % 2 == 0)    {l1[i1] = t->info;    i1++;}
        else                    {l2[i2] = t->info;   i2++;}
        estrai_aux(t->left, l1, l2, i1, i2);
    }
    else{
        if(t->info % 2 == 0)    {l1[i1] = t->info;    i1++;}
        else                    {l2[i2] = t->info;   i2++;}
        estrai_aux(t->left, l1, l2, i1, i2);
        estrai_aux(t->right, l1, l2, i1, i2);
    }  
}
// Add hereafter the definition of estrai
void estrai(tree* t, int* &l1, int &l1_size, int* &l2, int &l2_size){
    if(t == NULL){
        l1 = NULL; l2 = NULL;
        l1_size = 0; l2_size = 0;
        return;
    }
    scan_aux(t, l1_size, l2_size);
    //allocazione array
    l1 = new int[l1_size];
    l2 = new int[l2_size];
    //riempimento array
    int i = 0; int j = 0;
    estrai_aux(t, l1, l2, i, j);
    //ordinamento array
    bubblesort(l1, l1_size);
    bubblesort(l2, l2_size);
}
// Add here above the definition of estrai
