#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX_SIZE 256

char* shift(char* str, int n){
    int l = strlen(str);
    if(n >= l)
        n = n % l;
    char* new_str = new char[l + 1];
    for(int i = 0; i < l; i++){
        if(i + n >= l)
            new_str[i] = toupper(str[(i + n) - l]);
        else    
            new_str[i] = toupper(str[i + n]);
    } 
    new_str[l] = '\0';
    return new_str;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    fstream in;
    in.open(argv[1], ios::in);
    if(in.fail()){
        cout << "\nERROR: stream not properly opened\n";
        exit(1);
    }
    char str[MAX_SIZE]; int n;
    cout << "\nInserisci una stringa da ricercare nel file: "; cin >> str;
    cout << "\ne un numero per shiftare la stringa: "; cin >> n;
    char* shifted_str = shift(str, n);
    
    char r_str[MAX_SIZE];
    int occorrenze = 0;
    while(in >> r_str){
        int l1 = strlen(r_str);
        int l2 = strlen(shifted_str);
        for(int i = 0; i <= l1 - l2; i++)
            if(strncmp(r_str + i, shifted_str, l2) == 0)
                occorrenze++;
    }
    cout << "\nLa stringa " << shifted_str << " compare " << occorrenze << " volte nel file " << argv[1] << "\n";
    delete[] shifted_str;
    in.close();
}