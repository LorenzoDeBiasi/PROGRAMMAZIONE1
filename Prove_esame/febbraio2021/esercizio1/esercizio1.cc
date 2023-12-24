#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX_DIM 100

bool str_cmp(char* str, char* c_str){
    if(strlen(str) != strlen(c_str))
        return false;
    for(int i = 0; i < strlen(str); i++)
        if(tolower(str[i]) != tolower(c_str[i]))
            return false;
    return true;
}

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    fstream inm, inv, out;
    inm.open(argv[1], ios::in);
    out.open(argv[3], ios::out);
    if(inm.fail() || out.fail()){
        cout << "\nERROR: stream not properly opened\n";
        exit(1);
    }
    char str[MAX_DIM];
    while(inm >> str){
        inv.open(argv[2], ios::in);
        if(inv.fail()){
            cout << "\nERROR: stream not properly opened\n";
            exit(1);
        }
        char c_str[MAX_DIM];
        bool need_to_cens = false;
        while(inv >> c_str && !need_to_cens)
            need_to_cens = str_cmp(str, c_str);

        if(need_to_cens){
            for(int i = 0; i < strlen(str); i++)
                out << "X";
            out << " ";
        }
        else
            out << str << " ";
        inv.close();
    }
    inm.close();
    out.close();
}