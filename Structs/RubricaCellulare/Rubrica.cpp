#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;

struct contatto{
    char Nome[25], Cognome[25];
    int Numero;
};


void AggiungiContatto(contatto* nuovoC, char file[]){
    fstream Rubrica(file, ios::app);
    Rubrica << "\n" << (*nuovoC).Nome << " " << (*nuovoC).Cognome << "\nCellulare: " << (*nuovoC).Numero <<"\n";
    Rubrica.close();
}

int main(int argc, char* argv[]){

    //controlli dell'input a comand line
    if(argc != 2){
        cerr << "\nErrore: input non valido\nModalità d'uso: ./Aggiungi file.txt\n";
        exit(0);
    }


    contatto* pContatto;
    char risposta;
    do{

        pContatto = new contatto;

        cout << "\nInserisci nome: "; cin >>  (*pContatto).Nome; 
        cout << "\nInserisci cognome: "; cin >> (*pContatto).Cognome;
        cout << "\nInserisci numero: "; cin >> (*pContatto).Numero;

        AggiungiContatto(pContatto, argv[1]);

        delete pContatto;

        do{
            cout << "Aggiungere un nuovo contatto? "; 
            cin >> risposta;
        }while(risposta != 's' && risposta != 'n');

    }while(risposta == 's');

}