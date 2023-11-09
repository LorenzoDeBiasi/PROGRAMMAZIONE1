#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;



char* match(char p1[], fstream* file2){
    char c;
    int i = 0;
    char p2[100];
    while((*file2).get(c)){
        if(c == ' '){
            if(p2 == p1)
                return p2;
            else
                i = 0;
        }   
        else
            p2[i] = c;
    }
    char p[100] = "Nessuna parola in comune";
    return p;
}


void Check(char* files[], char parola[]){
    fstream file1, file2, file3;
    file1.open(files[1], ios::in);
    file2.open(files[2], ios::in);

    file3.open(files[3], ios::app);


    char c; int i = 0;
    while(file1.get(c)){
        if(c == ' ')
           file3 << match(parola, &file2) << " ";
        else
            parola[i] = c;
        
    }

    while(file3.get(c))
        cout << c;

    file1.close();
    file2.close();
    file3.close();
}


int main(int argc, char* argv[]){
    char parola[100];


    Check(argv, parola);

    cout << parola << endl;
}