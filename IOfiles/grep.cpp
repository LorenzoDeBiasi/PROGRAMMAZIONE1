#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;




bool grep(char * stringa, fstream * file){
    //controllo non ci siano errori nello stream
    if((*file).fail()){
        std::cerr << "Errore";
        exit(0);
    }  
    //matching
    char c; int i = 0;
    while((*file).get(c)){
        if(stringa[i] == '\0') 
            //endoffile raggiunto
            return true;
        if(tolower(stringa[i]) == tolower(c))
            i++;
        else i = 0;
    }
    return false;
}


//devo verificare che una certa stringa sia presente in uno o più file
int main (int argc, char * argv[]){
    //controllo che i parametri in entrata siano in numero corretto (nome eseguibile, stringa, nome file)
    if(argc < 3){
        std::cerr << "Digitare (file.out) (stringa ricercata) (file.txt) \n";
        exit(0);
    }
    char *stringa = argv[1];
    for(int i = 0; i < argc - 2; i++){
        //creo e apro lo stream
        fstream file;
        file.open(argv[i + 2], ios::in);

        //chiamo la funzione che controlla il matching

        if(grep(stringa, &file)){
            cout << endl << argv[1] << " è presente in " << argv[i + 2] << endl;
            file.close();
            return 0;
        }
        file.close();
    }
    cout << "\nLa stringa digitata non è presente in nessuno dei file\n";


}