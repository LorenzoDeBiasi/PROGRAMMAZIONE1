#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char * input);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char * input) {
    // Scrivere il codice qui
    int numero = 0;
    int lenCodifica = strlen(input);
    int esponente = lenCodifica;
    init();
    for (int i = 0; i <= lenCodifica; i++) {
        push(i + 1);
        if(i == lenCodifica || input[i] == 'I'){
            while(!vuota()){
                int t;
                top(t);
                numero = numero + t * pow(10, esponente);
                esponente--;
                pop();
            }
        }
    }
    deinit();
    return numero;
    // Potete assumere che l'array rispetti le assunzioni
    // dell'esercizio (non serve fare controlli sull'input)
}
