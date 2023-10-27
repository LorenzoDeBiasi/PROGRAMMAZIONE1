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
        
    
    Answers.open(argv[2], ios::in);

    //pescare una riga a caso
    //idea: aprire e chiudere lo stream ad ogni ciclo, ogni volta si va a guardare la riga
    //pescata dopo aver incontrato n caratteri di endline, dove n è pescato randomicamente ogni volta
    for(int i = 0; i < 5; i++){
        srand(time(0));
        int n = rand()%10;
        int counter = 0;
        
        Questions.open(argv[1], ios::in);
        Answers.open(argv[2], ios::in);

        do{
            Questions.getline(line, 256);
            Answers.getline(rcorretta, 256);
            counter ++;
        }while(counter != n);
        if(counter == n)
            counter = 0;

        cout << "\n" << line << " " << rcorretta << "\n";

        cin >> risposta;
        if(rcorretta[0] == risposta[0])
            cout << "GIUSTO\n";
        else
            cout << "SBAGLIATO\n";


        Questions.close();
        Answers.close();
    }

}