#include<stdio.h>
#include<stdlib.h>
#include <cal.h>

int main(){
int sw,a,b;
long a1,b1;
double a2,b2;
	while(1){
		printf("\n Menu \n1. Add \n2.Subtract \n3. Multiply \n4. Divide \n5. Exit\n");
		scanf("%d",&sw);
		switch(sw){
		case 1:
			printf("\nEnter two numbers :");
			scanf("%d%d",&a,&b);
			add(a,b);
			
		break;	
		case 2:printf("\nEnter two numbers :");
			scanf("%d%d",&a,&b);
			subtract(a,b);
		break;	
		case 3:printf("\nEnter two numbers :");
			scanf("%ld%ld",&a1,&b1);
			mul(a1,b1);
		break;	
		case 4:	printf("\nEnter two numbers :");
			scanf("%lf%lf",&a2,&b2);
			divide(a2,b2);	
		break;	
		case 5: exit(0);
		default:printf("Wrong Input: Try again");
				
		}
	}

}
