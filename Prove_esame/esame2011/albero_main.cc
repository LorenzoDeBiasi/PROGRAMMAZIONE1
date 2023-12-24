#include<iostream>
#include"alberochar.h"
using namespace std;


int main(){
    tree t;
    init(t);
    char choice;
        do{
        do{
            cout << "\nAvailable options:\n"
                << "Verify if stack is empty       (E)\n"
                << "Insert a node to tree          (I)\n"
                << "search a node of the tree      (S)\n"
                << "Print the tree                 (P)\n"
                << "Deinit the tree                (D)\n"
                << "Quit                           (Q)\n";
            cin >> choice;
        }while(choice != 'E' && choice != 'I' &&- choice != 'S' && choice != 'P' && choice != 'D' && choice != 'Q');
        if(choice == 'E'){
            if(empty(t))
                cout << "\nTree's empty\n";
            else
                cout << "\nTree's not empty\n";
        }
        if(choice == 'S'){
            cout << "\nInsert the value to search: ";
            char v; cin >> v;
            if(search(t, v))
                cout << "\n" << v << " is present\n";
            else
                cout << "\n" << v << " is not present\n";
        }
        if(choice == 'I'){
            cout << "\nInsert the value of the new element: ";
            char v; cin >> v;
            insert(t, v);
        }
        if(choice == 'P'){
            cout <<"\n";
            print(t, 3);
        }
        if(choice == 'D'){
            deinit(t);
            t = NULL;            
        }

    }while (choice != 'Q');
}