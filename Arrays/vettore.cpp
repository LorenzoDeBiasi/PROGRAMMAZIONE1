#include<iostream>
#include"vettore.h"
using namespace std;


int main(){

    int lenght;
    cout << "How long the vector has to be: ";
    cin >> lenght;
    int array[lenght];

    do
    {
        char choice;
        do{
            cout << "\nWhat do you want to do: Give new value 'V'  Print 'P'  Switch 'S'  Move 0s at the end 'Z'\n";
            cin  >> choice;  
        
        } while( choice != 'V' && choice != 'P' && choice != 'S' && choice != 'Z' );
        
        
        //blocco per assegnare i valori al vettore
        if(choice == 'V')
            CreateArray(array, lenght);



        //blocco per stampare il vettore 
        if(choice == 'P')
            PrintArray(array, lenght);
        



        //blocco per invertire il vettore
        if(choice == 'S')
            SwitchArray(array, lenght);

        
        //blocco per spostare gli zeri alla fine
        if(choice == 'Z')
            moveZero(array, lenght);

    } while (true);
}