#include<iostream>
#include"vettore.h"
#include"sorting.h"
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
            cout << "\nWhat do you want to do:\nGive new value 'V'  Print 'P'  Switch 'S'  Sort 'B'  Move 0s at the end 'Z'  Convert n 'C'\n";
            cin  >> choice;  
        
        } while( choice != 'V' && choice != 'P' && choice != 'S' && choice != 'B' && choice != 'Z'  && choice != 'C');
        
        
        //blocco per assegnare i valori al vettore
        if(choice == 'V')
            CreateArray(array, lenght);



        //blocco per stampare il vettore 
        if(choice == 'P')
            PrintArray(array, lenght);
        

        //blocco per invertire il vettore
        if(choice == 'S')
            SwitchArray(array, lenght);


        //blocco per ordinare il vettore
        if(choice == 'B')
            BubbleSort(array, lenght);

        
        //blocco per spostare gli zeri alla fine
        if(choice == 'Z')
            moveZero(array, lenght);

        if(choice == 'C'){
            int n, b;
            do{
                cout << "\nDimmi un numero (tra 0 e base^8 - 1) e la base (2 o 8): ";
                cin >> n >> b;
            }while ( (b != 2 && b != 8) || (n < 0 || n > (pow(b, 8) - 1)) );

            INTtoBIN(array, n, b);
        }


    } while (true);
}