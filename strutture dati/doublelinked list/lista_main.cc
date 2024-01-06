#include<iostream>
#include"lista.h"
using namespace std;



int main(){
    list L;
    init(L);
    char choice;
    do{
        cout << "\nDigit what you want to do:"
             << "\nInsert a node into the list      (I)"
             << "\nRemove nodes with same values    (R)"
             << "\nPrint the list                   (P)"
             << "\nQuit                             (Q)"
             << "\n";
        do{
            cin >> choice;
        }while(toupper(choice) != 'I' && toupper(choice) != 'R' && toupper(choice) != 'P' && toupper(choice) != 'Q');
        switch (choice)
        {
        case 'I':
            cout << "\nDigit the value to add: ";
            int n; cin >> n;
            insert(L, n);
            break;
        case 'R':
            cout << "\nDigit the value to remove: ";
            cin >> n;   
            remove_occurences(L, n);         
            break;
        case 'P':
            print(L);
            break;
        }
    }while(choice != 'Q');
    deinit(L);
}