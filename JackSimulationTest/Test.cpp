#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;


int main(int argc, char * argv[]){
    
    fstream Questions;
    fstream Answers;

    char risposta[256];
    char line[256];
    char rcorretta[256];
        
    Questions.open(argv[1], ios::in);
    Answers.open(argv[2], ios::in);

    
    while(Questions.getline(line, 256)){
        cout << line << endl;
        cin >> risposta;
        Answers.getline(rcorretta, 256);

        if(rcorretta[0] == risposta[0])
            cout << "\ngiusto\n";
        else
            cout << "\nsbagliato\n";
    }
    Questions.close();
    Answers.close();    
}