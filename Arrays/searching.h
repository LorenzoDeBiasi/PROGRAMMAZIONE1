

bool Ordinato(int a[], int n){
    int i = 0;
    while(i < n - 1){
        if(a[i] < a[i + 1])
            i++;
        else
            return false;       
    }
    return true;
}

int RicercaBinaria_Aux(int a[], int n, int i, int f){      
    if(i > f)
        return -1;

    if(n == a[ (i + f) / 2])
        return ( (f + i) / 2);
    else if(n < a[f / 2])
        return RicercaBinaria_Aux(a, n, i, ( (i + f) / 2) - 1);
    else if(n > a[f / 2])
        return RicercaBinaria_Aux(a, n, ( (i + f) / 2) + 1, f);
}

int RicercaBinaria(int a[], int n, int f, int i = 0){
    if(!Ordinato(a, f))
        QuickSort(a, f);

    if(n == a[ (f + i) / 2])
        return ( (f + i) / 2);
    if(n < a[f / 2])
        return RicercaBinaria_Aux(a, n, i, (f + i)/2);
    if(n > a[f / 2])
        return RicercaBinaria_Aux(a, n, (f + i)/2, f);
}