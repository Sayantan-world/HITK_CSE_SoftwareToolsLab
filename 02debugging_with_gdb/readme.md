# Debugging with gdb
---
## Some basic commands --

Read this __[guide](https://www.tutorialspoint.com/gnu_debugger/gdb_commands.htm)__ 

- (gdb)list - Displays the code(first 10 lines only)
- (gdb) b [line number] - to add breakpoints
- (gdb) run - Start debugging from the breakpoint
- (gdb) next OR (gdb) n - Go to next line, may skip a function if it is there
- (gdb) step OR (gdb) s - Go to next line, will NOT skip a function if it is there
- (gdb) backtrace OR (gdb) bt - Shows call stack (LIFO manner)
- (gdb) infolocals - Shows current state of all local variables
- (gdb) where - shows line number where segmentation fault or error is occuring
- (gdb) print [variable name] - Shows value of tht variable
- (gdb) watches [variable name] - To see the change in a variaable

---

## Program 1
---
Download the code p1.c
### CODE
```
#include <stdio.h>
int main()
{
        int i;
        int *p;
        *p=25;
        printf("i is %d and *p is %d",i,*p);
        return 0;
}

```
### GDB
---
```
Reading symbols from debug1...done.
(gdb) b 2
Breakpoint 1 at 0x652: file debug1.c, line 2.
(gdb) run
Starting program: /home/Debug
Breakpoint 1, main () at debug1.c:7
7
*p=25;
(gdb) s
Program received signal SIGSEGV, Segmentation fault.
0x0000555555554656 in main () at debug1.c:7
7
*p=25;

```
OBSERVATION- The value is not being assigned to the pointer.

REASON- The pointer p is not able to point at a specific memory location/(address). This is the reason the pointer is a dangling stack pointer.
It’s an uninitialized stack segment.

---

## Program 2
---
Download the code p2.c
### CODE
```
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

```
### OUTPUT
---
```
value of x is 0 after shifting by 1
value of x is 4 after shifting by 2
value of x is 16 after shifting by 4
value of x is 256 after shifting by 8
value of x is 0 after shifting by 16
value of x is 1 after shifting by 32
value of x is 1 after shifting by 64
value of x is 1 after shifting by 128

```
OBSERVATION- The value of x changes to 0 after few shifting towards the left. This should not happen while shifting as the number gets multiplied by
2 each time it gets shifted.

REASON- Short int has a byte size of 2. So, as we keep on shifting towards the left a certain point is reached where the value exceeds the value of
short int and because of it the value changes to zero. The range is (2^-16)-1 to 2^16. max size it can attain is of 32767.

---

## Program 3
---
Download the code p3.c
### CODE
```
#include <stdio.h>
int isquare(short int x){
        return x*x;
}
int main(){
        int i=1000000,j;
        j=isquare(i);
        printf("%d squared = %d",i,j);
        return 0;
}

```
### GDB
---
```
Breakpoint 1, main () at debug3.c:10
10
int i=1000000,j;
(gdb) s
11
j=isquare(i);
(gdb) s
isquare (x=16960) at debug3.c:5
5
return x*x;
(gdb) s
6
}

```
OBSERVATION- i takes the value 16960 as seen in the debugging
section of the program.

REASON- This is because short int has a byte size of 2 so it can exceed that
in the function isquare (x*x) return 16960.Max size it can attain is of
32767.

---
## Program 4
---
Download the code p4.c
### CODE
```
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

```
### GDB
---
```
9
for(n2=0;n2<=n;n2++)
(gdb) n
11
n1=1/n2;
(gdb) n
12 sum=sum+n1;
(gdb) print n1
$1 = inf
(gdb) print n2
$2 = 0
(gdb) n
9
for(n2=0;n2<=n;n2++)
(gdb) print sum
$3 = inf
(gdb)

```
OBSERVATION- The value of sum becomes zero. (same for n1)

REASON- At the start of the loop the value of n2 turns out to be zero. So,
during the assignment of the value to n1, n1 turns out to be infinity and
same reason for sum.

---
## Program 5
---
Download the code p5.c
### CODE
```
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

```
### GDB
---
```
(gdb) print *p
$2 = 25
(gdb) n
11
x=*p;
(gdb) print *p
$3 = 0
(gdb) n
12 printf("x is %d",x);
(gdb) print x
$4 = 0

```
OBSERVATION- In this case there is a heap memory allocation of the
pointer. The pointer is pointing to a specific address. The value of x is 0.

REASON- The pointing before freeing is having the value 25. And after it is
equal to 0. So, x also turns out to be zero.

---

## Program 6
---
Download the code p6.c
### CODE
```
#include <stdio.h>
int main()
{
        float x=0.01;
        if(x==0.01)
                printf("yes");
        else
                printf("no");
        return 0;
}

```
### GDB
---
```
Breakpoint 1, main () at debug6.c:5
5
float x=0.01;
(gdb) n
6
if(x==0.01)
(gdb) print x
$1 = 0.00999999978
(gdb) n
9
printf("no");

```
OBSERVATION- “no” appears as the output of the code.

REASON- As x has a floating-point data type so the number gets stored in
the form of IEEE-754 Floating Point Representation. And while retrieving
the number back the precision value of it gets lost.

---

## Program 7
---
Download the code p7.c
### CODE
```
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

```
### GDB
---
```

*UNEXPECTED BEHAVIOUR : stack protection detected in mordern machines (use old version of gdb) or turn off stack protection

```
OBSERVATION- In this case the array gets stored normally index by index
without showing any case of a different output. But sometimes in the last
loop it takes the value of i as 6 and *(arr+i) as some kind of a garbage value.

REASON- Array bound exception

---

