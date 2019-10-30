#include <stdio.h>
void f1(){
        int i;
        printf("------F1------\n");
        for(i=0; i<=0xfff123ff; i++) {
        }
}
void f2(){
        int i;
        printf("----F2-----\n");
        for(i=0; i<=0xf2f1ffff; i++) {
        }
}
void f3(){
        int i;
        printf("----F3-----\n");
        for(i=0; i<=0xfaaa1eff; i++) {
        }
}
int main(){
        f1();
        f2();
        f3();
        return 0;
}
