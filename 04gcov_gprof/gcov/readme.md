# Code coverage testing with gcov

gcov - gcov is a test coverage program. Use it in concert with GCC to analyze your programs to help create more efficient, 
faster running code and to discover untested parts of your program. You can use gcov as a profiling tool to help discover 
where your optimization efforts will best affect your code. You can also use gcov along with the other profiling tool, gprof, 
to assess which parts of your code use the greatest amount of computing time.

READ THIS __[GUIDE](https://www.tutorialspoint.com/unix_commands/gcov.htm)__

### Follow the steps below :

- Download fact.c and open terminalto move to ur current working directory and execute this
```
gcc -fprofile-arcs -ftest-coverage fact.c
```
When using gcov, you must first compile your program with two special GCC options: -fprofile-arcs -ftest-coverage. 
This tells the compiler to generate additional information needed by gcov (basically a flow graph of the program) and 
also includes additional code in the object files for generating the extra profiling information needed by gcov. 
These additional files are placed in the directory where the object file is located.<br><br>
__Generates fact.gcno file and a.out file__

- Now run the a.out file
```
./a.out
```
__Generates fact.gcda file__
- Now run gcov in ur soure file
```
gcov fact.c
```
Here u may have used -b or -a flags (read abt them in the GUIDE)<br><br>
Running gcov with your program’s source file names as arguments will now produce a listing of the code along with frequency of execution for each line.
<br><br>
__What u see is and fact.c.gcov is generated__
```
File 'fact.c'
Lines executed:72.73% of 11
Creating 'fact.c.gcov'
```
- Now display it using
```
cat fact.c.gcov
```
and this gets generated
```
       -:    0:Source:fact.c
        -:    0:Graph:fact.gcno
        -:    0:Data:fact.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:#include <stdio.h>
        1:    2:int fact(int n){
        1:    3:        int i=1,fact=1;
        1:    4:        if(n<=10) {
    #####:    5:                for(i=1; i<=n; i++)
    #####:    6:                        fact*=i;
    #####:    7:                return fact;
        -:    8:        }
        -:    9:        else {
        1:   10:                return -1;
        -:   11:        }
        -:   12:}
        1:   13:void main(){
        -:   14:        int x;
        1:   15:        x=fact(11);
        1:   16:        printf("Result : %d\n",x);
        1:   17:}
```        

Additional block information may succeed each line, when requested by command line option(use the flags)
The execution_count is - for lines containing no code and ##### for lines which were never executed. 
Some lines of information at the start have line_number of zero.


