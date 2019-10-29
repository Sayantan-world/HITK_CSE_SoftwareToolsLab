#include <stdio.h>
int isquare(short int x){
        return x*x;
}
int main(){
        int i=1000000,j;
        j=isquare(i);
        printf("%d squared = %d",i,j);
        return 0;
}
