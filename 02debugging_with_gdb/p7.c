#include <stdio.h>
int main()
{
        int arr[5],i;
        for(i=0; i<=5; i++) {
                arr[i]=i+1;
                printf("value of arr[%d] is %d",i,arr[i]);
        }
        return 0;
}
