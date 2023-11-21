#include"cifratura.h"


void crypt(char parola[], int chiave){
    for(int i = 0; parola[i] != ' ' && parola[i] != '\0' ; i++){
        if(parola[i] + chiave <= 'z')
            parola[i] += chiave;
        else
            parola[i] = 'a' - 1 + (chiave - ('z' - parola[i]));
    }
}
void decrypt(char parola[], int chiave){
    for(int i = 0; parola[i] != ' ' && parola[i] != '\0' ; i++){
        if(parola[i] - chiave >= 'a')
            parola[i] -= chiave;
        else
            parola[i] = 'z' + 1 - (chiave - (parola[i] - 'a'));
    }
}
