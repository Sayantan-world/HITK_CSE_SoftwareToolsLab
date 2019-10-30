#include <stdio.h>
int fact(int n){
        int res=1,i=1;
        while(n) {
                res=res*i;
                i++;
                n--;
        }
        return res;
}
