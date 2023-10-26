#include<iostream>
using namespace std;

void BubbleSort(int v[], int n){
    for(int i = 1; i < n; i++)
        //blocco funzionale
        for(int j = 0; j < i; j++)
            if( v[i] < v[j] )
                swap(v[i], v[j]);          
}



//non l'ho fatto io
int partition(int A[], int l, int r) {
    int i = l-1, j = r, v = A[r];
    while (true) {
        while (A[++i] < v);
        while (v < A[--j])
            if (j == l) break;
        if (i >= j) break;
        swap(A[i],A[j]);
    }
    swap(A[i],A[r]);
    return(i);
}
void QuickSort_aux(int a[], int i, int f){
    if( f <= i)
        return;
    int pivot = partition(a, i, f);
    QuickSort_aux(a, i, pivot - 1);
    QuickSort_aux(a, pivot + 1, f);
    
}
void QuickSort(int a[], int n){
    QuickSort_aux(a, 0, n - 1);
}

