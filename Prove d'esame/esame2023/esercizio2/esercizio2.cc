#include <iostream>
#include <cstddef>

using namespace std;

// Inserire qui la dichiarazione di get_elements
void get_elements(char* source, int dim_source, char* &dest_1, int& dim_d1, char* &dest_2, int& dim_d2);

void print(const char a[], const int s, const char *prefix)
{
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

int main() {
  const int maxdim = 10;

  char * d1;
  int d1_s = 10;

  char * d2;
  int d2_s;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;
  //s_s diventa la dimensione di s dopo la read_elements, è counter in pratica. 

  read_elements(s, ms, s_s);
  print(s, s_s, "Source = ");

  get_elements(s, s_s, d1, d1_s, d2, d2_s);
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

  delete [] d1;
  delete [] d2;
}

// Inserire qui la definizione di get_elements e di eventuali altre
// funzioni ausiliarie
void get_elements_aux(char* source, int dim_source, char* & dest_1, int& dim_d1, char* & dest_2, int& dim_d2, int contatore);

void get_elements(char* source, int dim_source, char* & dest_1, int& dim_d1, char* & dest_2, int& dim_d2){
    //RICORDA: quando hai problemi nell'usare un contatore perchè la funzione è ricorsiva e non possiede un contatore tra i parametri
    //puoi creare una funzione ausiliaria che contenga lei il contatore
    dim_d1 = 0;
    dim_d2 = 0;
    //questo contatore servirà solo per scorrere il vettore principale source, per gli altri due si sfrutterà la loro dimensione
    //che di ricorsione in ricorsione aumenterà
    get_elements_aux(source, dim_source, dest_1, dim_d1, dest_2, dim_d2, 0);
}
void get_elements_aux(char* source, int dim_source, char* & dest_1, int& dim_d1, char* & dest_2, int& dim_d2, int contatore){
    //l'allocazione verrà fatta quando il contatore sforerà la dimensione programmata del vettore principale
    //ossia all'ultima ricorsione, quando si comincerà a risalire indietro i due vettore dest verranno riempiti 
    //nelle posizioni salvate durante la discesa 
    if(contatore >= dim_source){
        dest_1 = new char[dim_d1];
        dest_2 = new char[dim_d2];
    }else{
        //LETTERE (SOLO MINUSCOLE)
        if(source[contatore] >= 'a' && source[contatore] <= 'z'){
            int pos = dim_d1++;//salvo la posizione per dopo la ricorsione, e nel mentre aumento anche l'indice dell'array d1
            get_elements_aux(source, dim_source, dest_1, dim_d1, dest_2, dim_d2, contatore + 1);
            dest_1[pos] = 'A' - (source[contatore] - 'z');
        }
        //NUMERI
        else if(source[contatore]>= '0' && source[contatore] <= '9'){
            int pos = dim_d2++;//salvo sempre per dopo, perchè non posso sfruttare il contatore poichè ho due array diversi
            get_elements_aux(source, dim_source, dest_1, dim_d1, dest_2, dim_d2, contatore + 1);
            dest_2[pos] = '9' - (source[contatore] - '0');
        }
        //QUALSIASI ALTRO CARATTERE
        else
            get_elements_aux(source, dim_source, dest_1, dim_d1, dest_2, dim_d2, contatore + 1);
    }
}

/*
IDEA DI FONDO:
    scorro source tramite un contatore, possibile grazie all'ausiliaria, che incremento a ogni ricorsione però la ricorsione
    la faccio tra due passaggi fondamentali il salvataggio della posizione di source interessata che servirà però DOPO tutte
    le chiamate, quando si risalirà dalla ricorsione, in modo che sapendo il numero di ricorsioni fatte potrò allocare i due 
    array conoscendo le lunghezze (incrementando ciascuna ad ogni ricorsione). Risalendo ogni chiamata si inseriranno gli 
    elementi appropriati dei due array tramite la posizione salvata in quella chiamata in cui ci si trova.  
*/