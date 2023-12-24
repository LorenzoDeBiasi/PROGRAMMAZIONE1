#include <iostream>
#include <cstdlib>
#include"coda.h"

using namespace std;

int trovaIlVincitore(int n, int k);

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "Usage: a./out <numeroDiAmici> <numeroDiSalti>" << endl;
        exit(0);
    }
    if(atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0){
        cerr << "\nInvalid input\n";
        exit(1);
    }
    cout << "Il vincitore e' l'amico numero " << trovaIlVincitore(atoi(argv[1]), atoi(argv[2])) << endl;
}


// Implementare la funzione sottostante come da consegna:
// - 'numeroDiAmici' è il numero di amici, o anche chiamato 'n'
// - 'numeroDiSalti' è il numero di salti, o anche chiamato 'k' 
int trovaIlVincitore(int numeroDiAmici, int numeroDiSalti) {
    init();
    for(int i = 1; i <= numeroDiAmici; i++)
        enqueue(i);
    
    //elimino il k nodo con dequeue, ma per farlo deve essere il primo
    //elemento della coda, quindi per fare ciò prendo tutti gli elementi
    //prima del k e li metto di nuovo in coda, eliminando quelli rimasti 
    //in testa 

    int vincitore;
    
    while(first(vincitore)){
        int saltirimanenti = numeroDiSalti;

        dequeue();
        enqueue(vincitore);

        while(saltirimanenti > 1){
            first(vincitore);
            dequeue();
            enqueue(vincitore);
            saltirimanenti--;
        }

        dequeue();
    }
    
    deinit();

    return vincitore;
}
