#include <stdio.h>
#include <stdlib.h>
int main(){
        int *p=(int *)malloc(sizeof(int));
        int x;
        *p=25;
        free(p);
        x=*p;
        printf("x is %d",x);
        return 0;
}
