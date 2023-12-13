#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX_LENGTH 255
char* shiftword(char* , int);
int main(int argc, char* argv[]){
    //controllo input
    if(argc != 3){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    //stream
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    //controllo stream
    if(in.fail() || out.fail()){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    //input utente
    int shift;
    cout << "\nInsert the shifting value: ";
    cin >> shift;
    char str[MAX_LENGTH];
    while(in >> str){
        out << shiftword(str, shift) << " ";
    }
    in.close();
    out.close();
}
char* shiftword(char* str, int shift){
    
    //si evita la testa se non è formata da lettere
    int j = 0;
    while(!(toupper(str[j]) >= ('A') && toupper(str[j]) <= ('Z'))){
        j++;
    }
    //si evita la coda
    int k = strlen(str);
    while (!(toupper(str[k]) >= ('A') && toupper(str[k]) <= ('Z'))){
        k--;
    }
    int range = k - j + 1;
    //una seconda stringa 
    char str_shifted[range];
    if(shift > range)
        shift %= range;
    for(int i = 0; i < range; i++){
        if(i + shift > range)
            str_shifted[i] = str[j + (shift - (k - i))]; 
        else
            str_shifted[i] = str[j + i + shift];
    }
    for(int i = j, I = 0; i < k; k++, I++)
        str[i] = str_shifted[I];
        

    return str;
}