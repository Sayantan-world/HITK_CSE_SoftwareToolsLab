#include <stdio.h>
int main()
{
        short int x,i;
        for(i=1; i<=128; i=i*2) {
                x<<=i;
                printf("\n value of x is %d after shifting by %d",x,i);
                x=1;
        }
        return 0;
}
