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

//stampa
void stampa_studente(studente* s);
//generazione
studente* genera_studente(char nome[], char cognome[], int matricola, float media);
void aggiungi_al_database(studente** database, char file[], int &i);
bool fill_database(studente** database, char file[], int N, int &i);
//ricerca
int cerca_matricola(studente ** database, int matricola, int DIM);
int cerca_nome_e_cognome(studente ** database, char * nome, char *cognome, int DIM);
int studente_top_media(studente ** database, int DIM);




int main(int argc, char* argv[]){
    //controlli input correto
    if(argc != 2){
        cerr << "Errore: input non valido\n";
        exit(0);
    }



    int n = 100;

    studente** DATABASE = new studente*[n];
    int Nstudenti = 0;

    do{
        char choice;
        do{
            cout << "\nCosa vuoi fare:\n";
            cout << "\nInserire un archivio 'I'\nAggiungere uno studente 'A'\nCercare per nome e cognome 'N'\nCercare per numero di matricola 'M'\nCercare per voti migliori 'V'\n\n";
            cin  >> choice; 
            choice = toupper(choice); 
        } while(choice != 'I' && choice != 'A' && choice != 'N' && choice != 'M' && choice != 'V');

        //Insert an archive file
        if(choice == 'I'){
            fill_database(DATABASE, argv[1], n, Nstudenti);
        } 
        //add a student
        if(choice == 'A'){
            if(Nstudenti <= 99)
                aggiungi_al_database(DATABASE, argv[1], Nstudenti);
            else
                cout << "\nNumero massimo di studenti raggiunto\n";
        }
        //Searching by name
        if(choice == 'N'){
            char nome[30], cognome[30];
            cout << "\nInserisci nome e cognome: "; cin >> nome >> cognome;
            stampa_studente(DATABASE[cerca_nome_e_cognome(DATABASE, nome, cognome, n)]);
        }
        //Searching by number
        if(choice == 'M'){
            int matricola;
            cout << "\nInserici numero di matricola: "; cin >> matricola;
            stampa_studente(DATABASE[cerca_matricola(DATABASE, matricola, n)]);
        }
        //Searching the best
        if(choice == 'V'){
            stampa_studente(DATABASE[studente_top_media(DATABASE, n)]);
        }
    }while( true );


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

void aggiungi_al_database(studente** database, char file[], int &i){
        char Nome[30], Cognome[30];
        int Matricola;
        float Media;
        cout << "Inserire: Nome Cognome Matricola Media: ";
        cin >> Nome >> Cognome >> Matricola >> Media;

        ++i;
        database[i] = genera_studente(Nome, Cognome, Matricola, Media);


        fstream Archivio;
        Archivio.open(file, ios::app);
        Archivio << "\n" << Nome << " " << Cognome << " " << Matricola << " " << Media;
        Archivio.close();
}

bool fill_database(studente** database, char file[], int N, int &i){

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


        while( Archivio >> nome >> cognome >> matricola >> media ){
            database[i] = genera_studente(nome, cognome, matricola, media);
            i++;
        }
        
        Archivio.close();

        //controllo riuscita del riempimento array
        if(i >= N)
            return false;

        return true;
    }
}

int cerca_matricola(studente ** database, int matricola, int DIM){
    for(int i = 0; i < DIM; i++)
        if(database[i]->matricola == matricola)
            return i;
    cout << "\nMatricola non presente\n";
    exit(0);
}

int cerca_nome_e_cognome(studente ** database, char * nome, char *cognome, int DIM){
    for(int i = 0; i < DIM; i++)
        if(strcmp(database[i]->nome, nome) == 0)
            if(strcmp(database[i]->cognome, cognome) == 0)
                return i;
    cout << "\nMatricola non presente\n";
    exit(0);    
}

int studente_top_media(studente ** database, int DIM){
    //potevo farlo con un quicksort sul database ma non avevo voglia
    int n = 0;
    for(int i = 0; i < DIM; i++)
        if(n < database[i]->media)
            n = i;
    return n;
}
