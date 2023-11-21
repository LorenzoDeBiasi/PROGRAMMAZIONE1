#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void estrai_lettera(char* stringa, int idx, char* risultato, int idxr){
    if(stringa[idx] == '\0')
        risultato[idxr] = '\0';
    else{
        if(stringa[idx] >= 'A' && stringa[idx] <= 'Z'){
            risultato[idxr] = stringa[idx];
            idxr++;
        }
        estrai_lettera(stringa, idx + 1, risultato, idxr);
    }
}


char* estrai(char* stringa){
    char* risultato = new char[81];
    estrai_lettera(stringa, 0, risultato, 0);
    return risultato;
}


int main(){
    char s[81];
    char* e;

    cin >> s;
    e = estrai(s);
    cout << "\n" << e << "\n";
    delete[] e;
}