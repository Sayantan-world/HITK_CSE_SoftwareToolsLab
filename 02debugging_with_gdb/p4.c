#include <stdio.h>
int main(){
        int n;
        float sum=0.0,n1,n2;
        printf("enter the value of the number");
        scanf("%d",&n);
        for(n2=0; n2<=n; n2++) {
                n1=1/n2;
                sum=sum+n1;
        }
        printf("the sum of 1/1+1/2+1/3+....+1/%d = %f",n,sum);
        return 0;
}
