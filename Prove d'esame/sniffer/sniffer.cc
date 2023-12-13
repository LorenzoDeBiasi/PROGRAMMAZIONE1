#include<iostream>
#include<fstream>
using namespace std;
#define MAX_DIM 16

bool isdigit(char str[5])       { return atoi(str); }

int main(int argc, char* argv[]){
    //controlli input
    if(argc != 2)   { cout << "\nERROR: input not valid\n";   exit(0); }
    //apertura stream
    fstream input;  input.open(argv[1], ios::in);
    //controllo stream
    if(input.fail()){ cout << "\nERROR: stream not opened properly\n";    exit(0); }

    char str[MAX_DIM];    bool keep = true;    int i = 0;     int counter = 0;
    while(input >> str){
        do{ 
            str[4] = '\0';
            keep = isdigit(str);
            
            if(keep)    { i++; input >> str; }
            if(i == 4)  { i = 0; counter++; keep = false; }

        }while(keep);
    }
    cout << "\nI found " << counter << " possible card numbers\n";
    input.close();
}