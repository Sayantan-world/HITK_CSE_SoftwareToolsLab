#include <stdio.h>
int fact(int n){
        int i=1,fact=1;
        if(n<=10) {
                for(i=1; i<=n; i++)
                        fact*=i;
                return fact;
        }
        else {
                return -1;
        }
}
void main(){
        int x;
        x=fact(11);
        printf("Result : %d\n",x);
}
