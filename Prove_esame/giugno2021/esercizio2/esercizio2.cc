#include<iostream>
#include<fstream>
using namespace std;


bool check_base(const char n, const int base) {
  switch(base) {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '8'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
	    ((n >= 'A') && (n <= 'F')) ||
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}
bool controlla(char * num, const int maxdim, const unsigned int base = 2) {
  for(int i = 0; ((i < maxdim) && (num[i] != '\0')); i++) {
    if (num[i] >= 'A' && num[i] <= 'Z') {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base)) return false;
  }
  return true;
}
long long int converti(char* source, int dim);
int main() {
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim)) {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = converti(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}
int power(int base, int esp){
    if(esp > 0)
        return base * power(base, esp - 1);
    else    
        return 1;
}
int cifra(char* source, int nbin){
    int n = source[nbin] - '0';
    return n;
}

long long int converti_aux(char* source, int dim, int &ndec, int nbin){
    if(source[nbin] != '\0' && source[nbin] != '\0'){
        int n = converti_aux(source, dim, ndec, nbin + 1);
        int sum = n + (cifra(source, nbin) * power(2, ndec));
        ndec++;
        return sum;
    }
    else
        return 0; 
}
long long int converti(char* source, int dim){
    /*
    ho un'array di cifre
    ogni cifra deve diventare in base decimale 
    ma un numero intero non un array di cifre
    quindi per ogni cifra trasformata devo sommarla
    con l'adeguata potenza di 10, e tramite RICORSIONE
    */
    int ndec = 0;
    return converti_aux(source, dim, ndec, 0);
    
}


