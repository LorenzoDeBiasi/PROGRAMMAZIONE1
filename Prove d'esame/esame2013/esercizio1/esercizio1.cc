#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX_DIM 100

int main(int argc, char* argv[]){
    //controlli 
    if(argc != 3){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    //stream
    fstream file;
    file.open(argv[1], ios::in);
    //controlli
    if(file.fail()){
        cout << "\nERROR: stream not properly opened\n";
        exit(0);
    }
    char str[MAX_DIM];
    while(file >> str){
        if(strstr(str, argv[2])){
            cout << "\nOne occurence of " << argv[2] << " has been found\n";
            file.close();
            return 0;
        }
    }
    cout << "\nNone occurences have been found\n";
    file.close();
}