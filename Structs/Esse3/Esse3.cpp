#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;

struct studente{
    char nome[30], cognome[30];
    int matricola;
    float media;
};


void stampa_studente(studente* s);
studente* genera_studente(char nome[], char cognome[], int matricola, float media);
bool fill_database(studente** database, char file[], int N);


int main(int argc, char* argv[]){
    //controlli input correto
    if(argc != 3){
        cerr << "Errore: input non valido";
        exit(0);
    }



    int n = atoi(argv[2]);

    studente** DATABASE = new studente*[n];

    cout << fill_database(DATABASE, argv[1], n);//posso passarlo senza & tanto è un array

    cout << DATABASE[0]->nome;

    for(int i = 0; i < n; i++)
        stampa_studente(DATABASE[i]);

    delete[] DATABASE;
}






void stampa_studente(studente* s){
    cout << "\nMatricola numero: " << s->matricola;
    cout << "\n" << s->nome << " " << s->cognome;
    cout << "\nMedia voti dello studente: " << s->media;
    cout << "\n";
}

studente* genera_studente(char nome[], char cognome[], int matricola, float media){
    studente* t = new studente;
    strcpy(t->nome, nome);
    strcpy(t->cognome, cognome);
    t->matricola = matricola;
    t->media = media;
    
    return t;
}

bool fill_database(studente** database, char file[], int N){

    bool risultato;
    fstream Archivio;
    Archivio.open(file, ios::in);

    //controllo stream
    if(Archivio.fail()){
        cerr << "\nErrore: file non aperto correttamente\n";
        exit(0);
    }
    else{
        char nome[31], cognome[31];
        int matricola;
        float media;
        int i = 0;

        while( Archivio >> nome >> cognome >> matricola >> media ){
            database[i] = genera_studente(nome, cognome, matricola, media);
            i++;
        }

        Archivio.close();
        return true;
    }
}