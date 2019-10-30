#include <stdio.h>
void new_func1(void);
void f1(){
        int i;
        printf("------F1 running------\n");
        for(i=0; i<=0x7ff123ff; i++) {
        }
        new_func1();
}
void f2(){
        int i;
        printf("------F2 running------\n");
        for(i=0; i<=0xf2f1ffff; i++) {
        }
}
void f3(){
        int i;
        printf("------F3 running------\n");
        for(i=0; i<=0xfaaa1eff; i++) {
        }
}
void new_func1(void)
{
        printf("------FI running------\n");
        int i = 0;

        for(; i<0xffffffee; i++);

        return;
}
int main(){
        f1();
        f2();
        f3();
        return 0;
}
