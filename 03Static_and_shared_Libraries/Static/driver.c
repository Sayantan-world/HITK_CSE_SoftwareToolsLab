#include <stdio.h>
#include "add.h"
#include "sub.h"
int main() {
        int a,b;
        printf("\nEnter 2 numbers: ");
        scanf("%d%d",&a,&b);
        printf("\nSum : %d",add(a,b));
        printf("\nDiff : %d\n",sub(a,b));
        return 0;
}
