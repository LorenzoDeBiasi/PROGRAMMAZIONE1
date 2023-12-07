#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;

int encode(char * decoded);
void decode(int coded, char * decoded);

int main(int argc, char* argv[]){
    //controllo input command line
    if(argc != 3){
        cout << "\nERROR: input not valid\n";
        exit(0);
    }
    //apertura stream
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    //controllo stream
    if(in.fail() || out.fail()){
        cout << "ERROR: stream not opened properly\n";
        exit(0);
    }
    int key;
    do{
        cout << "\nInsert a maximum 7-digit key: ";
        cin >> key;
    }while(key >= 10000000);
    char str[5];
    while(in >> str){
        str[4] = '\0';
        int num = encode(str) + key;
        decode(num, str);
        out << str << " ";
    }
    in.close();
    out.close();
}


int encode(char* decoded){
    int n = 0;
    for(int i = 0; i < strlen(decoded); i++){
        if(decoded[i] >= 'a' && decoded[i] <= 'z')
            n += ((decoded[i] - 'a') + 10)*pow(36, strlen(decoded) - 1 - i);
        else if(decoded[i] >= '0' && decoded[i] <= '9')
            n += (decoded[i] - '0')*pow(36, strlen(decoded) - 1 - i);
    }
    return n;
}

void decode(int coded, char* decoded){
    
    int i = 0;
    while( coded != 0){
        int modulo = coded % 36;
        if(modulo < 10){ // se è un numero
            coded = (coded - modulo) / 36;
            decoded[i] = '0' + modulo; 
        }
        else {
            coded = (coded - modulo) / 36;
            decoded[i] = modulo - 10 + 'a';
        }
        i++;
    }
    decoded[i] = '\0';
    for(int j= 0; j < i / 2; j++){
        char tmp = decoded[j];
        decoded[j] = decoded[i - j - 1];
        decoded[i - j - 1] = tmp;
   }
   
}