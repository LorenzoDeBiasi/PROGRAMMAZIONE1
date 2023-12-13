#include<iostream>
#include"stack.h"
using namespace std;


int main(){
    pila x;
    init(x);
    char choice;
    do{
        do{
            cout << "\nAvailable options:\n"
                << "Verify if stack is not empty   (E)\n"
                << "Add a node to stack            (A)\n"
                << "Shrink the higher element      (S)\n"
                << "Show the first element         (F)\n"
                << "Print the stack                (P)\n"
                << "Deinit the stack               (D)\n"
                << "Quit                           (Q)\n";
            cin >> choice;
        }while(choice != 'E' && choice != 'A' &&choice != 'S' &&choice != 'F' &&choice != 'P' && choice != 'D' && choice != 'Q');
        if(choice == 'E'){
            if(!nempty(x))
                cout << "\nStack's empty\n";
            else
                cout << "\nStack's not empty\n";
        }
             
        if(choice == 'F'){
            long n;
            first(x, n);
            cout << "\nThe first element is " << n << "\n";            
        }
        if(choice == 'S')
            shrink(x);
        if(choice == 'A'){
            cout << "\nInsert the value of the new element: ";
            long n; cin >> n;
            add(x, n);
        }
        if(choice == 'P'){
            cout <<"\n";
            print(x);
        }
        if(choice == 'D'){
            deinit(x);
            x = NULL;            
        }

    }while (choice != 'Q');

    //controllo deinit
    if(x != NULL)
        deinit(x);
    
}