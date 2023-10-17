
void SwitchArray(int array[], int n){
    int temp;
    
    for(int i = 0; i < (n / 2); i++){
        temp = array[i];
        array[i] = array[(n - 1) - i];
        array[(n - 1) - i] = temp;        
    }


}