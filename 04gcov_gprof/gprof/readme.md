# Runtime profiling with gprof	
gprof - Profiling is an important aspect of software programming.
Through profiling one can determine the parts in program code that are time consuming and need to be re-written. 
This helps make your program execution faster which is always desired.
<br><br>
READ THESE __[GUIDE1](https://www.thegeekstuff.com/2012/08/gprof-tutorial)__ __[GUIDE2](https://www.tutorialspoint.com/unix_commands/gprof.htm)__

### Follow the steps below :
- Download loops.c and open terminal to move to ur current working directory and type this
```
gcc -Wall -pg loops.c -o loops
```
Please Note: -Wall means all Warnings (enabled by compiler)<br><br>
-pg : Generate extra code to write profile information suitable for the analysis program gprof.
You must use this option when compiling the source files you want data about, and you must also use it when linking.
__Generates loops executable file__
- Next run the program
```
./loops
```
__Generates  gmon.out file__
- Now type these
```
gprof -b loops gmon.out > short_analysis.txt
```
```
 gprof loops gmon.out > analysis.txt
 ```
 
Here we put the analysis made by profiling the codes to both the text files.<br><br>
-b flag is used to make a shart compact version(eliminate verbose info) of the analysis(Flat profile and call graph only)
<br><br>
Short analysis looks like this and may vary in ur machine

- Now type 
```
cat short_analysis.txt
```
U get this
```
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls   s/call   s/call  name
 29.18      6.67     6.67        1     6.67     6.67  new_func1

 28.30     13.15     6.47        1     6.47     6.47  f3
 27.20     19.37     6.22        1     6.22     6.22  f2
 15.82     22.99     3.62        1     3.62    10.29  f1


                        Call graph


granularity: each sample hit covers 2 byte(s) for 0.04% of 22.99 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.00   22.99                 main [1]
                3.62    6.67       1/1           f1 [2]
                6.47    0.00       1/1           f3 [4]
                6.22    0.00       1/1           f2 [5]
-----------------------------------------------
                3.62    6.67       1/1           main [1]
[2]     44.8    3.62    6.67       1         f1 [2]
                6.67    0.00       1/1           new_func1 [3]
-----------------------------------------------
                6.67    0.00       1/1           f1 [2]
[3]     29.0    6.67    0.00       1         new_func1 [3]
-----------------------------------------------
                6.47    0.00       1/1           main [1]
[4]     28.2    6.47    0.00       1         f3 [4]
-----------------------------------------------
                6.22    0.00       1/1           main [1]
[5]     27.1    6.22    0.00       1         f2 [5]
-----------------------------------------------


Index by function name

   [2] f1                      [4] f3
   [5] f2                      [3] new_func1
```
