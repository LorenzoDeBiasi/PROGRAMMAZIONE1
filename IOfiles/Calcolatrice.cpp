#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;



/*
modalità d'uso
./Calcolatrice N1 operatore N2
*/


double Calcolatrice(double n1, double n2, char operatore){
    switch (operatore){
    case '+':
        return (n1 + n2);
        break;
    case '-':
        return (n1 - n2);
        break;
    case '*':
        return (n1 * n2);
        break;
    case '/':
        return (n1 / n2);
        break;
    case '^':
        return pow(n1, n2);
        break;
    
    default:
        cout << "\nERRORE: \noperatore inserito non valido\n";
        exit(0);
        break;
    }
}


int main(int argc, char* argv[]){

    if((int)*argv[1] < 48 || (int)*argv[1] > 57){
        cout << "ERRORE: \nnumeri inseriti non validi\n";
        exit(0);
    }


    if((int)*argv[3] < 48 || (int)*argv[3] > 57){
        cout << "ERRORE: \nnumeri inseriti non validi\n";
        exit(0);        
    }



    int a = atoi(argv[1]);
    int b = atoi(argv[3]);





    char operatore;

    if(strlen(argv[2]) == 1) 
        operatore = *argv[2];
    else{
        cout << "\nERRORE: \noperatore inserito non valido\n";
        exit(0);       
    }
        
    cout << Calcolatrice((double)a, (double)b, operatore) << endl;
}