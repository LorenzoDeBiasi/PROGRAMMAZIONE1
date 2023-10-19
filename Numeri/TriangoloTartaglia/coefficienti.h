int coefficiente(int r, int c){
    if(c == 1 || c == r)
        return 1;
    else
        return coefficiente(r-1, c-1) + coefficiente(r-1, c);
}