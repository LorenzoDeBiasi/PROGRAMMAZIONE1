#include<iostream>
#include<fstream>
using namespace std;

float* Allocazione(char file[], int M);
void BubbleSort(float v[], int n);

int main(int argc, char* argv[]){
    //controlli  ./a.out file N M
    if(argc != 4){ 
        cout << "ERRORE:\nComandi non eseguiti correttamente\n";
        return -1;        
    }
    if(atoi(argv[2]) <= 0){
        cout << "ERRORE:\nNumero inserito non valido\n";
        exit(0);        
    }



    float* array = Allocazione(argv[1], atoi(argv[3]));

    BubbleSort(array, atoi(argv[3]));

    for(int i = 0; i < atoi(argv[2]); i++)
        cout << "| " << array[i] << " |";
    cout << "\n";


    return 0;
}




float* Allocazione(char file[], int M){
    fstream Archivio;
    Archivio.open(file, ios::in);
    float* a = new float[M];
    char sn[6], c; 
    int i = 0, j = 0;
    while(Archivio.get(c)){
        sn[j] = c;
        j++;
        if(c == '\n' || Archivio.eof()){
            a[i] = atof(sn);
            j = 0;
            i++; 
        }
    }
    for(int k = i; k < M; k++)
        a[k] = -273.0;
    return a;
}

void BubbleSort(float v[], int n){
    for(int i = 1; i < n; i++)
        //blocco funzionale
        for(int j = 0; j < i; j++)
            if( v[i] > v[j] )
                swap(v[i], v[j]);          
}