#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;


struct Data{
    int giorno, mese, anno;
};

struct Matricola{
    char Nome[25], Cognome[25];
    Data Nascita;
    int Numero;
};

void AggiungiMatricola(Matricola* p, char file[]){
    fstream Archivio;
    Archivio.open(file, ios::app);
    
    Archivio << "\nMatricola numero: " << (*p).Numero << "\n";
    Archivio << (*p).Nome << " " << (*p).Cognome;
    Archivio << "\nData di Nascita: " << (*p).Nascita.giorno << " " << (*p).Nascita.mese << " " << (*p).Nascita.anno;
    
    Archivio.close();
}
void AssegnaNumero(Matricola* p, char file[]){
    
    (*p).Numero = rand() % 100000;


    //controllo numero già uscito
    fstream Archivio;
    Archivio.open(file, ios::in);
    char cr[20];
    char c[6];
    bool ripetuto = true;
    while(ripetuto){
        Archivio.getline(cr, 19);
        if(strcmp(cr, "Matricola numero: ") == 0){
            
            for(int i = 0; i < 6; i++){
                
            }          
        }

    }

}
void OrdinaMatricole(char file[]);


int main(int argc, char* argv[]){
    //controlli dell'input a comand line
    if(argc != 2){
        cerr << "\nErrore: input non valido\nModalità d'uso: ./Aggiungi file.txt\n";
        exit(0);
    }
    srand(time(0));

    Matricola* pm;
    char risposta;
    do{
        
        pm = new Matricola;
        

        cout << "\nInserisci nome: "; cin >>  (*pm).Nome; 
        cout << "\nInserisci cognome: "; cin >> (*pm).Cognome;
        cout << "\nInserisci data di nascita: "; cin >> (*pm).Nascita.giorno >> (*pm).Nascita.mese >> (*pm).Nascita.anno;
        
        AssegnaNumero(pm, argv[1]);
        AggiungiMatricola(pm, argv[1]);

        delete pm;




        do{
            cout << "\nVuoi aggiungere una nuova matricola? "; cin >> risposta;
        }while(risposta != 's' && risposta != 'n');    


    }while(risposta == 's');

    //OrdinaMatricole(argv[1]);

}