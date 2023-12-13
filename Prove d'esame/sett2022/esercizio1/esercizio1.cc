#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "\nERROR: invalid input\n";
        exit(0);
    }
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if(in.fail() || out.fail()){
        cout << "\nERROR: stream error\n";
        in.close(); 
        out.close();
        exit(1);
    }
    char c;
    char buffer[256];
    char max_buffer[256] = {};
    int l = 0;
    int max_l = 0;
    while(in.get(c)){
        if(c != '\n'){
            buffer[l] = c;
            l++;            
        }
        else if(c == '\n'){
            out << l << "\n";
            if(l > max_l){
                max_l = l;
                for(int i = 0; i < max_l; i++)
                    max_buffer[i] = buffer[i];
                max_buffer[max_l] = '\0';
            }
            l = 0;
        }
    }
    out << max_buffer << " " << max_l << "\n";
    in.close();
    out.close();
}