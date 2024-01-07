#include<iostream>
#include"coda.h"
using namespace std;

int LastManStanding(queue &Q, int Njumps, int Nnodes);

int main(){
    queue Q;
    init(Q);
    cout << "\nHow many are running to be selected: ";
    int Nnodes; cin >> Nnodes;
    for(int i = 1; i <= Nnodes; i++)
        enqueue(Q, i);
    cout << "\nChoose a number to be used in the selection: ";
    int Njumps; cin >> Njumps;
    cout << "\nNow the last man standing will be LEADER\n";
    cout << "\nThe new Leader is the number " << LastManStanding(Q, Njumps, Nnodes) << "\n\n";
    deinit(Q);
}

int LastManStanding(queue &Q, int Njumps, int Nnodes){
    int value;
    while(first(Q, value)){
        int jumpsleft = Njumps;
        dequeue(Q);
        enqueue(Q, value);
        while(jumpsleft > 1){
            first(Q, value);
            enqueue(Q, value);
            dequeue(Q);
            jumpsleft--;
        }
        dequeue(Q);
    }
    return value;
}