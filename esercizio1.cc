#include <iostream>
#include <fstream>
using namespace std;

// Inserire qui sotto la soluzione all'esercizio
int power(int base, int esp){
    if(esp == 0)
        return 1;
    else{
        return base*(power(base, esp - 1));
    }
}
int converti(int* array, int dim){
    int res = 1;
    for(int i = 0, e = dim; i < dim; i++, e--){
        res += array[i]*power(2, e);
    }
    return res;
}
int somma(int* array, int dim){
    int res = 0;
    for(int i = 0; i < dim; i++)
        res += array[i];
    return res;
}

void elaborariga(char* str, int* array, int& ris){
    int i = 0;
    int k = 0;
    int w = 0;
    int* new_array;
    do{
        while(str[i] != '+'){
            i++;
            k++;
        }
        
        
        new_array = new int[k];
        for(int j = 0; j < k; j++)
            new_array[j] = str[i - (k - j) - 1] - '0';
        

        i++;
        int n = converti(new_array, k);
        delete[] new_array;
        k = 0;
        array[w] = n;
        w++;
    }while(str[i] != '=');
    i++;
    
    
    while(str[i] != '\0'){
        i++;
        k++;
    }
    new_array = new int[k];
    for(int j = 0; j < k; j++)
        new_array[j] = str[i - (k - j) - 1] - '0';

    ris = converti(new_array, k);
    delete[] new_array;
}


int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "\nERRORE: input non valido\n";
        exit(0);
    }
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if(in.fail() || out.fail()){
        cout << "\nERRORE: stream non aperto correttamente\n";
        exit(1);
    }
    char str[128];
    int dim = 13;
    int array[dim];
    while(!in.eof()){
        int n;
        in.getline(str, 128);
        elaborariga(str, array, n);
        if(n == (somma(array, dim)))
            out << n << "\n";
        else
            out << "ERRORE\n";
    }
    in.close();
    out.close();    
}