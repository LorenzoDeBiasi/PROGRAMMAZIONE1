#include<iostream>
#include"vettore.h"
#include"sorting.h"
#include"searching.h"
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
            cout << "\nWhat do you want to do:\n";
            cout << "Give new value 'V'  Print 'P'  Switch 'S'  Sort 'B'  Move 0s at the end 'Z'  Convert a number'C'  find an element 'F'\n";
            cin  >> choice;  
        
        } while( choice != 'V' && choice != 'P' && choice != 'S' && choice != 'B' && choice != 'Z'  && choice != 'C' && choice != 'F');
        
        
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


        //blocco per convertire un numero in base 2 o 8
        if(choice == 'C'){
            int n, b;
            do{
                cout << "\nDimmi un numero (tra 0 e base^8 - 1) e la base (2 o 8): ";
                cin >> n >> b;
            }while ( (b != 2 && b != 8) || (n < 0 || n > (pow(b, 8) - 1)) );

            INTtoBIN(array, n, b);
        }

        //blocco per cercare la presenza di un numero nell'array
        if(choice == 'F'){
            int n;
            do{
                cout << "\nDimmi un numero (tra 0 e 9): ";
                cin >> n;
            }while(n < 0 || n > 9);
            cout << n << " si trova in posizione " << RicercaBinaria(array, n, lenght - 1) << endl;
        }

    } while (true);
}