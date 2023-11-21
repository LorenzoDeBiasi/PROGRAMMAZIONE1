#include"isamail.h"
#include<iostream>
#include<cstring>
using namespace std;

bool address(char parola[100], fstream& stati){
    
    char abbreviazione[5];
    char s[5];
    for(int i = 0; parola[i] != '\0'; i++)
        if(parola[i] == '@'){ //deve esserci una @
            //controllo utente
            for(int j = 0; parola[j] != '@'; j++){
                if(parola[0] == '.' && parola[0] == '@') //l'utente deve avere almeno un carattere e non deve essere un . o una @
                    return false;
                else if( 
                            (toupper(parola[j]) < 'A' && toupper(parola[j]) > 'Z')
                            && (parola[j] < '0' && parola[j] > '9')
                            && (parola[j] != '.' && parola[j] != '_') 
                        )
                    return false;
            }
            for(int j = i + 1; parola[j] != '\0'; j++)
                if(parola[j] != '@' && parola[j] == '.') //deve esserci solo una @ e un .
                    for(int x = j, y = 0; parola[x] != '\0'; x++, y++){
                        s[y] = parola[x];   
                    }
            while(stati >> abbreviazione)
                if(strcmp(abbreviazione, s) == 0)
                    return true;        
        }
    return false;
}