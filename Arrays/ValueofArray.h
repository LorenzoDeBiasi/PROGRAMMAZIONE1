#include<cstdlib>
#include<time.h>

void CreateArray(int array[], int n){
    srand(time(0));
    for(int i = 0; i < n; i++)
        array[i] = rand()%10;
}